#include "smallRock.h"

#include <iostream>
#include <cstdlib>

using namespace std;

SmallRock::SmallRock(SDL_Renderer* renderer, float x, float y)
{
	active = false;

	speed = 400.0f;

	SDL_Surface* surface = IMG_Load("./Assets/smallrock.png");

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	int w, h;

	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	posRect.w = w;
	posRect.h = h;

	posRect.x = x;
	posRect.y = y;

	pos_X = x;
	pos_Y = y;

	xDir = 0;
	yDir = 0;

	rockAngle = 0.0f;

	//center of the rocks sprite
	rockCenter.x = posRect.w / 2;
	rockCenter.y = posRect.h / 2;


}

void SmallRock::Reposition(float x,float y)
{
	active = true;

	posRect.x = x;
	posRect.y = y;

	pos_X = x;
	pos_Y = y;


	//location on screen 1=left,2=right,3=top,4=bottom
	speed = rand() % 2 + 3;
	speed *= 100;
	
	//number for random up and down
	int upOrDown = rand() % 2 + 1;
	
	int leftOrRight = rand() % 2 + 1;



	if (upOrDown ==1 )//up
	{
		if (leftOrRight == 1)//move left and up
		{
			xDir = -1;
			yDir = -1;
		}
		else//move right and up
		{
			xDir = 1;
			yDir = -2;
		}
	}
	else //2 is down
	{
		if (leftOrRight == 1)//move left and down
		{
			xDir = -1;
			yDir = 1;
		}
		else//move right and down
		{
			xDir = 1;
			yDir = 1;
		}
	}
}


void SmallRock::Deactivate()
{
	active = false;

	posRect.x = -2000;
	posRect.y = -2000;

	pos_X = posRect.x;
	pos_Y = posRect.y;









}















void SmallRock::update(float deltaTime)
{
	if (active)
	{
		//set small rocks new position
		pos_X += (speed * xDir) * deltaTime;
		pos_Y += (speed * yDir) * deltaTime;

		//adjust for precision loss
		posRect.x = (int)(pos_X + 0.5f);
		posRect.y = (int)(pos_Y + 0.5f);

		rockAngle += .1;


		//rock wrapping
		//check to see if rock is off the left of the screen
		if (posRect.x < (0 - posRect.w))
		{
			posRect.x = 1024;
			pos_X = posRect.x;
		}

		//check to see if player is off the right of the screen
		if (posRect.x > 1024)
		{
			posRect.x = (0 - posRect.w);
			pos_X = posRect.x;
		}

		//check to see if player is off the top of the screen
		if (posRect.y < (0 - posRect.w))
		{
			posRect.y = 768;
			pos_Y = posRect.y;
		}

		//check to see if player is off the bottom of the screen
		if (posRect.y > 768)
		{
			posRect.y = (0 - posRect.w);
			pos_Y = posRect.y;
		}
	}

	//end rock wrapping
}

void SmallRock::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, NULL, &posRect, rockAngle, &rockCenter, SDL_FLIP_NONE);
}


SmallRock::~SmallRock()
{
	//SDL_DestroyTexture(texture);
}





