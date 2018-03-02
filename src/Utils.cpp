#include "Utils.h"

#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

/**\file Utils.cpp
 * \author Henry J Schmale
 * 
 * Provides basic utility functions implementation
 */

ControlState::ControlState() 
: shootPressed(false), moveLeftPressed(false), moveRightPressed(false),
targetPosition(0, 0) {}

ControlState getControlState(const sf::RenderWindow& window) {
    ControlState cs;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        cs.moveLeftPressed = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        cs.moveRightPressed = true;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        cs.shootPressed = true;
    cs.targetPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    return cs;
}

const sf::Texture* getOrLoadTexture(const std::string& path) {
    static std::map<std::string,sf::Texture> textureCache;
    auto it = textureCache.find(path);
    if (it == textureCache.end()) {
        sf::Texture newTexture;
        if(!newTexture.loadFromFile(path)) {
            cout << "FAILED TO LOAD TEXTURE FROM: " << path << endl;
            return nullptr;
        }
        textureCache.insert({path, newTexture});
        return &textureCache.find(path)->second;
    }
    return &it->second;
}

sf::Vector2f operator/(sf::Vector2f v, int l) {
    return sf::Vector2f(v.x / l, v.y / l);
}

sf::Vector2f operator*(const sf::Vector2f& left, const sf::Vector2f& right) {
    return sf::Vector2f(left.x * right.x, left.y * right.y);
}