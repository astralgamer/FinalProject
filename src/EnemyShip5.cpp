#include "EnemyShip5.hpp"

EnemyShip5::EnemyShip5(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p,Texture text,Texture bul) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,444,200,p,text,bul)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	eg1 = new EnemyGun(atkspd,bul,p);
	eg2 = new EnemyGun(atkspd,bul,p);
}

void  EnemyShip5::update(){
	if(pos.y  >= 300)
		vel.y = 0;
	if(pos.x < width/2.0 + 20 && vel.x < 0)
		vel.x *= -1;
	if(pos.x > 780 - width/2.0 && vel.x > 0)
		vel.x *= -1;
	if(eg->firing = true){
		eg1->firing = true;
		eg2->firing = true;
	}
	else if(eg->firing = false){
		eg1->firing = false;
		eg2->firing = false;
	}
	pos += vel*1/ci::app::AppBasic::get()->getFrameRate();
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	eg->update(Vec2f(pos.x,pos.y+height/2));
	eg1->update(Vec2f(pos.x+width/2.0,pos.y+height/2));
	eg2->update(Vec2f(pos.x-width/2.0,pos.y+height/2));
}

void EnemyShip5::collide(){
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

void  EnemyShip5::draw(){
	gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	eg->draw();
	eg1->draw();
	eg2->draw();
}



