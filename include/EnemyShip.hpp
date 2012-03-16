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
    EnemyShip(int arrivalTime, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel, float width, float height,PlayerShip* p);
    vector<EnemyGun*> eg;
    virtual void draw();
	virtual void update();
	virtual void collide();
	virtual void init();
	int arrivalTime;
	float hp, width, height;
	Vec2f pos, vel;
	Rectf rec;
	Texture shipTexture;
	PlayerShip* p;
	float atkspd;
	bool firing;
};

#endif
