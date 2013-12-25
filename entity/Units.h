#pragma once

// TODO: warrior, worker, conqueror

#include "../Data.h"
#include "Entity.h"

/** Интерфейс для юнитов в игре, обеспечивает взаимодействия между всеми юнитами
 * параметры такие как принадлежность к фракции, жизни и т.д.
 *
 * Author: Insality*/

class Unit: public Entity {
public:
	Unit(){};
	virtual ~Unit(){};

	virtual void draw() = 0;
	void drawFractionColor();

	void setSize(int size){this->size = size;};
	int getSize(){return size;};

	void update();
	void moveTo(int x, int y);

	int goalX, goalY;
	int health, maxHealth, damage;
	int size;
	Data::fractions fraction;
};

class Warrior: public Unit{
public:
	Warrior();
	Warrior(int x, int y, Data::fractions fraction);
	virtual ~Warrior();

	void draw();
};

class Worker: public Unit{
public:
	Worker();
	Worker(int x, int y, Data::fractions fraction);
	virtual ~Worker();
	void draw();
};

class Conqueror: public Unit{
public:
	Conqueror();
	Conqueror(int x, int y, Data::fractions fraction);
	virtual ~Conqueror();
	void draw();
};
