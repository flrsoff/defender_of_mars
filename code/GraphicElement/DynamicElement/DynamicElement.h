#ifndef DYNAMIC_ELEMENT_H
#define DYNAMIC_ELEMENT_H

#include "../GraphicElement.h"

class DynamicElement : public GraphicElement{
protected:
    sf::Texture * textures;
    
    void moveLeft(const int & pixel);
    void moveRight(const int & pixel);
    void moveUp(const int & pixel);
    void moveDown(const int & pixel);
    void moveLeftUp(const int & pixel);
    void moveLeftDown(const int & pixel);
    void moveRightUp(const int & pixel);
    void moveRightDown(const int & pixel);

    virtual void selectTexture() = 0;
    virtual void handle_current_event(const int & fps) = 0;
public:
    sf::Sprite get_current_Sprite(const int & fps);
    virtual ~DynamicElement(){}
};
void DynamicElement::moveLeft(const int & pixel){
    move_position(-pixel, 0);
}
void DynamicElement::moveRight(const int & pixel){
    move_position(pixel, 0);
}
void DynamicElement::moveUp(const int & pixel){
    move_position(0, -pixel);
}
void DynamicElement::moveDown(const int & pixel){
    move_position(0, pixel);
}
void DynamicElement::moveLeftUp(const int & pixel){
    move_position(-pixel, -pixel);
}
void DynamicElement::moveLeftDown(const int & pixel){
    move_position(-pixel, pixel);
}
void DynamicElement::moveRightUp(const int & pixel){
    move_position(pixel, -pixel);
}
void DynamicElement::moveRightDown(const int & pixel){
    move_position(pixel, pixel);
}

sf::Sprite
DynamicElement::get_current_Sprite(const int & fps){
    handle_current_event(fps);
    //selectTexture();
    return get_sprite();
}

#endif