#include "graphics.h"

int paddle_width = 8;
int paddle_height = 24;

#define CLR_BLACK       0x0000
#define CLR_RED         0x001F
#define CLR_LIME        0x03E0
#define CLR_YELLOW      0x03FF
#define CLR_BLUE        0x7C00
#define CLR_MAG         0x7C1F
#define CLR_CYAN        0x7FE0
#define CLR_WHITE       0x7FFF

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

void DrawCenterLine()
{
	for(int j=0; j < SCREEN_HEIGHT; j++)
	{
		DrawPixel(SCREEN_WIDTH / 2, j, 0x7FFF); // white pixels
	}
}

void ClearCenterLine()
{
	for(int j=0; j < SCREEN_HEIGHT; j++)
	{
		DrawPixel(SCREEN_WIDTH / 2, j, 0x0000); // white pixels
	}
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

void ClearScreen()
{
	for(int i = 0; i < SCREEN_WIDTH; i++)
	{
		for(int j = 0; j < SCREEN_HEIGHT; j++)
		{
			DrawPixel(i, j, 0x0000);
		}
	}
}

void PrintCharacter(bool *character[64], int x, int y)
{
	// for(int i = 0; i < 64; i++)
	// {
	// 	if(character[i]) DrawPixel(x + i, y, CLR_WHITE);
	// }

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			int newY = y + i;
			int newX = x + j;
			int index = i * 8 + j;
			if(character[index]) 
			{
				DrawPixel(newX, newY, CLR_WHITE);
			}
			else
			{
				DrawPixel(newX, newY, CLR_BLACK);
			}
		}
	}
}