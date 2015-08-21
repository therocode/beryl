#include <fea/structure.hpp>
#include <fea/render2d.hpp>
#include <fea/userinterface.hpp>

class __BERYL_CNAME__ : public fea::Application
{
    public:
        __BERYL_CNAME__();
    protected:
        virtual void setup(const std::vector<std::string>& args) override;
        virtual void destroy() override; 
        virtual void loop() override;
    private:
        void handleInput();
        fea::Window mWindow;
        fea::InputHandler mInputHandler;
        fea::Renderer2D mRenderer;
};
