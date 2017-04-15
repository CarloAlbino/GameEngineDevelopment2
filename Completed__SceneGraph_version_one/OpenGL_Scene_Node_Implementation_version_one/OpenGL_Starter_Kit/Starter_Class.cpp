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
float g_oldTime;
float g_deltaSeconds = 0.00f;

const float SWITCH_TIME = 4.0f;
float g_switchTimer = 0.0f;

float g_rotationAngle = 0.0f;
//int g_modelToShow = 0;
std::vector<SceneNode*> g_models;
//GameGrid* g_grid;

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
	g_oldTime = glutGet(GLUT_ELAPSED_TIME);
	time(&g_lastFrameTime);

	glutDisplayFunc(Render);
	glutIdleFunc(Update);

	glutKeyboardFunc(handleKeyPresses);
	glutKeyboardUpFunc(handleKeyReleased);
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

	g_models[0]->Update(g_deltaSeconds);

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
		g_models[0]->Render();
	}
	//g_grid->Render();

	glFlush();
}

void InitializeModels(void)
{
	GameGrid* grid = new GameGrid("smallMap.txt", glm::mat4(1.0f), 1.0f);
	g_models.push_back(grid);

}

void CalculateDeltaSeconds(void)
{
	int t;
	t = glutGet(GLUT_ELAPSED_TIME);
	g_deltaSeconds = (t - g_oldTime) / 1000.0f;
	g_oldTime = t;
}

void handleKeyPresses(unsigned char key, int x, int y)
{
	g_models[0]->UpdateInput(key, true);
}

void handleKeyReleased(unsigned char key, int x, int y)
{
	g_models[0]->UpdateInput(key, false);
}