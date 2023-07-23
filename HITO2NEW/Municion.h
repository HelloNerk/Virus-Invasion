#pragma once
#include "Entidad.h"

class Municion :public Entidad {
private:
public:
	Municion(int x, int y, int w, int h) {
		width = w;
		height = h;
		this->x = x;
		this->y = y;
		visibility = true;
	}
	~Municion() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		g->DrawImage(bmp, x, y, width * 1.0, height * 1.0);
	}


	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}
	int getXWidth() { return x + width * 1.0; }
	int getYHeight() { return y + height * 1.0; }
};