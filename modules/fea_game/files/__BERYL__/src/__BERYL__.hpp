#include <fea/structure.hpp>
#include <fea/render2d.hpp>
#include <fea/util.hpp>
#include <fea/userinterface.hpp>
#include "inputhandler.hpp"
#include "messages.hpp"
#include "audioplayer.hpp"

class __BERYL_CNAME__ : public fea::Application,
    public fea::MessageReceiver<QuitMessage>
{
    public:
        __BERYL_CNAME__();
        ~__BERYL_CNAME__();
        void handleMessage(const QuitMessage& message) override;
    protected:
        virtual void setup(const std::vector<std::string>& args) override;
        virtual void destroy() override; 
        virtual void loop() override;
    private:
        fea::MessageBus mBus;
        fea::Renderer2D mRenderer;
        fea::Window mWindow;
        fea::InputHandler mFeaInputHandler;

        InputHandler mInputHandler;
        AudioPlayer mAudioPlayer;
};
