#pragma once
#include <fea/util.hpp>
#include <fea/userinterface.hpp>

class InputHandler
{
    public:
        InputHandler(fea::MessageBus& bus, fea::InputHandler& handler);
        void process();
    private:
        fea::InputHandler& mHandler;
        fea::MessageBus& mBus;
};
