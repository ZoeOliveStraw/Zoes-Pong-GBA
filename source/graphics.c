#include "graphics.h"

int paddle_width = 8;
int paddle_height = 24;

struct rect* CreateRect(int x, int y, int width, int height, int velocityX, int velocityY)
{
	struct rect* r = (struct rect*)malloc(sizeof(struct rect));
	r->x = x;
	r->y = y;
	r->width = width;
	r->height = height;
	r->velocityX = velocityX;
	r->velocityY = velocityY;
	r->prevX = x;
	r->prevY = y;
	return r;
}

void DrawPixel(int x, int y, int color)
{
	m3_mem[y][x] = color;
}

void DrawRect(struct rect* cRect)
{
	for(int i = cRect->x; i < cRect->x + cRect->width; i++)
	{
		for(int j = cRect ->y; j < cRect->y + cRect->height; j++)
		{
			DrawPixel(i, j, 0x7FFF);
		}
	}
}

void ClearPrevious(struct rect* cRect)
{
	for(int i = cRect->prevX; i < cRect->prevX + cRect->width; i++)
	{
		for(int j = cRect ->prevY; j < cRect->prevY + cRect->height; j++)
		{
			DrawPixel(i, j, 0x0000);
		}
	}
}