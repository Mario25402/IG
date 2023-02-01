/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#include <GL/glew.h>
#include "glwidget.h"
#include "qimagereader.h"
#include "window.h"
#include <iostream>

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Predefinido

/*****************************************************************************/
/*                               Constructor                                 */
/*****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
}

/*****************************************************************************/
/*                       Evento resize ventana                               */
/*****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}

/*****************************************************************************/
/*                            Limpiar ventana                                */
/*****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

/*****************************************************************************/
/*                            Evento de dibujo                               */
/*****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}

/*****************************************************************************/
/*                           Posicionar cámara                               */
/*****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}

/*****************************************************************************/
/*                          Cambio de proyección                             */
/*****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)

  if (perspectiva) glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
  else glOrtho(-orthoLimit, orthoLimit, -orthoLimit, orthoLimit, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
}

/*****************************************************************************/
/*                       Inicialización de OpenGL                            */
/*****************************************************************************/

void _gl_widget::initializeGL()
{

      /////////////////////////////////GLEW////////////////////////////////////

      glewExperimental = GL_TRUE;
      int err = glewInit();
      if (GLEW_OK != err){
        /*QMessageBox MsgBox(this);
        MsgBox.setText("Error: There is not OpenGL drivers\n\nPlease, "
                       "look for the information of your GPU "
                       "(AMD, INTEL or NVIDIA) and install the drivers");
        MsgBox.exec();
        Window->close();*/
        printf("%s", glewGetErrorString(err));
      }

      ////////////////////////////////Programa/////////////////////////////////

      const GLubyte* strm;

      strm = glGetString(GL_VENDOR);
      std::cerr << "Vendor: " << strm << "\n";
      strm = glGetString(GL_RENDERER);
      std::cerr << "Renderer: " << strm << "\n";
      strm = glGetString(GL_VERSION);
      std::cerr << "OpenGL Version: " << strm << "\n";

      if (strm[0] == '1'){
        std::cerr << "Only OpenGL 1.X supported!\n";
        exit(-1);
      }

      strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
      std::cerr << "GLSL Version: " << strm << "\n";

      int Max_texture_size=0;
      glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
      std::cerr << "Max texture size: " << Max_texture_size << "\n";

      glClearColor(1.0,1.0,1.0,1.0);
      glEnable(GL_DEPTH_TEST);

      ////////////////////////////////Texturas/////////////////////////////////

      // Code for reading an image
      QString File_name("/home/mario/Escritorio/IG/texturas/dia_8192.jpg");
      QImageReader Reader(File_name);
      Reader.setAutoTransform(true);
      QImage Image = Reader.read();
      if (Image.isNull()){
          QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                   tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
          exit(-1);
      }
      Image = Image.mirrored();
      Image = Image.convertToFormat(QImage::Format_RGB888);

      // Code to control the application of the texture
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

      // Code to pass the image to OpenGL to form a texture 2D
      glTexImage2D(GL_TEXTURE_2D, 0, 3, Image.width(), Image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, Image.bits());

      /////////////////////////////////Variables///////////////////////////////

      Observer_angle_x = 0;
      Observer_angle_y = 0;
      Observer_distance = DEFAULT_DISTANCE;

      Draw_point = false;
      Draw_line = true;
      Draw_fill = false;
      Draw_chess = false;

      Draw_light = false;
      Draw_texture = false;

      max_zoom  = false;
      max_boton = false;
      max_flash = false;

      flat = true;
      gouraud = false;

      luz0.activada = true;
      luz1.activada = false;
      num_mat = 0;

      old_x = Observer_angle_x;
      old_y = Observer_angle_y;

      perspectiva = true;
      orthoLimit = 1.8;
}

