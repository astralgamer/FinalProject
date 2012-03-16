#ifndef FinalProject_EnemyShip2_h
#define FinalProject_EnemyShip2_h

#include "EnemyShip.hpp"
#include "PlayerBullet.hpp"

class EnemyShip2: public EnemyShip{
public:
	EnemyShip2(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p,Texture text,Texture bul);
	void draw();
	void update();
	void collide();
	Rectf rec;
};
#endif