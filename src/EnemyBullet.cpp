#include "EnemyBullet.hpp"

#define SPEED 20
EnemyBullet::EnemyBullet(Vec2f pos, int hp, int radius, Vec2f vel){
	this->pos = pos;
	this->hp = hp;
	this->radius = radius;
	this->vel = vel;
}

void EnemyBullet::collide(PlayerShip* p){
		Vec2f closestPoint = pos;
		if( pos.x > p->rec.getX2() ) closestPoint.x = p->rec.getX2();
		else if( pos.x < p->rec.getX1() ) closestPoint.x = p->rec.getX1();
		if( pos.y > p->rec.getY2() ) closestPoint.y = p->rec.getY2();
		else if( pos.y < p->rec.getY1() ) closestPoint.y = p->rec.getY1();
    
		Vec2f diff = closestPoint -  pos;
		if( diff.x * diff.x + diff.y * diff.y > radius * radius ){}
		else{
			p->remainingLife -= hp;
			hp=0;
		}
}

void EnemyBullet::draw(Texture bullet){
	gl::draw( bullet,Vec2f(pos.x-radius/2.0,pos.y-radius/2.0));
}

void EnemyBullet::update(){
	pos += vel;
	if(pos.y > 650)
    {
        hp = 0;
    }
}
