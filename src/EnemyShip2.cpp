#include "EnemyShip2.hpp"

EnemyShip2::EnemyShip2(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel, PlayerShip* p,Texture text,Texture bul) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,60,74,p,text,bul)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
}

void  EnemyShip2::update(){
	if(pos.y + 150 >= p->mMouseLoc.y && vel.y > 0 && pos.y-height/2.0 > height/2.0+20)
		vel.y *= -1;
	if(pos.y-height/2.0 < height/2.0 && vel.y < 0)
		vel.y *= -1;
	if(pos.x < width/2.0 + 20 && vel.x < 0)
		vel.x *= -1;
	if(pos.x > 780 - width/2.0 && vel.x > 0)
		vel.x *= -1;
	pos += vel*1/ci::app::AppBasic::get()->getFrameRate();
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	eg->update(Vec2f(pos.x,pos.y+height/2));
}

void EnemyShip2::collide(){
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

void  EnemyShip2::draw(){
	gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	eg->draw();
}