//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "SDL/SDL_ttf.h"

#include "sstream"

#include "personality.h"
#include "culture.h"
#include "timer.h"
#include "text.h"

//Screen attributes
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 60;
int frame;

//Event handler
SDL_Event event;

//font
TTF_Font *font = NULL;

bool init_GL()
{
    //Set clear (background) color
    glClearColor( 0.5f, 0.7f, 1.0f, 1.0f );

	//Antialiasing
	glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);

	//text rendering
	glEnable(GL_TEXTURE_2D);

    //Set projection
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, SCREEN_WIDTH * 1.5, SCREEN_HEIGHT * 1.5, 0, -1, 1 );

    //Initialize modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //If there was any errors
    if( glGetError() != GL_NO_ERROR )
    {
        return false;
    }

    //If everything initialized
    return true;
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        return false;
    }

    //Create Window
    if(SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_OPENGL ) == NULL )
    {
        return false;
    }

    //Initialize OpenGL
    if( init_GL() == false )
    {
        return false;
    }

    //Set caption
    SDL_WM_SetCaption( "Preservation", NULL );

    return true;
}

void clean_up()
{
    //Quit SDL
    SDL_Quit();
}

void print_avg_details(Culture culture)
{
    //Set projection
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, -1, 1 );
    
    //Initialize modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    
	font = TTF_OpenFont( "November.ttf", 12 );
	ostringstream ostr;
	ostr << culture.getAverage()[0];
	string strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 0, 0, "red: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[1];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 15, 0, "green: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[2];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 30, 0, "blue: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[3];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 45, 0, "p1x: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[4];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 60, 0, "p1y: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[5];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 75, 0, "p2x: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[6];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 90, 0, "p2y: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[7];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 105, 0, "p3x: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[8];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 120, 0, "p3y: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[9];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 135, 0, "p4x: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[10];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 150, 0, "p4y: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[11];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 165, 0, "p5x: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[12];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 180, 0, "p5y: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[13];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 195, 0, "p6x: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[14];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 210, 0, "p6y: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[15];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 225, 0, "p7x: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[16];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 240, 0, "p7y: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[17];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 255, 0, "p8x: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[18];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 270, 0, "p8y: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[19];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 285, 0, "p9x: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[20];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 300, 0, "p9y: " + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[21];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 315, 0, "p10x:" + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[22];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 330, 0, "p10y:" + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[23];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 345, 0, "p11x:" + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[24];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 360, 0, "p11y:" + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[25];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 375, 0, "p12x:" + strVal);
	ostr.str("");
	strVal = "";
	ostr << culture.getAverage()[26];
	strVal = ostr.str();
	Text::render_text(font, 100, 255, 255, 0, 390, 0, "p12y:" + strVal);
	
	//Set projection
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, SCREEN_WIDTH * 1.5, SCREEN_HEIGHT * 1.5, 0, -1, 1 );
    
    //Initialize modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

int main( int argc, char *argv[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

	TTF_Init();

	
	//initialize random
	srand((int)time(NULL));

    //The frame rate regulator
    Timer fps;
	Timer update;

	//Start the frame timer
    fps.start();
	update.start();
	//for displaying fps
	string strVal;

	//Wait for user exit
	while( quit == false )
	{

        //While there are events to handle
		while( SDL_PollEvent( &event ) )
		{

			if( event.type == SDL_QUIT )
			{
                quit = true;
            }
		}

		//make personalities in culture slightly more like each other
		culture.normalize();

	    //Move the cultures
	    culture.move();

	    //Clear the screen
	    glClear( GL_COLOR_BUFFER_BIT );

	    //Show the cultures
	    culture.draw();
	    culture.drawOutline();
		
		//print details of average personality to screen
		print_avg_details(culture);

		//print fps to screen
		frame++;
		if(update.get_ticks() > 1000)
		{
			font = TTF_OpenFont( "November.ttf", 12 );
			ostringstream ostr;
			ostr << (int)(frame / (fps.get_ticks() / 1000.0f));
			strVal = ostr.str();
			update.start();
		}
		Text::render_text(font, 100, 255, 255, 750, 0, 0, "fps: " + strVal);

	    //Update screen
	    SDL_GL_SwapBuffers();

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
	}

	//Clean up
	clean_up();

	return 0;
}
