#ifndef DRAWENGINE_H
#define DRAWENGINE_H
class drawengine
{
public:
	drawengine(int xsize=30, int ysize=20);
	~drawengine();
	int createsprite(int index, char c);
	void deletesprite(int index);
	void erasesprite(int posx, int posy);
	void drawsprite(int index, int posx, int posy); 
	void createbackgroundtile(int index, char c);
	void setmap(char **);
	void drawbackground(void);
protected:
	char **map;
	int screenwidth;
	int screenheight;
	char spriteimage[16];
	char tileimage[16];
private:
	void gotoxy(int x, int y);
	void cursorvisibility(bool visibility);

};
#endif