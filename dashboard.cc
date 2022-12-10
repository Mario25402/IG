#include "dashboard.h"

_dashboard::_dashboard(float Size){

    // Crear tablero
    Vertices.resize(4);
    Triangles.resize(2);

    Vertices[0]=_vertex3f(-Size/2,Size/2,0);
    Vertices[1]=_vertex3f(-Size/2,-Size/2,0);
    Vertices[2]=_vertex3f(Size/2,-Size/2,0);
    Vertices[3]=_vertex3f(Size/2,Size/2,0);

    Triangles[0]=_vertex3ui(0,1,2);
    Triangles[1]=_vertex3ui(0,2,3);

}
