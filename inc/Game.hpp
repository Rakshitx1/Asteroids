#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game {
private:
    // Variables
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event sfEvent;

    // Private functions
    void initWindow();
    void initVariables();

public:
    Game();
    virtual ~Game();
    const bool running() const;
    void pollEvents();
    void update();
    void render();
};