/*****************************************************************************/
/*                        Evento tecla pulsada                               */
/*****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
    switch(Keyevent->key()){
        case Qt::Key_1:Object = OBJECT_TETRAHEDRON;break;
        case Qt::Key_2:Object = OBJECT_CUBE;break;
        case Qt::Key_3:Object = OBJECT_CONE;break;
        case Qt::Key_4:Object = OBJECT_CYLINDER;break;
        case Qt::Key_5:Object = OBJECT_SPHERE;break;
        case Qt::Key_6:Object = OBJECT_PLY;break;
        case Qt::Key_7:Object = OBJECT_HIERARCHICAL;break;
        case Qt::Key_8:Object = OBJECT_DASHBOARD;break;
        case Qt::Key_9:Object = OBJECT_GROUP;break;

        case Qt::Key_P:Draw_point =! Draw_point;break;
        case Qt::Key_L:Draw_line =! Draw_line;break;
        case Qt::Key_F:Draw_fill =! Draw_fill;break;
        //case Qt::Key_C:Draw_chess =! Draw_chess;break;

        case Qt::Key_Left:Observer_angle_y -= ANGLE_STEP;break;
        case Qt::Key_Right:Observer_angle_y += ANGLE_STEP;break;
        case Qt::Key_Up:Observer_angle_x -= ANGLE_STEP;break;
        case Qt::Key_Down:Observer_angle_x += ANGLE_STEP;break;
        case Qt::Key_PageUp:Observer_distance *= 1.2, orthoLimit *= 1.2;break;
        case Qt::Key_PageDown:Observer_distance /= 1.2, orthoLimit /= 1.2   ;break;

        case Qt::Key_A:modificadores.animado =! modificadores.animado;break;
        case Qt::Key_Q:modificadores.zoom += modificadores.tasa_zoom;
                     modificadores.zoom_rotar += modificadores.tasa_zoom_rotar; break;
        case Qt::Key_W:modificadores.zoom -= modificadores.tasa_zoom;
                     modificadores.zoom_rotar -= modificadores.tasa_zoom_rotar; break;
        case Qt::Key_S:modificadores.boton += modificadores.tasa_boton;break;
        case Qt::Key_D:modificadores.boton -= modificadores.tasa_boton;break;
        case Qt::Key_Z:modificadores.flash += modificadores.tasa_flash;break;
        case Qt::Key_X:modificadores.flash -= modificadores.tasa_flash;break;
        case Qt::Key_E:modificadores.tasa_zoom += 0.05;
                     modificadores.tasa_zoom_rotar += 1;break;
        case Qt::Key_R:modificadores.tasa_zoom -= 0.05;
                     modificadores.tasa_zoom_rotar -= 1;break;
        case Qt::Key_T:modificadores.tasa_boton += 0.05;break;
        case Qt::Key_Y:modificadores.tasa_boton -= 0.05;break;
        case Qt::Key_U:modificadores.tasa_flash += 0.005;break;
        case Qt::Key_I:modificadores.tasa_flash -= 0.005;break;

        case Qt::Key_F1:Draw_fill = !Draw_fill;break;
        case Qt::Key_F2:Draw_chess = !Draw_chess;break;
        case Qt::Key_F3:Draw_light = !Draw_light, flat = true, gouraud = false;break;
        case Qt::Key_F4:Draw_light = !Draw_light, gouraud = true, flat = false;break;
        case Qt::Key_F5:Draw_texture = !Draw_texture;break;
        case Qt::Key_F6:Draw_texture = true, Draw_light = true, flat = true, gouraud = false;break;
        case Qt::Key_F7:Draw_texture = true, Draw_light = true, gouraud= true, flat = false;break;

        case Qt::Key_J:luz0.activada = !luz0.activada, luz1.activada = false;break;
        case Qt::Key_K:luz1.activada = !luz1.activada, luz0.activada = false;break;
        case Qt::Key_M:((++num_mat) %= 3);break;
        case Qt::Key_C:perspectiva = true;break;
        case Qt::Key_V:perspectiva = false;break;
    }

    update();
}

/*****************************************************************************/
/*                            Dibujo de objetos                              */
/*****************************************************************************/

