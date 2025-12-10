#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"


using namespace Play;


enum Heading
{
	
	UP, 
	DOWN, 
	LEFT_,        // This keys when moving the snake
	RIGHT_
};

// Randommas the position with inne the value i'm give later 
int RandomPos(int min, int max);


//Randomas the coloure 
Colour RandomColore();


struct Apple

{
	
	Point2D pos;

	Apple();

	void DrewApple();
	
};


struct SnakePart
{
	Point2D pos;
	Colour colour;
	


	SnakePart();
	
	void DrewSnakePart();
	

};

template<typename T>
struct Array
{
	T* data;
	int size;
	int length;

	
	Array() : data(new T[10]), size(0), length(10) {
	}

	~Array() {
		if (data)
		{
			delete[] data;
		}
	}
	//  This dynamic array that double the size of the old array when it get full and makes new one 
	void pushback(T& integer)
	{
		int new_length = size + 1;
		if (new_length > length)
		{
			new_length = new_length * 3 / 2;
			T* new_data = new T[new_length];
			memcpy(new_data, data, length * sizeof(T));
			delete[] data;
			data = new_data;
		}
		data[size++] = integer;
	}


};



struct Snake
{
	Heading dir;
	Array<SnakePart>parts;
	Point2D lastTail;

	void Drew();
	

	void HandleInput();

	void Move();

	void AddPart();


	bool Collide(const Apple& apple);
	
};
