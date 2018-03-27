#include "HealthEntity.h"
#include <cassert>
#include "Utils.h"

HealthEntity::HealthEntity() 
:max_health(25), current_health(25.f) {
    assert(max_health == current_health);
}

void HealthEntity::applyDamageCalculation(DamageCalculation& dc) {
    if(dc.hit) {
        current_health -= dc.amount;
        cout << getCurrentHealth() << endl;
    }
}
