#include "EnemyBullet.hpp"

#define SPEED 20
EnemyBullet::EnemyBullet(Vec2f pos, float dmg, float radius, Vec2f vel){
	this->pos = pos;
	this->dmg = dmg;
	this->radius = radius;
	this->vel = vel;
	isAlive = true;
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
			p->remainingLife -= dmg;
			isAlive = false;
		}
}

void EnemyBullet::draw(Texture bullet){
	gl::draw( bullet,Vec2f(pos.x-radius/2.0,pos.y-radius/2.0));
}

void EnemyBullet::update(){
	pos += vel;
	if(pos.y > 650 || pos.y < -50 || pos.x < -50 || pos.x > 850)
    {
        isAlive = false;
    }
}
