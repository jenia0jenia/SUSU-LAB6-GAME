/** Абстрактный класс сущности, обеспечивает
 * основные параметры всех объектов игры (координаты, картинка, методы логики и рисовки и тд.)
 *
 * Author: Insality */
#pragma once

#include <string>

class Entity {
public:
	Entity(){};
	virtual ~Entity(){};
	int getX(){ return m_x;};
	int getY(){ return m_y;};
	void setX(int x) { m_x = x; };
	void setY(int y) { m_y = y; };
	void setName(std::string name) {m_name = name;};
	std::string getName() { return m_name; };
	virtual void draw() = 0;

private:
	int m_x, m_y;
	std::string m_name;
};
