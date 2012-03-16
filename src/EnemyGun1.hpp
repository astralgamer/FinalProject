#ifndef FinalProject_EnemyGun1_hpp
#define FinalProject_EnemyGun1_hpp

#include "EnemyShip6.hpp"
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

class EnemyGun1{
public:
    EnemyGun1(float atkspeed, Texture text, PlayerShip* p);
	void update(Vec2f pos);
    void draw();
    bool firing;
	float atkspd,t;  
	PlayerShip* p;
	Texture bulletTexture;
    vector<EnemyBullet*> bullets;
};

#endif