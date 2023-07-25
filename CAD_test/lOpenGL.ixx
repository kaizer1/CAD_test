module;


#include <windows.h>
#include <Gl/GL.h>
#include <glext.h>
#include <fstream>

import lWinApi;

#pragma comment(lib, "opengl32.lib")


export module lOpenGL;

namespace losGraphics {



#define MAX_SOURCE_SIZE (0x100000)
#define INFOLOG_SIZE 4096
#define GET_INFOLOG_SIZE INFOLOG_SIZE - 1
#define STRINGIFY(s) #s

    static constexpr auto VERTEX_OFFSET = 0;
    export void loadASTC(const char* nameTexture, GLuint* texID);
    export void LoadingStaticNormalsExist(GLuint& losM, const char* nameLoadModel, bool vaoExist);
    export using uint16 = unsigned short;// uint16;
    export void linkAndValidateProgram(unsigned int& enterProgram);

    export template <typename T>
        auto callingM(const char* namesCall, T t) -> auto {
        losWin::LosOutputStringConvert(namesCall, t);
    }


    void* GetAnyGLFuncAddress(const char* name)
    {
        void* p = (void*)wglGetProcAddress(name);
        if (p == 0 ||
            (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) ||
            (p == (void*)-1))
        {
            HMODULE module = LoadLibraryA("opengl32.dll");
            p = (void*)GetProcAddress(module, name);
        }

        return p;
    }


#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505



    export void checkErrorLos(int numberError) {

        auto storeError = glGetError();

        if (storeError != GL_NO_ERROR) {
            //LosOutputStringConvert("error gl ", NumberError);

            if (storeError == GL_INVALID_ENUM) {
                losWin::LosOutputStringConvert(" ERROR: invalied enum ! ", numberError);
            }
            else if (storeError == GL_INVALID_VALUE) {
                losWin::LosOutputStringConvert(" ERROR: invalid value  ! ", numberError);
            }
            else if (storeError == GL_STACK_OVERFLOW) {

                losWin::LosOutputStringConvert(" ERROR: stack overflow  ! ", numberError);
            }
            else if (storeError == GL_STACK_UNDERFLOW) {
                losWin::LosOutputStringConvert(" ERROR: stack underflow  ! ", numberError);
            }
            else if (storeError == GL_OUT_OF_MEMORY) {
                losWin::LosOutputStringConvert(" ERROR: out of memory ! ", numberError);
            }
            else if (storeError == GL_INVALID_OPERATION) {
                losWin::LosOutputStringConvert(" ERROR: invalid operation ! ", numberError);
            }


        }

    }


    export void loadShaderFromFiles(unsigned int& programGL, unsigned int shaderType, const char* asstsShader);





    /* typedef BOOL(WINAPI* PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats,
         int* piFormats, UINT* nNumFormats);

     typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);
     typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC) (int interval);*/

     /*  export PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
       export PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;*/
    PFNGLUSEPROGRAMPROC glUseProgram;
    //export void glUseProgram;
    export PFNGLCREATEPROGRAMPROC glCreateProgram;
    //export void glCreateProgram;
    PFNGLCREATESHADERPROC glCreateShader;

    PFNGLSHADERSOURCEPROC  glShaderSource;
    PFNGLCOMPILESHADERPROC  glCompileShader;
    PFNGLDELETESHADERPROC glDeleteShader;
    PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
    PFNGLGETSHADERIVPROC glGetShaderiv;
    PFNGLATTACHSHADERPROC glAttachShader;
    PFNGLLINKPROGRAMPROC glLinkProgram;
    PFNGLVALIDATEPROGRAMPROC glValidateProgram;
    PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
    PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
    PFNGLBUFFERDATAPROC glBufferData;
    PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
    PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
    PFNGLBINDBUFFERPROC glBindBuffer;
    PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
    //export void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
    PFNGLGENBUFFERSPROC glGenBuffers;
    PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
    PFNGLACTIVETEXTUREPROC glActiveTexture;
    PFNGLUNIFORM1IPROC glUniform1i;
    PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
    PFNGLDELETEPROGRAMPROC glDeleteProgram;
    PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArray;
    /* export PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;*/
    PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
    PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
    PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
    PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
    export PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
    PFNGLBINDBUFFERBASEPROC glBindBufferBase;



