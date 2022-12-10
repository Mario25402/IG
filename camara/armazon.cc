#include "camara_headers/armazon.h"

Armazon::Armazon()
{
    cube = new _cube;
}

void Armazon::draw(int mode, GradosLibertad modificadores)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-0.3);
    glScalef(1.2,1,1);
    ((Pantalla)*this).draw(mode);
    glPopMatrix();

    //////////////////////////////////////////////

    glPushMatrix();
    glTranslatef(0,0.55,-0.12);
    glScalef(0.7,0.7,0.7);
    ((Flash)*this).draw(mode, modificadores);
    glPopMatrix();

    //////////////////////////////////////////////

    glPushMatrix();
    glScalef(1.05,1,1);
    glTranslatef(-0.38,-0.5,0.3);
    ((Obturador)*this).draw(mode, modificadores);
    glPopMatrix();

    //////////////////////////////////////////////

    glPushMatrix();
    glScalef(1.2,1,0.6);
    cube->draw(mode);
    glPopMatrix();
}
