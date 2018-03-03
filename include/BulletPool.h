#ifndef BULLET_POOL_H_INC
#define BULLET_POOL_H_INC

#include "GameEntity.h"
#include <vector>

typedef float DamageValue;
typedef std::pair<bool,DamageValue> DamageCalculation;

class Bullet;

class BulletManager : public sf::Drawable {
    std::vector<Bullet> bullets;
    float timeElapsedSinceLastShot;
    float whenToShoot;
    size_t howManyToShoot;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    BulletManager();

    /** Creates a bullet at the given pos, traveling at the passed speed
     */
    void createBullet(sf::Vector2f pos, sf::Vector2f speed);

    /**\brief tests if a bullet hit the given entity
     * \return true if a bullet hit the given entity. with a damage calculation
     * 
     * Tests if any bullet hit a given GameEntity if an enemy was hit it will 
     * remove the bullet and return true.
     */
    DamageCalculation testBulletHit(GameEntity& entity);

    /**\brief calls the step function on all managed bullets to move them
     * \param fire whether to spawn new bullets
     */
    void step(float time, sf::Vector2f pos, sf::Vector2f speed, bool fire);
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

#endif // BULLET_POOL_H_INC