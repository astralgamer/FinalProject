#include "EnemyShip6.hpp"

EnemyShip6::EnemyShip6(float xpos, float ypos, PlayerShip* p,Texture text) : EnemyShip(0,200,0,xpos,ypos,0,0,44,56,p,text,text)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
}

void  EnemyShip6::update(){
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
}

void EnemyShip6::collide(){
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

void  EnemyShip6::draw(){
	gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
}



