#include "culture.h"

//temporary please delete
static int x = 0;
static int y = 0;

Culture::Culture()
{
	
}

void Culture::calcAverage()
{
	//number of personalities to loop through
	int numOfPersonalities = personalities.size();

	//number of attributed a personality has
	int numOfAttributes = personalities[0].getAll().size();

	//for calculating average of attributes
	GLfloat sum = 0;
	GLfloat avg = 0;

	//clear average so it can be reused
	average.clear();
	
	//loop through attributes
	for(int i = 0; i < numOfAttributes; i++)
	{
		//loop through personalities
		for(int e = 0; e < numOfPersonalities; e++)
		{
			//get and hold data from personality at index of current loop iteration
			curPersonality = personalities[e].getAll();
			
			//add current personality's current attribute to sum
			sum += curPersonality[i];

			//clear vector so it can hold values of next personality
			curPersonality.clear();
		}
		//find average of attributes
		avg = sum / numOfPersonalities;

		//add current attribute to average
		average.push_back(avg);
			
		//clear sum
		sum = 0;
	}
}

void Culture::normalize()
{
	//number of personalities to loop through
	int numOfPersonalities = personalities.size();
	
	for(int i = 0; i < numOfPersonalities; i++)
	{
		personalities[i].changeTowardAverage(getAverage());
	}
}

//for debugging. remove eventually
vector<GLfloat> Culture::getAverage()
{
	return average;
}

void Culture::addPersonality()
{
	
}

void Culture::birthPersonality()
{
	Personality newPers;

	newPers.randomize();
	
	//temporary please delete
	x += 200;
	y += 200;

	newPers.setX(x);

	newPers.setY(y);
	
	personalities.push_back(newPers);

	calcAverage();
} 

void Culture::calcMotion()
{
	
}

void Culture::calcOutline()
{    
    int curPos = 0;
    leftmost = 0;
    rightmost = 0;
    highest = 0;
    lowest = 0;
     
    //left line
    for(int i = 0; i < personalities.size(); i++)
    {
        curPos = personalities[i].getX();
        
        if(i == 0)
        {
            leftmost = curPos - 25;   
        }
        
        if(curPos < leftmost)
        {
            leftmost = curPos - 25;
        }
    }
    
    //right line
    for(int i = 0; i < personalities.size(); i++)
    {
        curPos = personalities[i].getX();
        
        if(curPos > rightmost)
        {
            rightmost = curPos + 80;
        }
    }
    
    //top line
    for(int i = 0; i < personalities.size(); i++)
    {
        curPos = personalities[i].getY();
        
        if(i == 0)
        {
            highest = curPos;   
        }
        
        if(curPos < highest)
        {
            highest = curPos;
        }
    }
    
    //bottom line
    for(int i = 0; i < personalities.size(); i++)
    {
        curPos = personalities[i].getY();
        
        if(curPos > lowest)
        {
            lowest = curPos + 100;
        }
    }
}

void Culture::move()
{
	
    calcMotion();

	int size = personalities.size();

	//send movements to personalities
	for(int i = 0; i < size; i++)
	{
		personalities[i].move();
	}

	calcOutline();
}

void Culture::draw()
{
	
	int size = personalities.size();

	for(int i = 0; i < size; i++)
	{
		personalities[i].draw();
	}
}

void Culture::drawOutline()
{
    //set line width
	glLineWidth(1.0f);
	
	//Start lines
    glBegin( GL_LINES );

        //Set color
        glColor4f(0.5f, 0.3f, 0.0f, 0.5f);

        //Draw line
	    glVertex3f(leftmost, highest, 0);
	    glVertex3f(leftmost, lowest, 0);
	    glVertex3f(rightmost, highest, 0);
	    glVertex3f(rightmost, lowest, 0);
	    glVertex3f(leftmost, lowest, 0);
	    glVertex3f(rightmost, lowest, 0);
	    glVertex3f(leftmost, highest, 0);
	    glVertex3f(rightmost, highest, 0);
		
    //End lines
    glEnd();

    //Reset
    glLoadIdentity();
    
    //Reset color
        glColor4f(0.5f, 0.3f, 0.0f, 1.0f);
}
