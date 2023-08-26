#ifndef DYNAMIC_WINDOW_H
#define DYNAMIC_WINDOW_H

#include "../Window.h"
#include <ctime>

size_t getMiliseconds() {return static_cast<size_t>(clock()*1000 / CLOCKS_PER_SEC);}

class DynamicWindow : public Window{

    size_t ms; 
    
protected:
    int fps;
    sf::Event event;
    virtual bool handleEvent() = 0;
    virtual void draw() = 0;
public:
    DynamicWindow();
    //DynamicWindow(const DynamicWindow& _DynamicWindow) = delete;//??
    virtual ~DynamicWindow();

    bool display();


    
};

DynamicWindow::DynamicWindow(){
    _print("DynamicWindow()");
    fps = 25;
    ms = getMiliseconds();
    
}

DynamicWindow::~DynamicWindow(){
    _print("~DynamicWindow()");
}

bool
DynamicWindow::display(){
    // while (std::time(nullptr)/fps - ms != 0){
    //     while(window.pollEvent(event)) 
    //         handleEvent();
    // }
    
    
    //std::cin.get();
    
    //
    if ((getMiliseconds() - ms)*fps/1000 != 0){
        window.clear();
        if (handleEvent()) return 0;
        draw();
        window.display();
        ms = getMiliseconds();
    }
    return 1;
}

#endif