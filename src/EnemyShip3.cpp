#include "EnemyShip3.hpp"

EnemyShip3::EnemyShip3(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,40,54,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
}

void  EnemyShip3::update(){
	if(p->mMouseLoc.y > pos.y)
		vel.y = 75;
	else
		vel.y = -75;
	if(p->mMouseLoc.x > pos.x)
		vel.x = 75;
	else
		vel.x = -75;
	EnemyShip::update();
	if(pos.x-width-200 < p->mMouseLoc.x && pos.x+width+200 > p->mMouseLoc.x && hp > 0){
		if(pos.y < p->mMouseLoc.y)
			firing=true;
	}
	else
		firing=false;
	for(int i=0;i<eg.size();i++){
		eg[i]->firing = firing;
		eg[i]->update(Vec2f(pos.x,pos.y-height/2),Vec2f(0,5));
	}
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