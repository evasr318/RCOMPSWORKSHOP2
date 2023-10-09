#include "core.h"
#include "MyShapes.h"
#include "TextureUtils.h"
using namespace std;

//draw textured quad 
void drawTexturedQuad(string textureLocation) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, stdTexture);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(-0.5f, 0.5f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(0.5f, 0.5f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(0.5f, -0.5f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(-0.5f, -0.5f);

	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

}

//draw modular regular shape
void drawTexturedModularRegular(int numberOfSides, string textureLocation) {
	const float pi = 3.141593;
	const float thetaStepSize = 2.0f * pi / float(numberOfSides);

	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < numberOfSides; i++) {

		float x = cosf(thetaStepSize * float(i));
		float y = sinf(thetaStepSize * float(i));

		glVertex2f(x, y);
	}

	glEnd();

}