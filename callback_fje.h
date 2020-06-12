#ifndef __CALLBACK_FJE_H__
#define __CALLBACK_FJE_H__

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "texture.h"
#include "stone.h"
#include "igrac.h"

#define TIMER_ID 0
#define TIMER_INTERVAL 50

extern int game_ongoing;
//indikator za game over prikaz
extern int animation_ind;
extern int score;


/* Deklaracije callback funkcija. */
void on_display(void);
void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int width, int height);
void on_release(unsigned char key, int x, int y);
void on_timer(int);
//funkcija za proveravanje kolizije
void check_collision(void);

#endif
