#include "camara_headers/obturador.h"

void Obturador::draw(int mode, GradosLibertad modificadores)
{
    float medida = 0;
    if (medida += modificadores.boton > modificadores.max_boton) medida = modificadores.max_boton;
    else if (medida += modificadores.boton < modificadores.min_boton) medida = modificadores.min_boton;
    else medida += modificadores.boton;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(1,medida,1);

    ((Boton)*this).draw(mode);

    glPopMatrix();
    glPushMatrix();

    ((Agarre)*this).draw(mode);

    glPopMatrix();
}
