#ifndef BACK_GROUND
#define BACK_GROUND

#include "../StaticElement.h"

enum TypeBackground{
    mars = 0
};

std::string files[] = {
   "../resources/images/backgroundGame/backgroundGame.jpg"
};

class Background : public StaticElement{
    TypeBackground type_background;
public:
    Background();
    Background(const TypeBackground & _background);//??
    Background(const Background & background);
    Background & operator = (const Background & background);//??

    void set_TypeBackground(const TypeBackground & _background);
};

Background::Background(){
    set_position(0,0);
}

// Background::Background(const Background & background){
//     if (this != &background){
//         posX = background.posX;
//         posY = background.posY;
//         sprite = background.sprite;
//         texture = background.texture;
//     } 
// }

Background::Background(const TypeBackground & _background){
    set_position(0,0);
    type_background = _background;
    loadImage(files[type_background]);
}

// Background&
// Background::operator = (const Background & background){
//     if (this != &background){
//         posX = background.posX;
//         posY = background.posY;
//         sprite = background.sprite;
//         texture = background.texture;
//     }
//     return *this;
// }

void
Background::set_TypeBackground(const TypeBackground & _background){
    type_background = _background;
    loadImage(files[type_background]);
}

#endif