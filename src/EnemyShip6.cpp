#include "EnemyShip6.hpp"

EnemyShip6::EnemyShip6(float xpos, float ypos, PlayerShip* p,Texture text) : EnemyShip(0,400,0,xpos,ypos,0,0,44,56,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	shipTexture = text;
	initVel = 50;
}

void  EnemyShip6::update(){
	if(p->mMouseLoc.y > pos.y)
		vel.y = initVel;
	else
		vel.y = -initVel;
	if(p->mMouseLoc.x > pos.x)
		vel.x = initVel;
	else
		vel.x = -initVel;
	EnemyShip::update();
	if(t > 1){
		initVel +=25;
		t=0;
	}
	
}

void EnemyShip6::collide(){
	EnemyShip::collide();
}

void  EnemyShip6::draw(){
	if(hp>0)
		gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	EnemyShip::draw();
}




