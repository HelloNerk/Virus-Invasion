#pragma once
#include "Entidad.h"

class Aliado :public Entidad {
private:
	int direction;
public:
	Aliado(int w, int h) {
		width = w;
		height = h;
		dx = dy = 10;
		this->x = 0;
		this->y = rand() % (450 - 670) + 420;
		idX = idY = 0;
		visibility = true;
	}

	~Aliado() {}

	void move(Graphics^ g) {
		if (dx > 0) { //se mueve a la derecha
			idY = 2;
		}
		else
			idY = 1; //se mueve a la izquierda
		x += dx;
		idX++;
		if (idX > 2)idX = 0;
	}
};
