#include "snake.h"
#include "constants.h"

Snake snake;
Apple apple;

using namespace Play;
int Frame = 0;

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	
	
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
	snake.AddPart();
	
	

	

	
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime )
{
	
	Play::ClearDrawingBuffer( Play::cBlack );
	snake.HandleInput();
	if ( Frame % 10 == 0) 
	{
		snake.Move();
	}
	
	snake.Drew();
	
	apple.DrewApple();
	if (snake.Collide(apple))
	{
		apple = Apple();   // respawn apple if snake colidde with the apple
	}
	

	Play::PresentDrawingBuffer();
	Frame++;
	
	return Play::KeyDown( KEY_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}
