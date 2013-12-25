#pragma once

/** Основной класс игры, игровой цикл тут.
 * Хранит в себе список всех объектов, занимается вызовом всех функций игровой логики и рисовки
 * Обрабатывает пользовательский ввод (слушает мышь и клавиаутуру)
 *
 * Author: Insality */

#include <vector>

#include "entity/Tile.h"
#include "entity/Units.h"

class Level {
public:
	Level();
	virtual ~Level();

	void draw();
	void update();
	void getUnit(int x, int y);
	void moveUnit(int x, int y);
	int distance (int x1, int y1, int x2, int y2);

private:
	bool m_isDrawGrid = false;
	std::vector< std::vector<Tile*> > map;
	std::vector<Unit*> units;

	Unit *curUnit;

	void drawBackground();
	void drawMap();
	void drawGrid();
	void drawLight(int x, int y);

};
