#include "Player.h"

/**
 * @brief Initialises the variables of the player
 * 
 */
void Player::initVariables()
{
    this->movementSpeed = 5.f;
}

/**
 * @brief Initialises the shape of the player
 * 
 */
void Player::initShape()
{
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setOrigin(this->shape.getSize().x / 2.f, this->shape.getSize().y / 2.f);
}

/**
 * @brief Construct a new Player:: Player object
 * 
 * @param posX
 * @param posY 
 */
Player::Player(float posX, float posY)
{
    this->shape.setPosition(posX, posY);

    this->initVariables();
    this->initShape();
}

/**
 * @brief Destroy the Player:: Player object
 * 
 */
Player::~Player()
{

}

/**
 * @brief Updates the player movement input
 * 
 */
void Player::updateInput()
{
    // Horizontal movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->shape.move(-this->movementSpeed, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->shape.move(this->movementSpeed, 0.f);
    }

    // Vertical movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        this->shape.move(0.f, -this->movementSpeed);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        this->shape.move(0.f, this->movementSpeed);
    }

    // Rotation
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        this->shape.rotate(-this->movementSpeed);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        this->shape.rotate(this->movementSpeed);
    }
}

/**
 * @brief Updates the player
 * 
 */
void Player::update()
{
    // Window bounds collision

    this->updateInput();
}

/**
 * @brief Renders the player to the target (e.g. Game Window)
 * 
 * @param target 
 */
void Player::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}
