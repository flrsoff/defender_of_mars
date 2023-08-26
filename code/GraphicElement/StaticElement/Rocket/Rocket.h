#ifndef ROCKET_H
#define ROCKET_H
#include "../StaticElement.h"

std::string texture_file = "../resources/images/rocket/rocket.png";

class Rocket : public StaticElement{
    
public:
    Rocket();
    Rocket(int posX, int posY);
    
    
};

Rocket::Rocket(){
    set_position(0,0);
    this->loadImage(texture_file);

}

Rocket::Rocket(int posX, int posY){
    set_position(0, 0);
    this->loadImage(texture_file);
}




#endif