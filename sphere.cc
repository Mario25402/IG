#include "sphere.h"

using namespace std;

/*******************************************************/

_sphere::_sphere(){
    _plyObject ply(PERFIL);
    vector <_vertex3f> Perfil = ply.getVertices();
    _rotation rotation(100, Perfil, Vertices, Triangles);
    calcNormales(1);
}

_sphere::_sphere(int n){
    vector <_vertex3f> Perfil;

    for (int i = 0; i < n; ++i){
        float x = 1*cos(M_PI*i/(n-1)-M_PI/2);
        float y = 1*sin(M_PI*i/(n-1)-M_PI/2);

        Perfil.push_back(_vertex3f(x,y,0));
    }

    _rotation rotation(100, Perfil, Vertices, Triangles);
    calcNormales(1);
}
