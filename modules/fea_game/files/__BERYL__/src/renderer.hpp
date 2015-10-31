#pragma once
#include <fea/rendering/renderer2d.hpp>

class Renderer
{
    public:
        Renderer(fea::Renderer2D& renderer);
        void render();

    private:
        fea::Renderer2D& mRenderer;
};
