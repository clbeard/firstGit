#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


//bool to maintain program loop
bool quit;
//delta time inti- for fram rate
float deltaTime = 0.0f;
int thisTime = 0;
int lastTime = 0;


//vars for players angle
float x, y,oldAngle;
float playerAngle = 0;// 0 controls angle

//for precision loss
float pos_X, pos_Y;

//float for direction
float xDir, xDirOld;
float yDir, yDirOld;

//player speed
float playerSpeed = 400.0f;

//create rectangles for the menu graphics
SDL_Rect playerPos;

//players center point
SDL_Point center;

//bullet info
#include "bullet.h"
#include <vector>

vector<Bullet> bulletList;


//declare sounds
Mix_Chunk* laser;
Mix_Chunk* explosion;

//hold score and level;
int playerScore;
int  gameLevel;






void CreateBullet()
{

	for (int i = 0; i < bulletList.size(); i++)
	{
		if (bulletList[i].active == false)
		{
			//play laser sound
			Mix_PlayChannel(-1, laser, 0);

			bulletList[i].active = true;

			

			bulletList[i].posRect.x = pos_X;

			bulletList[i].posRect.y = pos_Y;

			bulletList[i].pos_X = pos_X;

			bulletList[i].pos_Y = pos_Y;

			bulletList[i].xDir = xDirOld;

			bulletList[i].yDir = yDirOld;

			bulletList[i].Reposition();

			break;


			
		}


	}


}

#include <iostream>
#include <cstdlib>

using namespace std;

//large rocks
#include "largeRock.h"
#include <time.h>
vector<LargeRock> largeRockList;

//Small rocks
#include "smallRock.h"
#include <time.h>
vector<SmallRock> smallRockList;








