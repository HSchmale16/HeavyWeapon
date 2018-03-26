#ifndef ENEMY_MANAGER_H_INC
#define ENEMY_MANAGER_H_INC

#include "EnemyBase.h"

/** Constructs a requested enemy by name
 */
EnemyBase* makeEnemyByName(std::string name);

/**
 * Provides enemy spawning.
 * 
 * Supports 2 types of spawning
 * 
 * 1.) Spawn enemies based on the definition stored in a file
 * 2.) Spawn enemies infinitely
 */
class EnemyManager {
public:

};


#endif // ENEMY_MANAGER_H_INC