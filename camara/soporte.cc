#include "camara_headers/soporte.h"

void Soporte::draw(int mode)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.55,0.1,0.4);

    ((_cube)*this).draw(mode);

    glPopMatrix();
}
