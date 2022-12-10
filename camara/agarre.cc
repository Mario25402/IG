#include "camara_headers/agarre.h"

void Agarre::draw(int mode)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.4,1,0.4);

    ((_cylinder)*this).draw(mode);

    glPopMatrix();
}
