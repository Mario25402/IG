#ifndef OBJETIVO_H
#define OBJETIVO_H

#include "zoom.h"
#include "lentes.h"
#include "gradoslibertad.h"

/************************************/

class Objetivo:public Zoom, Lentes
{
public:
    void draw(int mode, GradosLibertad modificadores);
};

/************************************/

#endif
