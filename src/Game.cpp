#include "Game.h"

/**
 * @brief Initialise the Game variables
 * 
 */
void Game::initVariables()
{
    this->endGame = false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxSwagBalls = 10;
    this->points = 0;
}

/**
 * @brief Initialises the fonts of the game
 * 
 */
void Game::initFonts()
{
    if (!this->font.loadFromFile("assets/fonts/Dosis-Light.ttf"))
    {
        throw("ERROR::GAME::COULD NOT LOAD FONT");
    }
}

/**
 * @brief Initialises the text of the game
 * 
 */
void Game::initText()
{
    this->uiText.setFont(this->font);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setCharacterSize(24);
    this->uiText.setString("POINTS: " + std::to_string(this->points));
}

/**
 * @brief Initialises the window of the game
 * 
 */
void Game::initWindow()
{
    this->videoMode = sf::VideoMode(800, 600);
    this->window = new sf::RenderWindow(this->videoMode, "2D Ball Game", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

// Constructors and destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initText();
}

Game::~Game()
{
    delete this->window;
}

// Functions

/**
 * @brief Returns the open state of the window
 * 
 * @return true 
 * @return false 
 */
const bool Game::running() const
{
    return this->window->isOpen();
}

/**
 * @brief Check for events, e.g. closing the window and moving the player
 * 
 */
void Game::pollEvents()
{
    while (this->window->pollEvent(this->sfmlEvent))
    {
        switch (this->sfmlEvent.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

/**
 * @brief Spawn Swag Balls 
 * 
 */
void Game::spawnSwagBalls()
{
    if (this->spawnTimer < this->spawnTimerMax)
    {
        this->spawnTimer += 1.f;
    } 
    else if (this->swagBalls.size() < this->maxSwagBalls)
    {
        this->swagBalls.push_back(SwagBall(*this->window));
        this->spawnTimer = 0.f;
    }
}

/**
 * @brief Detect collisions between player and swag balls
 * 
 */
void Game::updateCollision()
{
    // Check the collision
    for (size_t i = 0; i < this->swagBalls.size(); i++)
    {
        if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
        {
            this->points++;
            this->swagBalls.erase(this->swagBalls.begin() + i);
        }
    }
}

/**
 * @brief Updates the game
 * 
 */
void Game::update()
{
    this->pollEvents();

    this->player.update(this->window);

    this->spawnSwagBalls();

    this->updateCollision();

    this->updateUi();

}

/**
 * @brief Updates the UI text
 * 
 */
void Game::updateUi()
{
    std::stringstream ss;
    
    ss << "POINTS: " << this->points << "\n";
    
    this->uiText.setString(ss.str());
}

/**
 * @brief Renders the UI text
 * 
 * @param target 
 */
void Game::renderUi(sf::RenderTarget* target)
{
    target->draw(this->uiText);
}

/**
 * @brief Renders the game
 * 
 */
void Game::render()
{
    this->window->clear();

    // Render game objects
    for (auto i : this->swagBalls)
    {
        i.render(this->window);
    }

    this->player.render(this->window);
    this->renderUi(this->window);

    this->window->display();
}
