#ifndef FinalProject_MainScene_hpp
#define FinalProject_MainScene_hpp

#include "SceneManager.hpp"
#include "PlayerShip.hpp"
#include "EnemyShip.hpp"
#include "EnemyShip1.hpp"
#include "EnemyShip2.hpp"
#include "EnemyShip3.hpp"
#include "EnemyShip4.hpp"
#include "EnemyShip5.hpp"
#include "EnemyShip6.hpp"
#include "PauseScene.hpp"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


#define FPS 60.0f

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class MainScene : public SceneManager::Scene {
	float t;
    virtual void onDeactivate(SceneManager &sm) {
		//delete this;
	}
    
    PauseScene pause;
    
public:
	MainScene() : pause(this) {};
	virtual void draw();
	virtual void update();
	void onKeyUp(KeyEvent &e);
    void setup();
    void mouseDown( MouseEvent &event );
    void mouseUp( MouseEvent &event );
    void mouseMove( MouseEvent &event );    
    void mouseDrag( MouseEvent &event );
    virtual void onLoad();
	void createLevel();
    
    Vec2f mMouseLoc;
    PlayerShip ps;
	Texture enShip1, enShip2, enShip3, enShip4, enShip5, enShip6, enBul1, enBul2;
	float time;
	float dt;
	vector<EnemyShip*> enemy;
};




#endif


