#include "camara_headers/objetivo.h"

void Objetivo::draw(int mode, GradosLibertad modificadores)
{
    GLfloat medida = 0;
    if ((medida+modificadores.zoom) > modificadores.max_zoom) medida = modificadores.max_zoom;
    else if ((medida+modificadores.zoom) < modificadores.min_zoom) medida = modificadores.min_zoom;
    else medida += modificadores.zoom;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(modificadores.zoom_rotar,0,0,1);

    ((Zoom)*this).draw(mode);

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.3);
    glScalef(1,1,medida);
    glRotatef(modificadores.zoom_rotar,0,0,1);

    ((Lentes)*this).draw(mode);

    glPopMatrix();
}
