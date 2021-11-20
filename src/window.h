#ifndef WINDOW_H
#define WINDOW_H

class Window
{
public:
    Window();
    Window(const DWORD WinSzX, const DWORD WinSzY, LPCSTR WinName, BYTE WinType);
    ~Window();
    inline VOID collapse();
    inline VOID expand();
    inline VOID check_keys();
};

Window::Window()
{
    _txWindowStyle &= ~WS_CAPTION; //окно без заголовка, размером с экран
    txCreateWindow (GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN));

}

Window::Window(const DWORD WinSzX, const DWORD WinSzY, LPCSTR WinName, BYTE WinType)
{
    switch (WinType)
    {
        case 0:
            _txWindowStyle &= ~WS_CAPTION;
            break;
        case 1:
            _txWindowStyle = WS_POPUP;
            break;
        case 2:
            _txWindowStyle = WS_BORDER;
            break;
        default:
            _txWindowStyle = WS_SYSMENU;
            break;
    }
    txCreateWindow(WinSzX, WinSzY);
    SetWindowText (txWindow(), WinName);
}

Window::~Window()
{
    txDestroyWindow();
}

inline VOID Window::collapse() { ShowWindow(txWindow(), SW_MINIMIZE); }

inline VOID Window::expand() { ShowWindow(txWindow(), SW_MAXIMIZE); }

inline VOID Window::check_keys()
{
    if(GetAsyncKeyState(VK_F1) & 0x8000)
        collapse();
    else if(GetAsyncKeyState(VK_F2) & 0x8000)
        expand();
}
#endif // WINDOW_H
