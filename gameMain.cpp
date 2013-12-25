/** Обеспечивает начало игры, создает дисплей, проводить начальную инициализацию,
 * создает класс level и начинает игру */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

#include "Data.h"
#include "Level.h"

using namespace std;

Level level;

void render(){
	glClear(GL_COLOR_BUFFER_BIT);

	level.draw();

	glFlush();
}

void initGL(){
	cout << "GL init..." << endl;
	glClearColor(0.2, 0.2, 0.2, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, Data::SCREEN_WIDTH, Data::SCREEN_HEIGHT, 0.0, -1.0, 1.0);
}

void update(int value){
//	cout << "UPDATE ITERATION!" << endl;
	glutPostRedisplay(); // Перерисовка

	level.update();

	glutTimerFunc(30, update, 0);
}

void input(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "Left click " << x << " " << y  << endl;
		level.getUnit(x, y);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		cout << "Left release" << endl;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		cout << "Right click " << x << " " << y << endl;
		level.moveUnit(x, y);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		cout << "Right release" << endl;
	}
}

int main(int argc, char *argv[]){
	// TODO: Инициализация и старт игры...
	cout << "Start game insanity!" << endl;
	cout << "Window GL init..." << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Data::SCREEN_WIDTH, Data::SCREEN_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(Strings::GAME_TITLE.c_str());
	initGL();
	glutDisplayFunc(render);
	glutTimerFunc(30, update, 0);

	// Input zone:
	glutMouseFunc(input);

	glutMainLoop();

	// Инициализация окна
	cout << "End of game..." << endl;
	return 0;
}
