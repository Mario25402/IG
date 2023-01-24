/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;

/*****************************************************************************/
/*                      Función de dibujado base                             */
/*****************************************************************************/


void _object3D::draw(int mode)
{
    switch (mode){
        case 0: draw_point(); break;
        case 1: draw_line();  break;
        case 2: draw_fill();  break;
        case 3: draw_chess(); break;
    }
}

/*****************************************************************************/
/*                              Modo lineas                                  */
/*****************************************************************************/

void _object3D::draw_line()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0;i<Triangles.size();i++){
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

     glEnd();
}

/*****************************************************************************/
/*                             Modo relleno                                  */
/*****************************************************************************/

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0;i<Triangles.size();i++){
        if (selected == i) glColor3fv((GLfloat *) &YEllOW);
        else glColor3fv((GLfloat *) &BLACK);

        glNormal3fv((GLfloat *) &NormalesFlat[i]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    for (unsigned long i = 0; i < NormalesSmooth.size(); ++i)
        glNormal3fv((GLfloat *) &NormalesSmooth[i]);

     glEnd();
}

/*****************************************************************************/
/*                             Modo ajedrez                                  */
/*****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0;i<Triangles.size();i++){
        if (i%2 == 0) glColor3fv((GLfloat *) &CYAN);
        else glColor3fv((GLfloat *) &BLACK);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

     glEnd();
}

/*****************************************************************************/
/*                             Modo textura                                  */
/*****************************************************************************/

void _object3D::draw_texture()
{
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);

    for (unsigned int i = 0; i < Triangles.size(); ++i){
        glTexCoord3f(VerticesTextura[Triangles[i]._0].x, VerticesTextura[Triangles[i]._0].y, VerticesTextura[Triangles[i]._0].z);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord3f(VerticesTextura[Triangles[i]._1].x, VerticesTextura[Triangles[i]._1].y, VerticesTextura[Triangles[i]._1].z);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord3f(VerticesTextura[Triangles[i]._2].x, VerticesTextura[Triangles[i]._2].y, VerticesTextura[Triangles[i]._2].z);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

/*****************************************************************************/
/*                        Calculo de normales                                */
/*****************************************************************************/

void _object3D::calcNormales(int modo)
{
    NormalesFlat.resize(Triangles.size());

    for (unsigned int i=0;i<Triangles.size();i++){
        _vertex3f a = Vertices[Triangles[i]._1] - Vertices[Triangles[i]._0];
        _vertex3f b = Vertices[Triangles[i]._2] - Vertices[Triangles[i]._0];

        NormalesFlat[i] = a.cross_product(b);
        NormalesFlat[i].normalize();
    }

    if (modo != 0){
        NormalesSmooth.resize(Vertices.size());

        for (unsigned int i = 0; i < Triangles.size(); i++)
        {
            NormalesSmooth[Triangles[i]._0] += NormalesFlat[i];
            NormalesSmooth[Triangles[i]._1] += NormalesFlat[i];
            NormalesSmooth[Triangles[i]._2] += NormalesFlat[i];
        }

        for (unsigned int i = 0; i < NormalesSmooth.size(); i++)
        {
            NormalesSmooth[i].normalize();
        }
    }
}

void _object3D::draw_selection()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0;i<Triangles.size();i++){
      float red = (i & 0x00FF0000) >> 16;
      float green = (i & 0x0000FF00) >> 8;
      float blue = (i & 0x000000FF);

      red /= 255.0;
      green /= 255.0;
      blue /= 255.0;

      _vertex3f color(red, green, blue);

      //cout << red << ", " << green << ", " << blue << endl;

      glColor3fv((GLfloat *) &color);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i][0]]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i][1]]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i][2]]);
    }
    glEnd();

}

void _object3D::select(float indice)
{
    this->selected = indice;
}
