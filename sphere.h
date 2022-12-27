#ifndef SPHERE_H
#define SPHERE_H

#include "ply_object.h"
#include "rotation.h"

/*******************************************************/

class _sphere : public _object3D
{
    const string PERFIL = "/home/mario/Escritorio/IG/ply_models/sphere.ply";
public:
    _sphere();
    _sphere(int n);
};

/*******************************************************/

#endif // SPHERE_H
