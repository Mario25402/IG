#include "camara_headers/boton.h"

void Boton::draw(int mode)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.2,0.15,0.2);

    switch (mode) {
        case 0: ((_cylinder)*this).draw_point(); break;
        case 1: ((_cylinder)*this).draw_line();  break;
        case 2: ((_cylinder)*this).draw_fill();  break;
        case 3: ((_cylinder)*this).draw_chess(); break;
    }

    glPopMatrix();
}
