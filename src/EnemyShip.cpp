#include "EnemyShip.hpp"

EnemyShip::EnemyShip(int arrivalTime, int hp, float atkspd, float xpos, float ypos,float xvel, float yvel, float width, float height,PlayerShip* p)
{
	this->p = p;
    this->hp = hp;
	this->arrivalTime = arrivalTime;	
	this->atkspd=atkspd;
	this->width = width;
	this->height = height;
	firing = false;
	pos = Vec2f(xpos,ypos);
	vel=Vec2f(xvel,yvel);
	eg.push_back(new EnemyGun(atkspd,p));
}

void  EnemyShip::update(){
	pos += vel*1/ci::app::AppBasic::get()->getFrameRate();
	rec = Rectf( Vec2f(pos.x-width/2.0,pos.y-height/2.0), Vec2f(pos.x+width/2.0,pos.y+height/2.0));
	for(int i=0;i<eg.size();i++){
		eg[i]->firing = firing;
		eg[i]->update(Vec2f(pos.x,pos.y-height/2));
	}
}

void EnemyShip::init(){
	for(int i=0;i<eg.size();i++)
		eg[i]->init();
}

void EnemyShip::collide(){
	bool col = false;
	if( (p->rec.getX1() <= rec.getX2() && p->rec.getX1() >= rec.getX1() )|| (p->rec.getX2() >= rec.getX1() && p->rec.getX2() <= rec.getX2())){
		if( (p->rec.getY1() <= rec.getY2() && p->rec.getY1() >= rec.getY1() )|| (p->rec.getY2() >= rec.getY1() && p->rec.getY2() <= rec.getY2())){
			col = true;
		} 
	}
	if( (rec.getX1() <= p->rec.getX2() && rec.getX1() >= p->rec.getX1() )|| (rec.getX2() >= p->rec.getX1() && rec.getX2() <= p->rec.getX2())){
		if( (rec.getY1() <= p->rec.getY2() && rec.getY1() >= p->rec.getY1() )|| (rec.getY2() >= p->rec.getY1() && rec.getY2() <= p->rec.getY2())){
			col = true;
		} 
	}
	if(col){
		int temp = p->remainingLife;
			if (hp > temp){
				p->remainingLife = 0;
				hp -= temp;
			}
			else{
				p->remainingLife -= hp;
				hp = 0;
			}
			for(int j=0;j<eg.size();j++)
				eg[j]->firing = false;
			firing = false;
			return;
	}
	for(int i=0;i<p->pg.bullets.size();i++){
		Vec2f closestPoint = p->pg.bullets[i]->pos;
		if( p->pg.bullets[i]->pos.x > rec.getX2() ) closestPoint.x = rec.getX2();
		else if( p->pg.bullets[i]->pos.x < rec.getX1() ) closestPoint.x = rec.getX1();
		if( p->pg.bullets[i]->pos.y > rec.getY2() ) closestPoint.y = rec.getY2();
		else if( p->pg.bullets[i]->pos.y < rec.getY1() ) closestPoint.y = rec.getY1();
    
		Vec2f diff = closestPoint -  p->pg.bullets[i]->pos;
		if( diff.x * diff.x + diff.y * diff.y > p->pg.bullets[i]->radius * p->pg.bullets[i]->radius){}
		else{
			hp -= p->pg.bullets[i]->dmg;
			p->pg.bullets[i]->isAlive = false;
			delete p->pg.bullets[i];
			p->pg.bullets.erase(p->pg.bullets.begin()+i);
			for(int j=0;j<eg.size();j++)
				eg[j]->firing = false;
			firing = false;
			return;
		}
	}
}

void  EnemyShip::draw(){
	for(int j=0;j<eg.size();j++)
		eg[j]->draw();
}