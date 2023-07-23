#pragma once
using namespace System::Drawing;

class Entidad {
protected:
	int x, y; // ubicacion
	int dx, dy; // movimiento
	int idX, idY; // index x e y
	int width, height;
	char direction;
	bool visibility;
public:
	Entidad() {
		width = 0;
		height = 0;
		direction = 'S';
		dx = dy = 0;
		x = y = 0;
		idX = idY = 0;
		visibility = true;
	}

	~Entidad() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 2.0, height * 2.0);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}


	int getXWidth() { return x + width * 1.0; }
	int getX() { return x; }
	int getY() { return y; }
	int getYHeight() { return y + height * 1.0; }
	char getDirection() { return direction; }
	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }
	Rectangle getRectangle() { return Rectangle(x, y, width * 2.0, height * 2.0); }
};



