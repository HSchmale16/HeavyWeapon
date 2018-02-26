#include "Utils.h"

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

ControlState getControlState(const sf::Window& window) {
    ControlState cs;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        cs.moveLeftPressed = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        cs.moveRightPressed = true;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        cs.shootPressed = true;
    cs.targetPosition = sf::Mouse::getPosition(window);
    return cs;
}