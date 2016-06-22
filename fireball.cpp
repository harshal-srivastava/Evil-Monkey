#include "stdafx.h"
#include "fireball.h"
#include <list>
fireball::fireball(Level *lev, drawengine *de, int s_index,float x, float y, float xdir, float ydir, int i_lives)
	: sprite(lev, de, s_index, x, y, i_lives)
{
	facingdirection.x=xdir;
	facingdirection.y=ydir;
	classID=FIREBALL_CLASSID;


}
void fireball::idleupdate(void)
{
	if (sprite::move(facingdirection.x, facingdirection.y))
	{
		list <sprite *>::iterator iter;
		for (iter=level->npc.begin(); iter!=level->npc.end(); iter++)
		{
			if ((*iter)->classID!=classID && (int)(*iter)->getx()==(int)pos.x && (int)(*iter)->gety()==(int)pos.y)
			{
				(*iter)->addlives(-1);
				addlives(-1);
			}
		}
	}
	else
		addlives(-1);
}