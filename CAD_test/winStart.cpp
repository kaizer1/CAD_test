/* Sergei Loskutnikov © */

#include <windows.h>
#include "lDefine.h"

import std;
import lMath;
import lOpenGL;
import lWinApi;


using namespace losMath;
using namespace losGraphics;
using namespace losWin;

static constexpr auto VERTEX_OFFSET = 0;
static constexpr unsigned int emptyProgram = 0;

myUnsignedInt myVAO;
myUnsignedInt firstProgram;
myUnsignedInt programRectangle;
myUnsignedInt VAORectangle;
myUnsignedInt matrixNormalUniform;
myUnsignedInt matrixModelViewUniform;
myUnsignedInt uniformIndexLightLos;


float matrixButton[4][4];

inline void RenderMainL();
inline void BuildprogramsGL();


void CallbackCallLoadOpenGLFunctions() {
	CallingLoadingExtension();
}


constexpr int width = 860;
constexpr int hwgih = 520;
float BearRotate = 0.0f;
myUnsignedInt matrixDrawRectangle;


auto finished = false;
inline constexpr float FRAMES_PER_SECOND = 60.0f;

bool frameReady = false;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int  nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	auto callBackFunctionOpenGL = std::bind_front(CallbackCallLoadOpenGLFunctions);
	auto callbackBuildGL = std::bind_front(BuildprogramsGL);
	MyRegisterClass(hInstance, callBackFunctionOpenGL, callbackBuildGL);


	if (!InitInstance(hInstance, nCmdShow, width, hwgih))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(109));
	MSG msg;


	while (!finished) {
		DWORD currentTick = GetTickCount();
		DWORD endTick = currentTick + 1000 / FRAMES_PER_SECOND;

		while (currentTick < endTick) {
			if (PeekMessage(&msg, losWin::returnHWND(), 0, 0, PM_REMOVE)) {
				if (WM_QUIT == msg.message) {
					finished = true;
					break;
				}
				else {
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				currentTick = GetTickCount();
			}
			else {
				break;
			}
		}
		RenderMainL();
	}
	return (int)msg.wParam;
}


void BuildprogramsGL() {


	glGenVertexArraysm(1, &myVAO);
	glBindVertexArraym(myVAO);

	firstProgram = glCreateProgram();
	loadShaderFromFiles(firstProgram, 0x8B31, "aShader.vert");
	loadShaderFromFiles(firstProgram, 0x8B30, "bShader.frag");
	linkAndValidateProgram(firstProgram);


	glUseProgramm(firstProgram);

	glBindAttribLocationm(firstProgram, 0, "aVertex");
	glBindAttribLocationm(firstProgram, 1, "bColor");




	// uniform 
	matrixDrawRectangle = glGetUniformLocationm(firstProgram, "matrixDraw");
	matrixNormalUniform = glGetUniformLocationm(firstProgram, "normalMatrix");
	matrixModelViewUniform = glGetUniformLocationm(firstProgram, "modelViewMatrix");


	// Block uniform 
	uniformIndexLightLos = glGetUniformBlockIndexm(firstProgram, "LightInfoLos");

	if (uniformIndexLightLos == -1) {
		LosOutputStringConvert(" return minus in uniform index Light ");
	}
	else {
		LosOutputStringConvert(" ok load my uniform size s ");
	}

	int blockSizes;
	glGetActiveUniformBlockivm(firstProgram, uniformIndexLightLos, glUniformBlockDataSize, &blockSizes);
	LosOutputStringConvert(" my sizes Block= ", blockSizes);

	sByte* blockBuffer = (sByte*)malloc(blockSizes);
	const defaultChar* names[] = { "Position", "Intensity" };
	const defaultChar* names2[] = { "InnerColor", "OuterColor", "RadiusInner", "RadiusOuter" };

	unsigned int indices[4];
	glGetUniformIndicesl(firstProgram, 4, names2, indices);
	LosOutputStringConvert(" my indices number 1 ", indices[0]);
	int offset[4];

	glGetActiveUniformsivm(firstProgram, 4, indices, glUniformOffset, offset);
	LosOutputStringConvert(" my offset number 1 ", offset[0]);

	float positionLight[] = { 0.94f, 0.64f, 0.64f, 0.0f };
	float intencityLight[] = { 1.0f, 1.0f, 0.75f, 1.0f };
	float innerRadius = 0.25f;
	float outerRadius = 0.45f;

	memcpy(blockBuffer + offset[0], positionLight, 4 * sizeof(float));
	memcpy(blockBuffer + offset[1], intencityLight, 4 * sizeof(float));
	memcpy(blockBuffer + offset[2], &innerRadius, sizeof(float));
	memcpy(blockBuffer + offset[3], &outerRadius, sizeof(float));

	checkErrorLos(4);
	if (firstProgram == -1) {
		LosOutputStringConvert("not compile program ");
	}


	GLuint b1, b2, b3;
	GLuint shot;
	glGenBuffersm(1, &b1);
	glGenBuffersm(1, &b2);
	glGenBuffersm(1, &shot);

	GLfloat vertexM1[8] = {
			1.0f,1.0f,
			0.0f,1.0f,
			1.0f,0.0f,
			0.0f,0.0f
	};


	GLfloat vertexM2[12] = {
			0.8f,0.7f, 0.0f,
			0.5f,0.4f, 0.0f,
			0.1f,0.9f, 1.0f,
			 0.8f,0.2f, 0.895f
	};



	glBindBufferm(glArrayBuf, b1);
	{
		glBufferDatam(glArrayBuf, 8 * sizeof(GLfloat), vertexM1, glStatDraw);
		glVertexAttribPointerm(0, 2, glFloat, GLFALSE, 0, (const void*)VERTEX_OFFSET);
		glEnableVertexAttribArraym(0);
	}

	glBindBufferm(glArrayBuf, b2);
	{
		glBufferDatam(glArrayBuf, 12 * sizeof(GLfloat), vertexM2, glStatDraw);
		glVertexAttribPointerm(1, 3, glFloat, GLFALSE, 0, (const void*)VERTEX_OFFSET);
		glEnableVertexAttribArraym(1);
	}





	GLuint uboHandle;
	glGenBuffersm(1, &uboHandle);
	glBindBufferm(glUniformBuffer, uboHandle);
	glBufferDatam(glUniformBuffer, blockSizes, blockBuffer, glDynamicDraw);
	glBindBufferBasem(glUniformBuffer, uniformIndexLightLos, uboHandle);



	GLushort myShot[8] = {
	   0, 1, 2, 3, 4
	};

	glBindBufferm(glElementArrayBuffer, shot);
	glBufferDatam(glElementArrayBuffer, 8 * sizeof(glUnsignedShort), myShot, 0x88E4);

	glUseProgramm(emptyProgram);
	glBindVertexArraym(emptyProgram);


	checkErrorLos(2);



	// 		glUseProgramm(programRectangle);
	//glBindVertexArraym(VAORectangle);

	//auto myvalues = std::clamp(0.1f, 0.0f, 1.0f);
	//LosOutputStringConvert(" my values CLAMP ", myvalues);


   //GLuint idTexture;
   ////loadASTC("Diffuse.astc", &idTexture);
   //checkErrorLos(6);
   ////LoadingStaticNormalsExist(idTexture, "hammerOk1.bin", false);
   //// load shader .glsl 

   //LosOutputStringConvert("start loading building program", 11);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			if (i == j) {
				matrixButton[i][j] = 1.0f;
			}
			else {
				matrixButton[i][j] = 0.0f;
			}
		}
	}
	matrixButton[3][3] = 1.0f;

	frameReady = true;
}



