#include "personality.h"

Personality::Personality()
{
    //Initialize offsets
    x = 0;
    y = 0;

	//Initialize colors
	red = 1.0;
	green = 0.5;
	blue = 0.0;

	//Initialize polygon points
	p1x = 0;
	p1y = 0;

	p2x = 20;
	p2y = 0;

	p3x = 40;
	p3y = 0;

	p4x = 60;
	p4y = 0;

	p5x = 60;
	p5y = 20;

	p6x = 60;
	p6y = 40;

	p7x = 60;
	p7y = 60;

	p8x = 40;
	p8y = 60;

	p9x = 20;
	p9y = 60;

	p10x = 0;
	p10y = 60;

	p11x = 0;
	p11y = 40;

	p12x = 0;
	p12y = 20;

    //Initialize velocity
    xVel = 0;
    yVel = 0;
}

int Personality::getX()
{
	return x;
}

int Personality::getY()
{
	return y;
}

void Personality::setX(int xIn)
{
	x = xIn;
}

void Personality::setY(int yIn)
{
	y = yIn;
}

float getRightmost()
{
	  return 0;
}

float getLeftmost()
{
	return 0;
}

float getHighest()
{
	return 0;
}

float getLowest()
{
	return 0;
}

void Personality::setAll(vector<GLfloat> personalityIn)
{
	red = personalityIn[0];
	green = personalityIn[1];
	blue = personalityIn[2];

	p1x = personalityIn[3];
	p1y = personalityIn[4];

	p2x = personalityIn[5];
	p2y = personalityIn[6];

	p3x = personalityIn[7];
	p3y = personalityIn[8];

	p4x = personalityIn[9];
	p4y = personalityIn[10];

	p5x = personalityIn[11];
	p5y = personalityIn[12];

	p6x = personalityIn[13];
	p6y = personalityIn[14];

	p7x = personalityIn[15];
	p7y = personalityIn[16];

	p8x = personalityIn[17];
	p8y = personalityIn[18];

	p9x = personalityIn[19];
	p9y = personalityIn[20];

	p10x = personalityIn[21];
	p10y = personalityIn[22];

	p11x = personalityIn[23];
	p11y = personalityIn[24];

	p12x = personalityIn[25];
	p12y = personalityIn[26];
}

vector<GLfloat> Personality::getAll()
{
	vector<GLfloat> personality;

	personality.push_back(red);
	personality.push_back(green);
	personality.push_back(blue);

	personality.push_back(p1x);
	personality.push_back(p1y);
	
	personality.push_back(p2x);
	personality.push_back(p2y);
	
	personality.push_back(p3x);
	personality.push_back(p3y);
	
	personality.push_back(p4x);
	personality.push_back(p4y);
	
	personality.push_back(p5x);
	personality.push_back(p5y);
	
	personality.push_back(p6x);
	personality.push_back(p6y);
	
	personality.push_back(p7x);
	personality.push_back(p7y);
	
	personality.push_back(p8x);
	personality.push_back(p8y);
	
	personality.push_back(p9x);
	personality.push_back(p9y);
	
	personality.push_back(p10x);
	personality.push_back(p10y);
	
	personality.push_back(p11x);
	personality.push_back(p11y);
	
	personality.push_back(p12x);
	personality.push_back(p12y);

	return personality;
}

void Personality::changeTowardAverage(vector<GLfloat> averageIn)
{
	vector<GLfloat> oldPersonality = getAll();
	vector<GLfloat> newPersonality;

	//rate at which shape will change
	float rate = 0.001f;
	//the slower rate at which the color will change
	float colorRate = 0.0001f;

	int size = averageIn.size();
	
	//loop through attributes in average
	for(int i = 0; i < size; i++)
	{
		/*	If average's current attribute (i) is less than or greater
			than oldPersonaliy's current attribute (i) add or subtract
			accordingly at rate and assign to newPersonality. Otherwise,
			if oldPersonality already equal to average assign same value
			to newPersonality.
		*/
		//first three attributes are colors
		if(i <= 2)
		{
			if(averageIn[i] > oldPersonality[i])
			{
				newPersonality.push_back(oldPersonality[i] + colorRate);
			}
			else if(averageIn[i] < oldPersonality[i])
			{
				newPersonality.push_back(oldPersonality[i] - colorRate);
			}
			else
			{
				newPersonality.push_back(oldPersonality[i]);
			}
		}
		else
		{
			if(averageIn[i] > oldPersonality[i])
			{
				newPersonality.push_back(oldPersonality[i] + rate);
			}
			else if(averageIn[i] < oldPersonality[i])
			{
				newPersonality.push_back(oldPersonality[i] - rate);
			}
			else
			{
				newPersonality.push_back(oldPersonality[i]);
			}
		}
	}

	setAll(newPersonality);

	oldPersonality.clear();
	newPersonality.clear();
}

