//INCLUDE HEADER
#include "surface.h"

//NAMESPACE
namespace ftw
{
	//CONSTRUCTORS
	Surface::Surface()
		: surf(NULL), width(0), height(0) { }


	Surface::Surface(const string & filename)
		:surf(NULL), width(0), height(0) { this->Create(filename); }

	//DECONSTRUCTOR
	Surface::~Surface() { this->Destory(); }

	//PROPERTY WIDTH | HEIGHT
	int Surface::GetWidth() const { return width; }
	int Surface::GetHeight() const { return height; }

	//CREATE
	bool Surface::Create(const string & filename)
	{
		//destory old surface if any
		Destory();

		//load in new surface
		surf = IMG_Load(filename.c_str());

		//if surface was not created
		if(surf == NULL)
		{
			//tell the user
			printf("Unable to load Surface! Name: %s Error: %s\n",
				filename.c_str(), SDL_GetError());
			return false;
		}

		//set color key for blit aplha (255, 0, 255)
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 0xFF, 0, 0xFF));

		//set dimensions
		width = surf->w;
		height = surf->h;

		//return no error
		return true;
	}

	//CREATE TEXTURE
	SDL_Texture * Surface::CreateTexture()
	{
		return surf != NULL ? SDL_CreateTextureFromSurface(device, surf) : NULL;
	}

	//DESTORY
	void Surface::Destory()
	{
		if(surf != NULL) SDL_FreeSurface(surf);
		surf = NULL;
		width = height = 0;
	}

	//RENDER
	void Surface::Render()
	{
		//if we need it we can implement it later
		//otherwise just use texture.
	}
}