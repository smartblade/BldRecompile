#include <App/Windows/WinApp.h>

class B_BladeApp : public B_WinApp
{
public:
    virtual bool Start();
    virtual bool ProcessEvents();
    virtual void End();
    B_BladeApp(HINSTANCE module, int nCmdShow, char *cmdLine);
};
