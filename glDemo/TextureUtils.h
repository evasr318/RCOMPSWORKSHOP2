#pragma once

// These libraries are needed to link the program (Visual Studio specific)
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"lib\\glfw3.lib")
#pragma comment(lib,"lib\\glew32s.lib")
#pragma comment(lib,"lib\\glew32.lib")
#pragma comment(lib,"lib\\FreeImage.lib")

#define GLEW_STATIC
#include "GL/glew.h" 
#include "GLFW/glfw3.h"
#include "FreeImage\\FreeImage.h"
#include <string>

class TextureUtils
{

	GLuint* stdTexture;



public:
	TextureUtils();
	virtual ~TextureUtils();

	virtual void init()


};