/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "qimagereader.h"
#include "window.h"
#include <iostream>

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);

  // Code for reading an image
  QString File_name("/home/mario/Escritorio/IG/texturas/dia_8192.jpg");
  QImage Image;
  QImageReader Reader (File_name);
  Reader.setAutoTransform(true);
  Image = Reader.read();
  if (Image.isNull()) {
    QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                             tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
    exit(-1);
  }
  Image=Image.mirrored();
  Image=Image.convertToFormat(QImage::Format_RGB888);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
      case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
      case Qt::Key_2:Object=OBJECT_CUBE;break;
      case Qt::Key_3:Object=OBJECT_CONE;break;
      case Qt::Key_4:Object=OBJECT_CYLINDER;break;
      case Qt::Key_5:Object=OBJECT_SPHERE;break;
      case Qt::Key_6:Object=OBJECT_PLY;break;
      case Qt::Key_7:Object=OBJECT_HIERARCHICAL;break;
      case Qt::Key_8:Object=OBJECT_DASHBOARD;break;
      case Qt::Key_9:Object=OBJECT_GROUP;break;

      case Qt::Key_P:Draw_point=!Draw_point;break;
      case Qt::Key_L:Draw_line=!Draw_line;break;
      case Qt::Key_F:Draw_fill=!Draw_fill;break;
      //case Qt::Key_C:Draw_chess=!Draw_chess;break;

      case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
      case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
      case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
      case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
      case Qt::Key_PageUp:Observer_distance*=1.2;break;
      case Qt::Key_PageDown:Observer_distance/=1.2;break;

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
      case Qt::Key_F6:flat = true, gouraud = false;break;
      case Qt::Key_F7:gouraud= true, flat = false;break;

      case Qt::Key_J:luz0.activada = !luz0.activada;break;
      case Qt::Key_K:luz1.activada = !luz1.activada;break;
      case Qt::Key_M:((++num_mat) %= 3);break;
      case Qt::Key_C:perspectiva = true, paralela = false;break;
      case Qt::Key_V:perspectiva = false, paralela = true;break;

  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
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
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
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
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw(2);break;
    case OBJECT_CUBE:Cube.draw(2);break;
    case OBJECT_CONE:Cone.draw(2);break;
    case OBJECT_CYLINDER:Cylinder.draw(2);break;
    case OBJECT_SPHERE:Sphere.draw(2);break;
    case OBJECT_PLY:Ply.draw(2);break;
    case OBJECT_HIERARCHICAL:Hierarchical.draw(2, modificadores);break;
    case OBJECT_DASHBOARD:Tablero.draw(2);break;
    default:break;
    }
  }

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
    default:break;
    }
  }

  if (Draw_light){
      glEnable(GL_LIGHTING);

      if (flat) glShadeModel(GL_FLAT);
      else if (gouraud) glShadeModel(GL_SMOOTH);

      if (luz0.activada){
          //luz0.posicion = _vertex4f(-1, 1, 0, 0.3);
          luz0.ambiental = _vertex4f(1, 0, 1, 1);
          luz0.difusa = _vertex4f(1, 1, 1, 1);
          luz0.especular = _vertex4f(1, 1, 0, 1);

          if (num_mat == 0){
              glMaterialf(GL_FRONT, GL_SHININESS, 20);
              glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &luz0.ambiental);
              glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &luz0.difusa);
              glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &luz0.especular);
          }
          if (num_mat == 1){
              glMaterialf(GL_FRONT, GL_SHININESS, 87);
              glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &luz0.ambiental);
              glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &luz0.difusa);
              glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &luz0.especular);
          }
          if (num_mat == 2){
              glMaterialf(GL_FRONT, GL_SHININESS, 109);
              glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &luz0.ambiental);
              glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &luz0.difusa);
              glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &luz0.especular);
          }

          glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat*)&luz0.posicion);
          glLightfv(GL_LIGHT0, GL_AMBIENT, (GLfloat*)&luz0.ambiental);
          glLightfv(GL_LIGHT0, GL_DIFFUSE, (GLfloat*)&luz0.difusa);
          glLightfv(GL_LIGHT0, GL_SPECULAR, (GLfloat*)&luz0.especular);

          glEnable(GL_LIGHT0);
      }

      if (luz1.activada){
          luz1.posicion = _vertex4f(-1, 1, 0, 0.3);
          luz1.ambiental = _vertex4f(1, 0, 1, 1);
          luz1.difusa = _vertex4f(1, 1, 1, 1);
          luz1.especular = _vertex4f(1, 1, 0, 1);

          if (num_mat == 0){
              glMaterialf(GL_FRONT, GL_SHININESS, 20);
              glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &luz1.ambiental);
              glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &luz1.difusa);
              glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &luz1.especular);
          }
          if (num_mat == 1){
              glMaterialf(GL_FRONT, GL_SHININESS, 87);
              glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &luz1.ambiental);
              glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &luz1.difusa);
              glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &luz1.especular);
          }
          if (num_mat == 2){
              glMaterialf(GL_FRONT, GL_SHININESS, 109);
              glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &luz1.ambiental);
              glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &luz1.difusa);
              glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &luz1.especular);
          }

          glLightfv(GL_LIGHT1, GL_POSITION, (GLfloat*)&luz1.posicion);
          glLightfv(GL_LIGHT1, GL_AMBIENT, (GLfloat*)&luz1.ambiental);
          glLightfv(GL_LIGHT1, GL_DIFFUSE, (GLfloat*)&luz1.difusa);
          glLightfv(GL_LIGHT1, GL_SPECULAR, (GLfloat*)&luz1.especular);

          glEnable(GL_LIGHT1);
      }
  }
  else if (!Draw_light) glDisable(GL_LIGHTING);

  if (Draw_texture){
      if (flat) glShadeModel(GL_FLAT);
      else if (gouraud) glShadeModel(GL_SMOOTH);


  }
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
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
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;

  Draw_light=false;
  Draw_texture=false;

  max_zoom  = false;
  max_boton = false;
  max_flash = false;

  flat = false;
  gouraud = false;
  luz0.activada = false;
  luz1.activada = false;
  num_mat = 0;

  perspectiva = true;
  paralela = false;
}

/*****************************************************************************//**
 * Especificación de la animación
 *
 *
 *
 *****************************************************************************/

void _gl_widget::animacion()
{
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

/****************************************************************s*/
