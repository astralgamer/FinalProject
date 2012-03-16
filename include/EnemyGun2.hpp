#ifndef FinalProject_EnemyGun2_hpp
#define FinalProject_EnemyGun2_hpp

#include "EnemyGun.hpp"

class EnemyGun2 : public EnemyGun{
public:
    EnemyGun2(float atkspeed);
	void update(Vec2f pos);
    void draw();
};


#endif