#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

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
    int points;

    sf::Font font;
    sf::Text uiText;
    
    std::vector<SwagBall> swagBalls;
    float spawnTimerMax;
    float spawnTimer;
    int maxSwagBalls;

    void initWindow();
    void initVariables();
    void initFonts();
    void initText();

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
    void updateCollision();
    void update();
    void updateUi();
    void renderUi(sf::RenderTarget* target);
    void render();
};