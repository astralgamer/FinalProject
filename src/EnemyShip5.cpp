#include "EnemyShip5.hpp"

EnemyShip5::EnemyShip5(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,444,200,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	eg.push_back(new EnemyGun(atkspd,p));
	eg.push_back(new EnemyGun(atkspd,p));
}

void  EnemyShip5::update(){
	if(pos.y  >= 300)
		vel.y = 0;
	if(pos.x < width/2.0 + 20 && vel.x < 0)
		vel.x *= -1;
	if(pos.x > 780 - width/2.0 && vel.x > 0)
		vel.x *= -1;
	for(int i=0;i<eg.size();i++)
		eg[i]->firing = firing;
	pos += vel*1/ci::app::AppBasic::get()->getFrameRate();
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	eg[0]->update(Vec2f(pos.x,pos.y+height/2));
	eg[1]->update(Vec2f(pos.x+width/2.0,pos.y-height/2));
	eg[2]->update(Vec2f(pos.x-width/2.0,pos.y-height/2));
}

void EnemyShip5::init(){
	shipTexture = Texture(loadImage(loadResource(RES_ENEMY5)));
	EnemyShip::init();
}

void EnemyShip5::collide(){
	EnemyShip::collide();
}

void  EnemyShip5::draw(){
	if(hp>0)
		gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	EnemyShip::draw();
}



