#pragma once

#include <iostream>
#include <ctime>

#include "Player.h"

class Game
{
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event sfmlEvent;

    Player player;

    void initWindow();
    void initVariables();

public:
    // Constructors and destructors
    Game();
    ~Game();

    // Accessors

    // Modifiers

    // Functions
    const bool running() const;
    void pollEvents();

    void update();
    void render();
};