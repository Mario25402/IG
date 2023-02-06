#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "object3d.h"

class _dashboard:public _object3D
{
public:
    _dashboard(float Size = 1, int n = 3);

    void Tablero(float Size, int n);
    void Textura(int n);
};

#endif // DASHBOARD_H
