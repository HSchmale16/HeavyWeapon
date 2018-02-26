#include <iostream>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;

Game game;


int main(int argc, char* argv[]) {

    // Code adapted from the SFML 2 "Window" example.
    sf::RenderWindow app(sf::VideoMode(800, 600), "heavyweapon");
    sf::Font font;
    sf::Text fps_text;

    fps_text.setFont(font);
    fps_text.setCharacterSize(24);
    fps_text.setFillColor(sf::Color::White);

    sf::Clock clock;
    float last_time = 0, current_time, fps, time_delta = 0;

    if (!font.loadFromFile("resources/fonts/F25_Bank_Printer.otf")) {
        return -1;
    }

    app.setFramerateLimit(120);

    while (app.isOpen()) {
        sf::Event Event;
        while (app.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                app.close();
            if (Event.type == sf::Event::LostFocus)
                game.pause();
            if (Event.type == sf::Event::GainedFocus)
                game.resume();
            if (Event.type == sf::Event::Resized) {
                app.setView(sf::View(sf::FloatRect(0, 0,
                    Event.size.width,
                    Event.size.height
                )));
                
            }
        }
        
        char c[20];
        snprintf(c, 20, "%07d fps", (int)fps);
        fps_text.setString(c);

        ControlState cs = getControlState(app);
        game.step(time_delta, cs);

        app.clear(sf::Color::Black);
        app.draw(game);
        app.draw(fps_text);
        app.display();

        // fps
        current_time = clock.restart().asSeconds();
        fps = 1.f / (time_delta = (current_time - last_time));
        last_time = current_time;
    }

    return 0;
}
