#include "EnemyShip2.hpp"

EnemyShip2::EnemyShip2(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel, PlayerShip* p) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,60,74,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	eg.push_back(new EnemyGun(atkspd,p));

}

void EnemyShip2::update(){
	if(pos.y + 150 >= p->mMouseLoc.y && vel.y > 0 && pos.y > height*1.5+20)
		vel.y *= -1;
	if(pos.y-height/2.0 < height/2.0 && vel.y < 0)
		vel.y *= -1;
	if(pos.x < width/2.0 + 20 && vel.x < 0)
		vel.x *= -1;
	if(pos.x > 780 - width/2.0 && vel.x > 0)
		vel.x *= -1;
	EnemyShip::update();
	if(pos.x-width-200 < p->mMouseLoc.x && pos.x+width+200 > p->mMouseLoc.x && hp > 0){
		if(pos.y < p->mMouseLoc.y)
			firing=true;
	}
	else
		firing=false;
	for(int i=0;i<eg.size();i++)
		eg[i]->firing = firing;
	eg[0]->update(Vec2f(pos.x-width/3,pos.y-height/2),Vec2f(-5,8));
	eg[1]->update(Vec2f(pos.x+width/3,pos.y-height/2),Vec2f(5,8));
}

void EnemyShip2::init(){
	shipTexture = Texture(loadImage(loadResource(RES_ENEMY2)));
	EnemyShip::init();
}

void EnemyShip2::collide(){
	EnemyShip::collide();
}

void  EnemyShip2::draw(){
	if(hp>0)
		gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	EnemyShip::draw();
}