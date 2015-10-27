#include <fea/structure.hpp>
#include <fea/render2d.hpp>
#include <fea/util.hpp>
#include <fea/userinterface.hpp>
#include "inputhandler.hpp"
#include "messages.hpp"
#include "audioplayer.hpp"
#include "renderer.hpp"

class __BERYL_CNAME__ : public fea::Application,
    public fea::MessageReceiver<QuitMessage>
{
    public:
        __BERYL_CNAME__();
        ~__BERYL_CNAME__();
        void handleMessage(const QuitMessage& message) override;
    protected:
        void loop() override;
    private:
        fea::MessageBus mBus;
        fea::Window mWindow;
        fea::Renderer2D mFeaRenderer;
        fea::InputHandler mFeaInputHandler;

        InputHandler mInputHandler;
        AudioPlayer mAudioPlayer;
        Renderer mRenderer;
};
