#include "Player.h"

/**
 * @brief Initialises the variables of the player
 * 
 */
void Player::initVariables()
{
    this->movementSpeed = 5.f;
    this->hpMax = 10;
    this->hp = this->hpMax;
}

/**
 * @brief Initialises the shape of the player
 * 
 */
void Player::initShape()
{
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
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
 * @brief Returns the shape of the player
 * 
 * @return const sf::RectangleShape& 
 */
const sf::RectangleShape &Player::getShape() const
{
    return this->shape;
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
}

/**
 * @brief Updates the player window bounds collision
 * 
 * @param target 
 */
void Player::updateWindowBoundsCollision(const sf::RenderTarget *target)
{
    sf::FloatRect playerBounds = this->shape.getGlobalBounds();

    // Left and Right bounds collision
    if (playerBounds.left <= 0.f)
    {
        this->shape.setPosition(0.f, this->shape.getPosition().y);
    } 
    else if (playerBounds.left + playerBounds.width >= target->getSize().x)
    {
        this->shape.setPosition(target->getSize().x - playerBounds.width, this->shape.getPosition().y);
    }

    // Top andBottom bounds collision
    if (playerBounds.top <= 0.f)
    {
        this->shape.setPosition(this->shape.getPosition().x, 0.f);
    }
    else if (playerBounds.top + playerBounds.height >= target->getSize().y)
    {
        this->shape.setPosition(this->shape.getPosition().x, target->getSize().y - playerBounds.height);
    }
}

/**
 * @brief Updates the player
 * 
 */
void Player::update(const sf::RenderTarget* target)
{
    this->updateInput();

    // Window bounds collision
    this->updateWindowBoundsCollision(target);

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
