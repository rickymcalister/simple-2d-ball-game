#pragma once

#include <iostream>
#include <ctime>
#include <vector>

#include "Player.h"
#include "SwagBall.h"

class Game
{
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event sfmlEvent;

    Player player;
    
    std::vector<SwagBall> swagBalls;
    float spawnTimerMax;
    float spawnTimer;
    int maxSwagBalls;

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

    void spawnSwagBalls();
    void update();
    void render();
};