void Personality::randomize()
{
	float randNum;
	
	//holder for ramdomized attributes
	vector<GLfloat> newPers;
	
	//randomize colors
	//red
	randNum = getRandNum(3) * 0.1f;
	newPers.push_back(randNum);
	
	//green
	randNum = getRandNum(2) * 0.1f;
	newPers.push_back(randNum);

	//blue
	randNum = getRandNum(3) * 0.1f;
	newPers.push_back(randNum);

	//randomize points
	//p1x
	randNum = getRandNum(0);
	newPers.push_back(randNum);
	//p1y
	randNum = getRandNum(0);
	newPers.push_back(randNum);

	//p2x
	randNum = getRandNum(20);
	newPers.push_back(randNum);
	//p2y
	randNum = getRandNum(0);
	newPers.push_back(randNum);

	//p3x
	randNum = getRandNum(40);
	newPers.push_back(randNum);
	//p3y
	randNum = getRandNum(0);
	newPers.push_back(randNum);

	//p4x
	randNum = getRandNum(60);
	newPers.push_back(randNum);
	//p4y
	randNum = getRandNum(20);
	newPers.push_back(randNum);

	//p5x
	randNum = getRandNum(60);
	newPers.push_back(randNum);
	//p5y
	randNum = getRandNum(40);
	newPers.push_back(randNum);

	//p6x
	randNum = getRandNum(60);
	newPers.push_back(randNum);
	//p6y
	randNum = getRandNum(60);
	newPers.push_back(randNum);

	//p7x
	randNum = getRandNum(40);
	newPers.push_back(randNum);
	//p7y
	randNum = getRandNum(80);
	newPers.push_back(randNum);

	//p8x
	randNum = getRandNum(20);
	newPers.push_back(randNum);
	//p8y
	randNum = getRandNum(80);
	newPers.push_back(randNum);

	//p9x
	randNum = getRandNum(0);
	newPers.push_back(randNum);
	//p9y
	randNum = getRandNum(80);
	newPers.push_back(randNum);

	//p10x
	randNum = getRandNum(-20);
	newPers.push_back(randNum);
	//p10y
	randNum = getRandNum(60);
	newPers.push_back(randNum);

	//p11x
	randNum = getRandNum(-25);
	newPers.push_back(randNum);
	//p11y
	randNum = getRandNum(40);
	newPers.push_back(randNum);

	//p12x
	randNum = getRandNum(-25);
	newPers.push_back(randNum);
	//p12y
	randNum = getRandNum(20);
	newPers.push_back(randNum);

	setAll(newPers);

}

float Personality::getRandNum(int lowNum)
{
	int randNum = 0;

	randNum = (rand() % 20) + lowNum;

	return (float)randNum;
}

void Personality::move()
{
    //Move the square left or right
    x += xVel;

    //Move the square up or down
    y += yVel;
}

void Personality::draw()
{
	//approximate center of polygon
	GLfloat cX = 45;
	GLfloat cY = 45;

    //Move to offset
    glTranslatef((GLfloat)x, (GLfloat)y, 0);

	glScalef(1, 1, 0);

    //Start polygon
    glBegin( GL_TRIANGLES );

        //Set color
        glColor4f(red, green, blue, 1.0);

        //Draw polygon
	    glVertex3f(p1x, p1y, 0);
	    glVertex3f(p2x, p2y, 0);
	    glVertex3f(cX, cY, 0);

	    glVertex3f(p2x, p2y, 0);
	    glVertex3f(p3x, p3y, 0);
	    glVertex3f(cX, cY, 0);

	    glVertex3f(p3x, p3y, 0);
	    glVertex3f(p4x, p4y, 0);
	    glVertex3f(cX, cY, 0);

		glVertex3f(p4x, p4y, 0);
	    glVertex3f(p5x, p5y, 0);
	    glVertex3f(cX, cY, 0);

	    glVertex3f(p5x, p5y, 0);
	    glVertex3f(p6x, p6y, 0);
	    glVertex3f(cX, cY, 0);

		glVertex3f(p6x, p6y, 0);
	    glVertex3f(p7x, p7y, 0);
	    glVertex3f(cX, cY, 0);

	    glVertex3f(p7x, p7y, 0);
	    glVertex3f(p8x, p8y, 0);
	    glVertex3f(cX, cY, 0);

		glVertex3f(p8x, p8y, 0);
	    glVertex3f(p9x, p9y, 0);
	    glVertex3f(cX, cY, 0);

	    glVertex3f(p9x, p9y, 0);
	    glVertex3f(p10x, p10y, 0);
	    glVertex3f(cX, cY, 0);

		glVertex3f(p10x, p10y, 0);
	    glVertex3f(p11x, p11y, 0);
	    glVertex3f(cX, cY, 0);

	    glVertex3f(p11x, p11y, 0);
	    glVertex3f(p12x, p12y, 0);
	    glVertex3f(cX, cY, 0);

		glVertex3f(p12x, p12y, 0);
	    glVertex3f(p1x, p1y, 0);
	    glVertex3f(cX, cY, 0);
		
    //End polygon
    glEnd();

	//set line width
	glLineWidth(0.5f);

	//Start lines
    glBegin( GL_LINES );

        //Set color
        glColor4f(0.5f, 0.3f, 0.0f, 1.0f);

        //Draw lines
	    glVertex3f(p1x, p1y, 0);
	    glVertex3f(p2x, p2y, 0);
	    glVertex3f(p2x, p2y, 0);
	    glVertex3f(p3x, p3y, 0);
	    glVertex3f(p3x, p3y, 0);
	    glVertex3f(p4x, p4y, 0);
	    glVertex3f(p4x, p4y, 0);
	    glVertex3f(p5x, p5y, 0);
	    glVertex3f(p5x, p5y, 0);
	    glVertex3f(p6x, p6y, 0);
	    glVertex3f(p6x, p6y, 0);
	    glVertex3f(p7x, p7y, 0);
	    glVertex3f(p7x, p7y, 0);
	    glVertex3f(p8x, p8y, 0);
	    glVertex3f(p8x, p8y, 0);
	    glVertex3f(p9x, p9y, 0);
	    glVertex3f(p9x, p9y, 0);
	    glVertex3f(p10x, p10y, 0);
	    glVertex3f(p10x, p10y, 0);
	    glVertex3f(p11x, p11y, 0);
	    glVertex3f(p11x, p11y, 0);
	    glVertex3f(p12x, p12y, 0);
	    glVertex3f(p12x, p12y, 0);
		glVertex3f(p1x, p1y, 0);
		
    //End lines
    glEnd();

    //Reset
    glLoadIdentity();
}
