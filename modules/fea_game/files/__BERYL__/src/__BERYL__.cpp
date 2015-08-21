#include "__BERYL_NAME__.hpp"
#include <fea/ui/sdl2windowbackend.hpp>
#include <fea/ui/sdl2inputbackend.hpp>

__BERYL_CNAME__::__BERYL_CNAME__() :
    mRenderer(fea::Viewport({__BERYL_XRES__, __BERYL_YRES__}, {0, 0}, fea::Camera({__BERYL_XRES__ / 2.0f, __BERYL_YRES__ / 2.0f}))),
    mWindow(new fea::SDL2WindowBackend()),
    mFeaInputHandler(new fea::SDL2InputBackend()),
    mInputHandler(mBus, mFeaInputHandler),
    mAudioPlayer(mBus)
{
    mBus.addSubscriber<QuitMessage>(*this);
}

__BERYL_CNAME__::~__BERYL_CNAME__()
{
    mBus.removeSubscriber<QuitMessage>(*this);
}

void __BERYL_CNAME__::handleMessage(const QuitMessage& message)
{
    (void)message;
    quit();
}

void __BERYL_CNAME__::setup(const std::vector<std::string>& args)
{
    (void)args;
    mWindow.create(fea::VideoMode(__BERYL_XRES__, __BERYL_YRES__), "__BERYL_CNAME__");
    mWindow.setVSyncEnabled(true);
    mRenderer.setup();
    mWindow.setFramerateLimit(60);
}

void __BERYL_CNAME__::destroy()
{
    mWindow.close();
}

void __BERYL_CNAME__::loop()
{
    mInputHandler.process();
    mAudioPlayer.update();

    mWindow.swapBuffers();
}
