module;


#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN         
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <dwmapi.h>
#include <windowsx.h>
#include <cstdint>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>



#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_RAYTRACINGOPENGL_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_RAYTRACINGOPENGL	107
#define IDI_SMALL				108
#define IDC_RAYTRACINGOPENGL	109
#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif
// Next default values for new objects
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif




#pragma comment(lib, "dwmapi.lib")




#define MAX_LOADSTRING 100



#define WGL_DRAW_TO_WINDOW_ARB         0x2001
#define WGL_ACCELERATION_ARB           0x2003
#define WGL_SWAP_METHOD_ARB            0x2007
#define WGL_SUPPORT_OPENGL_ARB         0x2010
#define WGL_DOUBLE_BUFFER_ARB          0x2011
#define WGL_PIXEL_TYPE_ARB             0x2013
#define WGL_COLOR_BITS_ARB             0x2014
#define WGL_DEPTH_BITS_ARB             0x2022
#define WGL_STENCIL_BITS_ARB           0x2023
#define WGL_FULL_ACCELERATION_ARB      0x2027
#define WGL_SWAP_EXCHANGE_ARB          0x2028
#define WGL_TYPE_RGBA_ARB              0x202B
#define WGL_CONTEXT_MAJOR_VERSION_ARB  0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB  0x2092
#define GL_ARRAY_BUFFER                   0x8892
#define GL_STATIC_DRAW                    0x88E4
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_TEXTURE0                       0x84C0
#define GL_BGRA                           0x80E1
#define GL_ELEMENT_ARRAY_BUFFER           0x8893



export module lWinApi;



namespace losWin {

    bool borderless = true;
    bool borderless_resize = true;
    bool borderless_drag = true;
    bool borderless_shadow = true;


    //export HGLRC;
    //export HDC;
    //export HWND;
    //export HINSTANCE;


    //template <typename T>
    export ATOM MyRegisterClass(HINSTANCE hInstance, std::function<void()> createCallbackFunc, std::function<void()> buildGLProgram);
    export int InitInstance(HINSTANCE hInstance, int nCmdShow, const int& mWidth, const int& mHeight);

    HGLRC ourOpenGLRenderingContext;
    HDC ourWindowHandleToDeviceContext;
    HDC m_deviceContext;
    HGLRC m_renderingContext;
    std::function<void()> baseCall;
    std::function<void()> buildGL;
    float destWidth;
    float destHeight;
    float n = 1.0f;

    auto hit_test(POINT cursor) -> LRESULT;


    LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    auto set_shadow(HWND handle, bool enabled) -> void;



