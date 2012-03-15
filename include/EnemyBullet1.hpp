#ifndef FinalProject_EnemyBullet1_h
#define FinalProject_EnemyBullet1_h

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "PlayerShip.hpp"
#include <iostream>
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class EnemyBullet1
{
public:
    EnemyBullet1(Vec2f pos, int hp);
	void collide(PlayerShip* p);
    void draw();
	void update();
    float radius;
	int hp;
	float width, height,t;
	Vec2f pos, vel;
	Rectf rec;
};

#endif
