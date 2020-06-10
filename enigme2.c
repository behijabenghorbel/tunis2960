/**
* @file enigme.c
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
/**
* @brief to display the background
* @param e the enigme
* @return Nothing
*/

void afficherbackground(enigme e)
{
	e.b.background=IMG_Load("backgroundenigme.png");
	e.b.position.x=0;
	e.b.position.y=0;
	SDL_BlitSurface(e.b.background,NULL,e.ecran,&e.b.position);
	SDL_Flip(e.ecran);
}

/**
* @brief to display the reverse card
* @param e the enigme
* @return Nothing
*/

void affichercarteinverser(enigme e)
{
	
	e.c[0].position.x=120;
	e.c[0].position.y=200;
	e.c[1].position.x=350;
	e.c[1].position.y=200;
	e.c[2].position.x=580;
	e.c[2].position.y=200;
	e.c[3].position.x=800;
	e.c[3].position.y=200;
	e.c[4].position.x=120;
	e.c[4].position.y=450;
	e.c[5].position.x=350;
	e.c[5].position.y=450;
	e.c[6].position.x=580;
	e.c[6].position.y=450;
	e.c[7].position.x=800;
	e.c[7].position.y=450;	

	e.c[0].carte=IMG_Load("carte.png");
	SDL_BlitSurface(e.c[0].carte,NULL,e.ecran,&e.c[0].position);
	e.c[1].carte=IMG_Load("carte.png");
	SDL_BlitSurface(e.c[1].carte,NULL,e.ecran,&e.c[1].position);
	e.c[2].carte=IMG_Load("carte.png");
	SDL_BlitSurface(e.c[2].carte,NULL,e.ecran,&e.c[2].position);
	e.c[3].carte=IMG_Load("carte.png");
	SDL_BlitSurface(e.c[3].carte,NULL,e.ecran,&e.c[3].position);
	e.c[4].carte=IMG_Load("carte.png");
	SDL_BlitSurface(e.c[4].carte,NULL,e.ecran,&e.c[4].position);
	e.c[5].carte=IMG_Load("carte.png");
	SDL_BlitSurface(e.c[5].carte,NULL,e.ecran,&e.c[5].position);
	e.c[6].carte=IMG_Load("carte.png");
	SDL_BlitSurface(e.c[6].carte,NULL,e.ecran,&e.c[6].position);
	e.c[7].carte=IMG_Load("carte.png");
	SDL_BlitSurface(e.c[7].carte,NULL,e.ecran,&e.c[7].position);
	SDL_Flip(e.ecran);	

}

