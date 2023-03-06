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
    int hp;
    int hpMax;

    void initVariables();
    void initShape();

public:
    Player(float posX = 100.f, float posY = 100.f);
    virtual ~Player();

    const sf::RectangleShape& getShape() const;

    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};