#pragma once

/** Класс для расположения этих объектов на карте мира.
 * Показывают какое поле в каждой клетке и дает возможность проводить
 * какие либо события (например, добывать железо)
 *
 * Author: Insality */

#include <string>
#include "Entity.h"

class Tile: public Entity {
public:
	Tile();
	Tile(int x, int y, std::string name);
	virtual ~Tile();

	virtual void draw();
};
