//INCLUDE HEADER
#include "sprite.h"

//NAMESPACE
namespace ftw
{
	//CONSTRUCTORS
	Sprite::Sprite()
		: pos(rect2()), clip(rect2()), tex(NULL) { }

	Sprite::Sprite(const rect2 & pos)
		: pos(pos), clip(rect2()), tex(NULL) { }

	Sprite::Sprite(const rect2 & pos, const rect2 & clip)
		: pos(pos), clip(clip), tex(NULL) { }

	Sprite::Sprite(const rect2 & pos, const rect2 & clip, const string & tex)
		: pos(pos), clip(clip), tex(new Texture(tex)) { }

	//DECONSTRUCTOR
	Sprite::~Sprite()
	{
		if(tex != NULL) delete tex;
		tex = NULL;
	}

	//RENDER
	void Sprite::Render() { tex->Render(pos, clip); }
}