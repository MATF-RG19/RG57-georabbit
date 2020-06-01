#ifndef __TEXTURE_H__
#define __TEXTURE_H__
#include<GL/glut.h>
#include "image.h"

/*Makroi za teksture*/
#define LAVA "lava.bmp"
#define CLOUDS "clouds.bmp"
#define STONE "stone.bmp"

//#define STONE_TEXTURE 2


GLuint id_tex[3];

void initialize_t();

#endif
