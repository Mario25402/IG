#include "dashboard.h"

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
/*
_dashboard::_dashboard(float Size, int n)
{
    Tablero(Size, n);
    Textura(n);
}

void _dashboard::Tablero(float Size, int n)
{
    Vertices.resize((n*n) * 4);
    Triangles.resize((n*n) * 2);

    int filas = n, columnas = n;
    int triangulo = 0, k = 0;
    float fila, tamTextura = 1;

    for (int i = 0; i < filas; ++i){
        fila = Size/2 - (i * Size/columnas);

        for (int j = 0; j < columnas; ++j)
        {
            Vertices[k]= _vertex3f(j * Size/columnas - Size/2, fila, 0);
            Vertices[k+1]= _vertex3f(Vertices[k].x + Size/columnas, Vertices[k].y, 0);
            Vertices[k+2]= _vertex3f(Vertices[k+1].x, Vertices[k].y - Size/columnas, 0);
            Vertices[k+3]= _vertex3f(Vertices[k].x, Vertices[k+2].y, 0);

            Triangles[triangulo] = _vertex3ui(k, k+3, k+2);
            Triangles[triangulo+1] = _vertex3ui(k, k+2, k+1);

            k += 4;
            triangulo += 2;
        }
    }

    calcNormales();
}

void _dashboard::Textura(int n)
{
    VerticesTextura.resize(Vertices.size());

    int filas = n, columnas = n;
    int k = 0;
    float tamTextura = 1, filaTextura;

    for (int i = 0; i < filas; ++i){
        filaTextura = tamTextura - (i * tamTextura/columnas);

        for (int j = 0; j < columnas; ++j)
        {
            VerticesTextura[k] = _vertex2f(j * tamTextura/columnas, filaTextura);
            VerticesTextura[k+1] = _vertex2f(VerticesTextura[k].x +  tamTextura/columnas, filaTextura);
            VerticesTextura[k+2] = _vertex2f(VerticesTextura[k+1].x, filaTextura -  tamTextura/columnas);
            VerticesTextura[k+3] = _vertex2f(VerticesTextura[k].x, VerticesTextura[k+2].y);

            k += 4;
        }
    }
}
*/
