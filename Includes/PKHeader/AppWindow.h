#ifndef _APPWINDOW_H
#define _APPWINDOW_H

#pragma once
#include <types.hpp>
#include <PKHeader/UIWindow.h>

class DllImport AppWindow : public UIWindow {
public:
    AppWindow(class AppWindow const&);
    AppWindow(class UIWindow*, int, int, int, bool);
    ~AppWindow(void);
    class AppWindow& operator=(class AppWindow const&);
    virtual int processMessage(struct HWND__*, unsigned int, unsigned int, long);

    class BaseApp* m_app; // _88
};

#endif
