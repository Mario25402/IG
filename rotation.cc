#include "rotation.h"

_rotation::_rotation(unsigned long N, vector<_vertex3f> curva_g, vector<_vertex3f> &Vertices, vector<_vertex3ui> &Triangles)
{
    float salto = 2*M_PI/(float)N;
    int cont = 0;

    Vertices.clear();
    Vertices.resize(N*curva_g.size());

    for (unsigned long long i = 0; i < N; ++i){
        for (unsigned long j = 0; j < curva_g.size(); ++j){
            float x = cos(i*salto) * curva_g[j].x;
            float y = curva_g[j].y;
            float z = -sin(i*salto)*curva_g[j].x;
            Vertices[cont] = _vertex3f(x,y,z);
            cont++;
        }
    }

    long n = Vertices.size();
    long m = n/N;

    Triangles.resize((m-1)*n*2);
    cont = 0;

    for (long f = 0; f < (m-1); ++f){
        for (long c = 0; c < n; ++c){
            long x=c%n;
            long y=(c+m)%n;
            long z=(c+1)%n;

            Triangles[cont]   = _vertex3ui(x,y,z);
            cont++;

            x = (x+m)%n;
            y = (y+1)%n;

            Triangles[cont] = _vertex3ui(x,y,z);
            cont++;
        }
    }
}
