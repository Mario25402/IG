#include "camara_headers/camara.h"

void Camara::draw(int mode, GradosLibertad modificadores)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    ((Armazon)*this).draw(mode, modificadores);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2,0,0.3);
    glScalef(0.7,0.7,0.6);
    ((Objetivo)*this).draw(mode, modificadores);
    glPopMatrix();
}