int main(int argc, char* argv[])
{
	//seed random numbers
	srand(time(NULL));

	SDL_Window* window;			//declare a pointer


	//create a renderer variable
	SDL_Renderer* renderer = NULL;
	
	SDL_Init(SDL_INIT_EVERYTHING); //initialize sdl2

	//create an application with the following setttings
	window = SDL_CreateWindow(
		"Space Rocks",
		SDL_WINDOWPOS_UNDEFINED,//inital x position
		SDL_WINDOWPOS_UNDEFINED,
		1024, //width in px
		768,	//height
		SDL_WINDOW_OPENGL



	);

	//check that the window was successfully created
	if (window == NULL)
	{
		//in the case that the winod couldnt be opened
		printf("Could not create window: %s/n", SDL_GetError());
		return 1;
	}
	
	//create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//background image
	//create
	SDL_Surface* surface = IMG_Load("./Assets/background.png");

	//create bkgd texture
	SDL_Texture* bkgd;
	
	//place surface into the texture
	bkgd = SDL_CreateTextureFromSurface(renderer, surface);

	//free the surface
	SDL_FreeSurface(surface);

	//create rectangle for the menu gaphcis
	SDL_Rect bkgdPos;

	//set bkgd x,y,width,height
	bkgdPos.x = 0;
	bkgdPos.y = 0;
	bkgdPos.w = 1024;
	bkgdPos.h = 768;



	//end background creation end

	//player image ---create


	//create sdl surface
	surface = IMG_Load("./Assets/Player.png");

	//create bkgd texture
	SDL_Texture* player;

	//place surface into the texture
	player = SDL_CreateTextureFromSurface(renderer, surface);

	//free the surface
	SDL_FreeSurface(surface);



	//set bkgdpos x ,y,width,height
	playerPos.x = 1024/2;
	playerPos.y = 768/2;
	playerPos.w = 49;//119
	playerPos.h = 32;//38

		//center of the players sprite
	center.x = playerPos.w / 2;
	center.y = playerPos.h / 2;

	//posx and y for precsion los
	pos_X = playerPos.x;
	pos_Y = playerPos.y;

	//the player graphics is facing right , so the xdirold is set to 1 so bullets go in correct direction
	xDir = 1;//if left -1 ,right 1
	yDir = 0;//up -1, down 1

	//the player graphics is facing right , so the xdirold is set to 1 so bullets go in correct direction
	xDirOld = 1;//if left -1 ,right 1
	yDirOld = 0;//up -1, down 1






	//player image ---create end










	//SDL event to handle input
	SDL_Event event;

	//create out bulletList
	for (int i = 0; i < 10; i++)
	{
		Bullet tempBullet(renderer, -1000.0f, -1000.0f);

		bulletList.push_back(tempBullet);
	}
	
	////create our large rockList
	//for (int i = 0; i < 10; i++)
	//{
	//	LargeRock tempRock(renderer, -1000.0f, -1000.0f);

	//	largeRockList.push_back(tempRock);
	//}

	////create our smallrockList
	//for (int i = 0; i < 2; i++)
	//{
	//	SmallRock tempRock(renderer, -1000.0f, -1000.0f);

	//	smallRockList.push_back(tempRock);
	//}




	//init audio playback
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	//load laser sound
	laser = Mix_LoadWAV("./Assets/laser.wav");

	//load explosion sound
	explosion = Mix_LoadWAV("./Assets/explosion.wav");



	//initialize player score, lives, and font
	playerScore = 0;
	gameLevel = 1;







	//level up 
	//rocks to start game
	int numberOfLargeRocks = 1;
	int numberOfSmallRocks = 2;

	//total number of rocks
	int totalNumberOfRocks = numberOfLargeRocks + numberOfSmallRocks;

	//total rocks destroyed
	int totalRocksDestroyed = 0;

	//create our large rockList
	for (int i = 0; i < numberOfLargeRocks; i++)
	{
		LargeRock tempRock(renderer, -1000.0f, -1000.0f);

		largeRockList.push_back(tempRock);
	}

	//create our smallrockList
	for (int i = 0; i < numberOfSmallRocks; i++)
	{
		SmallRock tempRock(renderer, -1000.0f, -1000.0f);

		smallRockList.push_back(tempRock);
	}


	//activate rocks for level 1
	for (int i = 0; i < numberOfLargeRocks; i++)
	{
		largeRockList[i].Reposition();
	}



	//end level up





cout << "You have reached Game level: " << gameLevel << endl;
	//basic program loop
	while (!quit)
	{
		
		//create deltaTime
		thisTime = SDL_GetTicks();
		deltaTime = (float)(thisTime - lastTime) / 1000;
		lastTime = thisTime;

		//check for input
		if (SDL_PollEvent(&event))
		{

			//close windows by windwos x button
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}

			switch (event.type)
			{
				//look for keypress
				case SDL_KEYUP:

				//check the space bar
				switch (event.key.keysym.sym)
				{
				case SDLK_SPACE:
					CreateBullet();
					break;

			/*	case SDLK_z:
					largeRockList[0].Reposition();
					break;*/
				//case SDLK_s:
				//	for (int i = 0; i < 2; i++)
				//	{
				//		if (smallRockList[i].active == false)
				//		{
				//			smallRockList[i].Reposition(largeRockList[0].posRect.x, largeRockList[0].posRect.y);
				//		}
				//	}
				//	//clear large rock
				//	largeRockList.clear();
				//	
				//	break;

				//case SDLK_a:

				//	//clear large rock 
				//	largeRockList.clear();

				//	//clear small rock 
				//	smallRockList.clear();

				//	for (int i = 0; i < 1; i++)
				//	{
				//		LargeRock tempRock(renderer, -1000.0f, -1000.0f);

				//		largeRockList.push_back(tempRock);
				//	}
				//	for (int i = 0; i < 2; i++)
				//	{
				//		SmallRock tempRock(renderer, -1000.0f, -1000.0f);

				//		smallRockList.push_back(tempRock);
				//	}

				//	break;

				default:
					break;
				}

			}

		}

		// player movement 
		//get the keyboard state
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

		//check which arrows are pressed for xDir
		if (currentKeyStates[SDL_SCANCODE_LEFT])
		{
			//if left button pressed set xdir to -1
			xDir = -1.0f;

		}
		else if (currentKeyStates[SDL_SCANCODE_RIGHT])
		{
			//if right button pressed set xdir to 1
			xDir = 1.0f;
		}
		else
		{
			//if neither pressed
			xDir = 0.0f;

		}

		//check which arrows are pressed for xDir
		if (currentKeyStates[SDL_SCANCODE_UP])
		{
			//if up button pressed, set yDir to -1
			yDir = -1.0f;
		}
		else if (currentKeyStates[SDL_SCANCODE_DOWN])
		{
			//if down button pressed set ydir to 1
			yDir = 1.0f;
		}
		else
		{
			//if neither pressed no movement
			yDir = 0.0f;
		}

		//start update
		//if player moving
		if (xDir != 0 || yDir != 0)
		{
			//get x and y
			x = playerPos.x = xDir;
			y = playerPos.y = yDir;

			//calculate angle
			playerAngle = atan2(yDir, xDir) * 180 / 3.14;

			//update old angle
			oldAngle = playerAngle;

			//update old direction
			xDirOld = xDir;
			yDirOld = yDir;

		}
		else
		{
			//update old angle
			oldAngle = playerAngle;
		}

		//get players new position
		pos_X += (playerSpeed * xDir) * deltaTime;
		pos_Y += (playerSpeed * yDir) * deltaTime;

		//adjust for precision loss
		playerPos.x = (int)(pos_X + 0.5f);
		playerPos.y = (int)(pos_Y + 0.5f);


		//player wrapping
		//check to see if player is off the left of the screen
		if (playerPos.x < (0 - playerPos.w))
		{
			playerPos.x = 1024;
			pos_X = playerPos.x;
		}

		//check to see if player is off the right of the screen
		if (playerPos.x >1024)
		{
			playerPos.x = (0-playerPos.w);
			pos_X = playerPos.x;
		}

		//check to see if player is off the top of the screen
		if (playerPos.y < (0 - playerPos.w))
		{
			playerPos.y = 768;
			pos_Y = playerPos.y;
		}

		//check to see if player is off the bottom of the screen
		if (playerPos.y >768)
		{
			playerPos.y = (0-playerPos.w);
			pos_Y = playerPos.y;
		}

















		//update bullets
		for (int i = 0; i < bulletList.size(); i++)
		{
			if (bulletList[i].active == true)
			{
				bulletList[i].Update(deltaTime);
			}
		}

		//update large rock
		for (int i = 0; i < largeRockList.size(); i++)
		{
			if (largeRockList[i].active == true)
			{
				largeRockList[i].update(deltaTime);
			}
		}

		//update small rock
		for (int i = 0; i < smallRockList.size(); i++)
		{
			if (smallRockList[i].active == true)
			{
				smallRockList[i].update(deltaTime);
			}
		}

		//wrapping collision detection ************

		//check for collision of bullets with large rocks
		//for loop to scroll thorough all the players bullets
		for (int i = 0; i < bulletList.size(); i++)
		{
			if (bulletList[i].active == true)
			{
				//check all large rocks against active bullet
				for (int j = 0; j < largeRockList.size(); j++)
				{
					//see if there is a collision betwenn this bullets and this large rock using sdl
					if (SDL_HasIntersection(&bulletList[i].posRect, &largeRockList[j].posRect))
					{
						//play explosion sound
						Mix_PlayChannel(-1, explosion, 0);


						//level up
						//need the small rocks that are false as the number of small rocksgrows
						int smallRockCounter = 0;


						//end level up


						//create two small rocks
						for (int i=0; i < smallRockList.size(); i++)
						{
							if (smallRockList[i].active == false)
							{
								smallRockList[i].Reposition(largeRockList[j].posRect.x, largeRockList[j].posRect.y);

								//increase smalllRockCounter
								smallRockCounter++;
							}

							//onece we find two inactive rocks we exit loop
							if (smallRockCounter == 2)
							{
								break;
							}


						}



						//reset the enemy
						largeRockList[j].Deactivate();

						//rest the bullet
						bulletList[i].Deactivate();

						playerScore += 50;

						cout << "Player Score: " << playerScore << endl;
						totalRocksDestroyed++;


					}
				}
			}
		}


		//check for collision of bullets with small rocks
		//for loop to scroll through all the players bullets
		for (int i = 0; i < bulletList.size(); i++)
		{
			if (bulletList[i].active == true)
			{
				//check all large rocks against active bullet
				for (int j = 0; j < smallRockList.size(); j++)
				{
					//see if there is a collision betwenn this bullets and this large rock using sdl
					if (SDL_HasIntersection(&bulletList[i].posRect, &smallRockList[j].posRect))
					{

						//play explosion sound
						Mix_PlayChannel(-1, explosion, 0);

						//end level up

						//reset the enemy
						smallRockList[j].Deactivate();

						playerScore += 100;

						cout << "Player Score: " << playerScore << endl;
						//rest the bullet
						bulletList[i].Deactivate();
						//add one to total destroyed
						totalRocksDestroyed++;

						//check to see if all rocks on the level destroyed
						if (totalRocksDestroyed >= totalNumberOfRocks)
						{
							
							gameLevel += 1;
							cout << "you have reached Game Level: " << gameLevel << endl;
							//zero out total rocks destoyred
							totalRocksDestroyed = 0;

							//add rocks to level
							numberOfLargeRocks++;
							numberOfSmallRocks += 2;

							totalNumberOfRocks = numberOfLargeRocks + numberOfSmallRocks;

							//clear large rock list
							largeRockList.clear();

							//clear small rock list
							smallRockList.clear();

							//rebuild rock list with new numbers


							//load large rocks
							for (int i = 0; i < numberOfLargeRocks; i++)
							{
								LargeRock tempRock(renderer, 1000.0f, 1000.0f);

								largeRockList.push_back(tempRock);
							}

							//load small rocks
							for (int i = 0; i < numberOfSmallRocks; i++)
							{
								SmallRock tempRock(renderer, -1000.0f, -1000.0f);

								smallRockList.push_back(tempRock);

							}

							//activate all large rocks for next level 
							for (int i = 0; i < numberOfLargeRocks; i++)
							{
								largeRockList[i].Reposition();
							}

						}
					}
				}
			}
		}
		//end of wrapping collision detection ************



		//end update



		//start draw
		//clear old buffer
		SDL_RenderClear(renderer);

		//draw bkgd
		SDL_RenderCopy(renderer, bkgd, NULL, &bkgdPos);

		//prepare to draw bullets
		for (int i = 0; i < bulletList.size(); i++)
		{
			if (bulletList[i].active == true)
			{
				bulletList[i].Draw(renderer);
			}
		}

		//prepare to draw largerock
		for (int i = 0; i < largeRockList.size(); i++)
		{
			if (largeRockList[i].active == true)
			{
				largeRockList[i].Draw(renderer);
			}
		}

		//prepare to draw smallrock
		for (int i = 0; i < smallRockList.size(); i++)
		{
			if (smallRockList[i].active == true)
			{
				smallRockList[i].Draw(renderer);
			}
		}

		//draw player
		SDL_RenderCopyEx(renderer, player, NULL, &playerPos, playerAngle, &center, SDL_FLIP_NONE);


		//draw new info to the screen'
		SDL_RenderPresent(renderer);



		//end draw
	}//end game loop


		//close and destroy the window
		SDL_DestroyWindow(window);

		//clean up
		SDL_Quit();


	

	return 0;
}
