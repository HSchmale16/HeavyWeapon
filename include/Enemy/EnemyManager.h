#ifndef ENEMY_MANAGER_H_INC
#define ENEMY_MANAGER_H_INC

#include "EnemyBase.h"
#include <cstdint>
#include <queue>

/** Constructs a requested enemy by name.
 * You are responsible for deleting the returned enemy when it's done
 * with it. Otherwise there will be a memory leak.
 */
EnemyBase* makeEnemyByName(const std::string& name);

enum EnemySpawnManagerMode {
    /// The enemy manager will do nothing. This is default
    DO_NOTHING, 
    /// A timeseries is loaded and used to determine when to spawn enemies
    TIMESERIES,
    /// Enemies are spawned according to ticks
    DELAY_BASED,
};

/**
 * A tick map is a mapping of valid enemy constructor strings to
 * a number ticks that must pass before that is spawned again.
 */
typedef std::map<std::string,uint64_t> TickMap;

/**
 * Provides enemy spawning.
 * 
 * Supports 2 types of spawning
 * 
 * 1.) Spawn enemies based on the definition stored in a file
 * 2.) Spawn enemies infinitely
 */
class EnemyManager : public sf::Drawable {
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    uint64_t currentTimeIndex;
    std::vector<EnemyBase*> enemiesOnScreen;
    EnemySpawnManagerMode mode;
    
    // DELAY BASED SPAWNING
    struct DelayValue {
        uint64_t ticksSinceLastSpawn;
        uint64_t spawnAfterTicks;
    };
    std::map<std::string,DelayValue> delays;

    void executeDelayTick(uint64_t ticksPassed);

    // TIMSERIES Spawning
    struct SpawnTimeFrame {
        long timeIndex;
        EnemyBase* enemy;
        
        bool operator<(const SpawnTimeFrame& rhs) const {
            return timeIndex < rhs.timeIndex;
        }
    };
    std::priority_queue<SpawnTimeFrame> tsSpawnQueue;

    void executeTimeseriesTick(uint64_t ticksPassed);
public:
    EnemyManager();

    void resetTime();

    EnemySpawnManagerMode getMode() const;

    void step(float seconds);

    void setDoNothing();

    void setTimeseries(const std::string&);

    void setDelayBased(const TickMap tm);
};


const size_t ENEMY_RESERVE_CAP = 50;

#endif // ENEMY_MANAGER_H_INC