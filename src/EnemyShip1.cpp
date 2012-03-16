#include "EnemyShip1.hpp"

EnemyShip1::EnemyShip1(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,46,46,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
}

void EnemyShip1::update(){
	if(pos.y + 150 >= p->mMouseLoc.y && vel.y > 0 && pos.y-height/2.0 > height/2.0+20)
		vel.y *= -1;
	if(pos.y-height/2.0 < height/2.0 && vel.y < 0)
		vel.y *= -1;
	if(pos.x < width/2.0 + 20 && vel.x < 0)
		vel.x *= -1;
	if(pos.x > 780 - width/2.0 && vel.x > 0)
		vel.x *= -1;
	EnemyShip::update();
}

void EnemyShip1::init(){
	shipTexture = Texture(loadImage(loadResource(RES_ENEMY1)));
	EnemyShip::init();
}

void EnemyShip1::collide(){
	EnemyShip::collide();
}

void  EnemyShip1::draw(){
	if(hp>0)
		gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	EnemyShip::draw();
}



