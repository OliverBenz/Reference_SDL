#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

void player_create(int x, int y, int w, int h);
void player_draw(SDL_Renderer *renderer);

#endif // PLAYER_H
