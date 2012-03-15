#include "EnemyShip.hpp"

EnemyShip::EnemyShip(int type, int arrivalTime, int bulletType, int hp, float atkspd, float xpos, float ypos,float xvel, float yvel, float width, float height)
{
	eg = new EnemyGun1(30);
	this->type=type;
    this->hp = hp;
	this->arrivalTime = arrivalTime;	
	this->atkspd=atkspd;
	this->width = width;
	this->height = height;
	pos = Vec2f(xpos,ypos);
	vel=Vec2f(xvel,yvel);
	rec = Rectf(Vec2f(pos.x+width/2,pos.y+height/2),Vec2f(pos.x-width/2,pos.y-height/2));
}

void  EnemyShip::update(float t){
	pos += vel*t;
	eg->update(Vec2f(pos.x,pos.y-height/2));
	rec = Rectf(Vec2f(pos.x+width/2,pos.y+height/2),Vec2f(pos.x-width/2,pos.y-height/2));
}

void collide(){
	//RECT RECT COLLISION
	/*
	Vec2f half1(width/2,height/2);
	Vec2f half2(o2->width/2,o2->height/2);
	Vec2f d;
	if(pos >= o2->pos){
		d = (pos - o2->pos) - (half1 + half2);
	}
	else{
		d = (o2->pos - pos) - (half1 + half2);
	}
	if( d.x < 0 && d.y < 0 ){
		
	}
	*/

	//CIRCLE RECT COLLISION
	/*
	Vec2f closestPoint = pos;
		if( pos.x < o2->rec.getX2() ) closestPoint.x = o2->rec.getX2();
		else if( pos.x > o2->rec.getX1() ) closestPoint.x = o2->rec.getX1();
		if( pos.y < o2->rec.getY2() ) closestPoint.y = o2->rec.getY2();
		else if( pos.y > o2->rec.getY1() ) closestPoint.y = o2->rec.getY1();
    
		Vec2f diff = closestPoint -  pos;
		if( diff.x * diff.x + diff.y * diff.y > radius * radius ){}
		else{
			o2->hp -= hp;
			hp=0;
		}
	*/
}

void  EnemyShip::draw(){	
	switch(type){
	case 1:
		gl::draw( Texture( loadImage( loadResource( RES_ENEMY ) ) ),pos);
		break;
	case 2:
		gl::draw( Texture( loadImage( loadResource( RES_ENEMY1 ) ) ),pos);
		break;
	}
	eg->draw();
}