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






























/*
typedef struct carte
{
	SDL_Surface* image=NULL;
	int code;
}carte;
/*typedef struct carte_enigme
{
	carte c1[2][4];
	SDL_Surface* c2[2][4];
	SDL_Rect positioncarte[2][4];
	int etat;
}carte_enigme;

*/
/*
	
int test(enigme* e,catre c1[i],catre c1[a])
{
	if(c1[i].code==c1[a].code)
	{
		SDL_BlitSurface(e->c1[i].carte,NULL,e->ecran,&e->c1[i].position);
		SDL_BlitSurface(e->c1[a].carte,NULL,e->ecran,&e->c1[a].position);
		SDL_Flip(ecran);
		return 1;
	}
	else
	{
		SDL_BlitSurface(e->c[i].carte,NULL,e->ecran,&e->c[i].position);
		SDL_BlitSurface(e->c[a].carte,NULL,e->ecran,&e->c[a].position);
		SDL_Flip(ecran);
		return 0;
	}
	
}
int clic(SDL_Rect positionclic ,enigme* e)
	{
	int i;
		for(i=0;i<8;i++)
		{
			if((positionclic.x>e->c[i].position.x) && (positionclic.x<) && (positionclic.y>e->c[i].position.y) && (positionclic.y<))
			{
				SDL_BlitSurface(e->c1[i].carte,NULL,e->ecran,&e->c[i].position);
				SDL_Flip(ecran);
				return c[i].code;
			}
			else 
				return 0;

*/
