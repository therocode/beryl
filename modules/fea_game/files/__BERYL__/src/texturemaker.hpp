#pragma once
#include <iostream>
#include <fea/render2d.hpp>
#include "lodepng/lodepng.hpp"
#pragma GCC diagnostic ignored "-Wunused-function"

static fea::Texture makeTexture(const std::string& path, bool smooth = false, bool interactive = false)
{
    uint32_t width;
    uint32_t height;

    std::vector<unsigned char> image; //the raw pixels

    //decode
    unsigned error = lodepng::decode(image, width, height, path);

    //if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
    fea::Texture texture;
    texture.create(width, height, &image[0], smooth, interactive);
    return texture;
}
