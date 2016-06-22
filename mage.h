#ifndef MAGE_H
#define MAGE_H
#include "drawengine.h"
#include "character.h"
class mage : public character
{
public:
	mage(Level *l, drawengine *de, int s_index, float x=1, float y=1, int lives=3, char spellkey=' ',char up_key='w', char down_key='s', char left_key='a', char right_key='d');
	bool keypress(char c);

protected:
	void castspell(void);

private:
	char spellkey;
};
#endif