#include "dashboard.h"

_dashboard::_dashboard(float Size){

    /*Vertices.resize(4);
    Triangles.resize(2);

    Vertices[0]=_vertex3f(-Size/2,Size/2,0);
    Vertices[1]=_vertex3f(-Size/2,-Size/2,0);
    Vertices[2]=_vertex3f(Size/2,-Size/2,0);
    Vertices[3]=_vertex3f(Size/2,Size/2,0);

    Triangles[0]=_vertex3ui(0,1,2);
    Triangles[1]=_vertex3ui(0,2,3);*/

    Vertices.resize(16);
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
    Triangles[17] = _vertex3ui(12,13,14);

    calcNormales();
}
