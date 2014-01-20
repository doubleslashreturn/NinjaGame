//INCLUDE HEADER
#include "texture.h"

//NAMESPACE
namespace ftw
{
	//CONSTRUCTORS
	Texture::Texture()
		: tex(NULL), width(0), height(0) { }

	Texture::Texture(const string & filename)
		: tex(NULL), width(0), height(0) { this->Create(filename); }

	//DECONSTRUCTOR
	Texture::~Texture() { this->Destory(); }

	//PROPERTY WIDTH | HEIGHT
	int Texture::GetWidth() const { return width; }
	int Texture::GetHeight() const { return height; }

	//CREATE
	bool Texture::Create(const string & filename)
	{
		//destory current texture if any
		Destory();

		//load surface
		Surface * surf = new Surface(filename);
		tex = surf->CreateTexture();

		//if the texture was not created
		if(tex == NULL)
		{
			//tell the user
			printf("Unable to load Texture! Name: %s Error: %s\n",
				filename.c_str(), SDL_GetError());
			return false;
		}

		//get dimensions
		width = surf->GetWidth();
		height = surf->GetHeight();

		//cleanup
		delete surf;

		//return no error
		return true;
	}

	//DESTORY
	void Texture::Destory()
	{
		if(tex != NULL) SDL_DestroyTexture(tex);
		tex = NULL;
		width = 0;
		height = 0;
	}

	//RENDER
	void Texture::Render(const rect2 & pos, const rect2 & clip)
	{
		if(tex != NULL) SDL_RenderCopy(device, tex, clip.Handle(), pos.Handle());
	}
}