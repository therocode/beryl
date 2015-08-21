#include "inputhandler.hpp"
#include "messages.hpp"

InputHandler::InputHandler(fea::MessageBus& bus, fea::InputHandler& handler):
    mHandler(handler),
    mBus(bus)
{
}

void InputHandler::process()
{
    fea::Event event;
    while(mHandler.pollEvent(event))
    {
        if(event.type == fea::Event::KEYPRESSED)
        {
            if(event.key.code == fea::Keyboard::ESCAPE)
                mBus.send(QuitMessage());

            mBus.send(KeyPressedMessage{event.key.code});
        }
        else if(event.type == fea::Event::CLOSED)
        {
            mBus.send(QuitMessage());
        }
        else if(event.type == fea::Event::RESIZED)
        {
            mBus.send(ResizeMessage{{event.size.width, event.size.height}});
        }
        else if(event.type == fea::Event::MOUSEBUTTONPRESSED)
        {
            mBus.send(MouseClickMessage{{event.mouseButton.x, event.mouseButton.y}});
        }
        else if(event.type == fea::Event::MOUSEBUTTONRELEASED)
        {
            mBus.send(MouseReleaseMessage{{event.mouseButton.x, event.mouseButton.y}});
        }
        else if(event.type == fea::Event::MOUSEMOVED)
        {
            mBus.send(MouseMoveMessage{{event.mouseMove.x, event.mouseMove.y}});
        }
    }
}
