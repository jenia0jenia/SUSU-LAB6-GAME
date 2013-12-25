#include "Units.h"

#include <GL/gl.h>
#include <iostream>

#include "../Data.h"

//#include "../Data.h"

void Unit::drawFractionColor() {
	if (this->fraction == Data::RED) {
		glPointSize(getSize() + 6);
		glColor3f(1, 0, 0);
		glBegin(GL_POINTS);
		{
			glVertex2f(getX(), getY());
		}
		glEnd();
	} else if (this->fraction == Data::BLUE) {
		glPointSize(getSize() + 6);
		glColor3f(0, 0, 1);
		glBegin(GL_POINTS);
		{
			glVertex2f(getX(), getY());
		}
		glEnd();
	}
}

void Unit::update(){
	if (Data::distance(getX(), getY(), goalX, goalY) > 4){
		if (getX() != goalX){
			if (getX() < goalX){
				setX(getX() + 1);
			}
			else{
				setX(getX() - 1);
			}
		}
		if (getY() != goalY){
			if (getY() < goalY) {
				setY(getY() + 1);
			} else {
				setY(getY() - 1);
			}
		}
	}
}

void Unit::moveTo(int x, int y){
	goalX = x;
	goalY = y;
}

// WARRIOR -=-=-=-=

Warrior::Warrior() {
}

Warrior::Warrior(int x, int y, Data::fractions fraction) {
	this->setSize(16);
	this->maxHealth = 150;
	this->health = this->maxHealth;
	this->damage = 50;
	this->setX(x);
	this->setY(y);
	this->goalX = getX();
	this->goalY = getY();
	this->fraction = fraction;
}

Warrior::~Warrior() {

}

void Warrior::draw() {
	drawFractionColor();
	glPointSize(getSize());
	glColor3f(0.4, 0.5, 0.8);
	glBegin(GL_POINTS);
	{
		glVertex2f(getX(), getY());
	}
	glEnd();
}

// WORKER -=-=-=-=-=-

Worker::Worker() {
}

Worker::Worker(int x, int y, Data::fractions fraction) {
	this->setSize(16);
	this->maxHealth = 150;
	this->health = this->maxHealth;
	this->damage = 50;
	this->setX(x);
	this->setY(y);
	this->goalX = getX();
	this->goalY = getY();
	this->fraction = fraction;
}

Worker::~Worker() {

}

void Worker::draw() {
	drawFractionColor();
	glPointSize(getSize());
	glColor3f(0.5, 1, 0.3);
	glBegin(GL_POINTS);
	{
		glVertex2f(getX(), getY());
	}
	glEnd();
}

// CONQUEROR -=-=-=-=-=

Conqueror::Conqueror() {
}

Conqueror::Conqueror(int x, int y, Data::fractions fraction) {
	drawFractionColor();
	this->setSize(16);
	this->maxHealth = 150;
	this->health = this->maxHealth;
	this->damage = 50;
	this->setX(x);
	this->setY(y);
	this->goalX = getX();
	this->goalY = getY();
	this->fraction = fraction;
}

Conqueror::~Conqueror() {

}

void Conqueror::draw() {
	drawFractionColor();
	glPointSize(getSize());
	glColor3f(0.2, 1, 1);
	glBegin(GL_POINTS);
	{
		glVertex2f(getX(), getY());
	}
	glEnd();
}
