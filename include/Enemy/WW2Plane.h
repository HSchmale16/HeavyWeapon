#ifndef WW2PLANE_H_INC
#define WW2PLANE_H_INC

#include "EnemyBase.h"

class WW2Plane : public EnemyBase {
public:
    WW2Plane();
    virtual void update(float step);
};


#endif // WW2PLANE_H_INC