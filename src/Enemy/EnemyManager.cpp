#include "Enemy/EnemyManager.h"
#include "Enemy/all.h"

EnemyBase* makeEnemyByName(const std::string& name) {
    if (name == "WW2Plane")
        return new WW2Plane();
    return nullptr;
}