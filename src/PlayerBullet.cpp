#include <iostream>
#include "PlayerBullet.hpp"
#include "PlayerShip.hpp"
#include "MainScene.hpp"

#define SPEED 15
#define DMG 100

PlayerBullet::PlayerBullet(Vec2f mMouseLoc)
{
    location = mMouseLoc;
    hp = DMG;
	radius = 15;
}

void PlayerBullet::update()
{
    location -= Vec2f(0,SPEED);
    if(location.y < 0)
    {
        hp = 0;
    }
}

void PlayerBullet::draw(Texture bullet)
{
    cinder::gl::draw( bullet, Vec2f(location.x-radius/2.0,location.y-radius/2.0));
}