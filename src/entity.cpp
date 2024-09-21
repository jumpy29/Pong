#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex), velocityX(0.0f), velocityY(0.0f), scaleX(1.0f), scaleY(1.0f)//using member initializer list saves time 
{
	// doing x = p_x first sets x to the default value, then assigns p_x to it. 
	// so using member initializer list saves time :)

	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;

}

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, float p_scaleX, float p_scaleY)
:pos(p_pos), tex(p_tex), velocityX(0.0f), velocityY(0.0f), scaleX(p_scaleX), scaleY(p_scaleY)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

Vector2f& Entity::getPos(){
	return pos;
}

Vector2f& Entity::getPreviousPos(){
	return previousPos;
}

SDL_Texture* Entity::getTex(){
	return tex;
}

SDL_Rect Entity::getCurrentFrame(){
	return currentFrame;
}

float Entity::getVelocityX(){
	return velocityX;
}

float Entity::getVelocityY(){
	return velocityY;
}

float Entity::getScaleX(){
	return scaleX;
}

float Entity::getScaleY(){
	return scaleY;
}

void Entity::setVelocityX(float p_velocityX){
	velocityX = p_velocityX;
}

void Entity::setVelocityY(float p_velocityY){
	velocityY = p_velocityY;
}

void Entity::setPosX(float p_x){
	pos.x = p_x;
}

void Entity::setPosY(float p_y){
	pos.y = p_y;
}

void Entity::setPreviousPos(Vector2f p_previousPos){
	previousPos = p_previousPos;
}

void Entity::updatePos(float p_deltaTime){
	setPreviousPos(getPos());

	pos.x+= velocityX*p_deltaTime;
	pos.y+= velocityY*p_deltaTime;
}