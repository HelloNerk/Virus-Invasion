#pragma once
#include "Entidad.h"
using namespace std;
using namespace System::Drawing;

class Heroe : public Entidad {
private:
public:
	Heroe(int w, int h) {
		width = w;
		height = h;
		dx = dy = 10;
		x = 640;
		y = 480;
		idX = idY = 0;
		direction = 'S';
	}


	void move(Graphics^ g, char i) {
		switch (i)
		{
		case 'A':
			if (x > 0) {
				idY = 1;
				x -= dx;
				direction = 'A';
			}
			break;
		case 'D':
			if (x + width * 2.0 < g->VisibleClipBounds.Width) {
				idY = 2;
				x += dx;
				direction = 'D';
			}
			break;
		case 'W':
			if (y > 450) {
				idY = 3;
				y -= dy;
				direction = 'W';
			}
			break;
		case 'S':
			if (y + height * 2.0 < g->VisibleClipBounds.Height) {
				idY = 0;
				y += dy;
				direction = 'S';
			}
			break;
		}
		idX++;
		if (idX > 3) idX = 0;
	}
	char getDirection() { return direction; }
	int getX() { return x; }
	int getY() { return y; }
};



