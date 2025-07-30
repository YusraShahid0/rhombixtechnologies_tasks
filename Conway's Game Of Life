#include <SFML/Graphics.hpp>
#include "Simulation.hpp"
#include <iostream>
using namespace sf;

void showStartScreen(sf::RenderWindow& window) {
    sf::Texture startTexture;
    if (!startTexture.loadFromFile("start_screen.png")) {
        std::cerr << "Error loading start screen image!" << std::endl;
        return;
    }

    sf::Sprite startSprite;
    startSprite.setTexture(startTexture);

    // Optional: Center the image if it's smaller than the window
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u imageSize = startTexture.getSize();
    startSprite.setPosition(
        (windowSize.x - imageSize.x) / 2,
        (windowSize.y - imageSize.y) / 2
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                return; // Start the simulation
        }

        window.clear();
        window.draw(startSprite);
        window.display();
    }
}


int main() {
    int width = 1600;
    int height = 920;
    int cellSize = 20;

    sf::RenderWindow window(sf::VideoMode(width, height), "Conway's Game of Life - Yusra Shahid");
    window.setFramerateLimit(12);

    // Show the start screen image
    showStartScreen(window);

    // Start simulation
    Simulation sim(width, height, cellSize);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        sim.run(window);
        window.display();
    }
}
