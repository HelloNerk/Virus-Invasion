#pragma once
#include "Entidad.h"

class Enemigo :public Entidad {
private:
	bool curado;
public:
	Enemigo(int w, int h, int x, int y) {
		width = w;
		height = h;
		dx = dy = 10;
		this->x = x;
		this->y = y;
		idX = idY = 0;
		visibility = true;
		curado = false;
	}
	~Enemigo() {}

	void draw(Graphics^ g, Bitmap^ bmp, Bitmap^ bmpcura) {
		if (curado == false) {
			Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
			Rectangle zoom = Rectangle(x, y, width * 2.5, height * 2.5);
			g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
		}
		else
		{
			Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
			Rectangle zoom = Rectangle(x, y, width * 2.5, height * 2.5);
			g->DrawImage(bmpcura, zoom, sectionShow, GraphicsUnit::Pixel);
		}
	}


	void move(int _x, int _y) { //izquierda a derecha

		if (x == _x) {
			x += 0;
		}
		else if (x > _x) {
			x -= dx;
			idY = 1;
			direction = 'A';
		}
		else if (x < _x) {
			x += dx;
			idY = 2;
			direction = 'D';
		}

		if (y == _y) {
			y += 0;
		}
		else if (y > _y) {
			y -= dy;
			idY = 3;
		}
		else if (y < _y) {
			y += dy;
			idY = 0;
		}

		idX++;
		if (idX > 3)idX = 0;
	}

	void movecura(Graphics^ g) {
		if (x < g->VisibleClipBounds.Width / 2) {
			x -= dx;
			idY = 1;
		}
		else
		{
			x += dx;
			idY = 2;
		}
		idX++;
		if (idX > 3)idX = 0;
	}

	Rectangle getRectangle() { return Rectangle(x, y, width * 2.5, height * 2.5); }
	void setcurado(bool c) {
		curado = c;
	}

	int getXWidth() { return x + width * 2.5; }
	int getYHeight() { return y + height * 2.5; }


	bool getcurado() {
		return curado;
	}
	char getDirection() { return direction; }
	void enemigodificil() {
		dx = dy = 20;
	}
};