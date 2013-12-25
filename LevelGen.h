/** Занимается генерацией уровня, создает матрицу из объектов клеток поля (песок, земля, трава и тд)
 * Генерирует список декораций и начальных расположений фракций
 *
 * Author: Insality*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Data.h"
#include "entity/Tile.h"

class LevelGen {
public:
	LevelGen();
	virtual ~LevelGen();

	void generate(std::vector< std::vector<Tile*> > &map){
		srand(time(0));
		std::cout << "map GEN" << std::endl;

		for (int i = 0; i < Data::TILES_WIDTH; i++) {
			std::vector<Tile*> temp;
			for (int j = 0; j < Data::TILES_HEIGHT; j++) {
				int rnd = rand()%2;
				if (rnd == 1)
					temp.push_back(new Tile(i * 32, j * 32, "Grass"));
				else
					temp.push_back(new Tile(i * 32, j * 32, "Stone"));
			}
			map.push_back(temp);
		}
	}
};
