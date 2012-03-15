#ifndef FinalProject_EnemyGun1_hpp
#define FinalProject_EnemyGun1_hpp

#include "EnemyBullet1.hpp"
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

class EnemyGun1
{
public:
    EnemyGun1(float atkspeed);
	void update(Vec2f pos);
    void draw();
    bool firing;
	float atkspeed;
    
    vector<EnemyBullet1*> bullets;
    double t;
};

#endif