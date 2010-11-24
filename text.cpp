#include "text.h"

Text::Text()
{

}

void Text::render_text(const TTF_Font *Font, const GLubyte& R, const GLubyte& G, const GLubyte& B, const double& X, const double& Y, const double& Z, const string& messageText)
{
	/*Create some variables.*/
	SDL_Color Color = {R, G, B};
	SDL_Surface *Message = TTF_RenderText_Blended(const_cast<TTF_Font*>(Font), messageText.c_str(), Color);
	unsigned Texture = 0;
 
	/*Generate an OpenGL 2D texture from the SDL_Surface*.*/
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
 
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Message->w, Message->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, Message->pixels);
 
	/*Draw this texture on a quad with the given xyz coordinates.*/
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(X, Y, Z);
		glTexCoord2d(1, 0); glVertex3d(X+Message->w, Y, Z);
		glTexCoord2d(1, 1); glVertex3d(X+Message->w, Y+Message->h, Z);
		glTexCoord2d(0, 1); glVertex3d(X, Y+Message->h, Z);
	glEnd();
 
	/*Clean up.*/
	glDeleteTextures(1, &Texture);
	SDL_FreeSurface(Message);
}