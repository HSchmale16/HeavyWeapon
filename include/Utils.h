#ifndef UTILS_H_INC
#define UTILS_H_INC

/**\file Utils.h
 * \author Henry J Schmale
 * 
 * Provides utility functions and random stuff
 * 
 */

#include <SFML/Window.hpp>

struct ControlState {
    bool shootPressed;
    bool moveLeftPressed;
    bool moveRightPressed;
    sf::Vector2i targetPosition;

    ControlState();
};

ControlState getControlState(const sf::Window& window);

#endif // UTILS_H_INC