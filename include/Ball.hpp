#pragma once 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Math.hpp"

class Ball : public Entity{
public:
	Ball(Vector2f p_pos, SDL_Texture* p_tex);
	Ball(Vector2f p_pos, SDL_Texture* p_tex, float p_scaleX, float p_scaleY);
	Ball(Vector2f p_pos, SDL_Texture* p_tex, int p_ballWidth, int p_ballHeight);
	void updatePos(float p_deltaTime, int p_windowWidth, int p_windowHeight);

private: 
	int ballWidth;
	int ballHeight;
};