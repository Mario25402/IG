#include "dashboard.h"

_dashboard::_dashboard(float Size){
    Vertices.resize(4);
    Triangles.resize(2);

    Vertices[0]=_vertex3f(-Size/2,Size/2,0);
    Vertices[1]=_vertex3f(-Size/2,-Size/2,0);
    Vertices[2]=_vertex3f(Size/2,-Size/2,0);
    Vertices[3]=_vertex3f(Size/2,Size/2,0);

    Triangles[0]=_vertex3ui(0,1,2);
    Triangles[1]=_vertex3ui(0,2,3);

    /*Vertices.resize(16);
    Triangles.resize(18);

    Vertices[0] = _vertex3f(-1.5,1.5,0);
    Vertices[1] = _vertex3f(-1.5,0.5,0);
    Vertices[2] = _vertex3f(-1.5,-0.5,0);
    Vertices[3] = _vertex3f(-1.5,-1.5,0);
    Vertices[4] = _vertex3f(-0.5,-1.5,0);
    Vertices[5] = _vertex3f(0.5,-1.5,0);
    Vertices[6] = _vertex3f(1.5,-1.5,0);
    Vertices[7] = _vertex3f(1.5,-0.5,0);
    Vertices[8] = _vertex3f(1.5,0.5,0);
    Vertices[9] = _vertex3f(1.5,1.5,0);
    Vertices[10] = _vertex3f(0.5,1.5,0);
    Vertices[11] = _vertex3f(-0.5,1.5,0);
    Vertices[12] = _vertex3f(-0.5,0.5,0);
    Vertices[13] = _vertex3f(-0.5,-0.5,0);
    Vertices[14] = _vertex3f(0.5,-0.5,0);
    Vertices[15] = _vertex3f(0.5,0.5,0);

    Triangles[0] = _vertex3ui(0,12,11);
    Triangles[1] = _vertex3ui(0,12,1);
    Triangles[2] = _vertex3ui(1,13,12);
    Triangles[3] = _vertex3ui(1,2,13);
    Triangles[4] = _vertex3ui(2,4,13);
    Triangles[5] = _vertex3ui(2,3,4);
    Triangles[6] = _vertex3ui(13,4,5);
    Triangles[7] = _vertex3ui(13,5,14);
    Triangles[8] = _vertex3ui(14,5,6);
    Triangles[9] = _vertex3ui(14,6,7);
    Triangles[10] = _vertex3ui(15,14,7);
    Triangles[11] = _vertex3ui(15,7,8);
    Triangles[12] = _vertex3ui(10,15,8);
    Triangles[13] = _vertex3ui(10,8,9);
    Triangles[14] = _vertex3ui(11,15,10);
    Triangles[15] = _vertex3ui(11,12,15);
    Triangles[16] = _vertex3ui(12,14,15);
    Triangles[17] = _vertex3ui(12,13,14);*/

    calcNormales();
}

_dashboard::_dashboard(float Size, int n)
{
    Vertices.resize((n*n) * 4);
    Triangles.resize((n*n) * 2);
    VerticesTextura.resize(Vertices.size());

    int filas = n, columnas = n;
    int triangulo = 0, k = 0;
    float fila, tamTextura = 1, filaTextura;

    for (int i = 0; i < filas; ++i){
        fila = Size/2 - (i * Size/columnas);
        filaTextura = tamTextura - (i * tamTextura/columnas);

        for (int j = 0; j < columnas; ++j)
        {
            VerticesTextura[k] = _vertex2f(j * tamTextura/columnas, filaTextura);
            Vertices[k]= _vertex3f(j * Size/columnas - Size/2, fila, 0);

            VerticesTextura[k+1] = _vertex2f(VerticesTextura[k].x +  tamTextura/columnas, filaTextura);
            Vertices[k+1]= _vertex3f(Vertices[k].x + Size/columnas, Vertices[k].y, 0);

            VerticesTextura[k+2] = _vertex2f(VerticesTextura[k+1].x, filaTextura -  tamTextura/columnas);
            Vertices[k+2]= _vertex3f(Vertices[k+1].x, Vertices[k].y - Size/columnas, 0);

            VerticesTextura[k+3] = _vertex2f(VerticesTextura[k].x, VerticesTextura[k+2].y);
            Vertices[k+3]= _vertex3f(Vertices[k].x, Vertices[k+2].y, 0);

            Triangles[triangulo] = _vertex3ui(k, k+3, k+2);
            Triangles[triangulo+1] = _vertex3ui(k, k+2, k+1);

            k += 4;
            triangulo += 2;
        }
    }

    calcNormales();
}
