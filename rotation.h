#ifndef ROTATION_H
#define ROTATION_H

#include "object3d.h"

class _rotation:public _object3D
{
public:
    _rotation(unsigned long N, vector<_vertex3f> curva_g, vector<_vertex3f> &Vertices, vector<_vertex3ui> &Triangles);
};

#endif // ROTATION_H
