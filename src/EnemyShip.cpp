#include "EnemyShip.hpp"

EnemyShip::EnemyShip(int arrivalTime, int hp, float atkspd, float xpos, float ypos,float xvel, float yvel, float width, float height,PlayerShip* p,Texture text,Texture bul)
{
	this->p = p;
	this->shipTexture = text;
    this->hp = hp;
	this->arrivalTime = arrivalTime;	
	this->atkspd=atkspd;
	this->width = width;
	this->height = height;
	pos = Vec2f(xpos,ypos);
	vel=Vec2f(xvel,yvel);
	eg = new EnemyGun(atkspd,bul,p);
}

void  EnemyShip::update(){
	pos += vel;
	eg->update(Vec2f(pos.x,pos.y-height/2));
}

void EnemyShip::collide(){

}

void  EnemyShip::draw(){
	eg->draw();
}