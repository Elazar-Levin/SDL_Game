#include "Game.h"
#include<iostream>
Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(360,240,0,&win, &ren);
	SDL_SetWindowTitle(win, "My Game!!!");
	TTF_Init();
	running = true;
	player.setDest(50,50,16*3,32*3);
	player.setSource(0,0,16,32);
	player.setImage("Assets/character.png",ren);
	font = TTF_OpenFont("Assets/Sans.ttf",24);
	effect.load("Assets/random1.wav");
	dWalk = player.createCycle(0,16,32,4,2000);
	rWalk = player.createCycle(1,16,32,4,2000);
	uWalk = player.createCycle(2,16,32,4,2000);
	lWalk = player.createCycle(3,16,32,4,2000);
	player.setCurAnimation(dWalk);
	loop();
}

Game::~Game()
{
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void Game::loop(){
	while(running)
	{
		lastFrame = SDL_GetTicks();
	
		
		
		
		
		render();
		input();
		update();
		
		
	}


}


void Game::render()
{
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.w = 360;
	rect.h = 240;
	SDL_RenderFillRect(ren, &rect);
	draw(player);
	
	//draw("Message", 20, 30, 0, 255, 0);
	
	frameCount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if(timerFPS > 1000/60)
	{
		SDL_Delay(1000/60 - timerFPS);
	}
	
	
	SDL_RenderPresent(ren);
}

void Game::draw(Object o)
{
	SDL_Rect dest = o.getDest();
	SDL_Rect src = o.getSource();
	SDL_RenderCopyEx(ren, o.getTex(), &src, &dest, 0 , NULL, SDL_FLIP_NONE);
}
void Game:: draw(const char* msg,int x,int y ,int r,int g,int b)
{
	SDL_Surface* surf;
	SDL_Texture* tex;
	SDL_Color colour;
	colour.r = r;
	colour.g = g;
	colour.b = b;
	colour.a = 255;
	SDL_Rect rect;
	surf = TTF_RenderText_Solid(font, msg, colour);
	tex = SDL_CreateTextureFromSurface(ren,surf);
	rect.x = x;
	rect.y = y;
	rect.w = surf -> w;
	rect.h = surf -> h;
	SDL_FreeSurface(surf);
	SDL_RenderCopy(ren,tex,NULL,&rect);
	SDL_DestroyTexture(tex);
	
}

void Game::input()
{
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		if(e.type== SDL_QUIT)	running=false;
		if(e.type== SDL_KEYDOWN)
		{
			if(e.key.keysym.sym == SDLK_ESCAPE) running = false;
			if(e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s)
				if(player.getCurAnimation()!=dWalk)
					player.setCurAnimation(dWalk);player.setMoving(true);
			if(e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d)
				if(player.getCurAnimation()!=rWalk)
					player.setCurAnimation(rWalk);player.setMoving(true);
			if(e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)
				if(player.getCurAnimation()!=uWalk)
					player.setCurAnimation(uWalk);player.setMoving(true);
			if(e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a)
				if(player.getCurAnimation()!=lWalk)
					player.setCurAnimation(lWalk);player.setMoving(true);
		}
		if(e.type== SDL_KEYUP)
		{
			if(e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s)
			{
				if(player.getCurAnimation()==dWalk)
				{
					player.setCurAnimation(dWalk);
				}
				player.setMoving(false);
			}
			if(e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d)
			{
				if(player.getCurAnimation()==rWalk)
				{
					player.setCurAnimation(rWalk);
				}
				player.setMoving(false);
			}
			if(e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)
			{
				if(player.getCurAnimation()==uWalk)
				{
					player.setCurAnimation(uWalk);
				}
				player.setMoving(false);
			}
			if(e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a)
			{
				if(player.getCurAnimation()==lWalk)
				{
					player.setCurAnimation(lWalk);
				}
				player.setMoving(false);
			}
		}		
			
		
	}
}

void Game::update()
{
	player.updateAnimation();

}
