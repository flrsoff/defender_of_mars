#ifndef GRAPHIC_ELEMENT_H
#define GRAPHIC_ELEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream> //..
#define _print(message) std::cout << (message) << std::endl//..
#define __print(message) std::cout << (message) << ' '//..

class GraphicElement{
    int posX;
    int posY;
    sf::Sprite sprite;
protected:
public:
    int get_posX();
    int get_posY();
    sf::Sprite get_sprite();

    void set_position(const int & posX, const int & posY);
    void set_texture(const sf::Texture & _texture);//??

    void move_position(const int & dX, const int & dY);

};

int
GraphicElement::get_posX() {
    return posX;
}

int
GraphicElement::get_posY(){
    return posY;
}

sf::Sprite
GraphicElement::get_sprite(){
    return sprite;
}

void
GraphicElement::set_position(const int & posX, const int & posY){
    this->posX = posX;
    this->posY = posY;
    sprite.setPosition(posX, posY);
}

void
GraphicElement::set_texture(const sf::Texture & _texture)
{
    sprite.setTexture(_texture);
}

void
GraphicElement::move_position(const int & dX, const int & dY){
    posX += dX; posY += dY;
    sprite.setPosition(posX, posY);
}


#endif