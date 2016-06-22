#include "stdafx.h"
#include "game.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <list>
using namespace std;
#define GAME_SPEED 33.33
bool game::run(void)
{
	level=new Level(&drawarea, 30, 20);
	drawarea.createbackgroundtile(TILE_EMPTY, ' ');
	drawarea.createbackgroundtile(TILE_WALL, 219);
	drawarea.createsprite(SPRITE_PLAYER, 1);
	drawarea.createsprite(SPRITE_ENEMY, '$');
	drawarea.createsprite(SPRITE_FIREBALL, '*');
	player=new mage(level, &drawarea, 0);
	level->draw();
	level->addplayer(player);
	level->addenemies(3);
	
	char key=' ';
	starttime=timeGetTime();
	framecount=0;
	lasttime=0;
	posx=0;
	player->move(0, 0);
	while (key!='q')
	{
		while (!getinput(&key))
		{
			timerupdate();
			
		}
		
		level->keypress(key);
		//cout<<endl<<"here is what you pressed "<<key<<endl;

	}
	delete player;
	//cout<<framecount/((timeGetTime()-starttime)/1000)<<" fps "<<endl;
	//cout<<endl<<"end of the game ";
	getch();
	return true;
}
bool game::getinput(char *c)
{
	if (kbhit())
	{
		*c=getch();
		return true;
	}
	return false;
}
void game::timerupdate(void)
{
	double currenttime=timeGetTime()-lasttime;
	if (currenttime<GAME_SPEED)
		return;
	level->update();
	framecount++;
	lasttime=timeGetTime();
}