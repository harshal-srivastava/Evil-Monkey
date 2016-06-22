#ifndef CHARACTER_H
#define CHARACTER_H
#include "sprite.h"
class character:public sprite
{
public:
	character(Level *l, drawengine *de, int s_index, float x=1, float y=1, int lives=3, char up_key='w', char down_key='s', char left_key='a', char right_key='d');
	virtual bool keypress(char c);
	virtual void addlives(int num=1);
protected:
	char upkey;
	char downkey;
	char leftkey;
	char rightkey;
};
#endif