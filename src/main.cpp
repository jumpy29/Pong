#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Utils.hpp"
#include "Entity.hpp"
#include "RenderWindow.hpp"
#include "Ball.hpp"
#include "Tile.hpp"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 780;
const float FIXED_TIMESTAMP = 0.016f;

int main(int argc, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO)>0){
		std::cout << "Hey.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	}

	if (!(IMG_Init(IMG_INIT_PNG))){
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
	}

	RenderWindow window("GAME v1.0", WINDOW_WIDTH, WINDOW_HEIGHT);   // creates a window

	//loading the textures
	SDL_Texture* ballTexture = window.loadTexture("res/gfx/ball.png");
	SDL_Texture* tileTexture = window.loadTexture("res/gfx/tile.png");
	SDL_Texture* tileHitTexture = window.loadTexture("res/gfx/tile_hit.png");

	Ball ball(Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), ballTexture);
	Tile tileLeft(Vector2f(0, WINDOW_HEIGHT/2), tileTexture, 3.0f, 5.0f);


	bool gameRunning = true;

	Uint32 lastFrameTime = SDL_GetTicks();
	float deltaTime = 0.016f;


	//events
	SDL_Event event;

	while (gameRunning){

		while (SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				gameRunning = false;
			}

			if (event.type==SDL_KEYDOWN){
				switch (event.key.keysym.sym){
					case SDLK_UP:
						tileLeft.moveUp(deltaTime, WINDOW_HEIGHT);
						break;

					case SDLK_DOWN:
						tileLeft.moveDown(deltaTime, WINDOW_HEIGHT);
						break;
				}
			}
		}

		Uint32 currentFrameTime = SDL_GetTicks();
		deltaTime = (currentFrameTime - lastFrameTime)/1000.0f; //divide to convert to seconds
		lastFrameTime = currentFrameTime;
		

		ball.updatePos(deltaTime, WINDOW_WIDTH, WINDOW_HEIGHT);

		window.clear(); //clear the screen before displaying the new frame to prevent overlapping




		//render here
		window.render(ball);
		window.render(tileLeft);

		window.display();
	}


	window.cleanup();
	SDL_Quit();

	return 0;
}