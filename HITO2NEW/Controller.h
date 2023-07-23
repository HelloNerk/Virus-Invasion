#pragma once
#include "Aliado.h"
#include "Enemigo.h"
#include "Proyectil.h"
#include "Municion.h"
#include "Virus.h"
#include <vector>
#include <time.h>
using namespace std;

class Controller {
private:
	vector<Enemigo*>vecenemigo;
	vector<Aliado*>vecaliado;
	vector<Proyectil*>vecbalas;
	vector<Municion*>vecmunicion;
	vector<Virus*>vecvirus;
	int vida;
	int puntaje;
	int numberofenemies;
	int cantbalas;
	int puntajemax;
	int secenemigos;
	int restavida;
	bool apareciondificil;
	int sumabalas;
	int curado;
	time_t iniciotiempo = clock();
	time_t tiempoaliado = clock();
	time_t tiempomunicion = clock();
	time_t tiempoenemigo = clock();
public:

	Controller() {
		vida = 80;
		puntaje = 0;
		cantbalas = 7;
		puntajemax = 50;
		secenemigos = 7;
		restavida = 5;
		apareciondificil = false;
		sumabalas = 5;
		curado = 0;
	}

	~Controller() {}

	void createEnemies(int width, int height) {
		if ((clock() - iniciotiempo) / CLOCKS_PER_SEC >= secenemigos) {
			Enemigo* e = new Enemigo(width, height, 0, rand() % (450 - 670) + 430);
			Enemigo* a = new Enemigo(width, height, 1220, rand() % (450 - 670) + 430);
			if (apareciondificil == true) {
				Enemigo* b = new Enemigo(width, height, 1220, rand() % (450 - 670) + 430);
				vecenemigo.push_back(b);
			}
			vecenemigo.push_back(e);
			vecenemigo.push_back(a);
			iniciotiempo = clock();
		}
	}

	void funcionaliado(int Mwidth, int Mheight) {
		if (vecaliado.size() > 0) {
			if ((clock() - tiempomunicion) / CLOCKS_PER_SEC >= rand() % (15 - 10) + 4) {
				for (int i = 0; i < vecaliado.size(); i++) {
					Municion* b = new Municion(vecaliado[i]->getX() + 17, vecaliado[i]->getY() + 50, Mwidth, Mheight);
					vecmunicion.push_back(b);
				}
				tiempomunicion = clock();
			}
		}
	}

	//int x, int y, int w, int h, char d
	void disparoenemigo(int w, int h) {
		if (vecenemigo.size() > 0) {
			if ((clock() - tiempoenemigo) / CLOCKS_PER_SEC >= 10) {
				for (int i = 0; i < vecenemigo.size(); i++) {
					if (vecenemigo[i]->getcurado() == false) {
						Virus* b = new Virus(vecenemigo[i]->getX() + 17, vecenemigo[i]->getY() + 22, w, h, vecenemigo[i]->getDirection());
						vecvirus.push_back(b);
					}
				}
				tiempoenemigo = clock();
			}
		}
	}

	void addBala(Proyectil* b) {
		vecbalas.push_back(b);
	}

	void addAliado(Aliado* b) {
		vecaliado.push_back(b);
	}

	void drawEveryThing(Graphics^ g, Bitmap^ bmpEnemy, Bitmap^ bmpAliado, Bitmap^ bmpbala, Bitmap^ bmpmunicion, Bitmap^ bmpvirus, Bitmap^ bmpcurado) {
		for (int i = 0; i < vecaliado.size(); i++)
		{
			vecaliado[i]->draw(g, bmpAliado);
		}

		for (int i = 0; i < vecenemigo.size(); i++)
		{
			vecenemigo[i]->draw(g, bmpEnemy, bmpcurado);
		}

		for (int i = 0; i < vecbalas.size(); i++)
		{
			vecbalas[i]->draw(g, bmpbala);
		}

		for (int i = 0; i < vecmunicion.size(); i++)
		{
			vecmunicion[i]->draw(g, bmpmunicion);
		}

		for (int i = 0; i < vecvirus.size(); i++)
		{
			vecvirus[i]->draw(g, bmpvirus);
		}
	}

	void moveEveryThing(Graphics^ g, int _x, int _y) {
		for (int i = 0; i < vecaliado.size(); i++)
		{
			vecaliado[i]->move(g);
		}
		for (int i = 0; i < vecenemigo.size(); i++)
		{
			if (vecenemigo[i]->getcurado() == false) {
				vecenemigo[i]->move(_x, _y);
			}
			else if (vecenemigo[i]->getcurado() == true)
			{
				vecenemigo[i]->movecura(g);
			}
		}
		for (int i = 0; i < vecbalas.size(); i++)
		{
			vecbalas[i]->move(g);
		}
		for (int i = 0; i < vecvirus.size(); i++)
		{
			vecvirus[i]->move(g);
		}
	}

