#ifndef ILUMINACION_H
#define ILUMINACION_H

#include "vertex.h"

struct Iluminacion{
    bool activada;

    _vertex4f posicion;
    _vertex4f ambiental;
    _vertex4f difusa;
    _vertex4f especular;

};

struct Material{
    float brillo;

    _vertex3f ambiental;
    _vertex3f difusa;
    _vertex3f especular;
};

#endif // ILUMINACION_H
