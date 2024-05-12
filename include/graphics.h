#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <gba_console.h>

#define MEM_VRAM         0x06000000
#define SCREEN_WIDTH     240
#define SCREEN_HEIGHT    160

typedef u16              M3LINE[SCREEN_WIDTH];
#define m3_mem           ((M3LINE*)MEM_VRAM)

extern int paddle_width;
extern int paddle_height;

/* players and ball rectangles */
struct rect
{
	int x;
	int y;
	int width;
	int height;
	int velocityX;
	int velocityY;
	int prevX;
	int prevY;
};

struct rect* CreateRect(int x, int y, int width, int height, int velocityX, int velocityY);

void DrawPixel(int x, int y, int color);

void DrawRect(struct rect* cRect);

void ClearPrevious(struct rect* cRect);

#endif