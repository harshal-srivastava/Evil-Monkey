#ifndef GAME_H
#define GAME_H

#include "drawengine.h"
#include "level.h"
#include "character.h"
#include "mage.h"
class game
{
public:
	bool run(void);
protected:
	bool getinput(char *c);
	void timerupdate(void);
private:
	Level *level;
	mage *player;
	double framecount;
	double lasttime;
	double starttime;
	int posx;
	drawengine drawarea;
};
#endif