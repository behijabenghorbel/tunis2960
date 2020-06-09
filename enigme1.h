#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include<SDL/SDL_getenv.h>
/**
* @struct questionenigme
* @brief struct for question
*/
typedef struct questionenigme
{
SDL_Surface *question; /*!<Surface.*/
SDL_Rect positionquestion; /*!<Rectangle*/
}questionenigme;
/**
* @struct enigme
* @brief struct for enigme
*/
typedef struct enigme
{
SDL_Surface *ecran; /*!<Surface.*/
questionenigme q;
int ouvert;
int resolu;
}enigme;

int afficherquestion(enigme e);
int  resolutionenigme(enigme e);
void liberer(enigme e);

#endif // HEADER_H_INCLUDED
