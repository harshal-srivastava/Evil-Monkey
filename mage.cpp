#include "stdafx.h"
#include "mage.h"
#include "fireball.h"
#include "level.h"
#include <list>
mage::mage(Level *l, drawengine *de, int s_index, float x, float y, int lives, char spell_key,char up_key, char down_key, char left_key, char right_key)
	       :character(l, de, s_index, x, y, lives, up_key, down_key, left_key, right_key)
{
	spellkey=spell_key;
	classID=MAGE_CLASSID;
}
bool mage::keypress(char c)
{
	bool val=character::keypress(c);
	if (val==false)
	{
		if (c==spellkey)
		{
			castspell();
		}
	}
	return val;
}
void mage::castspell(void)
{
	fireball *temp=new fireball(level, drawarea, SPRITE_FIREBALL, (int)pos.x+facingdirection.x, (int) pos.y+facingdirection.y, facingdirection.x, facingdirection.y);
	level->addNPC((sprite *)temp);

}



