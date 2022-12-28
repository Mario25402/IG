#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "object3d.h"

class _dashboard:public _object3D
{
public:
    _dashboard(float Size=1.0);
    _dashboard(float Size, int n);
};

#endif // DASHBOARD_H
