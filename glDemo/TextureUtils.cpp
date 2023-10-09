
#include "TextureUtils.h"
#include "MyShapes.h"
#include <stdexcept>

using namespace std;


//constructor, setting up simple stuff
TextureUtils::TextureUtils()
{
	FIBITMAP* bitmap = nullptr;
}
	//
	// Setup textures
	//

	// Load image file from disk

	auto textureImageFile = string(textureLocation);
	FIBITMAP* bitmap = FreeImage_Load(FIF_PNG, textureImageFile.c_str(), BMP_DEFAULT);

	if (bitmap) {

		// If image loaded, setup new texture object in OpenGL
		glGenTextures(1, &stdTexture); // can create more than 1!

		if (stdTexture) {

			glBindTexture(GL_TEXTURE_2D, stdTexture);

			// Setup texture image properties
			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				GL_RGBA,
				FreeImage_GetWidth(bitmap),
				FreeImage_GetHeight(bitmap),
				0,
				GL_BGRA,
				GL_UNSIGNED_BYTE,
				FreeImage_GetBits(bitmap));

			// Setup texture filter and wrap properties
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		}

		// Once the texture has been setup, the image data is copied into OpenGL.  We no longer need the originally loaded image
		FreeImage_Unload(bitmap);
	}
	else {

		cout << "Error loading image!" << endl;
	}
