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
#include"enigme.h"
#include<SDL/SDL_getenv.h>
/**
* @brief to initialize and display the enigma e
* @param e the enigme
* @return choix the int
*/
int afficherquestion(enigme e)
{
srand(time(0));
int choix=rand()%7+1;

if(choix==1)
{
e.q.question=IMG_Load("image1.png");
e.q.positionquestion.x=0;
e.q.positionquestion.y=0;
SDL_BlitSurface(e.q.question,NULL,e.ecran,&e.q.positionquestion);
SDL_Flip(e.ecran);

}
else if(choix==2)
{
e.q.question=IMG_Load("image2.png");
e.q.positionquestion.x=0;
e.q.positionquestion.y=0;
SDL_BlitSurface(e.q.question,NULL,e.ecran,&e.q.positionquestion);
SDL_Flip(e.ecran);

}
else if(choix==3)
{
e.q.question=IMG_Load("image3.png");
e.q.positionquestion.x=0;
e.q.positionquestion.y=0;
SDL_BlitSurface(e.q.question,NULL,e.ecran,&e.q.positionquestion);
SDL_Flip(e.ecran);

}
else if(choix==4)
{
e.q.question=IMG_Load("image4.png");
e.q.positionquestion.x=0;
e.q.positionquestion.y=0;
SDL_BlitSurface(e.q.question,NULL,e.ecran,&e.q.positionquestion);
SDL_Flip(e.ecran);

}
else if(choix==5)
{
e.q.question=IMG_Load("image5.png");
e.q.positionquestion.x=0;
e.q.positionquestion.y=0;
SDL_BlitSurface(e.q.question,NULL,e.ecran,&e.q.positionquestion);
SDL_Flip(e.ecran);

}
else if(choix==6)
{
e.q.question=IMG_Load("image6.png");
e.q.positionquestion.x=0;
e.q.positionquestion.y=0;
SDL_BlitSurface(e.q.question,NULL,e.ecran,&e.q.positionquestion);
SDL_Flip(e.ecran);

}
else if(choix==7)
{
e.q.question=IMG_Load("image7.png");
e.q.positionquestion.x=0;
e.q.positionquestion.y=0;
SDL_BlitSurface(e.q.question,NULL,e.ecran,&e.q.positionquestion);
SDL_Flip(e.ecran);

}


return choix;
}



/**
* @brief to solve the enigma e
* @param e the enigme
* @return int
*/

int resolutionenigme(enigme e)
{
SDL_Event event;
int n;
char ch[30];
SDL_Rect positionclic;

n=afficherquestion(e);

SDL_Flip(e.ecran);

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
positionclic.x=event.button.x;
positionclic.y =event.button.y;

FILE* f=NULL;
f=fopen("reponse.txt","r");
int caractereLu, ligne=1;
char position[30];
int ax,ay,bx,by;
if(f!=NULL)
{
rewind(f);
while ((caractereLu!=EOF) && (ligne<n))
{
caractereLu=fgetc(f);
  if (caractereLu=='\n')
ligne++;

}
fscanf(f,"%d %d %d %d",&ax,&bx,&ay,&by);
}
else
printf("not found \n");




if((event.button.x>ax) && (event.button.x<bx) && (event.button.y>ay) && (event.button.y<by))
{
e.resolu=1;
return 0;
}
else
{
e.resolu=0;
return resolutionenigme(e);
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
SDL_FreeSurface(e.q.question);
SDL_Quit();
}
