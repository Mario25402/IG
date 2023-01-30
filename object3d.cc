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

void _object3D::draw_fill(bool flat)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);

    if (flat){
        for (unsigned int i = 0; i < Triangles.size(); ++i){
            if (selected == i) glColor3fv((GLfloat *) &YEllOW);
            else glColor3fv((GLfloat *) &BLACK);

            glNormal3fv((GLfloat *) &NormalesFlat[i]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
    }

    else{
        for (unsigned long i = 0; i < Triangles.size(); ++i){
            glNormal3fv((GLfloat *) &NormalesSmooth[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glNormal3fv((GLfloat *) &NormalesSmooth[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glNormal3fv((GLfloat *) &NormalesSmooth[Triangles[i]._2]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
    }

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

        vector<_vertex3f> normalesVertice;

        for (unsigned int i = 0; i < Vertices.size(); ++i){
            normalesVertice.clear();

            for (unsigned int j = 0; j < Triangles.size(); ++j){
                if (Triangles[j].x == i or Triangles[j].y == i or Triangles[j].z == i)
                    normalesVertice.push_back(NormalesFlat[j]);
            }

            float sumX = 0, sumY = 0, sumZ = 0;
            int numNormales = normalesVertice.size();

            for (int j = 0; j < numNormales; ++j){
                sumX += normalesVertice[j].x;
                sumY += normalesVertice[j].y;
                sumZ += normalesVertice[j].z;
            }

            _vertex3f normal;
            normal.x = sumX / numNormales;
            normal.y = sumY / numNormales;
            normal.z = sumZ / numNormales;

            NormalesSmooth[i] = normal.normalize();
        }
    }

}

/*****************************************************************************/
/*                         Coloreado del Objeto                              */
/*****************************************************************************/

void _object3D::draw_selection()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0; i<Triangles.size(); ++i){
        float Red = (i & 0x00FF0000) >> 16;
        float Green = (i & 0x0000FF00) >> 8;
        float Blue = (i & 0x000000FF);

        Red /= 255.0;
        Green /= 255.0;
        Blue /= 255.0;
        _vertex3f color(Red, Green, Blue);

        glColor3fv((GLfloat *) &color);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
}

/*****************************************************************************/
/*                        Seleción de Triángulo                              */
/*****************************************************************************/

void _object3D::select(float indice)
{
    if (selected == indice) selected = -1;
    else selected = indice;
}
