#include "Game.h"

void Game::initVariables()
{
    this->endGame = false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxSwagBalls = 10;
}

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
}

Game::~Game()
{
    delete this->window;
}

// Functions

const bool Game::running() const
{
    return this->window->isOpen();
}

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

void Game::update()
{
    this->pollEvents();

    this->player.update(this->window);

    this->spawnSwagBalls();

}

void Game::render()
{
    this->window->clear();

    // Render game objects
    for (auto i : this->swagBalls)
    {
        i.render(this->window);
    }

    this->player.render(this->window);

    this->window->display();
}
