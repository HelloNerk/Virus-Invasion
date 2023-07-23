#pragma once
#include "Entidad.h"

class Virus :public Entidad {
private:
public:
	Virus(int x, int y, int w, int h, char d) {
		width = w;
		height = h;
		direction = d;
		dx = dy = 30;
		this->x = x;
		this->y = y;
		visibility = true;
	}
	~Virus() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		g->DrawImage(bmp, x, y, width * 0.1, height * 0.1);
	}

	void move(Graphics^ g)
	{
		if (direction == 'A' && x >= 0) {
			x -= dx;
		}
		else if (direction == 'D' && x + width * 0.1 < g->VisibleClipBounds.Width) {
			x += dx;
		}
		else
		{
			x += dx;
		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.1, height * 0.1);
	}
	int getXWidth() { return x + width * 0.1; }
	int getYHeight() { return y + height * 0.1; }
	void virusdificil() {
		dx = 40;
	}
};