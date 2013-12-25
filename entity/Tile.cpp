#include "Tile.h"

#include <GL/gl.h>

#include "../Data.h"

Tile::Tile() {
}

Tile::Tile(int x, int y, std::string name){
	this->setX(x);
	this->setY(y);
	this->setName(name);
}

Tile::~Tile() {
}

void Tile::draw() {
	if (getName() == "Grass"){
		glColor3f(0, 0.9, 0);
	}
	else{
		glColor3f(0.3,0.4,0.3);
	}

	glBegin(GL_QUADS);{
		glVertex2f(getX(), getY());
		glVertex2f(getX()+Data::TILE_SIZE, getY());
		glVertex2f(getX()+Data::TILE_SIZE, getY()+Data::TILE_SIZE);
		glVertex2f(getX(), getY()+Data::TILE_SIZE);
	}
	glEnd();
}
