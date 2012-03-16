#ifndef FinalProject_EnemyShip_h
#define FinalProject_EnemyShip_h

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <iostream>
#include "Resources.h"
#include "EnemyGun.hpp"
#include "PlayerShip.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class EnemyShip
{
public:
    EnemyShip(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel, float width, float height,PlayerShip* p, Texture text,Texture bul);
    EnemyGun* eg;
    virtual void draw();
	virtual void update();
	virtual void collide();
	int hp, arrivalTime;;
	float width, height;
	Vec2f pos, vel;
	PlayerShip* p;
	Texture shipTexture;
private:
	float atkspd;
};

#endif
