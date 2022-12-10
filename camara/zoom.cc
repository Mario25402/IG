#include "camara_headers/zoom.h"

void Zoom::draw(int mode)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(1,0.3,1);

    ((_cylinder)*this).draw(mode);

    glPopMatrix();
}
