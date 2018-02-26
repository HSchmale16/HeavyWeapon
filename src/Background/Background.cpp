#include "Background/Background.h"

Background::Background() {

}

void Background::step(float ms) {

}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.clear(sf::Color::Blue);
}
