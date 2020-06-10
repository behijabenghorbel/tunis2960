/*!
* @file nour.c
* @author Nour
* @date 10 juin 2020
*/
#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "nour.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran=NULL,*background=NULL;
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    SDL_Event event;
    int continuer = 1;
    personnage p;
int i=0;
//int done = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1048,737, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Test", NULL);
    p.sprite = IMG_Load("c1.png");
    background=IMG_Load("small.png");
    SDL_BlitSurface(background, NULL, ecran, &positionFond);
    SDL_SetColorKey(p.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(p.sprite->format, 0, 0, 255));
    initialiser_personnage(&p);
    while (continuer)
    { //  time () ;
        deplacerperso(&p,&continuer,&event);
        animperso(&i,&event,&p);
        afficher_perso1(p,ecran,background,positionFond);
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(p.sprite);
    SDL_Quit();
    return EXIT_SUCCESS;
}
