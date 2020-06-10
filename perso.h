#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
/*typedef struct vie
{SDL_Surface *vie ;
SDL_Rect posvie ;
} vie ;
typedef struct score
{SDL_Surface *texte;
SDL_Rect textepos ;
} score ;*/
typedef struct
{//int id;
    SDL_Rect position;
    SDL_Surface *sprite;
    //vie v;
    int score;
    double vitesse;
    double acceleration;
    int sol ;
}personnage;
void initialiser_personnage(personnage *p)
{
    p->position.x=20;
    p->position.y=490;
    p->position.w=75;
    p->position.h=80;
  //  p->v.val=100;
    p->acceleration=3;
    p->vitesse=5;
    p->score=0;
    p->sol = 490 ;
   // p->id=1;
    //p->v.o=init(p->v.o,25,25,100,100);
}
void afficher_perso1(personnage p, SDL_Surface *ecran,SDL_Surface *background,SDL_Rect positionFond)
{
    SDL_BlitSurface(background, NULL, ecran, &positionFond);
    SDL_BlitSurface (p.sprite,NULL,ecran,&p.position);


}

/*Uint32 time ()
{ Uint32 dt, t ;
double FPS = 50 ;
 t = SDL_GetTicks() ;
 dt = SDL_GetTicks()-t;
if (1000/FPS>dt)
SDL_Delay(1000/FPS-dt) ;// pour avoir un FPS constant
}*/

/**
* @param i compteur
* @return rien
*/
void animperso (int *i , SDL_Event *event, personnage *p)
{
 char ch[20];
    SDL_PollEvent(event);
    switch(event->type)
    {case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {case SDLK_RIGHT:
                (*i)++;
                if(*i>2)*i=1;
                sprintf(ch,"b%d.png",*i); //appeler l'image
                SDL_Delay(150);
                p->sprite = IMG_Load(ch);// afficher l'image
                break;
            case SDLK_LEFT: (*i)++;
                if(*i>2)*i=1;
                sprintf(ch,"c%d.png",*i);
                SDL_Delay(150);
                p->sprite = IMG_Load(ch);
                break;
        }
        break; }
}
/*void deplacerperso (personnage *p,int *continuer, SDL_Event *event)
{
    SDL_PollEvent(event);
    switch(event->type)
    {
        case SDL_QUIT:
            (*continuer)=0;
            break;
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {
            case SDLK_UP:
                p->position.y= p->position.y-2;
                break;
            case SDLK_DOWN:
                p->position.y+=2;
                break;
            case SDLK_RIGHT:
                p->position.x+=20;
                break;
            case SDLK_LEFT:
                p->position.x-=20;
                break;
        }
            break;
    }
}
*/

void jump (personnage *p)
{ //int gravite = 1 ;

while( p->position.y!= p->sol)
 p->position.y+=p->vitesse;
;}
void deplacerperso (personnage *p,int *continuer, SDL_Event *event)
{
    SDL_PollEvent(event);
    switch(event->type)
    {
        case SDL_QUIT:
            (*continuer)=0;
            break;
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {
            case SDLK_UP:
               if (p->position.y!=450)
                 { p->position.y-=p->vitesse;}
                break;

            case SDLK_RIGHT:
                p->position.x+=p->vitesse+p->acceleration*0.2;
                break;
            case SDLK_LEFT:
                p->position.x-=p->vitesse+p->acceleration*0.2;
                break;
                case SDLK_SPACE:
             p->acceleration = 9;
                p->position.x+=p->vitesse+p->acceleration*0.2;
                break;
        }
            break;
            case SDL_KEYUP :
           if(event->key.keysym.sym==SDLK_UP)
              {
                jump(p);
              }
          /* if(event->key.keysym.sym==SDLK_RIGHT)
             {while ( p->vitesse !=0)
              { p->vitesse--;
              p->position.x+=p->vitesse ;}
              }*/
            break;

    }
}
