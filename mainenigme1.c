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
#include"enigme.h"
#include<SDL/SDL_getenv.h>


int main(int argc, char *argv[])
{
enigme e;
int n;
if ( SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n" , SDL_GetError());
return 1 ;
}
e.ecran = SDL_SetVideoMode(1048,737, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);  
Mix_Music *music;
      music = Mix_LoadMUS("music.mp3");
      Mix_PlayMusic(music,0);

n=resolutionenigme(e);

Mix_FreeMusic(music);
liberer(e);

return EXIT_SUCCESS;
}
