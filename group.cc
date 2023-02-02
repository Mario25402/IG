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
    if (selected == 0) tetraedro.draw_fill(_colors_ne::YEllOW);
    else tetraedro.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 3, 0);
    if (selected == 1) tetraedro.draw_fill(_colors_ne::YEllOW);
    else tetraedro.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 3, 0);
    if (selected == 2) tetraedro.draw_fill(_colors_ne::YEllOW);
    else tetraedro.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 3, 0);
    if (selected == 3) tetraedro.draw_fill(_colors_ne::YEllOW);
    else tetraedro.draw_fill();
    glPopMatrix();

    ///////////////////////////////////Cubos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 1, 0);
    if (selected == 4) cubo.draw_fill(_colors_ne::YEllOW);
    else cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 1, 0);
    if (selected == 5) cubo.draw_fill(_colors_ne::YEllOW);
    else cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 1, 0);
    if (selected == 6) cubo.draw_fill(_colors_ne::YEllOW);
    else cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 1, 0);
    if (selected == 7) cubo.draw_fill(_colors_ne::YEllOW);
    else cubo.draw_fill();
    glPopMatrix();

    ///////////////////////////////////Conos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -1.5, 0);
    if (selected == 8) cono.draw_fill(_colors_ne::YEllOW);
    else cono.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -1.5, 0);
    if (selected == 9) cono.draw_fill(_colors_ne::YEllOW);
    else cono.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -1.5, 0);
    if (selected == 10) cono.draw_fill(_colors_ne::YEllOW);
    else cono.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -1.5, 0);
    if (selected == 11) cono.draw_fill(_colors_ne::YEllOW);
    else cono.draw_fill();
    glPopMatrix();

    //////////////////////////////////Esferas//////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -3, 0);
    if (selected == 12) esfera.draw_fill(_colors_ne::YEllOW);
    else esfera.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -3, 0);
    if (selected == 13) esfera.draw_fill(_colors_ne::YEllOW);
    else esfera.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -3, 0);
    if (selected == 14) esfera.draw_fill(_colors_ne::YEllOW);
    else esfera.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -3, 0);
    if (selected == 15) esfera.draw_fill(_colors_ne::YEllOW);
    else esfera.draw_fill();
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

void _group::draw_selection()
{
    ////////////////////////////Selección de color/////////////////////////////

    vector<_vertex3f> objetos;

    for (int i = 0; i < 16; ++i){
        float Red = (i & 0x00FF0000) >> 16;
        float Green = (i & 0x0000FF00) >> 8;
        float Blue = (i & 0x000000FF);

        _vertex3f color(Red/255, Green/255, Blue/255);
        objetos.push_back(color);

        //cout << endl << "Color: " << objetos[i][0] << " " << objetos[i][1] << " " << objetos[i][2] << endl;
    }

    ////////////////////////////////Tetraedros/////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 3, 0);
    tetraedro.draw_fill(objetos[0]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 3, 0);
    tetraedro.draw_fill(objetos[1]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 3, 0);
    tetraedro.draw_fill(objetos[2]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 3, 0);
    tetraedro.draw_fill(objetos[3]);
    glPopMatrix();

    ///////////////////////////////////Cubos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, 1, 0);
    cubo.draw_fill(objetos[4]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, 1, 0);
    cubo.draw_fill(objetos[5]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, 1, 0);
    cubo.draw_fill(objetos[6]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, 1, 0);
    cubo.draw_fill(objetos[7]);
    glPopMatrix();

    ///////////////////////////////////Conos///////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -1.5, 0);
    cono.draw_fill(objetos[8]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -1.5, 0);
    cono.draw_fill(objetos[9]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -1.5, 0);
    cono.draw_fill(objetos[10]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -1.5, 0);
    cono.draw_fill(objetos[11]);
    glPopMatrix();

    //////////////////////////////////Esferas//////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-3, -3, 0);
    esfera.draw_fill(objetos[12]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1, -3, 0);
    esfera.draw_fill(objetos[13]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -3, 0);
    esfera.draw_fill(objetos[14]);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(3, -3, 0);
    esfera.draw_fill(objetos[15]);
    glPopMatrix();

    glEnd();
}

/*****************************************************************************/
/*                        Seleción de Triángulo                              */
/*****************************************************************************/

void _group::select(float indice)
{
    if (selected == indice) selected = -1;
    else selected = indice;
}
