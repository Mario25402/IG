#include "group.h"

/*****************************************************************************/
/*                              Modo puntos                                  */
/*****************************************************************************/

void _group::draw_point()
{
    ////////////////////////////////Tetraedros/////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 3, 0);
    tetraedro.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 3, 0);
    tetraedro.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 3, 0);
    tetraedro.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 3, 0);
    tetraedro.draw_point();
    glPopMatrix();

    ///////////////////////////////////Cubos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 1, 0);
    cubo.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 1, 0);
    cubo.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 1, 0);
    cubo.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 1, 0);
    cubo.draw_point();
    glPopMatrix();

    ///////////////////////////////////Conos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -1.5, 0);
    cono.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -1.5, 0);
    cono.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -1.5, 0);
    cono.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -1.5, 0);
    cono.draw_point();
    glPopMatrix();

    //////////////////////////////////Esferas//////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -3, 0);
    esfera.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -3, 0);
    esfera.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -3, 0);
    esfera.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -3, 0);
    esfera.draw_point();
    glPopMatrix();
}

/*****************************************************************************/
/*                              Modo lineas                                  */
/*****************************************************************************/

void _group::draw_line()
{
    ////////////////////////////////Tetraedros/////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 3, 0);
    tetraedro.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 3, 0);
    tetraedro.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 3, 0);
    tetraedro.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 3, 0);
    tetraedro.draw_line();
    glPopMatrix();

    ///////////////////////////////////Cubos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 1, 0);
    cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 1, 0);
    cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 1, 0);
    cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 1, 0);
    cubo.draw_line();
    glPopMatrix();

    ///////////////////////////////////Conos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -1.5, 0);
    cono.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -1.5, 0);
    cono.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -1.5, 0);
    cono.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -1.5, 0);
    cono.draw_line();
    glPopMatrix();

    //////////////////////////////////Esferas//////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -3, 0);
    esfera.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -3, 0);
    esfera.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -3, 0);
    esfera.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -3, 0);
    esfera.draw_line();
    glPopMatrix();
}

/*****************************************************************************/
/*                             Modo relleno                                  */
/*****************************************************************************/

void _group::draw_fill()
{
    ////////////////////////////////Tetraedros/////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 3, 0);
    tetraedro.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 3, 0);
    tetraedro.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 3, 0);
    tetraedro.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 3, 0);
    tetraedro.draw_fill();
    glPopMatrix();

    ///////////////////////////////////Cubos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 1, 0);
    cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 1, 0);
    cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 1, 0);
    cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 1, 0);
    cubo.draw_fill();
    glPopMatrix();

    ///////////////////////////////////Conos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -1.5, 0);
    cono.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -1.5, 0);
    cono.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -1.5, 0);
    cono.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -1.5, 0);
    cono.draw_fill();
    glPopMatrix();

    //////////////////////////////////Esferas//////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -3, 0);
    esfera.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -3, 0);
    esfera.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -3, 0);
    esfera.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -3, 0);
    esfera.draw_fill();
    glPopMatrix();
}

/*****************************************************************************/
/*                             Modo ajedrez                                  */
/*****************************************************************************/

void _group::draw_chess()
{
    ////////////////////////////////Tetraedros/////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 3, 0);
    tetraedro.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 3, 0);
    tetraedro.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 3, 0);
    tetraedro.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 3, 0);
    tetraedro.draw_chess();
    glPopMatrix();

    ///////////////////////////////////Cubos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 1, 0);
    cubo.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 1, 0);
    cubo.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 1, 0);
    cubo.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 1, 0);
    cubo.draw_chess();
    glPopMatrix();

    ///////////////////////////////////Conos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -1.5, 0);
    cono.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -1.5, 0);
    cono.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -1.5, 0);
    cono.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -1.5, 0);
    cono.draw_chess();
    glPopMatrix();

    //////////////////////////////////Esferas//////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -3, 0);
    esfera.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -3, 0);
    esfera.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -3, 0);
    esfera.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -3, 0);
    esfera.draw_chess();
    glPopMatrix();
}
