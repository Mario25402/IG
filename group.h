#ifndef GROUP_H
#define GROUP_H

#include "object3d.h"
#include "cube.h"
#include "tetrahedron.h"
#include "cylinder.h"
#include "sphere.h"

/*******************************************************/

class _group : public _object3D
{
public:
   _tetrahedron *tetraedro;
    _cube *cubo;
    _cylinder *cilindro;
    _sphere *esfera;

    _group();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

/*******************************************************/

#endif // GROUP_H
