#include "largeRock.h"

#include <iostream>
#include <cstdlib>

using namespace std;

LargeRock::LargeRock(SDL_Renderer* renderer, float x, float y)
{
	active = false;

	speed = 200.0f;

	SDL_Surface* surface = IMG_Load("./Assets/bigrock.png");

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

void LargeRock::Deactivate()
{
	active = false;

	posRect.x = -2000;
	posRect.y = -2000;

	pos_X = posRect.x;
	pos_Y = posRect.y;





}




void LargeRock::Reposition()
{
	active = true;

	//location on screen 1=left,2=right,3=top,4=bottom
	int location = rand() % 4 + 1;

	///movement of astroid 1=left and right 2= up or down
	int direction = rand() % 2 + 1;

	if(location ==1)//left
	{
		//off screen to left
		posRect.x = -posRect.w;
		pos_X = posRect.x;

		//random from top to bottom
		//number for random up and down
		int bottomofScreen = 768 - (posRect.h * 2);
		posRect.y = rand() % bottomofScreen + posRect.h;
		pos_Y = posRect.y;

		if (direction == 1)
		{
			xDir = 1;
			yDir = 1;
		}
		else
		{
			xDir = 1;
			yDir = -1;
		}
	}
	 else if (location == 2)//right
	{
		//off screen to right
		posRect.x = 1024;
		pos_X = posRect.x;

		//random from top to bottom
		//number for random up and down
		int bottomofScreen = 768 - (posRect.h * 2);
		posRect.y = rand() % bottomofScreen + posRect.h;
		pos_Y = posRect.y;

		if (direction == 1)
		{
			xDir = -1;
			yDir = -1;
		}
		else
		{
			xDir = -1;
			yDir = 1;
		}
	}
	else if (location == 3)//top
	{

		//off screen top
		posRect.y = -posRect.h;
		pos_Y = posRect.y;

		//random from left to right
		//number for random left or right
		int sideofScreen = 1024 - (posRect.w * 2);
		posRect.x = rand() % sideofScreen + posRect.w;
		pos_X = posRect.x;

		if (direction == 1)
		{
			xDir = -1;
			yDir = 1;
		}
		else
		{
			xDir = 1;
			yDir = 1;
		}
	}
	else if (location == 4)//bottom
	{
		//off screen bottom
		posRect.y = 768;
		pos_Y = posRect.y;

		//random from left to right
		//number for random left or right
		int sideofScreen = 1024 - (posRect.w * 2);
		posRect.x = rand() % sideofScreen + posRect.w;
		pos_X = posRect.x;

		if (direction == 1)
		{
			xDir = -1;
			yDir = -1;
		}
		else
		{
			xDir = 1;
			yDir = -1;
		}

	}
}





void LargeRock::update(float deltaTime)
{
	if (active)
	{
		//get large rocks new position
		pos_X += (speed * xDir) * deltaTime;
		pos_Y += (speed * yDir) * deltaTime;

		//adjuest for precision loss
		posRect.x = (int)(pos_X + 0.5f);
		posRect.y = (int)(pos_Y + 0.5f);

		rockAngle += .1;

		//wrapping


		//end of wrapping

			//player wrapping
		//check to see if player is off the left of the screen
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
}

void LargeRock::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, NULL, &posRect, rockAngle, &rockCenter, SDL_FLIP_NONE);
}

LargeRock::~LargeRock()
{
	//SDL_DestroyTexture(texture);
}
