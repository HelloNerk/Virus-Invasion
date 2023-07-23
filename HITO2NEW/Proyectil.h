#pragma once
#include "Entidad.h"

class Proyectil :Entidad {
private:
public:
	Proyectil(int x, int y, int w, int h, char d) {
		width = w;
		height = h;
		direction = d;
		dx = dy = 50;
		this->x = x;
		this->y = y;
		visibility = true;
	}
	~Proyectil() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		g->DrawImage(bmp, x, y, width * 0.2, height * 0.2);
	}

	void move(Graphics^ g)
	{
		if (direction == 'S' && y + height * 0.2 <= g->VisibleClipBounds.Height) {
			y += dy;
		}
		if (direction == 'W' && y >= 0) {
			y -= dy;
		}
		if (direction == 'A' && x >= 0) {
			x -= dx;
		}
		if (direction == 'D' && x + width * 0.2 <= g->VisibleClipBounds.Width) {
			x += dx;
		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.2, height * 0.2);
	}
	int getX() { return x; }
	int getY() { return y; }
	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }
	int getXWidth() { return x + width * 0.2; }
	int getYHeight() { return y + height * 0.2; }
};	