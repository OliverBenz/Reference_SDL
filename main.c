#include <stdlib.h>
#include <error.h>
#include <SDL2/SDL.h>

#include "eventHandler.h"
#include "player.h"

typedef struct app{
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1020

int initSDL(App *app);

int main(int argc, char *argv[]){
	App app;
	if(! initSDL(&app))
		return EXIT_FAILURE;
	
	player_create(0,0,64,64);
	
	SDL_Event event;

	while(1){
		player_draw(app.renderer);

		eventHandler(&event);

		// Render to Screen
		SDL_RenderPresent(app.renderer);

		SDL_Delay(200);
	}

	// Destroy
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();

	return 0;
}

int initSDL(App *app){
	int rendFlag = SDL_RENDERER_ACCELERATED;
	int windFlag = 0;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
		return -1;
	}
	
	app->window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windFlag);
	if(!app->window){
		fprintf(stderr, "Could not open window: %s\n", SDL_GetError());
		return -1;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app->renderer = SDL_CreateRenderer(app->window, -1, rendFlag);	
	if(!app->renderer){
		fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
		return -1;
	}
}
