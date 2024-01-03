#include "Game.hpp"

bool a = false;
bool b = false;
bool c = false;
bool d = false;
bool e = false;

// Constructors & Destructors

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
    this->initPlayer();
    this->bullets.clear();
}

Game::~Game() {
    delete this->window;
}

// Functions

void Game::initWindow() {
    /*
    Other options:
        this->videoMode = sf::VideoMode(800, 600);
        this->videoMode.width = SCREEN_WIDTH;
        this->videoMode.height = SCREEN_HEIGHT;
    */

    this->videoMode = sf::VideoMode::getDesktopMode();
    this->window = new sf::RenderWindow(this->videoMode, "SFML Window", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);

    this->window->setFramerateLimit(60);
    
}

void Game::initVariables() {
    this->window = nullptr;
    this->points = 0;
    this->health = 10;
    this->maxEnemies = 9;
}

void Game::initEnemies() {
    
}

void Game::initPlayer() {
    if(!this->playerTexture.loadFromFile("res/images/player.png")) {
        std::cout << "ERROR::GAME::INITPLAYER::Failed to load player texture!" << std::endl;
    }
    this->player.setTexture(this->playerTexture);
    this->player.setOrigin(this->player.getGlobalBounds().width / 2, this->player.getGlobalBounds().height / 2);
    this->player.setScale(0.3f, 0.3f);
    this->player.setPosition(this->videoMode.width / 2, this->videoMode.height / 2);
    this->player.setRotation(-90.f);
}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->sfEvent)) {
        switch (this->sfEvent.type) {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if (this->sfEvent.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                    break;
                }
                if (this->sfEvent.key.code == sf::Keyboard::W || this->sfEvent.key.code == sf::Keyboard::Up) {
                    a = true;
                }
                if (this->sfEvent.key.code == sf::Keyboard::S || this->sfEvent.key.code == sf::Keyboard::Down) {
                    b = true;
                }
                if (this->sfEvent.key.code == sf::Keyboard::A || this->sfEvent.key.code == sf::Keyboard::Left) {
                    c = true;
                }
                if (this->sfEvent.key.code == sf::Keyboard::D || this->sfEvent.key.code == sf::Keyboard::Right) {
                    d = true;
                }
                if(this->sfEvent.key.code == sf::Keyboard::Space) {
                    e = true;
                }
                break;

            case sf::Event::KeyReleased:
                if (this->sfEvent.key.code == sf::Keyboard::W || this->sfEvent.key.code == sf::Keyboard::Up) {
                    a = false;
                }
                if (this->sfEvent.key.code == sf::Keyboard::S || this->sfEvent.key.code == sf::Keyboard::Down) {
                    b = false;
                }
                if (this->sfEvent.key.code == sf::Keyboard::A || this->sfEvent.key.code == sf::Keyboard::Left) {
                    c = false;
                }
                if (this->sfEvent.key.code == sf::Keyboard::D || this->sfEvent.key.code == sf::Keyboard::Right) {
                    d = false;
                }
                if(this->sfEvent.key.code == sf::Keyboard::Space) {
                    e = false;
                }
                break;
    }
    }
    if (b) {
        this->enemy.move(
            -std::cos((this->enemy.getRotation() - 90) * M_PI / 180.f) * 4.f,
            -std::sin((this->enemy.getRotation() - 90) * M_PI / 180.f) * 4.f
        );
    }
    if (c) {
        this->enemy.rotate(-3.f);
    }
    if (d) {
        this->enemy.rotate(3.f);
        }
    if (b) {
        this->enemy.move(
            -std::cos((this->enemy.getRotation() - 90) * M_PI / 180.f) * 4.f,
            -std::sin((this->enemy.getRotation() - 90) * M_PI / 180.f) * 4.f
        );
    }
    if (c) {
        this->enemy.rotate(-3.f);
    }
    if (d) {
        this->enemy.rotate(3.f);
    }
}


void Game::update(){
    this->pollEvents();
    // this->updateMousePositions();
    this->updateEnemies();
    this->updatePlayer();
    this->updateBullet();
}

void Game::updateEnemies() {

}

