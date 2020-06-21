#include "eventHandler.h"

void eventHandler(SDL_Event *event){
	while(SDL_PollEvent(event)){
		switch(event->type){
			case SDL_QUIT:
				exit(0);
				break;
			case SDL_KEYDOWN:
				keyboardHandler(event->key.keysym.scancode);
				break;
			default:
				break;
		}
	}
}

void keyboardHandler(SDL_Scancode sc){
	switch(sc){
		case SDL_SCANCODE_ESCAPE:
			exit(0);
			break;
		default:
			break;
	}
}
