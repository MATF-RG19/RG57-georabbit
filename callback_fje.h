#ifndef __CALLBACK_FJE_H__
#define __CALLBACK_FJE_H__

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "texture.h"
#include "stone.h"


/* Deklaracije callback funkcija. */
void on_display(void);
void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int width, int height);


#endif
