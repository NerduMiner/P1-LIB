#undef UNICODE

#include <PKHeader/CmdStream.h>
#include <PKHeader/ModuleMgr.h>
#include <PKHeader/NodeMgr.h>
#include <PKHeader/RamStream.h>
#include <PKHeader/System.h>
#include <PKHeader/UIMgr.h>
#include <PKHeader/UIWindow.h>

#include "Resource.h"
#include "framework.h"
#include <corecrt_io.h>
#include <stdio.h>

MenuPlugin* gMenuPlugins = new MenuPlugin();

class UIMain : public UIWindow {
public:
    UIMain(UIWindow* parent, int unk1, int dwStyle, int dwExStyle, bool unk2)
        : UIWindow(parent, unk1, dwStyle, dwExStyle, unk2)
    {
    }

    virtual int processMessage(HWND hWnd, unsigned int Msg, WPARAM wParam, long lParam)
    {
        if (Msg == WM_COMMAND) {
            for (MenuPlugin* i = gMenuPlugins; i; i = i->m_next) {
                if (i->m_prev == wParam) {
                    modMgr->Alloc(i->m_name);
                    return UIWindow::processMessage(hWnd, Msg, wParam, lParam);
                }
            }
        }
        if (Msg == WM_CLOSE) {
            exit(0);
        }

        return UIWindow::processMessage(hWnd, Msg, wParam, lParam);
    }
};

UIMain* gMainWindow;

static void print(const char* fmt, ...)
{
    if (!sysCon) {
        return;
    }

    va_list args;
    va_start(args, fmt);

    sysCon->print("%s: ", "PKGUI");

    char dest[1024];
    vsprintf(dest, fmt, args);
    if (strlen(dest)) {
        sysCon->write(dest, strlen(dest));
    }
}

static void load_plugins_folder(const char* dir)
{
    HMENU hSubMenu = nullptr;
    if (gMainWindow) {
        HMENU hMenu = GetMenu(gMainWindow->m_hWnd);
        if (hMenu) {
            hSubMenu = GetSubMenu(hMenu, 0);
        }
    }

    char searchStr[260];
    _finddata_t fd_file;
    sprintf(searchStr, "%s/*.dll", dir);
    long dll = _findfirst(searchStr, &fd_file);

    char pathToDll[260];
    for (bool dll_count = (dll == -1); !dll_count; dll_count = (_findnext(dll, &fd_file) != 0)) {
        sprintf(pathToDll, "%s/%s", dir, fd_file.name);

        if (hSubMenu) {
            Module* foundMod = modMgr->loadModule(_strdup(pathToDll));
            foundMod->menuPlugins(*gMenuPlugins, hSubMenu);
        }
    }

    _findclose(dll);
}

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    sysHInst = hInstance;

    nodeMgr = new NodeMgr();
    modMgr = new ModuleMgr();
    uiMgr = new UIMgr();

    gMainWindow = new UIMain(nullptr, NULL, WS_VISIBLE | WS_CAPTION | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_THICKFRAME, NULL, true);

    RectArea windowArea(690, 32, 1260, 300);
    gMainWindow->setFrame(windowArea);

    gMainWindow->createWindow("DUIClearWin", "OpenGL / Dolphin System", LoadMenu(sysHInst, MAKEINTRESOURCE(IDR_MENU1)));
    gsys->createDebugStream(gMainWindow);
    gMainWindow->refreshWindow();
    ShowWindow(gMainWindow->m_hWnd, SW_SHOWNORMAL);

    print("sysBootup rewrite by Axiot - 2021\n");
    gsys->m_router = new AtxDirectRouter("127.0.0.1");

    load_plugins_folder("plugins");

    MessageBox(NULL, "Open any plugin then close this window", "Warning !", MB_OK | MB_ICONWARNING);
    u32 exitCode = gsys->run(nullptr);

    if (nodeMgr) {
        delete nodeMgr;
    }
    if (uiMgr) {
        delete uiMgr;
    }
    // supposed to delete modMgr but it corrupts the heap for some reason

    return exitCode;
}