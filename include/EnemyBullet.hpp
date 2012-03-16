#ifndef FinalProject_EnemyBullet_h
#define FinalProject_EnemyBullet_h

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

class EnemyBullet
{
public:
    EnemyBullet(Vec2f pos, int hp, int radius, Vec2f vel);
	void collide(PlayerShip* p);
    void draw(Texture bullet);
	void update();
	int hp, radius;
	Vec2f pos, vel;
};

#endif