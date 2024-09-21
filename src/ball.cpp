#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include "Ball.hpp"

Ball::Ball(Vector2f p_pos, SDL_Texture* p_tex):Entity(p_pos, p_tex), ballWidth(32), ballHeight(32){
	setVelocityX(500.0f);
	setVelocityY(500.0f);
};

Ball::Ball(Vector2f p_pos, SDL_Texture* p_tex, float p_scaleX, float p_scaleY):Entity(p_pos, p_tex, p_scaleX, p_scaleY), ballWidth(32), ballHeight(32){
	setVelocityX(500.0f);
	setVelocityY(500.0f);
};

Ball::Ball(Vector2f p_pos, SDL_Texture* p_tex, int p_ballWidth, int p_ballHeight)
:Entity(p_pos, p_tex), ballWidth(p_ballWidth), ballHeight(p_ballHeight)
{}

void Ball::updatePos(float p_deltaTime, int p_windowWidth, int p_windowHeight){
	Entity::updatePos(p_deltaTime);

	if (getPos().x<0){
		setVelocityX(-getVelocityX());
		setPosX(0);
	} else if (getPos().x + (ballWidth*getScaleX())  > p_windowWidth){
		setVelocityX(-getVelocityX());
		setPosX(p_windowWidth - (ballWidth*getScaleX()));
	}
	if (getPos().y<0){
		setVelocityY(-getVelocityY());
		setPosY(0);
	} else if (getPos().y + (ballHeight*getScaleY())  > p_windowHeight){
		setVelocityY(-getVelocityY());
		setPosY(p_windowHeight - (ballHeight*getScaleY()));
	}
	 
}

