#ifndef WINDOW
#define WINDOW

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <queue>//..
#include <map>
#include <iostream> //..
#define _print(message) std::cout << (message) << std::endl//..
#define __print(message) std::cout << (message) << ' '//..

#include "../GraphicElement/StaticElement/Background/Background.h"

class Window{
    int width;
    int height;
    std::string title;
    Background background;

    
protected:
    

    sf::RenderWindow window;

    int get_width();
    int get_height();
    sf::Sprite get_Sprite_background();

    void set_size(const int & width, const int & height);
    void set_title(const std::string & title);
    void set_background(const TypeBackground & background);

    
public:
    
    Window();
    virtual ~Window();
    
    
};

Window::Window(){
    window.create(sf::VideoMode(640, 480), title);
    
    _print("Window()");
}

int
Window::get_width(){
    return width;
}

int
Window::get_height(){
    return height;
}

sf::Sprite
Window::get_Sprite_background(){
    return background.get_sprite();
}

void
Window::set_size(const int & width, const int & height){
    this->width = width;
    this->height = height;
    window.setSize(sf::Vector2u(width, height));
}

void 
Window::set_title(const std::string & title){
    this->title = title;
    window.setTitle(title);
}

void
Window::set_background(const TypeBackground & background){
    this->background.set_TypeBackground(background);
}

Window::~Window(){
    window.close();
    std::cout << "~Window()" << std::endl;
}



#endif