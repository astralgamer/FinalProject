#include "EnemyGun.hpp"

EnemyGun::EnemyGun(float atkspd, Texture text,PlayerShip* p){
    this->p = p;
	firing = false;
    t = 0;
	bulletTexture = text;
	this->atkspd = atkspd;
}

void EnemyGun::update(Vec2f pos)
{
	t += 1/ci::app::AppBasic::get()->getFrameRate();
    if(firing){
        if( t > 1.0/atkspd){
            bullets.push_back(new EnemyBullet(pos,50,15,Vec2f(0,15)));
            t = 0;
        }
    }
    
	for( int i = 0; i < bullets.size();i++){
        bullets[i]->update();
		bullets[i]->collide(p);
		if( bullets[i]->hp <= 0){
			delete bullets[i];
			bullets.erase(bullets.begin()+i);
        }
    }
}

void EnemyGun::draw()
{
   for( int i = 0; i < bullets.size();i++){
        bullets[i]->draw(bulletTexture);
    }
}
