#include "BulletPool.h"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f speed)
: velocity(speed.x * SPEED, speed.y * SPEED) {
    shape.setRadius(BASE_BULLET_RADIUS);
    shape.setOrigin(sf::Vector2f(5, 5) / 2.f);
    shape.setPosition(pos);
}

bool Bullet::step(float time) {
    shape.move(velocity * time);
    const sf::Vector2f& pos = shape.getPosition();
    if (pos.x < -50 || pos.y < -50 || pos.x > 850) {
        return true;
    }
    return false;
}

sf::Vector2f Bullet::getPosition() const {
    return shape.getPosition();
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape);
}

/*
 * BulletManager Impl
 */

BulletManager::BulletManager(Game& game)
        : timeElapsedSinceLastShot(0), 
        whenToShoot(TIME_BETWEEN_SHOTS),
        howManyToShoot(BASE_BULLETS_PER_SHOT),
        game(game) {
    bullets.reserve(BULLET_POOL_BASE_SIZE);
}

void BulletManager::createBullet(sf::Vector2f pos, sf::Vector2f vel) {
    bullets.push_back(Bullet(pos, vel));
}

void BulletManager::step(float time, const sf::Vector2f& pos, 
        const sf::Vector2f& speed, bool fire) {
    timeElapsedSinceLastShot += time;
    if (fire && timeElapsedSinceLastShot > whenToShoot) {
        timeElapsedSinceLastShot = 0;
        createBullet(pos, speed);
    }
    // Step each bullet forward
    auto bit = bullets.begin ();
    while (bit != bullets.end ()) {
        if(bit->step (time)) {
            bit = bullets.erase (bit);
        } else {
            ++bit;
        }
    }
}

DamageCalculation BulletManager::testBulletHit(const HealthEntity& he) {
    sf::FloatRect bounds = he.getBounds();
    auto bit = bullets.begin();

    DamageCalculation calculation;

    while (bit != bullets.end ()) {
        if (bounds.contains (bit->getPosition ())) {
            calculation.hit = true;
            /// TODO: Bullet Damage Real Calculation
            calculation.amount += 10.f;
            // rm bullet cause hit
            bit = bullets.erase (bit);
        } else {
            ++bit;
        }
    }
    return calculation;
}

void  BulletManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto& b : bullets)
        target.draw(b);
}
