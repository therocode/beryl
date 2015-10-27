#include "__BERYL_NAME__.hpp"
#include <fea/ui/sdl2windowbackend.hpp>
#include <fea/ui/sdl2inputbackend.hpp>

__BERYL_CNAME__::__BERYL_CNAME__() :
    mWindow(new fea::SDL2WindowBackend(), fea::VideoMode(__BERYL_XRES__, __BERYL_YRES__), "__BERYL_CNAME__"),
    mFeaRenderer(fea::Viewport({__BERYL_XRES__, __BERYL_YRES__}, {0, 0}, fea::Camera({__BERYL_XRES__ / 2.0f, __BERYL_YRES__ / 2.0f}))),
    mFeaInputHandler(new fea::SDL2InputBackend()),
    mInputHandler(mBus, mFeaInputHandler),
    mAudioPlayer(mBus),
    mRenderer(mFeaRenderer)
{
    mWindow.setVSyncEnabled(true);
    mWindow.setFramerateLimit(60);

    subscribe(mBus, *this, false);
}

void __BERYL_CNAME__::handleMessage(const QuitMessage& message)
{
    (void)message;
    quit();
}

void __BERYL_CNAME__::loop()
{
    mInputHandler.process();
    mAudioPlayer.update();
    mRenderer.render();

    mWindow.swapBuffers();
}