    ATOM MyRegisterClass(HINSTANCE hInstance, std::function<void()> createCallbackFunc, std::function<void()> buildGLProgram)
    {

        baseCall = createCallbackFunc;
        buildGL = buildGLProgram;
        WNDCLASSEXW wcex;

        wcex.cbSize = sizeof(WNDCLASSEX);

        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = hInstance;
        wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RAYTRACINGOPENGL));
        wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_RAYTRACINGOPENGL);
        // was szWindowClass

        wcex.lpszClassName = L"slkjgksadjflkasdklf";
        wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

        return RegisterClassExW(&wcex);
    }

    HWND hWnd = nullptr;


    export inline const HWND returnHWND() noexcept {
        return hWnd;
    }

    export void LosOutputStringConvert(const char* textMessages, int n = 0) {


        WCHAR EmptyMess[150] = L"Simple message to empty \n";
        std::string newSteing = textMessages;
        std::wstring kjj(newSteing.size(), 0);
        MultiByteToWideChar(CP_UTF8, 0, &newSteing[0], (int)newSteing.size(), &kjj[0], newSteing.size());


        //  n : 0 ?   , 

        if (n == 0) {
            wsprintfW(EmptyMess, L"losGames: %s \n", kjj.c_str()); //
        }
        else {
            wsprintfW(EmptyMess, L"losGames: %s %d \n", kjj.c_str(), n); //
        }

        OutputDebugStringW(EmptyMess);
        // EmptyMess = L"";
    }


    int InitInstance(HINSTANCE hInstance, int nCmdShow, const int& mWidth, const int& mHeight)
    {

        const wchar_t CLASS_NAME[20] = L"OpenGL Copter model";
        hWnd = CreateWindowExW(0, L"slkjgksadjflkasdklf", CLASS_NAME, WS_POPUP | WS_THICKFRAME | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX,
            200, 200, mWidth, mHeight, nullptr, nullptr, nullptr, hInstance);

        if (!hWnd)
        {
            return FALSE;
        }

        LosOutputStringConvert("in my InitInstance", 1);

        ::SetWindowLongPtrW(hWnd, GWL_STYLE, static_cast<LONG>(WS_POPUP | WS_THICKFRAME | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX));
        set_shadow(hWnd, true);

        ::SetWindowPos(hWnd, nullptr, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE);
        //::ShowWindow(hWnd, SW_SHOW);

        ShowWindow(hWnd, nCmdShow);
        UpdateWindow(hWnd);
        return TRUE;
    }


    auto composition_enabled() -> bool {
        BOOL composition_enabled = FALSE;
        bool success = ::DwmIsCompositionEnabled(&composition_enabled) == S_OK;
        return composition_enabled && success;
    }


    auto set_shadow(HWND handle, bool enabled) -> void {

        if (composition_enabled()) {
            static const MARGINS shadow_state[2]{ { 0,0,0,0 },{ 1,1,1,1 } };
            ::DwmExtendFrameIntoClientArea(handle, &shadow_state[enabled]);
        }
    }


    auto maximized(HWND hwnd) -> bool {
        WINDOWPLACEMENT placement;
        if (!::GetWindowPlacement(hwnd, &placement)) {
            return false;
        }

        return placement.showCmd == SW_MAXIMIZE;
    }


    auto adjust_maximized_client_rect(HWND window, RECT& rect) -> void {
        if (!maximized(window)) {
            return;
        }

        auto monitor = ::MonitorFromWindow(window, MONITOR_DEFAULTTONULL);
        if (!monitor) {
            return;
        }

        MONITORINFO monitor_info{};
        monitor_info.cbSize = sizeof(monitor_info);
        if (!::GetMonitorInfoW(monitor, &monitor_info)) {
            return;
        }
        rect = monitor_info.rcWork;
    }


    LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        if (message == WM_NCCREATE) {
            auto userdata = reinterpret_cast<CREATESTRUCTW*>(lParam)->lpCreateParams;
            ::SetWindowLongPtrW(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(userdata));
        }

        switch (message)
        {

        case WM_NCCALCSIZE: {
            {
                auto& params = *reinterpret_cast<NCCALCSIZE_PARAMS*>(lParam);
                adjust_maximized_client_rect(hWnd, params.rgrc[0]);
                return 0;
            }
            break;
        }
        case WM_NCHITTEST: {
            // When we have no border or title bar, we need to perform our
            // own hit testing to allow resizing and moving.
            {
                return hit_test(POINT{
                    GET_X_LPARAM(lParam),
                    GET_Y_LPARAM(lParam)
                    });
            }
            break;
        }
        case WM_NCACTIVATE: {
            if (!composition_enabled()) {
                // Prevents window frame reappearing on window activation
                // in "basic" theme, where no aero shadow is present.
                return 1;
            }
            break;
        }


        case WM_CREATE:
        {
            LosOutputStringConvert(" start in create ! ");
            PIXELFORMATDESCRIPTOR pfd =
            {
                sizeof(PIXELFORMATDESCRIPTOR),
                1,
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
                PFD_TYPE_RGBA,
                32,
                0, 0, 0, 0, 0, 0,
                0,
                0,
                0,
                0, 0, 0, 0,
                24,
                8,
                0,
                PFD_MAIN_PLANE,
                0,
                0, 0, 0
            };

            ourWindowHandleToDeviceContext = GetDC(hWnd);

            destWidth = LOWORD(lParam);
            destHeight = HIWORD(lParam);

            int  letWindowsChooseThisPixelFormat;
            letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
            SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

            ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
            wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);

            baseCall();


            typedef BOOL(WINAPI* PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats,
                int* piFormats, UINT* nNumFormats);

            typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);
            typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC) (int interval);

            PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
            PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
            PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

            wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
            wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
            wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");

            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(ourOpenGLRenderingContext);
            ourOpenGLRenderingContext = NULL;
            ReleaseDC(hWnd, ourWindowHandleToDeviceContext);
            ourWindowHandleToDeviceContext = 0;
            int attributeListInt[19];
            int pixelFormat2[1];
            unsigned int formatCount;
            int result;
            PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
            int attributeList[5];

            m_deviceContext = GetDC(hWnd);
            if (!m_deviceContext)
            {
                LosOutputStringConvert("no 777 device context");
                return false;
            }

            attributeListInt[0] = WGL_SUPPORT_OPENGL_ARB;
            attributeListInt[1] = TRUE;
            attributeListInt[2] = WGL_DRAW_TO_WINDOW_ARB;
            attributeListInt[3] = TRUE;
            attributeListInt[4] = WGL_ACCELERATION_ARB;
            attributeListInt[5] = WGL_FULL_ACCELERATION_ARB;
            attributeListInt[6] = WGL_COLOR_BITS_ARB;
            attributeListInt[7] = 24;
            attributeListInt[8] = WGL_DEPTH_BITS_ARB;
            attributeListInt[9] = 24;
            attributeListInt[10] = WGL_DOUBLE_BUFFER_ARB;
            attributeListInt[11] = TRUE;
            attributeListInt[12] = WGL_SWAP_METHOD_ARB;
            attributeListInt[13] = WGL_SWAP_EXCHANGE_ARB;
            attributeListInt[14] = WGL_PIXEL_TYPE_ARB;
            attributeListInt[15] = WGL_TYPE_RGBA_ARB;
            attributeListInt[16] = WGL_STENCIL_BITS_ARB;
            attributeListInt[17] = 8;
            attributeListInt[18] = 0;

            int result1 = wglChoosePixelFormatARB(m_deviceContext, attributeListInt, NULL, 1, pixelFormat2, &formatCount);
            if (result1 != 1)
            {
                LosOutputStringConvert("Error to wglChoosePixelFormat", 21);
                return false;
            }


            result1 = SetPixelFormat(m_deviceContext, pixelFormat2[0], &pixelFormatDescriptor);
            if (result1 != 1)
            {
                LosOutputStringConvert("Error to serPixelPerfect", 21);
                return false;
            }

            attributeList[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
            attributeList[1] = 4;
            attributeList[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
            attributeList[3] = 6;
            attributeList[4] = 0;


            m_renderingContext = wglCreateContextAttribsARB(m_deviceContext, 0, attributeList);
            if (m_renderingContext == NULL)
            {
                LosOutputStringConvert("no render context");
                return false;
            }


            result1 = wglMakeCurrent(m_deviceContext, m_renderingContext);
            if (result1 != 1)
            {
                LosOutputStringConvert("sdf");
                return false;
            }

            wglSwapIntervalEXT(1);
            buildGL();
        }
        case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {

            case IDM_EXIT:
                wglDeleteContext(ourOpenGLRenderingContext);
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;

        case WM_LBUTTONDOWN:
        {
            //LosOutputStringConvert("d);
            POINT pLos;
            ::GetCursorPos(&pLos);
            LosOutputStringConvert(" press buttons ", pLos.x);
            LosOutputStringConvert("press buttons ", pLos.y);


            RECT rectLos;
            ::GetClientRect(hWnd, &rectLos);
            LosOutputStringConvert("get this touch ");

        }
        break;


        case WM_KEYDOWN:
            if (lParam & (1 << 30)) {
                // Ignore repeats
                return 0;
            }

            switch (wParam) {
            case VK_SPACE:
                // space press 
                LosOutputStringConvert("Space press ");
                return 0;

            case 'Q':
                LosOutputStringConvert("quit press and final all ");
                PostQuitMessage(0);
                return 0;


            }

        case WM_DESTROY:

            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        return 0;
    }


    export const void swapBuff() {
        SwapBuffers(m_deviceContext);
    }

    auto hit_test(POINT cursor) -> LRESULT {
        const POINT border{
            ::GetSystemMetrics(SM_CXFRAME) + ::GetSystemMetrics(SM_CXPADDEDBORDER),
            ::GetSystemMetrics(SM_CYFRAME) + ::GetSystemMetrics(SM_CXPADDEDBORDER)
        };
        RECT window;
        if (!::GetWindowRect(hWnd, &window)) {
            return HTNOWHERE;
        }

        const auto drag = borderless_drag ? HTCAPTION : HTCLIENT;

        enum region_mask {
            client = 0b0000,
            left = 0b0001,
            right = 0b0010,
            top = 0b0100,
            bottom = 0b1000,
        };

        const auto result =
            left * (cursor.x < (window.left + border.x)) |
            right * (cursor.x >= (window.right - border.x)) |
            top * (cursor.y < (window.top + border.y)) |
            bottom * (cursor.y >= (window.bottom - border.y));

        switch (result) {
        case left: return borderless_resize ? HTLEFT : drag;
        case right: return borderless_resize ? HTRIGHT : drag;
        case top: return borderless_resize ? HTTOP : drag;
        case bottom: return borderless_resize ? HTBOTTOM : drag;
        case top | left: return borderless_resize ? HTTOPLEFT : drag;
        case top | right: return borderless_resize ? HTTOPRIGHT : drag;
        case bottom | left: return borderless_resize ? HTBOTTOMLEFT : drag;
        case bottom | right: return borderless_resize ? HTBOTTOMRIGHT : drag;
        case client: return drag;
        default: return HTNOWHERE;
        }
    }

}