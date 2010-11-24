#ifndef _culturemanager_h_
	#define _culturemanager_h_

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <vector>

#include "culture.h"
#include "personality.h"

using namespace std;

class CultureManager
{
	private:

		vector<Culture> cultures;

		vector<Personality> outsiders;

	public:

		CultureManager();
		
		void normalize();

		void move();

		void draw();

};
#endif
