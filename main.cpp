#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main(int argc, char* argv[]) {

  // Code adapted from the SFML 2 "Window" example.

  cout << "Version " << heavyweapon_VERSION_MAJOR << "." << heavyweapon_VERSION_MINOR << endl;

  sf::Window App(sf::VideoMode(800, 600), "heavyweapon");

  while (App.isOpen()) {
    sf::Event Event;
    while (App.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed)
	App.close();
    }
    App.display();
  }
}
