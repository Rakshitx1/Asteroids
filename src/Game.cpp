#include "Game.hpp"

// Constructors & Destructors

Game::Game() {
    this->initVariables();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

// Functions

void Game::initWindow() {
    // this->videoMode.getDesktopMode();
    // this->videoMode = sf::VideoMode(800, 600);
    this->videoMode.width = 800;
    this->videoMode.height = 600;

    this->window = new sf::RenderWindow(this->videoMode, "SFML Window", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initVariables() {
    this->window = nullptr;
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
}

void Game::render(){
    this->window->clear(sf::Color(0, 0, 0, 0));

    // Render items

    this->window->display();
}