/**
* @brief to solve the enigma e
* @param e the enigme
* @return int
*/
int  ev(enigme e)
{
	int i=8;
	SDL_Event event;

	afficherbackground(e);
	affichercarteinverser(e);

	e.c1[0].position.x=120;
	e.c1[0].position.y=210;
	e.c1[1].position.x=350;
	e.c1[1].position.y=210;
	e.c1[2].position.x=580;
	e.c1[2].position.y=210;
	e.c1[3].position.x=800;
	e.c1[3].position.y=210;
	e.c1[4].position.x=120;
	e.c1[4].position.y=460;
	e.c1[5].position.x=350;
	e.c1[5].position.y=460;
	e.c1[6].position.x=580;
	e.c1[6].position.y=460;
	e.c1[7].position.x=800;
	e.c1[7].position.y=460;	
	e.c1[8].position.x=0;
	e.c1[8].position.y=0;


	e.c1[0].carte=IMG_Load("photo1.png");
	e.c1[0].code=1;
	e.c1[1].carte=IMG_Load("photo2.png");
	e.c1[1].code=2;
	e.c1[2].carte=IMG_Load("photo3.png");
	e.c1[2].code=3;
	e.c1[3].carte=IMG_Load("photo4.png");
	e.c1[3].code=4;
	e.c1[4].carte=IMG_Load("photo2.png");
	e.c1[4].code=2;
	e.c1[5].carte=IMG_Load("photo3.png");
	e.c1[5].code=3;
	e.c1[6].carte=IMG_Load("photo1.png");
	e.c1[6].code=1;
	e.c1[7].carte=IMG_Load("photo4.png");
	e.c1[7].code=4;
	e.c1[8].code=5;
	e.c1[8].carte=IMG_Load("pomme.gif");


	e.c[0].position.x=120;
	e.c[0].position.y=200;
	e.c[1].position.x=350;
	e.c[1].position.y=200;
	e.c[2].position.x=580;
	e.c[2].position.y=200;
	e.c[3].position.x=800;
	e.c[3].position.y=200;
	e.c[4].position.x=120;
	e.c[4].position.y=450;
	e.c[5].position.x=350;
	e.c[5].position.y=450;
	e.c[6].position.x=580;
	e.c[6].position.y=450;
	e.c[7].position.x=800;
	e.c[7].position.y=450;	

	e.c[0].carte=IMG_Load("carte.png");
	e.c[1].carte=IMG_Load("carte.png");
	e.c[2].carte=IMG_Load("carte.png");
	e.c[3].carte=IMG_Load("carte.png");
	e.c[4].carte=IMG_Load("carte.png");
	e.c[5].carte=IMG_Load("carte.png");
	e.c[6].carte=IMG_Load("carte.png");
	e.c[7].carte=IMG_Load("carte.png");

	
	while(1)
	{	
		
		while(SDL_PollEvent(&event)==1)
		{
			switch(event.type)
			{
				case SDL_QUIT:	
				return 0;  
				break;

				case SDL_KEYDOWN:
				if(event.key.keysym.sym==SDLK_ESCAPE)
					return 0;
				break;

				case SDL_MOUSEBUTTONDOWN:
					if (event.button.button ==SDL_BUTTON_LEFT)
					{
						if((event.button.x>0) && (event.button.x<220) && (event.button.y>0) && (event.button.y<250))
						{
							
							SDL_BlitSurface(e.c1[0].carte,NULL,e.ecran,&e.c1[0].position);
							SDL_Flip(e.ecran);
							if(e.c1[0].code!=e.c1[i].code)
							{
								SDL_Delay(1000);
								SDL_BlitSurface(e.c[i].carte,NULL,e.ecran,&e.c[i].position);
								SDL_BlitSurface(e.c[0].carte,NULL,e.ecran,&e.c[0].position);
								SDL_Flip(e.ecran);
										
							}
							else
							{
								SDL_BlitSurface(e.c1[i].carte,NULL,e.ecran,&e.c1[i].position);
								SDL_BlitSurface(e.c1[0].carte,NULL,e.ecran,&e.c1[0].position);
								SDL_Flip(e.ecran);
									
							}
							i=0;
							

						}
						else if((event.button.x>350) && (event.button.x<450) && (event.button.y>200) && (event.button.y<250))
						{
							SDL_BlitSurface(e.c1[1].carte,NULL,e.ecran,&e.c1[1].position);
							SDL_Flip(e.ecran);
							
							
							if(e.c1[1].code!=e.c1[i].code)
							{
								SDL_Delay(1000);
								SDL_BlitSurface(e.c[i].carte,NULL,e.ecran,&e.c[i].position);
								SDL_BlitSurface(e.c[1].carte,NULL,e.ecran,&e.c[1].position);	
								SDL_Flip(e.ecran);
										
							}
							else
							{
								SDL_BlitSurface(e.c1[i].carte,NULL,e.ecran,&e.c1[i].position);
								SDL_BlitSurface(e.c1[1].carte,NULL,e.ecran,&e.c1[1].position);
								SDL_Flip(e.ecran);
									
							}
							i=1;
							

						}
						else if((event.button.x>580) && (event.button.x<680) && (event.button.y>200) && (event.button.y<250))
						{
							SDL_BlitSurface(e.c1[2].carte,NULL,e.ecran,&e.c1[2].position);
							SDL_Flip(e.ecran);
							
							if(e.c1[2].code!=e.c1[i].code)
							{
								SDL_Delay(1000);
								SDL_BlitSurface(e.c[i].carte,NULL,e.ecran,&e.c[i].position);
								SDL_BlitSurface(e.c[2].carte,NULL,e.ecran,&e.c[2].position);
								SDL_Flip(e.ecran);
										
							}
							else
							{
								SDL_BlitSurface(e.c1[i].carte,NULL,e.ecran,&e.c1[i].position);
								SDL_BlitSurface(e.c1[2].carte,NULL,e.ecran,&e.c1[2].position);
								SDL_Flip(e.ecran);
									
							}
							i=2;


						}
						else if((event.button.x>800) && (event.button.x<900) && (event.button.y>200) && (event.button.y<250))
						{
							SDL_BlitSurface(e.c1[3].carte,NULL,e.ecran,&e.c1[3].position);
							SDL_Flip(e.ecran);
							

							if(e.c1[3].code!=e.c1[i].code)
							{
								SDL_Delay(1000);
								SDL_BlitSurface(e.c[i].carte,NULL,e.ecran,&e.c[i].position);
								SDL_BlitSurface(e.c[3].carte,NULL,e.ecran,&e.c[3].position);
								SDL_Flip(e.ecran);
										
							}
							else
							{
								SDL_BlitSurface(e.c1[i].carte,NULL,e.ecran,&e.c1[i].position);
								SDL_BlitSurface(e.c1[3].carte,NULL,e.ecran,&e.c1[3].position);
								SDL_Flip(e.ecran);
									
							}
							i=3;
							

						}
						else if((event.button.x>150) && (event.button.x<250) && (event.button.y>450) && (event.button.y<600))
						{
							SDL_BlitSurface(e.c1[4].carte,NULL,e.ecran,&e.c1[4].position);
							SDL_Flip(e.ecran);
							

							if(e.c1[4].code!=e.c1[i].code)
							{	
								SDL_Delay(1000);
								SDL_BlitSurface(e.c[i].carte,NULL,e.ecran,&e.c[i].position);
								SDL_BlitSurface(e.c[4].carte,NULL,e.ecran,&e.c[4].position);
								SDL_Flip(e.ecran);
										
							}
							else
							{
								SDL_BlitSurface(e.c1[i].carte,NULL,e.ecran,&e.c1[i].position);
								SDL_BlitSurface(e.c1[4].carte,NULL,e.ecran,&e.c1[4].position);
								SDL_Flip(e.ecran);
									
							}
							i=4;

						}
						else if((event.button.x>350) && (event.button.x<450) && (event.button.y>450) && (event.button.y<600))
						{
							SDL_BlitSurface(e.c1[5].carte,NULL,e.ecran,&e.c1[5].position);
							SDL_Flip(e.ecran);
							
							if(e.c1[5].code!=e.c1[i].code)
							{	SDL_Delay(1000);
								SDL_BlitSurface(e.c[i].carte,NULL,e.ecran,&e.c[i].position);
								SDL_BlitSurface(e.c[5].carte,NULL,e.ecran,&e.c[5].position);
								SDL_Flip(e.ecran);
										
							}
							else
							{
								SDL_BlitSurface(e.c1[i].carte,NULL,e.ecran,&e.c1[i].position);
								SDL_BlitSurface(e.c1[5].carte,NULL,e.ecran,&e.c1[5].position);
								SDL_Flip(e.ecran);
									
							}
							i=5;

						}
						else if((event.button.x>580) && (event.button.x<680) && (event.button.y>450) && (event.button.y<600))
						{
							SDL_BlitSurface(e.c1[6].carte,NULL,e.ecran,&e.c1[6].position);
							SDL_Flip(e.ecran);
							if(e.c1[6].code!=e.c1[i].code)
							{
								SDL_Delay(1000);
								SDL_BlitSurface(e.c[i].carte,NULL,e.ecran,&e.c[i].position);
								SDL_BlitSurface(e.c[6].carte,NULL,e.ecran,&e.c[6].position);
								SDL_Flip(e.ecran);
										
							}
							else
							{
								SDL_BlitSurface(e.c1[i].carte,NULL,e.ecran,&e.c1[i].position);
								SDL_BlitSurface(e.c1[6].carte,NULL,e.ecran,&e.c1[6].position);
								SDL_Flip(e.ecran);
									
							}
							i=6;

						}
						else if((event.button.x>800) && (event.button.x<900) && (event.button.y>450) && (event.button.y<600))
						{
							SDL_BlitSurface(e.c1[7].carte,NULL,e.ecran,&e.c1[7].position);
							SDL_Flip(e.ecran);
							if(e.c1[7].code!=e.c1[i].code)
							{
								SDL_Delay(1000);
								SDL_BlitSurface(e.c[i].carte,NULL,e.ecran,&e.c[i].position);
								SDL_BlitSurface(e.c[7].carte,NULL,e.ecran,&e.c[7].position);
								SDL_Flip(e.ecran);
										
							}
							else
							{
								SDL_BlitSurface(e.c1[i].carte,NULL,e.ecran,&e.c1[i].position);
								SDL_BlitSurface(e.c1[7].carte,NULL,e.ecran,&e.c1[7].position);
								SDL_Flip(e.ecran);
								
							}
							i=7;

						}	
						
					}
				}
			}
	}		
}


/**
* @brief to free the surface
* @param e the enigme
* @return Nothing
*/					

void liberer(enigme e)
{
	SDL_FreeSurface(e.b.background);
	SDL_FreeSurface(e.c[0].carte);
	SDL_FreeSurface(e.c[1].carte);
	SDL_FreeSurface(e.c[2].carte);
	SDL_FreeSurface(e.c[3].carte);
	SDL_FreeSurface(e.c[4].carte);
	SDL_FreeSurface(e.c[5].carte);
	SDL_FreeSurface(e.c[6].carte);
	SDL_FreeSurface(e.c[7].carte);
	SDL_FreeSurface(e.c1[0].carte);
	SDL_FreeSurface(e.c1[1].carte);
	SDL_FreeSurface(e.c1[2].carte);
	SDL_FreeSurface(e.c1[3].carte);
	SDL_FreeSurface(e.c1[4].carte);
	SDL_FreeSurface(e.c1[5].carte);
	SDL_FreeSurface(e.c1[6].carte);
	SDL_FreeSurface(e.c1[7].carte);
			
	
	SDL_Quit();
}
