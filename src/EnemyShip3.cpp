#include "EnemyShip3.hpp"

EnemyShip3::EnemyShip3(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p,Texture text,Texture bul) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,40,54,p,text,bul)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
}

void  EnemyShip3::update(){
	if(p->mMouseLoc.y > pos.y)
		vel.y = 50;
	else
		vel.y = -50;
	if(p->mMouseLoc.x > pos.x)
		vel.x = 50;
	else
		vel.x = -50;
	pos += vel*1/ci::app::AppBasic::get()->getFrameRate();
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	eg->update(Vec2f(pos.x,pos.y+height/2));
}

void EnemyShip3::collide(){
	for(int i=0;i<p->pg.bullets.size();i++){
		Vec2f closestPoint = p->pg.bullets[i]->location;
		if( p->pg.bullets[i]->location.x > rec.getX2() ) closestPoint.x = rec.getX2();
		else if( p->pg.bullets[i]->location.x < rec.getX1() ) closestPoint.x = rec.getX1();
		if( p->pg.bullets[i]->location.y < rec.getY2() ) closestPoint.y = rec.getY2();
		else if( p->pg.bullets[i]->location.y > rec.getY1() ) closestPoint.y = rec.getY1();
    
		Vec2f diff = closestPoint -  p->pg.bullets[i]->location;
		if( diff.x * diff.x + diff.y * diff.y > p->pg.bullets[i]->radius * p->pg.bullets[i]->radius){}
		else{
			hp -= p->pg.bullets[i]->hp;
			delete p->pg.bullets[i];
			p->pg.bullets.erase(p->pg.bullets.begin()+i);
		}
	}
}

void  EnemyShip3::draw(){
	gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	eg->draw();
}