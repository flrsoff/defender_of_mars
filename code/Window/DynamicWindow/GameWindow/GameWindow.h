#ifndef GAME_WINDOW
#define GAME_WINDOW

#include "../DynamicWindow.h"
#include "../../../GraphicElement/StaticElement/Rocket/Rocket.h"
#include "../../../GraphicElement/DynamicElement/Entity/PositiveEntity/PositiveEntity.h"
class GameWindow : public DynamicWindow{
    short move_key = 0; //---- udlr 8421

protected:
    void draw();
    bool handleEvent();
    Rocket rocket;
    PositiveEntity positive_entity;
    
public:
    GameWindow();
    GameWindow(const int& width, const int& height, const std::string& title);
    GameWindow(const GameWindow& _GameWindow) = delete;
    ~GameWindow();

};

GameWindow::GameWindow(){
    _print("GameWindow()");
    this->set_title("GameWindow");
    this->set_background(mars);
    rocket.set_position(this->get_width() / 2 - rocket.get_sprite().getTextureRect().width, 
    this->get_height() / 2 - rocket.get_sprite().getTextureRect().height/2);
    
    positive_entity.set_position(this->get_width() / 2 - positive_entity.get_sprite().getTextureRect().width, 
    this->get_height() / 2 - positive_entity.get_sprite().getTextureRect().height/2);
}

GameWindow::GameWindow(const int& width, const int& height, const std::string& title){
    _print("GameWindow(par)");
    
    this->set_size(width, height);
    this->set_title(title);
    this->set_background(mars);
    rocket.set_position(this->get_width() / 2 - rocket.get_sprite().getTextureRect().width / 2, 
    this->get_height() / 2 - rocket.get_sprite().getTextureRect().height/2);
    
    positive_entity.set_position(this->get_width() / 2 - positive_entity.get_sprite().getTextureRect().width, 
    this->get_height() / 2 - positive_entity.get_sprite().getTextureRect().height/2);
}

GameWindow::~GameWindow(){
    _print("~GameWindow()");
    
}

void GameWindow::draw(){
    window.draw(this->get_Sprite_background());
    window.draw(rocket.get_sprite());
    window.draw(positive_entity.get_current_Sprite(fps));
}

bool GameWindow::handleEvent(){
    
    while(window.pollEvent(event)){
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            // if (event.key.code == sf::Keyboard::W){
            //     move_key |= 8;
            // }
            // if (event.key.code == sf::Keyboard::S){
            //     move_key |= 4;
            // }
            // if (event.key.code == sf::Keyboard::A){
            //     move_key |= 2;
            // }
            // if (event.key.code == sf::Keyboard::D){
            //     move_key |= 1;
            // }
            switch (event.key.code)
            {
            case sf::Keyboard::W:
                move_key |= 8;
                //positive_entity.Up();
                break;
            case sf::Keyboard::S:
                move_key |= 4;
                //positive_entity.Down();
                break;
            case sf::Keyboard::A:
                move_key |= 2;
                //positive_entity.Left();
                break;
            case sf::Keyboard::D:
                move_key |= 1;
                //positive_entity.Right();
                break;
            default:
                break;
            }
            break;
        case sf::Event::KeyReleased:
            
            switch (event.key.code)
            {
            case sf::Keyboard::W:
                move_key -= (move_key & 8);
                //positive_entity.Up();
                break;
            case sf::Keyboard::S:
                move_key -= (move_key & 4);
                //positive_entity.Down();
                break;
            case sf::Keyboard::A:
                move_key -= (move_key & 2);
                //positive_entity.Left();
                break;
            case sf::Keyboard::D:
                move_key -= (move_key & 1);
                //positive_entity.Right();
                break;
            default:
                break;
            }
            break;
        case sf::Event::Closed:
            return 1;
       
        }
    } 
    positive_entity.move_PositiveEntity(move_key);
    return 0;
}

#endif
