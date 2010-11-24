#ifndef _text_h_
	#define _text_h_

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "SDL/SDL_ttf.h"
#include "string"

using namespace std;

class Text
{
	public:

		Text();
		
		static void render_text(const TTF_Font *Font, const GLubyte& R, const GLubyte& G, const GLubyte& B, const double& X, const double& Y, const double& Z, const string& messageText);

};
#endif
