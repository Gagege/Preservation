#ifndef _personality_h_
	#define _personality_h_

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "vector"
#include "time.h"

using namespace std;

class Personality
{
    private:

    //The offsets
    int x, y;
	
	//points of polygon
	GLfloat p1x, p2x, p3x, p4x, p5x, p6x, p7x, p8x, p9x, p10x, p11x, p12x;
	GLfloat p1y, p2y, p3y, p4y, p5y, p6y, p7y, p8y, p9y, p10y, p11y, p12y;
	
	//color of polygon
	GLfloat red, green, blue;

    //The velocity of the square
    int xVel, yVel;

	float getRandNum(int lowNum);

    public:
    //Initializes
    Personality();

	int getX();

	int getY();

	void setX(int xIn);

	void setY(int yIn);
	
	//get the position of the rightmost point of the personality
	float getRightmost();

	//get the position of the leftmost point of the personality
	float getLeftmost();

	//get the position of the highest point of the personality
	float getHighest();

	//get the position of the lowest point of the personality
	float getLowest();
	
	//pass vector of floats in to set all attributes
	void setAll(vector<GLfloat> personalityIn);

	//get all attributes as a vector
	vector<GLfloat> getAll();

	//pass vector of floats in to change attributes slightly toward values in passed vector
	void changeTowardAverage(vector<GLfloat> averageIn);
	
	//randomize all attrubutes. essentially creates a new personality
	void randomize();

    //Moves the square
    void move();

    //Shows the square on the screen
    void draw();
};

#endif