void _gl_widget::draw_objects()
{
    Axis.draw_line();

    /////////////////////////////////Puntos//////////////////////////////////////
    if (Draw_point){
        glPointSize(3);
        glColor3fv((GLfloat *) &MAGENTA);

        switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw(0);break;
            case OBJECT_CUBE:Cube.draw(0);break;
            case OBJECT_CONE:Cone.draw(0);break;
            case OBJECT_CYLINDER:Cylinder.draw(0);break;
            case OBJECT_SPHERE:Sphere.draw(0);break;
            case OBJECT_PLY:Ply.draw(0);break;
            case OBJECT_HIERARCHICAL:Hierarchical.draw(0, modificadores);break;
            case OBJECT_DASHBOARD:Tablero.draw(0);break;
            case OBJECT_GROUP:Group.draw_point();break;
            default:break;
        }
    }

    /////////////////////////////////Lineas//////////////////////////////////////
    if (Draw_line){
        glLineWidth(2);
        glColor3fv((GLfloat *) &BLUE);

        switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw(1);break;
            case OBJECT_CUBE:Cube.draw(1);break;
            case OBJECT_CONE:Cone.draw(1);break;
            case OBJECT_CYLINDER:Cylinder.draw(1);break;
            case OBJECT_SPHERE:Sphere.draw(1);break;
            case OBJECT_PLY:Ply.draw(1);break;
            case OBJECT_HIERARCHICAL:Hierarchical.draw(1, modificadores);break;
            case OBJECT_DASHBOARD:Tablero.draw(1);break;
            case OBJECT_GROUP:Group.draw_line();break;
            default:break;
        }
    }

    /////////////////////////////////Relleno/////////////////////////////////////
    if (Draw_fill){
        glColor3fv((GLfloat *) &BLACK);

        switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw(2);break;
            case OBJECT_CUBE:Cube.draw(2);break;
            case OBJECT_CONE:Cone.draw(2);break;
            case OBJECT_CYLINDER:Cylinder.draw(2);break;
            case OBJECT_SPHERE:Sphere.draw_fill(flat);break;
            case OBJECT_PLY:Ply.draw(2);break;
            case OBJECT_HIERARCHICAL:Hierarchical.draw(2, modificadores);break;
            case OBJECT_DASHBOARD:Tablero.draw(2);break;
            case OBJECT_GROUP:Group.draw_fill();break;
            default:break;
        }
    }

    /////////////////////////////////Ajedrez/////////////////////////////////////
    if (Draw_chess){
        switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw(3);break;
            case OBJECT_CUBE:Cube.draw(3);break;
            case OBJECT_CONE:Cone.draw(3);break;
            case OBJECT_CYLINDER:Cylinder.draw(3);break;
            case OBJECT_SPHERE:Sphere.draw(3);break;
            case OBJECT_PLY:Ply.draw(3);break;
            case OBJECT_HIERARCHICAL:Hierarchical.draw(3, modificadores);break;
            case OBJECT_DASHBOARD:Tablero.draw(3);break;
            case OBJECT_GROUP:Group.draw_chess();break;
            default:break;
        }
    }

    //////////////////////////////////Luces//////////////////////////////////////
    if (!Draw_light) glDisable(GL_LIGHTING);
    else draw_light();

    ////////////////////////////////Texturas/////////////////////////////////////
    if (Draw_texture){
        if (Object==OBJECT_DASHBOARD) Tablero.draw_texture();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Práctica 3

/*****************************************************************************/
/*                              Animación                                    */
/*****************************************************************************/

void _gl_widget::animacion(){
    if (modificadores.animado){

        ///////////////////////////////ZOOM////////////////////////////////////
        if (modificadores.zoom >= modificadores.max_zoom) max_zoom = true;
        else if (modificadores.zoom <= modificadores.min_zoom) max_zoom = false;

        // Aumentar
        if (!max_zoom){
            modificadores.zoom += modificadores.tasa_zoom;
            modificadores.zoom_rotar += modificadores.tasa_zoom_rotar;
        }

        // Disminuir
        else{
            modificadores.zoom -= modificadores.tasa_zoom;
            modificadores.zoom_rotar -= modificadores.tasa_zoom_rotar;

        }

        ///////////////////////////////BOTON///////////////////////////////////
        if (modificadores.boton >= modificadores.max_boton) max_boton = true;
        else if (modificadores.boton <= modificadores.min_boton) max_boton = false;

        // Aumentar
        if (!max_boton){
            modificadores.boton += modificadores.tasa_boton;
        }

        // Disminuir
        else{
            modificadores.boton -= modificadores.tasa_boton;
        }

        ///////////////////////////////FLASH///////////////////////////////////
        if (modificadores.flash >= modificadores.max_flash) max_flash = true;
        else if (modificadores.flash <= modificadores.min_flash) max_flash = false;

        // Aumentar
        if (!max_flash){
            modificadores.flash += modificadores.tasa_flash;
        }

        // Disminuir
        else{
            modificadores.flash -= modificadores.tasa_flash;
        }
    }

    update();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Práctica 4

/*****************************************************************************/
/*                        Configuración de luces                             */
/*****************************************************************************/

void _gl_widget::draw_light(){
    glEnable(GL_LIGHTING);

    /////////////////////////////////MODO//////////////////////////////////////
    if (flat) glShadeModel(GL_FLAT);
    else if (gouraud) glShadeModel(GL_SMOOTH);

    ///////////////////////////////MATERIAL////////////////////////////////////
    /// JADE
    if (num_mat == 0){
        m0.brillo = 12.8;
        m0.ambiental = _vertex4f(0.135, 0.2225, 0.1575, 0.95);
        m0.difusa = _vertex4f(0.54, 0.89, 0.63, 0.95);
        m0.especular = _vertex4f(0.316228, 0.316228, 0.316228, 0.95);

        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, (GLfloat) m0.brillo);
        glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &m0.ambiental);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &m0.difusa);
        glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &m0.especular);
    }

    /// CYAN PLASTIC
    else if (num_mat == 1){
        m1.brillo = 32;
        m1.ambiental = _vertex4f(0, 0.1, 0.06, 1);
        m1.difusa = _vertex4f(0, 0.50980392, 0.50980392, 1);
        m1.especular = _vertex4f(0.50980392, 0.50980392, 0.50980392, 1);

        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, (GLfloat) m1.brillo);
        glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &m1.ambiental);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &m1.difusa);
        glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &m1.especular);
    }

    /// YELLOW RUBBER
    else if (num_mat == 2){
        m2.brillo = 10;
        m2.ambiental = _vertex4f(0.05, 0.05 , 0, 1);
        m2.difusa = _vertex4f(0.5 , 0.5, 0.4, 1);
        m2.especular = _vertex4f(0.7, 0.7, 0.04, 1);

        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, (GLfloat) m2.brillo);
        glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &m2.ambiental);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &m2.difusa);
        glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &m2.especular);
    }

    ////////////////////////////////LUZ 0//////////////////////////////////////
    if (luz0.activada){
        glDisable(GL_LIGHT1);

        luz0.posicion = _vertex4f(200, 300, 200, 0);
        luz0.ambiental = _vertex4f(0.2, 0.2, 0.2, 1);
        luz0.difusa = _vertex4f(1, 1, 1, 1);
        luz0.especular = _vertex4f(1, 1, 1, 1);

        glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat*)&luz0.posicion);
        glLightfv(GL_LIGHT0, GL_AMBIENT, (GLfloat*)&luz0.ambiental);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, (GLfloat*)&luz0.difusa);
        glLightfv(GL_LIGHT0, GL_SPECULAR, (GLfloat*)&luz0.especular);

        glEnable(GL_LIGHT0);
    }

    /////////////////////////////////LUZ 1/////////////////////////////////////
    if (luz1.activada){
        glPushMatrix();
        glDisable(GL_LIGHT0);

        luz1.posicion = _vertex4f(1, -1, 1, 0);
        luz1.ambiental = _vertex4f(1, 0, 1, 1);
        luz1.difusa = _vertex4f(1, 0, 1, 1);
        luz1.especular = _vertex4f(1, 0, 1, 1);

        glLightfv(GL_LIGHT1, GL_POSITION, (GLfloat*)&luz1.posicion);
        glLightfv(GL_LIGHT1, GL_AMBIENT, (GLfloat*)&luz1.ambiental);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, (GLfloat*)&luz1.difusa);
        glLightfv(GL_LIGHT1, GL_SPECULAR, (GLfloat*)&luz1.especular);

        glEnable(GL_LIGHT1);
        glPopMatrix();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Práctica 5

