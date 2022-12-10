#include "camara_headers/flash.h"

void Flash::draw(int mode, GradosLibertad modificadores)
{
    float medida = 0;
    if (medida += modificadores.flash > modificadores.max_flash) medida = modificadores.max_flash;
    else if (medida += modificadores.flash < modificadores.min_flash) medida = modificadores.min_flash;
    else medida += modificadores.flash;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1+(medida*9.5),1);
    glTranslatef(0,(medida/9.5)+0.005,-0.05);
    ((Soporte)*this).draw(mode);
    glPopMatrix();

    medida += 0.25;    // necesario para colocar la luz encima del soporte

    glPushMatrix();
    glTranslatef(0,medida,0.05);
    ((Luz)*this).draw(mode);
    glPopMatrix();
}
