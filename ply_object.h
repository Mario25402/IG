#ifndef PLY_OBJECT_H
#define PLY_OBJECT_H

#include <string>
#include "file_ply_stl.h"
#include "object3d.h"

using namespace std;

/************************************************************/

class _plyObject:public _file_ply, public _object3D
{
protected:
    _file_ply file;
    vector <float> coordenadas;
    vector <unsigned int> posiciones;
public:
  _plyObject();
  _plyObject(const string &archivo);
  vector<_vertex3f> getVertices();
};

/************************************************************/

#endif // PLY_OBJECT_H
