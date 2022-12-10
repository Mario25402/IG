#include "camara_headers/cristal.h"

void Cristal::draw(int mode)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.25,0);

    ((_sphere)*this).draw(mode);

    glPopMatrix();
}
