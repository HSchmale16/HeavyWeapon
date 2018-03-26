#include "Enemy/EnemyManager.h"
#include "Enemy/all.h"
#include <iostream>

EnemyBase* makeEnemyByName(const std::string& name) {
    if (name == "WW2Plane")
        return new WW2Plane();
    return nullptr;
}


// ENEMYMANAGER IMPL

EnemyManager::EnemyManager()
: mode(DO_NOTHING) {
    enemiesOnScreen.reserve(ENEMY_RESERVE_CAP);
}

void EnemyManager::resetTime() {
    currentTimeIndex = 0;
}

void EnemyManager::step(float seconds) {
    uint64_t ticksPassed = seconds * 1000;
    currentTimeIndex += ticksPassed;
    switch(mode) {
    case TIMESERIES:
        executeTimeseriesTick(ticksPassed);
        break;
    case DELAY_BASED:
        executeDelayTick(ticksPassed);
        break;
    case DO_NOTHING:
        break;
    }

    for (auto& enemy : enemiesOnScreen) {
        enemy->update(seconds);
    }
}

void EnemyManager::setDoNothing() {
    mode = DO_NOTHING;
}

void EnemyManager::setDelayBased(const TickMap tm) {
    delays.clear();
    for (auto& p : tm) {
        delays.insert({p.first, {0, p.second}});
    }
    mode = DELAY_BASED;
}

// TICK EXECUTORS
void EnemyManager::executeTimeseriesTick(uint64_t ticksPassed) {

}

void EnemyManager::executeDelayTick(uint64_t ticksPassed) {
    static int n = 0;
    ++n;
    for (auto& t : delays) {
        t.second.ticksSinceLastSpawn += ticksPassed;
        if (t.second.ticksSinceLastSpawn > t.second.spawnAfterTicks) {
            enemiesOnScreen.push_back(makeEnemyByName(t.first));
            t.second.ticksSinceLastSpawn = 0;
        }
        if(n % 100 == 0) {
            std::cout << t.first << "  " << t.second.ticksSinceLastSpawn << std::endl;
        }
    }
}

// Draw
void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(EnemyBase* e : enemiesOnScreen) {
        target.draw(*e, states);
    }
}
