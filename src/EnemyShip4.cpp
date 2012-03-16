#include "EnemyShip4.hpp"

EnemyShip4::EnemyShip4(int arrivalTime, int hp, float xpos, float ypos, float xvel, float yvel,PlayerShip* p,Texture text,Texture bul) : EnemyShip(arrivalTime,hp,0,xpos,ypos,xvel,yvel,82,94,p,text,bul)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	t = 0;
	missle = bul;
}

void  EnemyShip4::update(){
	t += 1/ci::app::AppBasic::get()->getFrameRate();
	if( t > 2){
        minions.push_back(new EnemyShip6(pos.x,pos.y, p,missle));
        t = 0;
    }
	for(int i=0;i<minions.size();i++){
		minions[i]->update();
		minions[i]->collide();
		if(minions[i]->hp <= 0){
			delete minions[i];
			minions.erase(minions.begin()+i);
		}
	}
	if(pos.x < width/2.0 + 20 && vel.x < 0)
		vel.x *= -1;
	if(pos.x > 780 - width/2.0 && vel.x > 0)
		vel.x *= -1;
	pos += vel*1/ci::app::AppBasic::get()->getFrameRate();
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
}

void EnemyShip4::collide(){
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

void  EnemyShip4::draw(){
	gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	for(int i=0;i<minions.size();i++){
		minions[i]->draw();
	}
}



