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


void _object3D::draw(int mode)
{
    switch (mode){
        case 0: draw_point(); break;
        case 1: draw_line();  break;
        case 2: draw_fill();  break;
        case 3: draw_chess(); break;
    }
}

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

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0;i<Triangles.size();i++){
        glNormal3fv((GLfloat *) &Normales[i]);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

     glEnd();
}

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

void _object3D::calcNormales()
{
    Normales.resize(Triangles.size());

    for (unsigned long i = 0; i < Triangles.size(); ++i){
        float Ax = Vertices[Triangles[i]._1].x - Vertices[Triangles[i]._0].x;
        float Ay = Vertices[Triangles[i]._1].y - Vertices[Triangles[i]._0].y;
        float Az = Vertices[Triangles[i]._1].z - Vertices[Triangles[i]._0].z;

        float Bx = Vertices[Triangles[i]._2].x - Vertices[Triangles[i]._0].x;
        float By = Vertices[Triangles[i]._2].y - Vertices[Triangles[i]._0].y;
        float Bz = Vertices[Triangles[i]._2].z - Vertices[Triangles[i]._0].z;

        float Nx = (Ay * Bz) - (Az * By);
        float Ny = (Ax * Bz) - (Az * Bx);
        float Nz = (Ax * By) - (Ay * Bx);

        Normales[i] = _vertex3f(Nx,Ny,Nz);
        Normales[i].normalize();
    }
}

void _object3D::calcNormalesGuoraud()
{
    int i = 0;
}
