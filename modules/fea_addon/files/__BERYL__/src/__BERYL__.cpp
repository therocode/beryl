#include "__BERYL_NAME__.hpp"
#include <fea/ui/sdl2windowbackend.hpp>
#include <fea/ui/sdl2inputbackend.hpp>

__BERYL_CNAME__::__BERYL_CNAME__() :
    mWindow(new fea::SDL2WindowBackend(), fea::VideoMode(__BERYL_XRES__, __BERYL_YRES__), "__BERYL_CNAME__"),
    mInputHandler(new fea::SDL2InputBackend()),
    mRenderer(fea::Viewport({__BERYL_XRES__, __BERYL_YRES__}, {0, 0}, fea::Camera({__BERYL_XRES__ / 2.0f, __BERYL_YRES__ / 2.0f})))
{
    mWindow.setVSyncEnabled(true);
    mWindow.setFramerateLimit(60);
}

void __BERYL_CNAME__::loop()
{
    handleInput();

    //update code

    mWindow.swapBuffers();
}

void __BERYL_CNAME__::handleInput()
{
    fea::Event event;
    while(mInputHandler.pollEvent(event))
    {
        if(event.type == fea::Event::KEYPRESSED)
        {
            if(event.key.code == fea::Keyboard::ESCAPE)
                quit();
        }
        else if(event.type == fea::Event::CLOSED)
        {
            quit();
        }
        else if(event.type == fea::Event::RESIZED)
        {
            mRenderer.setViewport(fea::Viewport({event.size.width, event.size.height}, {0, 0}, fea::Camera({event.size.width / 2.0f, event.size.height / 2.0f})));
        }
        else if(event.type == fea::Event::MOUSEBUTTONPRESSED)
        {
            //
        }
        else if(event.type == fea::Event::MOUSEBUTTONRELEASED)
        {
            //
        }
        else if(event.type == fea::Event::MOUSEMOVED)
        {
            //
        }
    }
}
