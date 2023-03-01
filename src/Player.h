#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
    sf::RectangleShape shape;

    float movementSpeed;

    void initVariables();
    void initShape();

public:
    Player(float posX = 100.f, float posY = 100.f);
    virtual ~Player();

    void updateInput();
    void update();
    void render(sf::RenderTarget* target);
};