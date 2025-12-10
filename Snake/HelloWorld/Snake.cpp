#include "Snake.h"
#define PLAY_USING_GAMEOBJECT_MANAGER
#define PLAY_IMPLEMENTATION
#include "Play.h"
#include <random>
#include "constants.h"

using namespace std;

//Random Position 
int RandomPos(int min, int max)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max); // distribution in range [min, max]

	return dist6(rng);
}

//Random colore function
Colour RandomColore()
{
	Colour colori[] = { cRed, cGreen, cBlue, cMagenta, cCyan, cYellow, cOrange, cWhite, cGrey };
	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(0, 8);

	return colori[dist(rng)];
}
// This  innisualize random position for apple and i made grid size bigger so it doesn't spawn outside the screen:  
Apple::Apple()
{
	this->pos = Point2D(RandomPos(0, DISPLAY_WIDTH/ GRID_SIZE), RandomPos(0, DISPLAY_HEIGHT/ GRID_SIZE));
}

// It draw the apple
void Apple::DrewApple()
{
	DrawCircle(this->pos* GRID_SIZE, GRID_SIZE/2, cCyan);
}

SnakePart::SnakePart() :pos(Point2D(0.0f, 1.0f)), colour(RandomColore())
{


}
//i'm made this into grid system instead of pixels
void SnakePart::DrewSnakePart()
{
	DrawCircle(pos* GRID_SIZE, GRID_SIZE/2, colour);
}


//It goes throw Array size for snikeparts and  draw them:
void Snake::Drew()
{
	for (int i = 0; i < parts.size; i++)
	{
		parts.data[i].DrewSnakePart();
	}
}

// Setup the moving keys

void Snake::HandleInput()
{
	if (KeyDown(KeyboardButton::KEY_UP))
	{
		dir = UP;
	}
	if (KeyDown(KeyboardButton::KEY_LEFT))
	{
		dir = LEFT_;
	}
	if (KeyDown(KeyboardButton::KEY_DOWN))
	{
		dir = DOWN;
	}
	if (KeyDown(KeyboardButton::KEY_RIGHT))
	{
		dir = RIGHT_;
	}
}
//this moves everypart pne position forword and setup the x and y for the movement
void Snake::Move()
{

	for (int i = parts.size - 1; i > 0; i--)
	{
		parts.data[i].pos = parts.data[i - 1].pos;
	}

	Point2D& head = parts.data[0].pos;
	switch (dir)
	{
	case UP:head.y++; break;
	case DOWN:head.y--; break;
	case LEFT_:head.x--; break;
	case RIGHT_:head.x++; break;
	}

}
//This add part in the back of the snake using pushback funcion i made:
void Snake::AddPart()
{

	SnakePart new_Snakepart;
	parts.pushback(new_Snakepart);
}

bool Snake::Collide(const Apple& apple)
{
	//checks if hea of the snake collides with apple position and if they do it that part in snakes tail:
	if (parts.data[0].pos == apple.pos)
	{
		AddPart();
		return true;
	}
	return false;
}

