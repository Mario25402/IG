#ifndef CAMARA_H
#define CAMARA_H

#include "objetivo.h"
#include "armazon.h"

/************************************/

class Camara:public Objetivo, Armazon
{
public:
    void draw(int mode, GradosLibertad modificadores);
};

/************************************/

#endif
