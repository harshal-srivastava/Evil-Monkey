#ifndef SPRITE_H
#define SPRITE_H
#include "drawengine.h"
#include "level.h"
enum
{
	SPRITE_CLASSID,
	CHARACTER_CLASSID,
	ENEMY_CLASSID,
	FIREBALL_CLASSID,
	MAGE_CLASSID
};
 struct vector
{
	float x;
	float y;
};
class sprite
{
public:
	sprite(Level *l,drawengine *de, int s_index, float x=1, float y=1, int i_lives=1);
	~sprite();
	vector getposition(void);
		float getx(void);
	float gety(void);
	virtual void addlives(int num=1);
	int getlives(void);
	bool isalive(void);
	virtual void idleupdate(void);
	virtual bool move(float x, float y);
	int classID;

	


protected:
	Level *level;
	drawengine* drawarea;
	vector pos;
	int spriteindex;
	int numlives;
	
	vector facingdirection;
	void draw(float x, float y);
	void erase(float x, float y);
	bool isvalidlevelmove(int xpos, int ypos);

};

#endif