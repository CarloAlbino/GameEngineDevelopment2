// Includes
#include <math.h>
#include <ctime>
//
#include "Primitives.h"
#include "CompositeModels.h"
#include "GameGrid.h"
////

// Forward declarations
void Update(void);
void Render(void);
void InitializeModels(void);
void CalculateDeltaSeconds(void);
// Camera //
void handleKeyPresses(unsigned char key, int x, int y);
void handleKeyReleased(unsigned char key, int x, int y);
void handleMouseMove(int button, int state, int x, int y);
////

// Global variables

// Other //
time_t g_lastFrameTime;
float g_deltaSeconds = 0.00f;

const float SWITCH_TIME = 4.0f;
float g_switchTimer = 0.0f;

float g_rotationAngle = 0.0f;
int g_modelToShow = 0;
std::vector<SceneNode*> g_models;

////

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First Application");
	glClearColor(0.0, 0.0, 0.0, 0.0);

	InitializeModels();
	time(&g_lastFrameTime);

	glutDisplayFunc(Render);
	glutIdleFunc(Update);

	//glutKeyboardFunc(handleKeyPresses);
	//glutKeyboardUpFunc(handleKeyReleased);
	//glutMouseFunc(handleMouseMove);

	//cam = new Camera(windowWidth, windowHeight);
	//init();

	glutMainLoop();

	return 0;
}

void Update(void)
{
	// DeltaSeconds
	CalculateDeltaSeconds();

	//int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	//int deltaTime = timeSinceStart - oldTimeSinceStart;
	//oldTimeSinceStart = timeSinceStart;

	// Functionality
	//if (g_modelToShow == 2)
	//{
	//	g_rotationAngle += 0.001f;
	//}
	//else
	//{
	//	g_rotationAngle += 0.0001f;
	//}

	//g_switchTimer += g_deltaSeconds;
	//if (g_switchTimer > SWITCH_TIME)
	//{
	//	g_switchTimer = 0.0f;
	//	g_modelToShow++;
	//	if (g_modelToShow >= g_models.size())
	//	{
	//		g_modelToShow = 0;
	//	}
	//}

	// Render
	glutPostRedisplay();
}

void Render(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Ready to Draw
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (g_models.size() > 0)
	{
		// Rotate
		//glm::mat4 rot = glm::rotate(glm::mat4(1.0), g_rotationAngle, glm::vec3(1, 1, 1));

		//g_models[g_modelToShow]->SetTransform(rot);
		g_models[g_modelToShow]->Render();
	}

	glFlush();
}

void InitializeModels(void)
{
	//Car* car = new Car(glm::mat4(1.0f), 1.0f);
	//car->SetColor(1.0f, 0.0f, 0.0f);
	//car->SetScale(0.3f, 0.3f, 0.3f);
	//g_models.push_back(car);

	//Cube* cube = new Cube(glm::mat4(1.0f), 1.0f);
	//cube->SetColor(1.0f, 0.0f, 0.0f);
	//cube->SetScale(1, 1, 1);
	//g_models.push_back(cube);


	GameGrid* grid = new GameGrid("smallMap.txt", glm::mat4(1.0f), 1.0f);
	g_models.push_back(grid);

	//Cone* cone = new Cone(glm::mat4(1.0f), 1.0f);
	//cone->SetColor(1.0f, 0.0f, 0.0f);
	//cone->SetScale(1, 1, 1);
	//g_models.push_back(cone);

	//Sphere* sphere = new Sphere(glm::mat4(1.0f), 1.0f);
	//sphere->SetColor(1.0f, 0.0f, 0.0f);
	//sphere->SetScale(1, 1, 1);
	//g_models.push_back(sphere);

	//Cylinder* cylinder = new Cylinder(glm::mat4(1.0f), 1.0f);
	//cylinder->SetColor(1.0f, 0.0f, 0.0f);
	//cylinder->SetScale(1, 1, 1);
	//g_models.push_back(cylinder);

	//StairCase* staircase = new StairCase(glm::mat4(1.0f), 1.0f);
	//staircase->SetColor(1.0f, 0.0f, 0.0f);
	//staircase->SetScale(1, 1, 1);
	//g_models.push_back(staircase);


}

void CalculateDeltaSeconds(void)
{
	time_t timer;
	time(&timer);

	g_deltaSeconds = difftime(timer, g_lastFrameTime);

	g_lastFrameTime = timer;
}

void handleKeyPresses(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':

	case 's':

	case 'a':

	case 'd':

	default:
		//do nothing
		break;
	}
}

void handleKeyReleased(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':

	case 's':

	case 'a':

	case 'd':

	default:
		//do nothing
		break;
	}
}