	void collision(Graphics^ g, Rectangle h) {
		//verificar
		for (int i = 0; i < vecbalas.size(); i++)
		{
			if (vecbalas[i]->getX() <= 0 || vecbalas[i]->getXWidth() >= g->VisibleClipBounds.Width ||
				vecbalas[i]->getY() <= 0 || vecbalas[i]->getYHeight() >= g->VisibleClipBounds.Height) {
				vecbalas[i]->setVisibility(false);
			}
		}

		for (int i = 0; i < vecvirus.size(); i++)
		{
			if (vecvirus[i]->getX() <= 0 || vecvirus[i]->getXWidth() >= g->VisibleClipBounds.Width ||
				vecvirus[i]->getY() <= 0 || vecvirus[i]->getYHeight() >= g->VisibleClipBounds.Height) {
				vecvirus[i]->setVisibility(false);
			}
		}

		for (int i = 0; i < vecaliado.size(); i++)
		{
			if (vecaliado[i]->getX() <= 0 || vecaliado[i]->getXWidth() >= g->VisibleClipBounds.Width ||
				vecaliado[i]->getY() <= 0 || vecaliado[i]->getYHeight() >= g->VisibleClipBounds.Height) {
				vecaliado[i]->setVisibility(false);
			}
		}

		for (int i = 0; i < vecenemigo.size(); i++)
		{
			if (vecenemigo[i]->getcurado() == true) {
				if (vecenemigo[i]->getX() <= 0 || vecenemigo[i]->getXWidth() >= g->VisibleClipBounds.Width ||
					vecenemigo[i]->getY() <= 0 || vecenemigo[i]->getYHeight() >= g->VisibleClipBounds.Height) {
					vecenemigo[i]->setVisibility(false);
				}
			}
		}

		// colision bullet vs enemy
		for (int i = 0; i < vecenemigo.size(); i++)
		{
			for (int j = 0; j < vecbalas.size(); j++)
			{
				if (vecenemigo[i]->getcurado() == false) {
					if (vecenemigo[i]->getRectangle().IntersectsWith(vecbalas[j]->getRectangle())) {
						vecenemigo[i]->setcurado(true);
						vecbalas[j]->setVisibility(false);
						puntaje += 5;
						curado ++;
					}
				}
			}
		}

		for (int i = 0; i < vecvirus.size(); i++)
		{
			if (vecvirus[i]->getRectangle().IntersectsWith(h)) {
				vecvirus[i]->setVisibility(false);
				vida -= restavida;
			}
		}


		//colision heroe vs enemigo
		for (int i = 0; i < vecenemigo.size(); i++)
		{
			if (vecenemigo[i]->getcurado() == false) {
				if (vecenemigo[i]->getRectangle().IntersectsWith(h)) {
					vida -= restavida;
					vecenemigo[i]->setVisibility(false);
				}
			}
		}

		//colision heroe con municion
		for (int i = 0; i < vecmunicion.size(); i++) {
			if (vecmunicion[i]->getRectangle().IntersectsWith(h)) {
				vecmunicion[i]->setVisibility(false);
				cantbalas += sumabalas;
			}
		}
		//borrar
		for (int i = 0; i < vecbalas.size(); i++)
		{
			if (!vecbalas[i]->getVisibility()) { //if(vecbalas[i]->getVisibility()==false)
				vecbalas.erase(vecbalas.begin() + i);
			}
		}

		for (int i = 0; i < vecenemigo.size(); i++)
		{
			if (!vecenemigo[i]->getVisibility()) {
				vecenemigo.erase(vecenemigo.begin() + i);
			}
		}

		for (int i = 0; i < vecmunicion.size(); i++)
		{
			if (!vecmunicion[i]->getVisibility()) {
				vecmunicion.erase(vecmunicion.begin() + i);
			}
		}

		for (int i = 0; i < vecvirus.size(); i++)
		{
			if (!vecvirus[i]->getVisibility()) {
				vecvirus.erase(vecvirus.begin() + i);
			}
		}
	}

	int getvida() { return vida; }
	int getpuntaje() { return puntaje; }
	int getcantbalas() { return cantbalas; }
	void disminuircantbalas() { cantbalas--; }

	bool perdio() {
		if (vida <= 0) {
			return true;
		}
	}

	bool gano() {
		if (puntaje >= puntajemax) {
			return true;
		}
	}

	void juegodificil() {
		for (int i = 0; i < vecenemigo.size(); i++) {
			vecenemigo[i]->enemigodificil();
		}
		for (int i = 0; i < vecvirus.size(); i++) {
			vecvirus[i]->virusdificil();
		}
		vida = 50;
		puntajemax = 100;
		secenemigos = 5;
		restavida = 10;
		cantbalas = 5;
		apareciondificil = true;
		sumabalas = 3;
	}
	int getcurado() {
		return curado;
	}
};