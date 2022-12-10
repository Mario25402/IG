#ifndef ARMAZON_H
#define ARMAZON_H

#include "pantalla.h"
#include "flash.h"
#include "obturador.h"

/************************************/

class Armazon:public Pantalla, Flash, Obturador
{
private:
    _cube *cube;
public:
    Armazon();
    void draw(int mode, GradosLibertad modificadores);
};

/************************************/

#endif
