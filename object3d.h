/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
public:
    vector<_vertex3ui> Triangles;
    vector<_vertex3f> NormalesFlat;
    vector<_vertex3f> NormalesSmooth;
    vector<_vertex3f> VerticesTextura;

    float selected = -1.0;

    void draw(int mode);
    void draw_line();
    void draw_fill(bool flat = true);
    void draw_chess();
    void draw_light();
    void draw_texture();
    void draw_selection();
    void select(float indice);
    void calcNormales(int modo = 0);
    void draw_fill(_vertex3f color);
};

#endif // OBJECT3D_H
