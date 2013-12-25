#include "Units.h"

class PlayerFactory {
public:
	PlayerFactory(){};
	virtual ~PlayerFactory(){};

	virtual Unit* createWarrior(int x, int y) = 0;
	virtual Unit* createWorker(int x, int y) = 0;
	virtual Unit* createConqueror(int x, int y) = 0;
};

class BluePlayerFactory: public PlayerFactory
{
public:
	BluePlayerFactory(){};
	virtual ~BluePlayerFactory(){};
	Unit* createWarrior(int x, int y){
		return new Warrior(x, y, Data::BLUE);
	}
	Unit* createWorker(int x, int y){
		return new Worker(x, y, Data::BLUE);
	}
	Unit* createConqueror(int x, int y){
		return new Conqueror(x, y, Data::BLUE);
	}
};

class RedPlayerFactory: public PlayerFactory
{
public:
	RedPlayerFactory(){};
	virtual ~RedPlayerFactory(){};
	Unit* createWarrior(int x, int y){
		return new Warrior(x, y, Data::RED);
	}
	Unit* createWorker(int x, int y){
		return new Worker(x, y, Data::RED);
	}
	Unit* createConqueror(int x, int y){
		return new Conqueror(x, y, Data::RED);
	}
};