/*****************************************************************************/
/*                          Movimiento de ratón                              */
/*****************************************************************************/

void _gl_widget::mouseMoveEvent(QMouseEvent *Event)
{
    int x = Event->position().x();
    int y = Event->position().y();

    if (old_x < x) Observer_angle_y += ANGLE_STEP*2;
    else if (old_x > x) Observer_angle_y -= ANGLE_STEP*2;
    old_x = x;

    if (old_y < y) Observer_angle_x += ANGLE_STEP*2;
    else if (old_y > y) Observer_angle_x -= ANGLE_STEP*2;
    old_y = y;

    update();
}

/*****************************************************************************/
/*                            Zoom de ratón                                  */
/*****************************************************************************/

void _gl_widget::wheelEvent(QWheelEvent *Event){
    int dist = Event->pixelDelta().y();

    if (perspectiva){
        if (dist > 0){
            if (Observer_distance > 0.2) Observer_distance -= 0.2;
        }
        else if (dist < 0) Observer_distance += 0.2;
    }

    else{
        if (dist > 0){
            if (orthoLimit > 0.2) orthoLimit -= 0.2;
        }
        else if (dist < 0) orthoLimit += 0.2;
    }

    Event->accept();
    update();
}

/*****************************************************************************/
/*                      Click derecho del ratón                              */
/*****************************************************************************/

