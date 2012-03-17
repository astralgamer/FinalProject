#include <iostream>
#include "PlayerGun.hpp"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#define BPS 10
#define SPEED 15
#define DMG 75

PlayerGun::PlayerGun()
{
    firing = false;
    t = 0;
}

void PlayerGun::update(Vec2f mMouseLoc)
{
    t += 1/ci::app::AppBasic::get()->getFrameRate(); 
    if(firing)
    {
        if( t > 1.0/BPS)
        {
            bullets.push_back(new PlayerBullet(mMouseLoc,DMG,15,Vec2f(0,SPEED)));
            t = 0;
        }
    }
    
    for( int i=0;i<bullets.size();i++){
        bullets[i]->update();
        if( !bullets[i]->isAlive )
        {
			delete bullets[i];
			bullets.erase(bullets.begin()+i);
        }
    }
}

void PlayerGun::init()
{
    bulletTexture = Texture(loadImage(loadResource(RES_BULLET)));
}

void PlayerGun::draw()
{
	for( int i=0;i<bullets.size();i++ )
        bullets[i]->draw(bulletTexture);
}
