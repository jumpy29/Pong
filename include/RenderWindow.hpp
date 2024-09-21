#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"

class RenderWindow{
public:
	RenderWindow(const char* p_title, int p_w, int p_h); // constructor
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanup();
	void clear();
	void render(Entity& p_entity);
	void renderInterpolated(Entity& p_entity, float p_interpolationFactor);
	void display();
	int getRefreshRate();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;  
};