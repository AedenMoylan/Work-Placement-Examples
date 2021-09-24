#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GameObject.h>
#include <playerObject.h>
#include <GoalObject.h>

using namespace std;
using namespace sf;
using namespace glm;

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
private:

	static const int MAX_CUBES = 20;
	GameObject* game_object[MAX_CUBES];
	PlayerObject* player_object;
	GoalObject* goal_object;


	
	RenderWindow window;
	Clock clock;
	Time time;
	bool animate = false;
	vec3 animation = vec3(0.0f);
	float rotation = 0.0f;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	void checkCollision();

	float ranNumX = 0;
	float ranNumY = 0;

	bool isGameOver = false;
	int score = 0;

	float cubeXPosition[MAX_CUBES];
	float cubeYPosition[MAX_CUBES];
	float cubeZPosition[MAX_CUBES];

};

#endif  // ! GAME_H