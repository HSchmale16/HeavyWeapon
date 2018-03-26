#ifndef WW2PLANE_H_INC
#define WW2PLANE_H_INC

#include "EnemyBase.h"

class WW2Plane : public EnemyBase {
    const float SPEED_PER_SEC = -100.0f;
    const std::string SPRITESHEET_PATH = "resources/textures/TestEnemy.png";
public:
    WW2Plane();
    virtual void update(float step);
};


#endif // WW2PLANE_H_INC