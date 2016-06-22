#include "stdafx.h"
#include "level.h"
#include "character.h"
#include "enemy.h"
#include <stdlib.h>
#include <list>
Level::Level(drawengine *de, int w, int h)
{
	drawarea=de;
	width=w;
	height=h;
	player=0;
	level =new char *[width];
	for (int x=0; x<width; x++)
		level[x]=new char[height];
	createlevel();
	drawarea->setmap(level);
}
Level::~Level()
{
	for (int x=0; x<width; x++)
		delete [] level[x];
	delete [] level;
	for (iter=npc.begin(); iter!=npc.end(); iter++)
		delete (*iter);
}
void Level::createlevel(void)
{
	for (int x=0; x<width; x++)
	{
		for (int y=0; y<height; y++)
		{
			int random=rand()%100;
			if (y==0 || y==height-1 || x==0 || x==width-1)
			{
				level[x][y]=TILE_WALL;
			}
			else
			{
			if (random<90 || (x<3 && y<3))
				level[x][y]=TILE_EMPTY;
			else
				level[x][y]=TILE_WALL;
			}
		}
	}

}
void Level::draw(void)
{
	drawarea->drawbackground();
}
void Level::addplayer(character *p)
{
	player=p;
}
bool Level::keypress(char c)
{
	if (player)
		if (player->keypress(c))
			return true;
	return false;
}
void Level::update(void)
{
	for (iter=npc.begin(); iter!=npc.end(); iter++)
	{
		(*iter)->idleupdate();
		if ((*iter)->isalive()==false)
		{
			sprite *temp=*iter;
			iter--;
			delete temp;
			npc.remove(temp);

		}
	}
}
void Level::addenemies(int num)
{
int i=num;
while (i>0)
{
	int xpos=int((float(rand()%100)/100)*(width-2)+1);
	int ypos=int((float(rand()%100)/100)*(height-2)+1);
	if (level[xpos][ypos]!=TILE_WALL)
	{
		enemy *temp= new enemy(this, drawarea, SPRITE_ENEMY, (float) xpos, float(ypos));
		temp->addgoal(player);
		addNPC((sprite *)temp);
		i--;
	}
}
}
void Level::addNPC(sprite *spr)
{
	npc.push_back(spr);
}
