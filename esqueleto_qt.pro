HEADERS += \
  camara/agarre.hpp \
  camara_headers/agarre.h \
  camara_headers/armazon.h \
  camara_headers/boton.h \
  camara_headers/camara.h \
  camara_headers/cristal.h \
  camara_headers/flash.h \
  camara_headers/gradoslibertad.h \
  camara_headers/lentes.h \
  camara_headers/luz.h \
  camara_headers/objetivo.h \
  camara_headers/obturador.h \
  camara_headers/pantalla.h \
  camara_headers/soporte.h \
  camara_headers/zoom.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  dashboard.h \
  file_ply_stl.h \
  iluminacion.h \
  object3d.h \
  axis.h \
  ply_object.h \
  rotation.h \
  rotation_ply.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  camara/agarre.cc \
  camara/armazon.cc \
  camara/boton.cc \
  camara/camara.cc \
  camara/cristal.cc \
  camara/flash.cc \
  camara/lentes.cc \
  camara/luz.cc \
  camara/objetivo.cc \
  camara/obturador.cc \
  camara/pantalla.cc \
  camara/soporte.cc \
  camara/zoom.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  dashboard.cc \
  file_ply_stl.cc \
  object3d.cc \
  axis.cc \
  ply_object.cc \
  rotation.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += openglwidgets
