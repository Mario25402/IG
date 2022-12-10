#include "sphere.h"

using namespace std;

/*******************************************************/

_sphere::_sphere()
{
    /*for (int i = 0; i < 12; ++i){
        cout << "Conjunto " << i << endl
             << "Vertice 1: " << 1*cos(M_PI*i/11-M_PI/2) << "\t"
             << "Vertice 2: " << 1*sin(M_PI*i/11-M_PI/2) << "\t"
             << "Vertice 3: " << "0\n" << endl;
    }*/

    _plyObject ply(PERFIL);
    vector <_vertex3f> Perfil = ply.getVertices();
    _rotation rotation(50, Perfil, Vertices, Triangles);
    calcNormales();
}
