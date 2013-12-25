/** Класс с игровой и системной информацией для доступа во всем проекте
 * Все различные константы, строки тут
 */
#pragma once

#include <cmath>
#include <string>

using namespace std;

namespace Strings {
	const static string GAME_TITLE = "Iron Will RPG";
};

class Data {
public:
	const static int TILES_WIDTH = 30;
	const static int TILES_HEIGHT = 20;
	const static int TILE_SIZE = 32;
	const static int SCREEN_WIDTH = TILES_WIDTH * TILE_SIZE;
	const static int SCREEN_HEIGHT = TILES_HEIGHT * TILE_SIZE;

	enum fractions {
		RED = 0, BLUE
	};

	enum tiles {
		GRASS = 0, STONE, IRON, DIRT
	};

	enum buildings {
		CASTLE = 0, HOUSE, BARRACKS
	};

	enum units {
		WARRIOR = 0, WORKER, CONQUEROR
	};

	enum decorations {
		TREE = 0, TREE2,
	};

	static int distance(int x1, int y1, int x2, int y2){
		return sqrt( (double)((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) );
	};
};
