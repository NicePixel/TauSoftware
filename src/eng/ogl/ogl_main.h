/* ogl_main.h
 * Initialization functions and small utilities.
 */
#pragma once
#include "../global.h"

// Initialize the graphics subsystem
// Calls SDL init functions, GLEW, create a GL context, ...
// Calls other init functions, such as `tau_gra_*_init()`
// Exceptions:
// 	CGraException, CTauGraFontException
void tau_gra_init(const char* windowTitle);

// Show the current render to the screen
void tau_gra_updatewindow(void);

// Clear the current framebuffer's buffer
// Change the current framebuffer with `tau_gra_framebuffer_use`,
// check "ogl_framebuffer.h" for info.
//
// By default this clears the screen.
#define TAU_CLEAR_COLORBUFFER GL_COLOR_BUFFER_BIT
#define TAU_CLEAR_DEPTHBUFFER GL_DEPTH_BUFFER_BIT
#define TAU_CLEAR_COLORANDDEPTHBUFFER (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
void tau_gra_clear(int what);

void tau_gra_disableDepthTest(void);
void tau_gra_enableDepthTest(void);

// Hold data about the current state of the window, such as its W/H, the mode...
typedef struct
{
	int width, height;
	int mode;
	float clear_r, clear_g, clear_b;
} TVIDEO_INFO;

TVIDEO_INFO tau_gra_videogetinfo(void);

// Switch video modes
#define TAU_VIDEOMODE_WINDOW     0
#define TAU_VIDEOMODE_FULLSCREEN SDL_WINDOW_FULLSCREEN	/* expected to be 1 */
void tau_gra_videomode(int mode);

