#include "stdafx.h"
#include "drawengine.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <list>
using namespace std;
drawengine::drawengine(int xsize, int ysize)
{
	screenwidth=xsize;
	screenheight=ysize;
	cursorvisibility(false);
	map=0;
}
drawengine::~drawengine()
{
	cursorvisibility(true);
	gotoxy(0, screenheight);
}
int drawengine::createsprite(int index, char c)
{
	if(index>=0 && index<16)
	{
		spriteimage[index]=c;
		return index;
	}
	return -1;
}
void drawengine::deletesprite(int index)
{

}
void drawengine::drawsprite(int index, int posx, int posy)
{
	gotoxy(posx, posy);
	cout<<spriteimage[index];
}
void drawengine::erasesprite(int posx, int posy)
{
	gotoxy(posx, posy);
	cout<<' ';
}
void drawengine::setmap(char **data)
{
	map=data;
}
void drawengine::createbackgroundtile(int index, char c)
{
	if (index>=0 && index<16)
	{
		tileimage[index]=c;
	}
}
void drawengine::drawbackground(void)
{
	if (map)
	{
		for (int y=0; y<screenheight; y++)
		{
			gotoxy(0,y);
			for (int x=0; x<screenwidth; x++)
				cout<<tileimage[map[x][y]];
		}
	}
}
void drawengine::gotoxy(int x, int y)
{
	HANDLE output_handle;
	COORD pos;
	pos.X=x;
	pos.Y=y;
	output_handle= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output_handle, pos); 
}
void drawengine::cursorvisibility(bool visibility)
{
	HANDLE output_handle;
	CONSOLE_CURSOR_INFO ccinfo;
	ccinfo.dwSize=1;
	ccinfo.bVisible=visibility;
	output_handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(output_handle, &ccinfo);
}
