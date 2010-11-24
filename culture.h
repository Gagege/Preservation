#ifndef _culture_h_
	#define _culture_h_

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <vector>

#include "personality.h"

using namespace std;

class Culture
{
	private:
		
		//average of all personalities in culture
		vector<GLfloat> average;
		
		//for holding values of a personality while calculating the average personality
		vector<GLfloat> curPersonality;
		
		//collection of all personalities in culture
		vector<Personality> personalities;
		
		//sets a random looping motion for the culture to follow 
		void calcMotion();

		//finds the outline around the culture
		void calcOutline();
		
		//for drawing box around culture
		int leftmost;
		
		int rightmost;
		
		int highest;
		
		int lowest;

	public:

		Culture();
		
		//find the average of all the personalities in this culture
		void calcAverage();
		
		//translate all contained personalities toward average
		void normalize();

		vector<GLfloat> getAverage();

		//add personality from outside
		void addPersonality();
		
		//add personality from inside. "child" is median of two personalities
		void birthPersonality();

		void move();

		void draw();
		
		void drawOutline();
};
#endif
