#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Tile.hpp"


Tile::Tile(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex)
{
	setVelocityY(20000.0f);
	setVelocityX(0.0f);
}

Tile::Tile(Vector2f p_pos, SDL_Texture* p_tex, float p_scaleX, float p_scaleY)
:Entity(p_pos, p_tex, p_scaleX, p_scaleY)
{
	setVelocityY(20000.0f);
	setVelocityX(0.0f);
}

void Tile::moveUp(float p_deltaTime, int p_windowHeight){
	setPreviousPos(getPos());

	setPosY(getPos().y - (getVelocityY()*p_deltaTime));

	if (getPos().y + (getCurrentFrame().h*getScaleY())<=0){
		setPosY(p_windowHeight);
	}
}

void Tile::moveDown(float p_deltaTime, int p_windowHeight){
	setPreviousPos(getPos());

	setPosY(getPos().y + (getVelocityY()*p_deltaTime));

	if (getPos().y>=p_windowHeight){
		setPosY(0-(getCurrentFrame().w*getScaleY()));
	}
}


