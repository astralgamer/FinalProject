#include <iostream>
#include "PlayerGun.hpp"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#define BPS 5

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
            bullets.push_back(new PlayerBullet(mMouseLoc));
            t = 0;
        }
    }
    
    for( int i=0;i<bullets.size();i++){
        bullets[i]->update();
        if( bullets[i]->hp <= 0 )
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
	for( int i=0;i<bullets.size();i++){
        if( bullets[i]->hp <= 0 )
        {
			delete bullets[i];
			bullets.erase(bullets.begin()+i);
        }
    }
	for( int i=0;i<bullets.size();i++ ){
        bullets[i]->draw(bulletTexture);
    }
}

/*void PlayerGun::mouseDown( MouseEvent event ) {
    firing = true;
    mMouseLoc = event.getPos();
}

void PlayerGun::mouseUp( MouseEvent event ){
    firing = false;
}*/
