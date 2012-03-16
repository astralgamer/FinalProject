#ifndef FinalProject_EnemyGun_hpp
#define FinalProject_EnemyGun_hpp

#include "EnemyBullet.hpp"
#include "PlayerShip.hpp"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <iostream>
#include "Resources.h"
#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class EnemyGun{
public:
    EnemyGun(float atkspeed, Texture text, PlayerShip* p);
	void update(Vec2f pos);
    void draw();
    bool firing;
	float atkspd,t;  
	PlayerShip* p;
	Texture bulletTexture;
    vector<EnemyBullet*> bullets;
};

#endif