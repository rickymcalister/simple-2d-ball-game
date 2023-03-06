#include "SwagBall.h"

/**
 * @brief Initialises the shape, colour, size and position of the swag ball
 * 
 * @param window 
 */
void SwagBall::initShape(const sf::RenderWindow& window)
{
    this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
    sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    this->shape.setFillColor(color);
    this->shape.setPosition(
        sf::Vector2f(
            static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
            static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)
        )
    );
}

/**
 * @brief Construct a new Swag Ball:: Swag Ball object
 * 
 * @param window 
 */
SwagBall::SwagBall(const sf::RenderWindow& window)
{
    this->initShape(window);
}

/**
 * @brief Destroy the Swag Ball:: Swag Ball object
 * 
 */
SwagBall::~SwagBall()
{

}

void SwagBall::update()
{

}

/**
 * @brief  Renders the swag ball to the target
 * 
 * @param target 
 */
void SwagBall::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}