constexpr inline static float contsRBlack = 10.0f / 255.0f;


inline void RenderMainL() {



	if (frameReady) {



		callClear(contsRBlack, 0.0f, 0.0f, 1.0f);

		//losWin::LosOutputStringConvert("render game ");


		lm44 pers = perspectiveLosRithg<float>(45.0f, width / hwgih, 0.1f, 100.f);



		const lv3 eye = lv3{ 3.5f, 3.1f, 2.2f };  // firstCamera
		const lv3 cent = lv3{ 0.2f, 0.1f, 0.0f };

		//}

		lv3 eye2 = lv3{ 0.2f, 1.3f, 1.9f };  // secondsCamera
		lv3 eye3 = lv3{ -2.6f, 2.2f, -0.4f };  // thirdsCamera
		//LosVector3  = LosVector3 {BearTransX, 0.0f, BearTransZ}; // was 0.4f, 0.0f, 0.0f
		lv3 up{ 0, 1, 0 };
		lm44 er = identity();

		lm44 LookAt = LookAt_RightLos(eye, cent, up, er);
		lm44 LosMat = identity();
		lm44 finalMM = pers * LookAt * LosMat;
		lm44 PAL = pers * LookAt;



		/*	glUseProgramm(firstProgram);
			glBindVertexArraym((unsigned int)myVAO);


			lm44 LosBearM = identity();

			LosBearM.rotateLosY(BearRotate);
			lm44 finalBearMM = PAL * LosBearM;

			glUniformMatrix4fv_m((int)matrixDrawRectangle, 1, GLFALSE, &finalBearMM.elements[0][0]);
			drawElements((myUnsignedInt)glTrianglesStrip, (int)12, (myUnsignedInt)glUnsignedShort, (void*)0);
			BearRotate += 0.1f;*/



		checkErrorLos(1);

		glUseProgramm(firstProgram);
		glBindVertexArraym(myVAO); // was VAORectangle 

		matrixButton[0][0] = ((2 / (float)width) * 120.0f); // width object's
		matrixButton[1][1] = ((2 / (float)hwgih) * 140.0f); // height object's 
		matrixButton[3][0] = ((2 / (float)width) * (150.0f)) - 1;  // x_midToPlace   xMidFont
		matrixButton[3][1] = ((1 - (2 / (float)hwgih) * 240.0f));

		checkErrorLos(3);
		glUniformMatrix4fv_m(matrixDrawRectangle, 1, GLFALSE, &matrixButton[0][0]);
		checkErrorLos(6);
		drawElements(glTriangles, 8, glUnsignedShort, 0); // was INT
		checkErrorLos(4);


		glUseProgramm(emptyProgram);
		glBindVertexArraym(emptyProgram);

		checkErrorLos(5);

	}


	swapBuff();

}