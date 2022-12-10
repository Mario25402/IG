#ifndef FLASH_H
#define FLASH_H

#include "gradoslibertad.h"
#include "soporte.h"
#include "luz.h"

/************************************/

class Flash:public Soporte, Luz
{
public:
    void draw(int mode, GradosLibertad modificadores);
};

/************************************/

#endif
