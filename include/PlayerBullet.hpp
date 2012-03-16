#ifndef FinalProject_PlayerBullet_hpp
#define FinalProject_PlayerBullet_hpp

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class PlayerBullet
{
public:
    PlayerBullet();
    PlayerBullet(Vec2f pos, float dmg, float radius, Vec2f vel);
	void draw(Texture bullet);
	void update();
	float dmg, radius;
	Vec2f pos, vel;
	bool isAlive;

};

#endif