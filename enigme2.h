#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
/**
* @struct backgroundenigme
* @brief struct for background
*/
typedef struct backgroundenigme
{
	SDL_Surface* background;
	SDL_Rect position;
}backgroundenigme;
/**
* @struct carteenigme
* @brief struct for card
*/
typedef struct carteenigme
{
	SDL_Surface* carte;
	SDL_Rect position;
	int code;
}carteenigme;
/**
* @struct enigme
* @brief struct for enigme
*/
typedef struct enigme
{
	SDL_Surface* ecran;
	backgroundenigme b;
	carteenigme c[8];
	carteenigme c1[9];
	int ouvert;
	int resolu;
}enigme;


void afficherbackground(enigme e);
void affichercarteinverser(enigme e);
int  ev(enigme e);
void liberer(enigme e);
#endif // HEADER_H_INCLUDED
