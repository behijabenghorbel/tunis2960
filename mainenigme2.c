/**
* @file main.c
*/


#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include<SDL/SDL_getenv.h>
#include"enigme.h"

int main(int argc, char **argv[])
{	
	enigme e;
	int n;
	if ( SDL_Init(SDL_INIT_VIDEO)!=0) 
	{
		printf("Unable to initialize SDL: %s\n" , SDL_GetError());
		return 1 ; 
	}
	e.ecran = SDL_SetVideoMode(1048,737, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	n=ev(e);

	liberer(e);

return EXIT_SUCCESS;
}
