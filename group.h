#ifndef GROUP_H
#define GROUP_H

#include "object3d.h"
#include "cube.h"
#include "tetrahedron.h"
#include "cone.h"
#include "sphere.h"

/*******************************************************/

class _group : public _object3D
{
public:
   _tetrahedron tetraedro;
    _cube cubo;
    _cone cono;
    _sphere esfera;

    int selected = -1;

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_selection();
    void select(float indice);

};

/*******************************************************/

#endif // GROUP_H
