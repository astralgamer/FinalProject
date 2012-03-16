#include <iostream>
#include "PlayerBullet.hpp"
#include "PlayerShip.hpp"
#include "MainScene.hpp"

PlayerBullet::PlayerBullet(Vec2f mMouseLoc, float dmg, float radius, Vec2f vel)
{
    pos = mMouseLoc;
	this->vel = vel;
	isAlive = true;
    this->dmg = dmg;
	this->radius = radius;
}

void PlayerBullet::update()
{
    pos -= vel;
    if(pos.y < 0)
    {
        isAlive = false;
    }
}

void PlayerBullet::draw(Texture bullet)
{
    cinder::gl::draw( bullet, Vec2f(pos.x-radius/2.0,pos.y-radius/2.0));
}