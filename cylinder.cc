#include "cylinder.h"

/*******************************************************/

_cylinder::_cylinder()
{
    _plyObject ply(PERFIL);
    vector <_vertex3f> Perfil = ply.getVertices();
    _rotation rotation(20, Perfil, Vertices, Triangles);
    calcNormales();
}
