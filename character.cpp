#include "stdafx.h"
#include "character.h"
#include <list>
character::character(Level *lvl, drawengine *de, int s_index, float x, float y, int lives, char u, char d, char l, char r)
	:sprite(lvl, de, s_index, x, y, lives)
{
	upkey=u;
	downkey=d;
	leftkey=l;
	rightkey=r;
	classID=CHARACTER_CLASSID;
}
bool character::keypress(char c)
{
	if (c==upkey)
		return move(0,-1);
	
	if (c==downkey)
		return move(0,1);
	
	if (c==leftkey)
		return move(-1,0);
	
	if (c==rightkey)
		return move(1,0);
	return false;
}
void character::addlives(int num)
{
	sprite::addlives(num);
	if (sprite::isalive())
	{
		pos.x=1;
		pos.y=1;
		move(0, 0);
	}

}