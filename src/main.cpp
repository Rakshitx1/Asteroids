#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    sf::Event ev;
    int i = 0;

    while (window.isOpen()){
        while (window.pollEvent(ev)){
            if (ev.type == sf::Event::Closed){
                window.close();
            }
            if (sf::Event::KeyPressed){
                if (ev.key.code == sf::Keyboard::Escape){
                    window.close();
                    break;
                }

            }
        }

        if(i % 2 == 0){
            window.clear(sf::Color::Black);
        }
        else{
            window.clear(sf::Color::Blue);
        }
        i++;
        window.display();
    }


    return 0;
}
