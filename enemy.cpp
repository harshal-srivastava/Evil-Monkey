#include "stdafx.h"
#include "enemy.h"
#include "level.h"
#include "character.h"
#include <math.h>
#include <stdlib.h>
#include <list>
enemy::enemy(Level *l, drawengine *de, int s_index, float x, float y, int i_lives)
	: sprite(l, de, s_index, x, y, i_lives)
{
	goal =0;
	classID=ENEMY_CLASSID;
}
bool enemy::move(float x, float y)
{
	int xpos=(int)(pos.x+x);
	int ypos=(int)(pos.y+y);
	if (isvalidlevelmove(xpos, ypos))
	{
		list <sprite *>::iterator iter;
		for (iter = level->npc.begin(); iter!=level->npc.end(); iter++)
		{
			if ((*iter)!=this && (int)(*iter)->getx()==xpos && (int)(*iter)->gety()==ypos)
			{
				return false;

			}
		}
		erase(pos.x, pos.y);
	pos.x+=x;
	pos.y+=y;
	facingdirection.x=x;
	facingdirection.y=y;
	draw(pos.x, pos.y);
	if ((int)goal->getx()==xpos && (int)goal->gety()==ypos)
		goal->addlives(-1);

	return true;
	}
	return false;
}
void enemy::idleupdate(void)
{
	if (goal)
		simulateAI();
}
void enemy::addgoal(character *g)
{
	goal =g;
}
void enemy::simulateAI(void)
{
	vector goal_pos = goal->getposition();
	vector direction;
	direction.x=goal_pos.x-pos.x;
	direction.y=goal_pos.y-pos.y;
	float mag=sqrt(direction.x*direction.x+direction.y*direction.y);
	direction.x=direction.x/(mag*14);
	direction.y=direction.y/(mag*14);
	if (!move(direction.x, direction.y))
	{
		while (!move(float(rand()%3-1),float (rand()%3-1)))
		{
		}
	}
}