    export void callClear(float r, float g, float b, float a) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(r, g, b, 1.0F);
    }

    export void CallingLoadingExtension() {

        //losWin::LosOutputStringConvert(" we  openGL  ", 4);
        glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
        glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
        glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
        glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
        glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
        glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
        glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
        glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
        glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
        glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
        glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
        glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
        glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
        glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
        glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
        glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
        glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
        glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
        glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
        glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
        glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
        glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
        glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
        glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
        glDeleteVertexArray = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArray");
        glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)wglGetProcAddress("glCompressedTexImage2D");
        glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)wglGetProcAddress("glGetUniformBlockIndex");
        glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)wglGetProcAddress("glGetActiveUniformBlockiv");
        glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)wglGetProcAddress("glGetActiveUniformsiv");
        glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)wglGetProcAddress("glGetUniformIndices");
        glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)wglGetProcAddress("glBindBufferBase");
    }


    GLuint loadShaderLos(GLenum enu, const char* shaderSource)
    {
        GLuint shaderL;
        GLint compiled;

        shaderL = glCreateShader(enu);

        if (shaderL != 0)
        {
            glShaderSource(shaderL, 1, &shaderSource, NULL);

            glCompileShader(shaderL);
            compiled = 0;
            glGetShaderiv(shaderL, GL_COMPILE_STATUS, &compiled);
            if (compiled != GL_TRUE)
            {

                //LosOutputStringConvert("sdf");
                GLint infoLen = 0;
                glGetShaderiv(shaderL, GL_INFO_LOG_LENGTH, &infoLen);
                if (infoLen > 0)
                {

                    char* logBuffer = (char*)malloc(infoLen);
                    if (logBuffer != NULL)
                    {
                        glGetShaderInfoLog(shaderL, infoLen, NULL, logBuffer);
                        // LosOutputStringConvert(" error my this ", 4);
                        free(logBuffer);
                        logBuffer = NULL;
                    }
                    glDeleteShader(shaderL);
                    shaderL = 0;
                }
            }
            //LosOutputStringConvert("final loading ", 2);
        }
        return shaderL;
    }


    //static char* readShaderSource(std::string_view shaderFile)
    //{
       // FILE* fp = std::fopen(shaderFile.data(), "rb");

        //if (fp == NULL) {
            //LosOutputStringConvert(" null my shaders ");
          //  return NULL;
        //}

        //std::SEEK_ENS 

       //std:: fseek(fp, 0L, SEEK_END);
       // long size = std::ftell(fp);

       // long size = 1024;
        // std::fseek(fp, 0L, SEEK_SET);
        //char* buf = new char[size + 1];
        // fread(buf, 1, size, fp);

        // buf[size] = '\0';
        //std::fclose(fp);


     //   return buf;
    //}

    void loadShaderFromFiles(unsigned int& programGL, unsigned int shaderType, const char* asstsShader) {

        std::string baseAssets = "assets/Shaders/";
        baseAssets += asstsShader;

        std::ifstream f(baseAssets);
        std::string str((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());


        GLchar infolog[INFOLOG_SIZE];

        GLuint id = glCreateShader(shaderType);
        //std::string str = text;
        //str = additional_str + str;
        const char* c = str.c_str();
        glShaderSource(id, 1, &c, 0);
        glCompileShader(id);

        GLint success;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(id, GET_INFOLOG_SIZE, 0, infolog);
            losWin::LosOutputStringConvert(infolog);

        }
        else
        {
            glAttachShader(programGL, id);
            glDeleteShader(id);
            losWin::LosOutputStringConvert("Success load and attach shares ! ");
        }

        //auto sourceShader = readShaderSource(asstsShader);
        //LosOutputStringConvert("ok in shader created 0 ");
        //GLuint shaderNew = glCreateShader(shaderType);
        //LosOutputStringConvert("ok in shader created 1");
       // glShaderSource(shaderNew, 1, &sourceShader, NULL);
        //LosOutputStringConvert("ok in shader created 2");
        //glCompileShader(shaderNew);
        //LosOutputStringConvert("ok in shader created !");
        //glDeleteShader(shaderNew);

       // return shaderNew;
    }




    export class ETCHeader
    {
    private:
        unsigned char paddenWidthMSB;
        unsigned char paddenWidthLSB;
        unsigned char paddenHeightMSB;
        unsigned char paddenHeightLSB;
        unsigned char widthMSB;
        unsigned char widthLSB;
        unsigned char heightMSB;
        unsigned char heightLSB;

    public:
        ETCHeader() {}


        ETCHeader(unsigned char* data) {
            paddenWidthMSB = data[8];
            paddenWidthLSB = data[9];
            paddenHeightMSB = data[10];
            paddenHeightLSB = data[11];
            widthMSB = data[12];
            widthLSB = data[13];
            heightMSB = data[14];
            heightLSB = data[15];
        }

        unsigned short getWidth(void)
        {
            return (widthMSB << 8) | widthLSB;
        }


        unsigned short getHeight(void)
        {
            return (heightMSB << 8) | heightLSB;
        }


        unsigned short getPaddedWidth(void)
        {
            return (paddenWidthMSB << 8) | paddenWidthLSB;
        }

        unsigned short getPaddedHeight(void)
        {
            return (paddenHeightMSB << 8) | paddenHeightLSB;
        }

        //      GLsizei getSize();
        GLsizei getSize()
        {
            /* if (internalFormat != GL_COMPRESSED_RG11_EAC && internalFormat != GL_COMPRESSED_SIGNED_RG11_EAC &&
                 internalFormat != GL_COMPRESSED_RGBA8_ETC2_EAC && internalFormat != GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC)
             {
                 return (getPaddedWidth() * getPaddedHeight()) >> 1;
             }*/
             // else
              //{
            return (getPaddedWidth() * getPaddedHeight());
            //}
        }
    };


    export typedef struct
    {
        unsigned char  magic[4];
        unsigned char  blockdim_x;
        unsigned char  blockdim_y;
        unsigned char  blockdim_z;
        unsigned char  xsize[3];   /* x-size = xsize[0] + xsize[1] + xsize[2] */
        unsigned char  ysize[3];   /* x-size, y-size and z-size are given in texels */
        unsigned char  zsize[3];   /* block count is inferred */
    } astc_header;




    void loadASTC(const char* nameTexture, GLuint* texID) {


        std::string baseAssets = "assets/textures/";
        baseAssets += nameTexture;

        losWin::LosOutputStringConvert(baseAssets.c_str(), 8);


        //std::fstream my_file{};
        //my_file.open("my_file", std::ios::out);
        // std::fstream dis(" ", std::ifstream::in);



        std::ifstream is(baseAssets.c_str(), std::ios::binary);

        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg);

        losWin::LosOutputStringConvert("my lenght assets texture = ", length);
        char* buffers = new char[length + 1];

        is.read(buffers, length);

        is.close();


        unsigned int n_bytes_to_read = 0;
        int xblocks = 0;
        int yblocks = 0;
        int zblocks = 0;

        /* Number of bytes for each dimension. */
        int xsize = 0;
        int ysize = 0;
        int zsize = 0;

        //auto length = 1024;
        //char* buffers = new char[length + 1];
        astc_header* astc_data_ptr = (astc_header*)buffers;

        xsize = astc_data_ptr->xsize[0] + (astc_data_ptr->xsize[1] << 8) + (astc_data_ptr->xsize[2] << 16);
        ysize = astc_data_ptr->ysize[0] + (astc_data_ptr->ysize[1] << 8) + (astc_data_ptr->ysize[2] << 16);
        zsize = astc_data_ptr->zsize[0] + (astc_data_ptr->zsize[1] << 8) + (astc_data_ptr->zsize[2] << 16);

        xblocks = (xsize + astc_data_ptr->blockdim_x - 1) / astc_data_ptr->blockdim_x;
        yblocks = (ysize + astc_data_ptr->blockdim_y - 1) / astc_data_ptr->blockdim_y;
        zblocks = (zsize + astc_data_ptr->blockdim_z - 1) / astc_data_ptr->blockdim_z;

        n_bytes_to_read = xblocks * yblocks * zblocks << 4;

        (glGenTextures(1, texID));
        (glBindTexture(GL_TEXTURE_2D, *texID));

        GLenum compressed_data_internal_format;
        compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;

        /*  switch (astcs)
          {
          case  tenForsixe:
              compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR;
              break;

          case tenForEight:
              compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;
              break;

          case tenForTen:
              compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR;
              break;

          case   tenForTenNotAlpha:
              compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x10_KHR;
              break;


          default:
              compressed_data_internal_format = GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR;
              break;
          }*/


          // GLenum compressed_data_internal_format = GL_COMPRESSED_RGBA_ASTC_10x8_KHR;
           /* Upload texture data to ES. */

        (glCompressedTexImage2D(GL_TEXTURE_2D,
            0,
            compressed_data_internal_format,
            xsize,
            ysize,
            0,
            n_bytes_to_read,
            (const GLvoid*)&astc_data_ptr[1]));

        (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
        (glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));


        (glBindTexture(GL_TEXTURE_2D, 0));

    }



    void linkAndValidateProgram(unsigned int& enterProgram) {

        glLinkProgram(enterProgram);
        glValidateProgram(enterProgram);
    }



    void LoadingStaticNormalsExist(GLuint& losM, const char* nameLoadModel, bool vaoExist) {

        losWin::LosOutputStringConvert(" in Hammer model loading ");
        //AAssetManager* loadAssets = backAssetMan(); // w "TestArray2.bin",  TestStone2 planeDes  stone3 UpTower
        //AAsset* StrawberyAssets = AAssetManager_open(loadAssets, nameLoadModel, AASSET_MODE_BUFFER); // AASSET_MODE_STREAMING
        std::string baseAssets = "assets/Model/";
        baseAssets += nameLoadModel;



        std::ifstream is(baseAssets.c_str(), std::ios::binary);

        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg);

        losWin::LosOutputStringConvert("my lenght assets model = ", length);
        //char* buffers = new char[length + 1];







        //unsigned int losJokVertex;
        //is.read(reinterpret_cast<char*>(&losJokVertex), sizeof(uint32_t));
        //AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&losJokVertex), sizeof(uint32_t));
        //unsigned int losIndexesAssets;

        //AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&losIndexesAssets), sizeof(uint32_t));
        //is.read(reinterpret_cast<char*>(&losIndexesAssets), sizeof(uint32_t));
        //unsigned int uvCountAssets;
        //AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&uvCountAssets), sizeof(uint32_t));
        //is.read(reinterpret_cast<char*>(&uvCountAssets), sizeof(uint32_t));
        //losWin::LosOutputStringConvert(" my uvCount = ", uvCountAssets);

        //unsigned int normCountAssets;
        //AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&normCountAssets), sizeof(unsigned int));
        //is.read(reinterpret_cast<char*>(&normCountAssets), sizeof(unsigned int));
        //logRun(" losIndexesAssets == %d \n", losIndexesAssets); //
        //losM.drawIndexs = losIndexesAssets;


        //unsigned short bIndexAssets[losIndexesAssets];


        //uint16 aStraw[losJokVertex];
        //int aReadOkStraw = AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&aStraw), losJokVertex * sizeof(uint16));
        //CheckRead(aReadOkStraw, 1);


        //aReadOkStraw = AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&bIndexAssets), losIndexesAssets * sizeof(unsigned short));
        //CheckRead(aReadOkStraw, 13);
        //logRun( "my index == %d, %d \n", bIndexAssets[7], bIndexAssets[163]);
        //uint16 bUVAssets[uvCountAssets];
        //aReadOkStraw = AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&bUVAssets), uvCountAssets * sizeof(uint16));
        //CheckRead(aReadOkStraw, 23);
        // normCount
        //uint16 bNPillar[normCountAssets];
        // logRun("normCount == %d \n", normCountAssets);
        //aReadOkStraw = AAsset_read(StrawberyAssets, reinterpret_cast<char*>(&bNPillar), normCountAssets * sizeof(uint16));
       // CheckRead(aReadOkStraw, 33);
       // AAsset_close(StrawberyAssets);

        losWin::LosOutputStringConvert(" in ArcaMila final");


        is.close();
        // if (!vaoExist)
          //   glGenVertexArrays(1, &losM.vao);


         //auto KolNio = strcmp(nameLoadModel, "PollExcelent.bin");  // PollExcelent.bin

         //if (KolNio == 0) {
         //    const auto numbC = losJokVertex / 3;

         //    auto minX = 0.0f, maxX = 0.0f, minY = 0.0f, maxY = 0.0f, minZ = 0.0f, maxZ = 0.0f;

         //    //HalfToFloat
         //    for (int i = 0; i < numbC; i += 3) {
         //        auto x = HalfToFloat(aStraw[i]);
         //        auto y = HalfToFloat(aStraw[i + 1]);
         //        auto z = HalfToFloat(aStraw[i + 2]);

         //        if (x > maxX)
         //            maxX = x;

         //        if (x < minX)
         //            minX = x;


         //        if (y > maxY)
         //            maxY = y;

         //        if (y < minY)
         //            minY = y;

         //        if (z > maxZ)
         //            maxZ = z;

         //        if (z < minZ)
         //            minZ = z;

         //    }

         //    //logRun(" My  minMax : PollExcelent \n");
         //    //logRun(" Min max  X : %f, %f \n", minX, maxX);
         //    //logRun(" Min max  Y : %f, %f \n", minY, maxY);
         //    //logRun(" Min max  Z : %f, %f \n", minZ, maxZ);
         //    //
         //    //// Moneta
         //    //// Min max  X : -0.067444, 0.067444
         //    //// Min max  Y : 0.000000, 0.164429
         //    //// Min max  Z : -0.015564, 0.000061
         //}


        // logRun(" in ArcaMila 12");
        // glBindVertexArray(losM.vao);

        // GLuint bufferf1, bufferf2, bufferf3, buUnirr4;
        // glGenBuffers(1, &bufferf1);
        // glGenBuffers(1, &bufferf2);
        // glGenBuffers(1, &bufferf3);
        // glGenBuffers(1, &buUnirr4);


        // glBindBuffer(GL_ARRAY_BUFFER, bufferf1);
        // {
        //     glBufferData(GL_ARRAY_BUFFER, losJokVertex * sizeof(uint16), aStraw, GL_STATIC_DRAW);
        //     glVertexAttribPointer(0, 3, GL_HALF_FLOAT, GL_FALSE, 0, (const void*)VERTEX_OFFSET);
        //     glEnableVertexAttribArray(0);
        // }
        // logRun(" in ArcaMila 13");
        // glBindBuffer(GL_ARRAY_BUFFER, bufferf2);
        // {
        //     glBufferData(GL_ARRAY_BUFFER, uvCountAssets * sizeof(uint16), bUVAssets, GL_STATIC_DRAW);
        //     glVertexAttribPointer(1, 2, GL_HALF_FLOAT, GL_FALSE, 0, (const void*)VERTEX_OFFSET);
        //     glEnableVertexAttribArray(1);
        // }
        // logRun(" in ArcaMila 14");
        // glBindBuffer(GL_ARRAY_BUFFER, bufferf3);
        // {
        //     glBufferData(GL_ARRAY_BUFFER, normCountAssets * sizeof(uint16), bNPillar, GL_STATIC_DRAW);
        //     glVertexAttribPointer(2, 3, GL_HALF_FLOAT, GL_FALSE, 0, (const void*)VERTEX_OFFSET);
        //     glEnableVertexAttribArray(2);
        // }

        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buUnirr4);

        // // BIGS ERROR !!!
        // // RY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage)
        //// GLsizei size = losIndexesAssets * sizeof(GL_UNSIGNED_SHORT);  // was losIndexesAssets * sizeof(GL_UNSIGNED_SHORT)
        // logRun(" Big ERROOR's !!!  ");

        // glBufferData(GL_ELEMENT_ARRAY_BUFFER, losIndexesAssets * sizeof(unsigned  short), bIndexAssets, GL_STATIC_DRAW);

        // glBindVertexArray(0);
    }



    export inline const void  drawElements(unsigned int mode, int count, unsigned int type, const void* indices) {
        glDrawElements(mode, count, type, indices);
    }

    export constexpr inline void  glUniformMatrix4fv_m(int location, int count, bool transpose, const float* value) noexcept {
        glUniformMatrix4fv((int)location, count, transpose, value);
    }


    export constexpr inline void glUseProgramm(unsigned int programM) noexcept {
        glUseProgram(programM);
    }


    export constexpr inline void glBindVertexArraym(unsigned int vao) noexcept {
        glBindVertexArray(vao);
    }



    export constexpr inline void glBindBufferm(unsigned int target, unsigned int buffer) noexcept {
        glBindBuffer(target, buffer);
    }

    export constexpr inline void glBufferDatam(unsigned int target, int size, const void* data, unsigned int usage) noexcept {
        glBufferData(target, size, data, usage);
    }



    export constexpr inline void glVertexAttribPointerm(unsigned int index, int size, unsigned int type, bool normalized, int stride, const void* pointer) noexcept {
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    }


    export constexpr inline void glEnableVertexAttribArraym(unsigned int index) noexcept {
        glEnableVertexAttribArray(index);
    }

    export constexpr inline void glGenBuffersm(int n, unsigned int* buffers) noexcept {
        glGenBuffers(n, buffers);
    }


    export constexpr inline void glBindAttribLocationm(unsigned int program, unsigned int index, const char* name) noexcept {
        glBindAttribLocation(program, index, name);
    }

    export constexpr inline unsigned int glGetUniformLocationm(unsigned int program, const char* name) noexcept {
        return glGetUniformLocation(program, name);
    }


    export constexpr inline unsigned int glGetUniformBlockIndexm(unsigned int program, const char* uniformBlockName) noexcept {
        return glGetUniformBlockIndex(program, uniformBlockName);
    }


    // (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
    export constexpr inline void glGetActiveUniformBlockivm(unsigned int program, unsigned int uniformBlockIndex, unsigned int pname, int* params) {
        glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
    }

    export constexpr inline void glGenVertexArraysm(int n, unsigned int* arrays) noexcept {
        glGenVertexArrays(n, arrays);
    }


    export constexpr inline void glGetActiveUniformsivm(unsigned int program, int uniformCount, const unsigned int* uniformIndices, unsigned int pname, int* params) {
        glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
    }

    // (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
    export constexpr inline void glGetUniformIndicesl(unsigned int program, int uniformCount, const char* const* uniformNames, unsigned int* uniformIndices) noexcept {
        glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
    }

    export constexpr inline void glBindBufferBasem(unsigned int target, unsigned int index, unsigned int buffer) {
        glBindBufferBase(target, index, buffer);
    }





}