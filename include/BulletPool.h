#ifndef BULLET_POOL_H_INC
#define BULLET_POOL_H_INC

#include "HealthEntity.h"
#include <vector>


class Bullet;
class Game;

/** Manages the bullets on screen, and how they spawn
 */
class BulletManager : public sf::Drawable {
    std::vector<Bullet> bullets;
    float timeElapsedSinceLastShot;
    float whenToShoot;
    size_t howManyToShoot;
    Game& game;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    BulletManager(Game& game);

    /** Creates a bullet at the given pos, traveling at the passed speed
     */
    void createBullet(sf::Vector2f pos, sf::Vector2f speed);

    /**\brief tests if a bullet hit the given entity
     * \return true if a bullet hit the given entity. with a damage calculation
     * 
     * Tests if any bullet hit a given GameEntity if an enemy was hit it will 
     * remove the bullet and return true.
     */
    DamageCalculation testBulletHit(HealthEntity& entity);

    /**\brief Steps the bullet management forward
     * \param fire whether to spawn new bullets
     * 
     * This will spawn a new bullet if fire is pressed, and then step each of the 
     * bullets on screen forward.
     */
    void step(
        float time, 
        const sf::Vector2f& pos, 
        const sf::Vector2f& speed,
        bool fire);
};

class Bullet : public sf::Drawable {
private:
    static const constexpr float SPEED = 300.f;
    sf::CircleShape shape;
    sf::Vector2f velocity;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Bullet(sf::Vector2f pos, sf::Vector2f speed);

    /**\return true if this bullet should be removed
     */
    bool step(float time);
};

const size_t BULLET_POOL_BASE_SIZE = 2000;
const float TIME_BETWEEN_SHOTS = 0.5f;
const float BASE_BULLET_RADIUS = 1.0f;
const size_t BASE_BULLETS_PER_SHOT = 1;

#endif // BULLET_POOL_H_INC