void Game::updatePlayer() {
    const float playerSpeed = 9.6f;  // Adjust the player's movement speed as needed

    // Update player position based on input
    if (a) {
        this->player.move(
            std::cos((this->player.getRotation()) * M_PI / 180.f) * playerSpeed,
            std::sin((this->player.getRotation()) * M_PI / 180.f) * playerSpeed
        );
    }
    if (b) {
        this->player.move(
            -std::cos((this->player.getRotation()) * M_PI / 180.f) * playerSpeed,
            -std::sin((this->player.getRotation()) * M_PI / 180.f) * playerSpeed
        );
    }
    if (c) {
        this->player.rotate(-3.f);
    }
    if (d) {
        this->player.rotate(3.f);
    }

    // Wrap player around the window if it goes beyond its boundaries
    const sf::Vector2f& playerPosition = this->player.getPosition();
    const sf::Vector2u& windowSize = this->window->getSize();

    if (playerPosition.x > windowSize.x) {
        this->player.setPosition(0.f, playerPosition.y);
    } else if (playerPosition.x < 0.f) {
        this->player.setPosition(windowSize.x, playerPosition.y);
    }

    if (playerPosition.y > windowSize.y) {
        this->player.setPosition(playerPosition.x, 0.f);
    } else if (playerPosition.y < 0.f) {
        this->player.setPosition(playerPosition.x, windowSize.y);
    }
}


void Game::render(){
    this->window->clear(sf::Color(0, 0, 0, 0));

    // Render game objects
    this->renderPlayer();

    this->renderBullets();

    this->window->display();
}

void Game::renderEnemies() {
    // for (auto &e : this->enemies) {
    //     this->window->draw(e);
    // }
}

void Game::renderPlayer() {
    this->window->draw(this->player);
}

void Game::updateMousePositions(){
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::updateBullet() {
    if (e) {
        // Calculate the initial position of the bullet based on the player's position and rotation
        sf::Vector2f bulletDirection(std::cos((this->player.getRotation()) * M_PI / 180.f),
                                     std::sin((this->player.getRotation()) * M_PI / 180.f));

        // sf::Vector2f bulletInitialPosition = this->player.getPosition();// + bulletDirection; // Adjust with playerSize if needed

        sf::Vector2f bulletInitialPosition(this->player.getPosition().x + bulletDirection.x - 15.f, this->player.getPosition().y + bulletDirection.y );

        // Create a new bullet and set its properties
        Bullet* newBullet = new Bullet(bulletDirection, bulletInitialPosition);
        newBullet->bullet.setRotation(this->player.getRotation());

        // std::cout << "Bullet rotation: " << newBullet->bullet.getRotation() << std::endl;

        if(newBullet->bullet.getRotation() >= 90 && newBullet->bullet.getRotation() <= 270) {
            newBullet->bullet.setTexture(newBullet->bulletTexture2);
        }

        // Add the new bullet to the bullets vector
        this->bullets.push_back(newBullet);

        // e = false;
    }

    // Use a separate vector to store bullets to be removed
    std::vector<Bullet*> bulletsToRemove;

    for (auto &b : this->bullets) {
        b->bullet.move(
            // std::cos(() * M_PI / 180.f) * 4.f,
            // std::sin(() * M_PI / 180.f) * 4.f
            b->bulletDirection * b->bulletSpeed
        );

        if (b->bullet.getPosition().x < 0 || b->bullet.getPosition().x > this->window->getSize().x ||
            b->bullet.getPosition().y < 0 || b->bullet.getPosition().y > this->window->getSize().y) {
            
            // Add bullets to be removed to the separate vector
            bulletsToRemove.push_back(b);
        }

        // std::cout << "no. of bullets: " << this->bullets.size() << std::endl;
    }

    // Remove bullets from the main vector
    for (auto &b : bulletsToRemove) {
        this->bullets.erase(std::remove(this->bullets.begin(), this->bullets.end(), b), this->bullets.end());
        delete b;  // Delete the bullet
    }
}

void Game::renderBullets() {
    for (auto &b : this->bullets) {
        // this->window->draw(b.bullet);
        this->window->draw(b->bullet);
    }
}
