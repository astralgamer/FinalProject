#include "EnemyBullet1.hpp"

#define SPEED 20
EnemyBullet1::EnemyBullet1(Vec2f pos, int hp){
	this->pos = pos;
	this->hp = hp;
	this->radius = 5;
	vel = Vec2f(0,-100);
	t = 0;
}
void EnemyBullet1::collide(PlayerShip* p){

}

void EnemyBullet1::draw(){
	gl::draw( Texture( loadImage( loadResource( RES_EBULLET1 ) ) ),pos);
}

void EnemyBullet1::update(){
	pos += vel*(getElapsedSeconds()-t);
	t = getElapsedSeconds();
}