void _gl_widget::mousePressEvent(QMouseEvent *Event){
    if (Event->button() == Qt::RightButton){
        Xpicked = Event->position().x();
        Ypicked = Event->position().y();

        Ypicked = (Ypicked * -1) + Window->height();

        pick();
    }

    update();
}

/*****************************************************************************/
/*                                  Pick                                     */
/*****************************************************************************/

void _gl_widget::pick()
{
    makeCurrent();

    // Frame Buffer Object to do the off-screen rendering
    GLuint FBO;
    glGenFramebuffers(1,&FBO);
    glBindFramebuffer(GL_FRAMEBUFFER,FBO);

    // Texture for drawing
    GLuint Color_texture;
    glGenTextures(1,&Color_texture);
    glBindTexture(GL_TEXTURE_2D,Color_texture);
    // RGBA8
    glTexStorage2D(GL_TEXTURE_2D,1,GL_RGBA8, Window->width(),Window->height());
    // this implies that there is not mip mapping
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    // Texure for computing the depth
    GLuint Depth_texture;
    glGenTextures(1,&Depth_texture);
    glBindTexture(GL_TEXTURE_2D,Depth_texture);
    // Float
    glTexStorage2D(GL_TEXTURE_2D,1,GL_DEPTH_COMPONENT24, Window->width(),Window->height());

    // Attatchment of the textures to the FBO
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,Color_texture,0);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,Depth_texture,0);

    // OpenGL will draw to these buffers (only one in this case)
    static const GLenum Draw_buffers[]={GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1,Draw_buffers);

    // Limpi
    glClearColor(1.0,1.0,1.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*************************/

    // dibujar escena para seleccion
    draw_selection();

    /*************************/

    // get the pixel
    int Color;
    glReadBuffer(GL_FRONT);
    glPixelStorei(GL_PACK_ALIGNMENT,1);
    glReadPixels(Xpicked,Ypicked,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&Color);

    /*************************/

    // convertir de RGB a identificador
    float Red = (Color & 0x000000FF);
    float Green = (Color & 0x0000FF00) >> 8;
    float Blue = (Color & 0x00FF0000) >> 16;

    //cout << endl << "Rojo: " << Red << " Verde: " << Green << " Azul: " << Blue << endl;

    int identificador = (256*256*Red) + (256*Green) + Blue;
    //cout << endl << "Identificador: " << identificador << endl;

    draw_selection(identificador);
    update();

    /*************************/

    glDeleteTextures(1,&Color_texture);
    glDeleteTextures(1,&Depth_texture);
    glDeleteFramebuffers(1,&FBO);

    // the normal framebuffer takes the control of drawing
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER,defaultFramebufferObject());
}

/*****************************************************************************/
/*                      Selección triangulo (pick)                           */
/*****************************************************************************/

void _gl_widget::draw_selection(int indice){

    if (indice == -1){
        switch(Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw_selection();break;
            case OBJECT_CUBE:Cube.draw_selection();break;
            case OBJECT_CONE:Cone.draw_selection();break;
            case OBJECT_CYLINDER:Cylinder.draw_selection();break;
            case OBJECT_SPHERE:Sphere.draw_selection();break;
            case OBJECT_PLY:Ply.draw_selection();break;
            case OBJECT_DASHBOARD:Tablero.draw_selection();break;
            case OBJECT_GROUP:Group.draw_selection();break;
        }
    }

    else{
        switch(Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.select(indice);break;
            case OBJECT_CUBE:Cube.select(indice);break;
            case OBJECT_CONE:Cone.select(indice);break;
            case OBJECT_CYLINDER:Cylinder.select(indice);break;
            case OBJECT_SPHERE:Sphere.select(indice);break;
            case OBJECT_PLY:Ply.select(indice);break;
            case OBJECT_DASHBOARD:Tablero.select(indice);break;
            case OBJECT_GROUP:Group.select(indice);break;
        }
    }
}
