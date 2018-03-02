#ifndef UTILS_H_INC
#define UTILS_H_INC

/**\file Utils.h
 * \author Henry J Schmale
 * 
 * Provides utility functions and random stuff
 * 
 */
#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

struct ControlState {
    bool shootPressed;
    bool moveLeftPressed;
    bool moveRightPressed;
    sf::Vector2f targetPosition;

    ControlState();
};

ControlState getControlState(const sf::RenderWindow& window);

/**
 * Attempts to get the requested texture from a map<path,texture> 
 * otherwise it will load it from disk placing it into the cache.
 */
const sf::Texture* getOrLoadTexture(const std::string& path);

sf::Vector2f operator/(sf::Vector2f v, int l);

sf::Vector2f operator*(const sf::Vector2f& left, const sf::Vector2f& right);


#endif // UTILS_H_INC