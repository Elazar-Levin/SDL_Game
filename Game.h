#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Audio.h"
#include "Object.h"
#include "entity.h"
class Game {
	public:
		Game();
		~Game();
		void loop();
		void update() ;
		void render() ;
		void input() ;
		void draw(Object o);
		void draw(const char* msg,int x,int y ,int r,int g,int b);
	private:
		SDL_Renderer* ren;
		SDL_Window* win;
		bool running;
		int frameCount, timerFPS,lastFrame;
		Entity player;
		TTF_Font *font;
		Audio effect;
		int lWalk,rWalk,uWalk,dWalk;
};

#endif

