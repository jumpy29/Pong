#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

class Entity{
	public:
		Entity(Vector2f p_pos, SDL_Texture* p_tex);
		Entity(Vector2f p_pos, SDL_Texture* p_tex, float p_scaleX, float p_scaleY);
		Vector2f& getPos();
		Vector2f& getPreviousPos();
		SDL_Texture* getTex();
		SDL_Rect getCurrentFrame();
		float getVelocityX();
		float getVelocityY();
		float getScaleX();
		float getScaleY();
		void setVelocityX(float p_velocityX);
		void setVelocityY(float p_velocityY);
		void setPosX(float p_x);
		void setPosY(float p_y);
		void setPreviousPos(Vector2f p_previousPos);
		void updatePos(float p_deltaTime);

	private:
		Vector2f pos;
		Vector2f previousPos;
		SDL_Rect currentFrame;
		SDL_Texture* tex;
		float velocityX;
		float velocityY;
		float scaleX;
		float scaleY;


};