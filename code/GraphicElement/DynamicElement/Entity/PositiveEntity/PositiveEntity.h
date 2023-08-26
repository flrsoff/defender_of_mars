#ifndef POSITIVE_ENTITY_H
#define POSITIVE_ENTITY_H

#include "../Entity.h"
#define convert

enum CurrentMovement{
    _none = 0,
    _up = 1,
    _down = 2,
    _left = 3,
    _right = 4
};

class PositiveEntity : public Entity{
    CurrentMovement current_movent = _none;
public:
    PositiveEntity();
    ~PositiveEntity();
    
    void Up();
    void Down();
    void Left();
    void Right();
    void UpLeft();
    void UpRight();
    void DownLeft();
    void DownRight();
    
    void handle_current_event(const int & fps);
    void move_PositiveEntity(const short & move_key);
};

PositiveEntity::PositiveEntity(){
    textures = new sf::Texture[12];

    speed = 100;
    speed_steep = 15;

    this->loadTexture("../resources/images/positiveEntity/UP1.png", UP1);
    this->loadTexture("../resources/images/positiveEntity/UP2.png", UP2);
    this->loadTexture("../resources/images/positiveEntity/UP3.png", UP3);
    this->loadTexture("../resources/images/positiveEntity/DOWN1.png", DOWN1);
    this->loadTexture("../resources/images/positiveEntity/DOWN2.png", DOWN2);
    this->loadTexture("../resources/images/positiveEntity/DOWN3.png", DOWN3);
    this->loadTexture("../resources/images/positiveEntity/LEFT1.png", LEFT1);
    this->loadTexture("../resources/images/positiveEntity/LEFT2.png", LEFT2);
    this->loadTexture("../resources/images/positiveEntity/LEFT3.png", LEFT3);
    this->loadTexture("../resources/images/positiveEntity/RIGHT1.png", RIGHT1);
    this->loadTexture("../resources/images/positiveEntity/RIGHT2.png", RIGHT2);
    this->loadTexture("../resources/images/positiveEntity/RIGHT3.png", RIGHT3);

    sf::RenderWindow _window(sf::VideoMode(640,480), "back ground");
    moment_of_motion = 16 + 3;
    selectTexture();
    
}

PositiveEntity::~PositiveEntity(){
    delete [] textures;
}



void PositiveEntity::Up(){
    if (current_movent == _none) {current_movent = _up; moment_of_motion = 32 + 3;}
}

void PositiveEntity::Down(){
    if (current_movent == _none) {current_movent = _down; moment_of_motion = 16 + 3;}
}

void PositiveEntity::Left(){
    if (current_movent == _none) {current_movent = _left; moment_of_motion = 8 + 3;}
}

void PositiveEntity::Right(){
    if (current_movent == _none) {current_movent = _right; moment_of_motion = 4 + 3;}
}

void PositiveEntity::UpLeft()
{
    if (current_movent == _none) {current_movent = _up; moment_of_motion = 32 + 8 + 3;}
}

void PositiveEntity::UpRight()
{
    if (current_movent == _none) {current_movent = _up; moment_of_motion = 32 + 4 + 3;}
}

void PositiveEntity::DownLeft()
{
    if (current_movent == _none) {current_movent = _up; moment_of_motion = 16 + 8 + 3;}
}

void PositiveEntity::DownRight()
{
    if (current_movent == _none) {current_movent = _up; moment_of_motion = 16 + 4 + 3;}
}

void PositiveEntity::handle_current_event(const int & fps){
    //_print("PositiveEntity::handle_current_event(const int & fps)");
    if (current_movent != _none){
        //__print(8 & 3); 

        tact++; tact_++;
        if (speed_steep * tact / fps != 0){
            moment_of_motion++;
            tact = 0;
            if (int(moment_of_motion & 3) == 0) {moment_of_motion -= 4;}
            else if (int(moment_of_motion & 3) == 3) {
                tact = 0;
                current_movent = _none;
            }selectTexture();
        }
        if (speed * tact_ / fps != 0){
            if (int(moment_of_motion)&32) moveUp(speed * tact_ / fps);
            if (int(moment_of_motion)&16) moveDown(speed * tact_ / fps);
            if (int(moment_of_motion)&8) moveLeft(speed * tact_ / fps);
            if (int(moment_of_motion)&4) moveRight(speed * tact_ / fps);
            tact_ = 0;
        }
    } 
}

void PositiveEntity::move_PositiveEntity(const short &move_key)
{
    //---- udlr 8421
    if ((move_key & 8) && !(move_key & 4) && !(move_key & 2) && !(move_key & 1)) Up();
    if (!(move_key & 8) && (move_key & 4) && !(move_key & 2) && !(move_key & 1)) Down();
    if (!(move_key & 8) && !(move_key & 4) && (move_key & 2) && !(move_key & 1)) Left();
    if (!(move_key & 8) && !(move_key & 4) && !(move_key & 2) && (move_key & 1)) Right();
    if ((move_key & 8) && !(move_key & 4) && (move_key & 2) && !(move_key & 1)) UpLeft();
    if ((move_key & 8) && !(move_key & 4) && !(move_key & 2) && (move_key & 1)) UpRight();
    if (!(move_key & 8) && (move_key & 4) && (move_key & 2) && !(move_key & 1)) DownLeft();
    if (!(move_key & 8) && (move_key & 4) && !(move_key & 2) && (move_key & 1)) DownRight();
}
#endif