#include "Entity_A.h"

using namespace fmt;

Entity_A::Entity_A(Tile &tile, uint8_t h) : tile(&tile), height(h)
{
    if(tile.entityStack.empty())
        tile.entityStack.push({this, h});
    else {
        tile.entityStack.push({ this, (int16_t)(tile.getHeight() + h) });
    }
}

text_style Entity_A::getColor() const
{
    int16_t height = tile->getHeight();
    float H = ((float)height) / MAX_HEIGHT;
    float V = 0.8f;
    float S = 0.8f;
    uint8_t R, G, B;
    if (S == 0)
    {
        R = (uint8_t)(V * 255);
        G = (uint8_t)(V * 255);
        B = (uint8_t)(V * 255);
    }
    else
    {
        float var_h = H * 6;

        if (var_h == 6)
            var_h = 0;      //H must be < 1

        int var_i = int(var_h);             //Or ... var_i = floor( var_h )
        float var_1 = V * (1 - S);
        float var_2 = V * (1 - S * (var_h - var_i));
        float var_3 = V * (1 - S * (1 - (var_h - var_i)));

        float var_r, var_g, var_b;

        if (var_i == 0) { var_r = V;     var_g = var_3; var_b = var_1; }
        else if (var_i == 1) { var_r = var_2; var_g = V;     var_b = var_1; }
        else if (var_i == 2) { var_r = var_1; var_g = V;     var_b = var_3; }
        else if (var_i == 3) { var_r = var_1; var_g = var_2; var_b = V; }
        else if (var_i == 4) { var_r = var_3; var_g = var_1; var_b = V; }
        else { var_r = V;     var_g = var_1; var_b = var_2; }

        R = (uint8_t)(var_r * 255);
        G = (uint8_t)(var_g * 255);
        B = (uint8_t)(var_b * 255);
    }

    return fg(rgb(R, G, B));
}