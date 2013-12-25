#include "Level.h"

//#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <stddef.h>
#include <cmath>
//#include <iostream>

#include "Data.h"
#include "entity/Factories.h"
#include "LevelGen.h"

Level::Level() {
	LevelGen levelGen;
	levelGen.generate(map);

//	Создание юнитов начальных на карте с помощью фабрик:
	BluePlayerFactory BlueFactory;
	RedPlayerFactory RedFactory;
	units.push_back(BlueFactory.createWarrior(64, 32));
	units.push_back(BlueFactory.createWorker(64, 64));
	units.push_back(BlueFactory.createConqueror(64, 96));

	units.push_back(RedFactory.createWarrior(128, 32));
	units.push_back(RedFactory.createWorker(128, 64));
	units.push_back(RedFactory.createConqueror(128, 96));
}

Level::~Level() {
	delete curUnit;
}

void Level::draw() {
	drawBackground();
	drawMap();

	if (m_isDrawGrid) {
		drawGrid();
	}

	if (curUnit){
		drawLight(curUnit->getX(), curUnit->getY());
	}

	for (size_t i = 0; i < units.size(); i++){
		units[i]->draw();
	}
}

void Level::update(){
	for (size_t i = 0; i < units.size(); i++) {
		units[i]->update();
	}
}

void Level::getUnit(int x, int y) {
	for (size_t i = 0; i < units.size(); i++) {
		if ((Data::distance(units[i]->getX(), units[i]->getY(), x, y)) < 20) {
			curUnit = units[i];
			return;
		}
	}
	curUnit = NULL;
	return;
}

void Level::moveUnit(int x, int y){
	if (curUnit){
		curUnit->moveTo(x, y);
	}
}

void Level::drawBackground(){
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_QUADS);{
		glVertex2f(0, 0);
		glVertex2f(Data::SCREEN_WIDTH, 0);
		glVertex2f(Data::SCREEN_WIDTH, Data::SCREEN_HEIGHT);
		glVertex2f(0, Data::SCREEN_HEIGHT);
	}
	glEnd();
}

void Level::drawMap() {
//	TODO:: убрать привязку к дате...
	for (int i = 0; i < Data::TILES_WIDTH; i++) {
		for (int j = 0; j < Data::TILES_HEIGHT; j++) {
			map[i][j]->draw();
		}
	}
}

void Level::drawGrid(){
	glColor3f(0, 0, 0.4);
	for (int i = 0; i < Data::TILES_WIDTH; i++){
		for (int j = 0; j < Data::TILES_HEIGHT; j++) {
			glBegin(GL_LINES);{
				glVertex2f(32*i, 0);
				glVertex2f(32*i, Data::SCREEN_HEIGHT);
				glVertex2f(0, 32*j);
				glVertex2f(Data::SCREEN_WIDTH, 32*j);
			}
			glEnd();
		}
	}
}

void Level::drawLight(int x, int y) {
	glColor3f(0.7, 0.7, 0.1);
	glPointSize(32);
	glBegin (GL_POINTS);
	{
		glVertex2f(x, y);
	}
	glEnd();
}
