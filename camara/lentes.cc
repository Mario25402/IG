#include "camara_headers/lentes.h"

void Lentes::draw(int mode)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,0.7);

    ((Cristal)*this).draw(mode);

    glPopMatrix();
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.7,0.7,0.7);

    ((_cylinder)*this).draw(mode);

    glPopMatrix();
}
