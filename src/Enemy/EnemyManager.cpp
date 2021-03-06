#include "Enemy/EnemyManager.h"
#include "Enemy/all.h"
#include "BulletPool.h"
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

EnemyManager::~EnemyManager() {
    // clear the on screen manager
    auto it = enemiesOnScreen.begin();
    while(it != enemiesOnScreen.end()) {
        delete *it;
        it = enemiesOnScreen.erase(it);
    }

    // clear the priority queue
    while(!tsSpawnQueue.empty()) {
        SpawnTimeFrame frame = tsSpawnQueue.top();
        delete frame.enemy;
        tsSpawnQueue.pop();
    }
}

void EnemyManager::resetTime() {
    currentTimeIndex = 0;
}

void EnemyManager::step(float seconds, BulletManager& bm) {
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

    auto enemyIt = enemiesOnScreen.begin();
    while(enemyIt != enemiesOnScreen.end()) {
        EnemyBase* enemy = *enemyIt;
        enemy->update(seconds);
        DamageCalculation dc = bm.testBulletHit(*enemy);
        enemy->applyDamageCalculation(dc);


        if(enemy->getKilledState()) {
            enemyIt = enemiesOnScreen.erase(enemyIt);
            delete enemy;
        } else {
            ++enemyIt;
        }
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
    /// TODO: Implemnet
}

void EnemyManager::executeDelayTick(uint64_t ticksPassed) {
    for (auto& t : delays) {
        t.second.ticksSinceLastSpawn += ticksPassed;
        if (t.second.ticksSinceLastSpawn > t.second.spawnAfterTicks) {
            enemiesOnScreen.push_back(makeEnemyByName(t.first));
            t.second.ticksSinceLastSpawn = 0;
        }
    }
}

// Draw
void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(EnemyBase* e : enemiesOnScreen) {
        target.draw(*e, states);
    }
}
