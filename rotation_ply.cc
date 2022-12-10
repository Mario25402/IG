#include "rotation_ply.h"
#include "rotation.h"
#include "ply_object.h"

_rotationPly::_rotationPly(){
    _plyObject Ply;

    vector<_vertex3f> perfil = Ply.getVertices();
    cout << "\nVertices: " << perfil.size() << endl;
    _rotation rotation(15, perfil, Vertices, Triangles);
    cout << "\nNuevos Vertices: " << Vertices.size() << endl;
    cout << "\nNuevos Triangulos: " << Triangles.size() << endl;
}
