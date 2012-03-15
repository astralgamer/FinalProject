#ifndef FinalProject_EnemyShip_h
#define FinalProject_EnemyShip_h

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <iostream>
#include "Resources.h"
#include "EnemyGun1.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class EnemyShip
{
public:
    EnemyShip(int type, int arrivalTime, int bulletType, int hp, float atkspd, float xpos, float ypos, float xvel, float yvel, float width, float height);
    EnemyGun1* eg;
    void draw();
	void update(float t);
    float radius;
	int arrivalTime, hp, bulletType;
	float atkspd, width, height;
	Vec2f pos, vel;
	Rectf rec;
private:
	int type;
};

#endif
