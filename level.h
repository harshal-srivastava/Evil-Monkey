#ifndef LEVEL_H
#define LEVEL_H
#include <list>
using std::list;
enum
{
	SPRITE_PLAYER,
	SPRITE_ENEMY,
	SPRITE_FIREBALL
};
enum 
{
	TILE_EMPTY,
	TILE_WALL
};
#include "drawengine.h"
//#include "character.h"
class sprite;
class character;
class Level
{
public:
	Level(drawengine *de, int width=30, int height=20);
	~Level();
	void addplayer(character *p);
	void update(void);
	void draw(void);
	bool keypress(char c);
	void addenemies(int num);
	void addNPC(sprite *spr);
	friend class sprite;
protected:
	void createlevel(void);
private:
	int width;
	int height;
	char **level;
	character *player;
	drawengine *drawarea;
public:
	list <sprite *> npc;
	list <sprite *>::iterator iter;
};
#endif