#include "EnemyShip3.hpp"

EnemyShip3::EnemyShip3(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,40,54,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
}

void  EnemyShip3::update(){
	if(p->mMouseLoc.y > pos.y)
		vel.y = 50;
	else
		vel.y = -50;
	if(p->mMouseLoc.x > pos.x)
		vel.x = 50;
	else
		vel.x = -50;
	EnemyShip::update();
}

void EnemyShip3::init(){
	shipTexture = Texture(loadImage(loadResource(RES_ENEMY3)));
	EnemyShip::init();
}

void EnemyShip3::collide(){
	EnemyShip::collide();
}

void  EnemyShip3::draw(){
	if(hp>0)
		gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	EnemyShip::draw();
}