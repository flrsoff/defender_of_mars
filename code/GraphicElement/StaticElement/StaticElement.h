#ifndef STATIC_ELEMENT
#define STATIC_ELEMENT

#include "../GraphicElement.h"

class StaticElement : public GraphicElement{
protected:
protected:
    sf::Texture texture;
    void loadImage(const std::string & file_name);


};

void
StaticElement::loadImage(const std::string & file_name){
    texture.loadFromFile(file_name);
    this->set_texture(texture);
}

#endif