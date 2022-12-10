#include "camara_headers/pantalla.h"

void Pantalla::draw(int mode)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.8,0.8,0);

    ((_cube)*this).draw(mode);

    glPopMatrix();
}
