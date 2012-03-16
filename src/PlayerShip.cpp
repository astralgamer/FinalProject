#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <iostream>

#include "PlayerShip.hpp"

#define DT .5f
#define THING 1/2.f
#define PLAYER_HP 10000

float t = 0;

PlayerShip::PlayerShip()
{
	remainingLife = PLAYER_HP;
    mMouseLoc = Vec2f(0,0);
    direction = Straight;
    tween = 0;
	width = 100;
	height = 100;
	rec = Rectf( Vec2f(mMouseLoc.x-width/2,mMouseLoc.y), Vec2f(mMouseLoc.x+width/2,mMouseLoc.y+height));
}

void PlayerShip::init()
{
    shipTexture = Texture( loadImage( loadResource( RES_SHIPMAP ) ) );
    pg.init();
}

void PlayerShip::update(Vec2f location)
{
    t += 1/ci::app::AppBasic::get()->getFrameRate(); 
    loc = mMouseLoc;
    mMouseLoc = location;
	rec = Rectf( Vec2f(mMouseLoc.x-width/2,mMouseLoc.y), Vec2f(mMouseLoc.x+width/2,mMouseLoc.y+height));
    switch(direction)
    {
        case Left:
            if( tween > -4 ){
                tween-=DT;
                if( loc.x - mMouseLoc.x < 0 && t > THING ){
                    t = 0;
                    direction = Right;
                }
                else if(t > THING){
                    t = 0;
                    direction = Straight;
                }
            }
            else{
                tween = -4;
                if( loc.x - mMouseLoc.x < 0 && t > THING ){
                    t = 0;
                    direction = Right;
                }
                else if(t > THING){
                    t = 0;
                    direction = Straight;
                }
            }
            break;
        case Straight:
            if( tween == 0 ){
                if( loc.x - mMouseLoc.x > 0 && t > THING){
                    t = 0;
                    direction = Left;
                }
                else if( loc.x - mMouseLoc.x < 0 && t > THING){
                    t = 0;
                    direction = Right;
                }
                else if(t > THING){
                    t = 0;
                    direction = Straight;
                }
            }
            else if( tween < 0 ){
                tween+=DT;
            }
            else if( tween > 0 ){
                tween-=DT;
            }
            break;
        case Right:
            if( tween < 4 ){
                tween+=DT;
                if( loc.x - mMouseLoc.x > 0 && t > THING){
                    t = 0;
                    direction = Left;
                }
                else if(t > THING){
                    t = 0;
                    direction = Straight;
                }
            }
            else{
                tween = 4;
                if( loc.x - mMouseLoc.x > 0 && t > THING){
                    t = 0;
                    direction = Left;
                }
                else if(t > THING){
                    t = 0;
                    direction = Straight;
                }
            }
            break;
    }
        
    //cout << tween << endl;
    pg.update(mMouseLoc);
}

void PlayerShip::draw()
{
    cinder::gl::draw( shipTexture, Area(Vec2f(100*(floor(tween)+4), 0), Vec2f(100*(floor(tween)+4) + 100, 100)), Rectf(mMouseLoc - Vec2f(50,0), mMouseLoc + Vec2f(50,100)) );
    pg.draw();
}