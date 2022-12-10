#ifndef GRADOSLIBERTAD_H
#define GRADOSLIBERTAD_H

struct GradosLibertad{
    bool animado = false;

    float zoom       = 1;	// Clase Objetivo
    float zoom_rotar = 0;	// Clase Objetivo
    float boton      = 1;	// Clase Obturador
    float flash      = 0;	// Clase Flash

    float tasa_zoom =     0.01;
    float tasa_zoom_rotar =  2;
    float tasa_boton =    0.05;
    float tasa_flash =   0.005;
    
    float max_zoom  = 1.8;
    float min_zoom  = 0.2;
    float max_boton =   1;
    float min_boton = 0.4;
    float max_flash = 0.3;
    float min_flash =   0;
    
};

#endif
