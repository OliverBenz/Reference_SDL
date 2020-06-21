#include "player.h"

SDL_Rect player;

void player_create(int x, int y, int w, int h){
	player.x = x;
	player.y = y;
	player.w = w;
	player.h = h;
}

void player_draw(SDL_Renderer *renderer){
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &player);
}
