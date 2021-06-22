#include <PKHeader/AppWindow.h>
#include <PKHeader/BaseApp.h>
#include <PKHeader/OptionBox.h>
#include <PKHeader/System.h>
#include <attach_module.h>

static void print(const char* fmt, ...)
{
    if (!sysCon) {
        return;
    }

    va_list args;
    va_start(args, fmt);

    sysCon->print("%s: ", "axiotPlugin");

    char dest[1024];
    vsprintf(dest, fmt, args);
    if (strlen(dest)) {
        sysCon->write(dest, strlen(dest));
    }
}

class AxiotPlugin : public BaseApp {
public:
    AxiotPlugin()
    {
        m_window = new AppWindow(nullptr, NULL, 0x16CF0000, 0x40000, true);
        m_window->m_app = this;

        RectArea frame(690, 312, 1260, 518);
        m_window->setFrame(frame);
        m_window->createWindow("DUIGenWin", "axiotPlugin", NULL);

        gsys->createDebugStream(m_window);
        m_window->refreshWindow();
        ShowWindow(m_window->m_hWnd, SW_SHOWNORMAL);

        print("axiot plugin setup complete\n");
    }

    ~AxiotPlugin()
    {
        delete m_window;
    }

    virtual int idle()
    {
        // Every frame when the window is in focus

        return 0;
    }

    AppWindow* m_window = nullptr;
    AtxDirectRouter* m_router = nullptr;
};

static AxiotPlugin* generatePlugin()
{
    return new AxiotPlugin;
}

Object ObjectList[]
    = {
          Object("axiotPlugin", true, &generatePlugin),
          Object(nullptr, false, nullptr),
      };