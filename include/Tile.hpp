#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Math.hpp"

class Tile: public Entity{
public: 
	Tile(Vector2f p_pos, SDL_Texture* p_tex);
	Tile(Vector2f p_pos, SDL_Texture* p_tex, float p_scaleX, float p_scaleY);
	void moveUp(float p_deltaTime, int p_windowHeight);
	void moveDown(float p_deltaTime, int p_windowHeight);
	
private: 

};
