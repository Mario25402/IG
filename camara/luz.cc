#include "camara_headers/luz.h"

void Luz::draw(int mode)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.9,0.4,0.6);

    ((_cube)*this).draw(mode);

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.3);
    glScalef(0.8,0.3,0);

    ((_cube)*this).draw(mode);

    glPopMatrix();
}
