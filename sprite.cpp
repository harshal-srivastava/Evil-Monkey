#include "stdafx.h"
#include "sprite.h"
#include <list>
sprite::sprite(Level *l,drawengine *de, int s_index, float x, float y, int i_lives)
{
	drawarea=de;
	pos.x=x;
	pos.y=y;
	spriteindex=s_index;
	numlives=i_lives;
	facingdirection.x=1;
	facingdirection.y=0;
	classID=SPRITE_CLASSID;
	level=l;

}
sprite::~sprite()
{
	erase(pos.x, pos.y);
}
vector sprite::getposition(void)
{
	return pos;
}
float sprite::getx(void)
{
	return pos.x;
}
float sprite::gety(void)
{
	return pos.y;
}
void sprite::addlives(int num)
{
	numlives+=num;
}
int sprite::getlives(void)
{
	return numlives;
}
bool sprite::isalive(void)
{
	return numlives>0;
}
bool sprite::move(float x, float y)
{
	int xpos=(int)(pos.x+x);
	int ypos=(int)(pos.y+y);
	if (isvalidlevelmove(xpos, ypos))
	{
	erase(pos.x, pos.y);
	pos.x+=x;
	pos.y+=y;
	facingdirection.x=x;
	facingdirection.y=y;
	draw(pos.x, pos.y);
	return true;
	}
	return false;
}
void sprite::draw(float x, float y)
{
	drawarea->drawsprite(spriteindex, (int)x, (int)y);
}
void sprite::erase(float x, float y)
{
	drawarea->erasesprite((int)x, (int)y);
}
bool sprite::isvalidlevelmove(int xpos, int ypos)
{
	if (level->level[xpos][ypos]!=TILE_WALL)
		return true;
	return false;
}
void sprite::idleupdate(void)
{

}
