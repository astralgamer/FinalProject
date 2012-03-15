#include "EnemyGun1.hpp"

EnemyGun1::EnemyGun1(float atkspeed){
    firing = false;
    t = 0;
	this->atkspeed = atkspeed;
}

void EnemyGun1::update(Vec2f pos)
{
    if(firing){
        if(getElapsedSeconds() - t > 1.0/atkspeed){
            bullets.push_back(new EnemyBullet1(pos,50));
            t = getElapsedSeconds();
        }
    }
    
	for( int i = 0; i < bullets.size();i++){
		EnemyBullet1* b = bullets[i];
        b->update();
		if( b->hp <= 0 ){
			bullets.erase(bullets.begin()+i);
			delete b;
        }
    }
}

void EnemyGun1::draw()
{
   for( int i = 0; i < bullets.size();i++){
		EnemyBullet1* b = bullets[i];
        b->draw();
    }
}
