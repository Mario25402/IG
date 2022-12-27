#include "ply_object.h"
#include <iostream>

using namespace std;

/************************************************************/

// Constructor por defecto, cualquier archivo se creará dada la ruta
// en este caso para probarla, usaremos a beethoven

_plyObject::_plyObject()
{
    file.open("/home/mario/Escritorio/IG/ply_models/beethoven.ply");
    file.read(coordenadas, posiciones);
    file.close();

    Vertices.resize(coordenadas.size()/3);

    long cont = 0;
    for (unsigned long i = 0; i < coordenadas.size()/3; i++){
        Vertices[i] = _vertex3f(coordenadas[cont], coordenadas[cont+1], coordenadas[cont+2]);
        cont+=3;
    }

    Triangles.resize(posiciones.size()/3);

    cont = 0;
    for (unsigned long i = 0; i < posiciones.size()/3; ++i){
        Triangles[i] = _vertex3ui(posiciones[cont], posiciones[cont+1], posiciones[cont+2]);
        cont+=3;
    }

    calcNormales();
}

// Constructor con parametro de archivo

_plyObject::_plyObject(const string &archivo)
{
    file.open(archivo);
    file.read(coordenadas, posiciones);
    file.close();

    Vertices.resize(coordenadas.size()/3);

    long cont = 0;
    for (unsigned long i = 0; i < coordenadas.size()/3; i++){
        Vertices[i] = _vertex3f(coordenadas[cont], coordenadas[cont+1], coordenadas[cont+2]);
        cont+=3;
    }

    Triangles.resize(posiciones.size()/3);

    cont = 0;
    for (unsigned long i = 0; i < posiciones.size()/3; ++i){
        Triangles[i] = _vertex3ui(posiciones[cont], posiciones[cont+1], posiciones[cont+2]);
        cont+=3;
    }

    calcNormales();
}

// Función auxiliar para la creación por rotación

vector<_vertex3f> _plyObject::getVertices(){
    return Vertices;
}
