#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Bullet {
public:
    sf::Sprite bullet;
    sf::Texture bulletTexture1, bulletTexture2;
    sf::Vector2f bulletDirection;
    float bulletSpeed;

    Bullet(sf::Vector2f direction, sf::Vector2f position) {
        bulletTexture1.loadFromFile("res/images/m_bullet2.png");
        bulletTexture2.loadFromFile("res/images/bullet2.png");
        bullet.setTexture(bulletTexture1);
        bullet.setScale(2.f, 2.f);
        bulletDirection = direction;
        bulletSpeed = 5;
        bullet.setPosition(position);
    }
};

class Game {
private:
    // Variables
    sf::RenderWindow *window{};
    sf::VideoMode videoMode;
    sf::Event sfEvent{};

    // Mouse positions
    sf::Vector2i mousePosWindow;

    // Game logic
    int points{};
    int health{};
    int maxEnemies{};
    std::vector<Bullet*> bullets;

    // Game Objects
    std::vector<sf::Sprite> enemies;
    sf::Sprite enemy;
    sf::Sprite player;
    sf::Texture enemyTexture;
    sf::Texture playerTexture;

    // Private functions
    void initWindow();
    void initVariables();
    void initEnemies();
    void initPlayer();

public:
    Game();
    virtual ~Game();

    const bool running() const;
    
    void pollEvents();
    void update();
    void updateEnemies();
    void updatePlayer();
    void render();
    void renderEnemies();
    void renderPlayer();
    void renderBullets();
    void updateMousePositions();
    void fireBullet();
    void updateBullet();
    
    // update angle
    void axs();
};
