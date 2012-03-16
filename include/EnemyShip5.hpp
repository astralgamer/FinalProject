#ifndef FinalProject_EnemyShip5_h
#define FinalProject_EnemyShip5_h

#include "EnemyShip.hpp"
#include "PlayerBullet.hpp"

class EnemyShip5: public EnemyShip{
public:
	EnemyShip5(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p,Texture text,Texture bul);
	void draw();
	void update();
	void collide();
	Rectf rec;
	EnemyGun* eg1;
	EnemyGun* eg2;
};
#endif