#ifndef ENTITY_H
#define ENTITY_H

#include "../DynamicElement.h"
enum index{
    UP1 = 0,
    UP2 = 1,
    UP3 = 2,
    DOWN1 = 3,
    DOWN2 = 4,
    DOWN3 = 5,
    LEFT1 = 6,
    LEFT2 = 7,
    LEFT3 = 8,
    RIGHT1 = 9,
    RIGHT2 = 10,
    RIGHT3 = 11
};

class Entity : public DynamicElement{
protected:
    //пикселей в секунду
    int speed;
    int speed_steep;

    //---- --__ момент движения 0-4
    //--__ __-- направление движения --ud lr--  32 16 -- 8 4 
    char moment_of_motion; 
    int tact = 0; //такт для выбора текстуры
    int tact_ = 0; //такт для выбора положения
    void loadTexture(const std::string& file_name, index type);
    index curr_index;
    
    void set_curr_index(index _curr_index);
    void selectTexture();
    virtual void handle_current_event(const int & fps) = 0;

    virtual ~Entity(){}
};

void
Entity::loadTexture(const std::string& file_name, index type){
    textures[type].loadFromFile(file_name);
}

void
Entity::set_curr_index(index _curr_index)
{
    curr_index = _curr_index;
    set_texture(textures[curr_index]);
}

void Entity::selectTexture()
{   
    switch (moment_of_motion)
    {
    case 32:
        set_curr_index(UP1);
        break;
    case 33:
        set_curr_index(UP2);
        break;
    case 34:
        set_curr_index(UP3);
        break;
    case 35:
        set_curr_index(UP2);
        break;
    case 16:
        set_curr_index(DOWN1);
        break;
    case 17:
        set_curr_index(DOWN2);
        break;
    case 18:
        set_curr_index(DOWN3);
        break;
    case 19:
        set_curr_index(DOWN2);
        break;
    case 8:
        set_curr_index(LEFT1);
        break;
    case 9:
        set_curr_index(LEFT2);
        break;
    case 10:
        set_curr_index(LEFT3);
        break;
    case 11:
        set_curr_index(LEFT2);
        break;
    case 4:
        set_curr_index(RIGHT1);
        break;
    case 5:
        set_curr_index(RIGHT2);
        break;
    case 6:
        set_curr_index(RIGHT3);
        break;
    case 7:
        set_curr_index(RIGHT2);
        break;
    //ul
    case 40:
        set_curr_index(UP1);
        break;
    case 41:
        set_curr_index(UP2);
        break;
    case 42:
        set_curr_index(UP3);
        break;
    case 43:
        set_curr_index(UP2);
        break;
    //ur
    case 36:
        set_curr_index(UP1);
        break;
    case 37:
        set_curr_index(UP2);
        break;
    case 38:
        set_curr_index(UP3);
        break;
    case 39:
        set_curr_index(UP2);
        break;
    //dl
    case 24:
        set_curr_index(DOWN1);
        break;
    case 25:
        set_curr_index(DOWN2);
        break;
    case 26:
        set_curr_index(DOWN3);
        break;
    case 27:
        set_curr_index(DOWN2);
        break;
    //dr
    case 20:
        set_curr_index(DOWN1);
        break;
    case 21:
        set_curr_index(DOWN2);
        break;
    case 22:
        set_curr_index(DOWN3);
        break;
    case 23:
        set_curr_index(DOWN2);
        break;
    default:
        break;
    }
}

#endif