#ifndef LENTES_H
#define LENTES_H

#include "cristal.h"
#include "cylinder.h"

/************************************/

class Lentes:public Cristal, _cylinder
{
public:
    void draw(int mode);
};

/************************************/

#endif
