#ifndef ENEMY_H
#define ENEMY_H
#include "sprite.h"
class Level;
class character;
class enemy : public sprite
{
public:
	enemy(Level *l, drawengine *de, int s_index, float x=1, float y=1, int i_lives=1);
	void addgoal(character *g);
	bool move(float x, float y);
	void idleupdate(void);
protected:
	void simulateAI(void);
	character *goal;

};
#endif