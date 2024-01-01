#include "Game.hpp"

// Constructors & Destructors

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game() {
    delete this->window;
}

// Functions

void Game::initWindow() {
    // this->videoMode.getDesktopMode();
    // this->videoMode = sf::VideoMode(800, 600);
    this->videoMode.width = SCREEN_WIDTH;
    this->videoMode.height = SCREEN_HEIGHT;

    this->window = new sf::RenderWindow(this->videoMode, "SFML Window", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initEnemies() {
    this->enemy.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f);
    this->enemy.setOrigin(sf::Vector2f(50.f, 50.f));
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Blue); 
    this->enemy.setOutlineThickness(10.f);
}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents(){
    while(this->window->pollEvent(this->sfEvent)){
        switch(this->sfEvent.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            
            case sf::Event::KeyPressed:
                if(this->sfEvent.key.code == sf::Keyboard::Escape){
                    this->window->close();
                    break;
                }

                        
        }
    }
}

void Game::update(){
    this->pollEvents();
    this->updateMousePositions();
}

void Game::render(){
    this->window->clear(sf::Color(0, 0, 0, 0));

    // Draw game objects
    this->window->draw(this->enemy);

    this->window->display();
}

void Game::updateMousePositions(){
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}
