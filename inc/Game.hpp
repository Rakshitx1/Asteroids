#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Game {
private:
    // Variables
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event sfEvent;

    // Mouse positions
    sf::Vector2i mousePosWindow;

    // Game Objects
    sf::RectangleShape enemy;

    // Private functions
    void initWindow();
    void initVariables();
    void initEnemies();

public:
    Game();
    virtual ~Game();

    const bool running() const;
    
    void pollEvents();
    void update();
    void render();
    void updateMousePositions();
};