#ifndef FIREBALL_H
#define FIREBALL_H
#include "sprite.h"
class fireball : public sprite
{
public:
	fireball(Level *lev, drawengine *de, int s_index, float x=1, float y=1, float xdir=0, float ydir=1, int i_lives=6);
	void idleupdate();
protected:
};
#endif