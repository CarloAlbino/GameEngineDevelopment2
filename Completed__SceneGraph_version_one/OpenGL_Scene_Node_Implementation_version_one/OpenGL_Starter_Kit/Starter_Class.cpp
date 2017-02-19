#include <math.h>
#include "Primitves.h"
#include "CompositeModels.h"

float rotation_angle = 0.0f;
float x, y=0;


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Ready to Draw
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glm::mat4 rot = glm::rotate(glm::mat4(1.0), rotation_angle, glm::vec3(1, 1, 1));
	Cone* redTank = new Cone(rot, 1.0f);
	redTank->setColor(1.0, 0.0, 0.0);
	redTank->SetScale(2, 1, 1);
	redTank->render();

	Tank blueTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(-x, y, 0)), 0.1);
	blueTank.setColor(0.0, 0.0, 1.0);
	blueTank.render();

	Tank greenTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, -y, 0)), 0.1);
	greenTank.setColor(0.0, 1.0, 0.0);
	greenTank.render();

	Tank whiteTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(-x, -y, 0)), 0.1);
	whiteTank.setColor(1.0, 1.0, 1.0);
	whiteTank.render();

	Tank bigTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, 0, 0)), 0.2);
	bigTank.setColor(1.0, 0.0, 1.0);
	bigTank.render();

	glFlush();
}


void myIdleFunc()
{
	rotation_angle += 0.001;
	x += 0.0001;
	y -= 0.0001;
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First Application");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	glutDisplayFunc(myDisplay);
	glutIdleFunc(myIdleFunc);
	glutMainLoop();
	return 0;
}