#ifndef OBTURADOR_H
#define OBTURADOR_H

#include "boton.h"
#include "agarre.h"

/************************************/

class Obturador:public Boton, Agarre
{
public:
    void draw(int mode, GradosLibertad modificadores);
};

/************************************/

#endif
