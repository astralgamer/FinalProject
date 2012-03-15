#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "PlayerShip.hpp"
#include "EnemyShip.hpp"
#include <list>
#include <vector>
#include <iostream>

#define FPS 60.0f

using namespace std;
using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;


class FinalProjectApp : public AppBasic {
public:
    void prepareSettings( Settings *settings );
	void setup();
    void mouseDown( MouseEvent event);
    void mouseMove( MouseEvent event );
	void mouseDrag( MouseEvent event );	
	void mouseUp( MouseEvent event );	
	void update();
	void draw();
	void createLevel();
    
	float time;
	float dt;
    Vec2f mMouseLoc;
    PlayerShip ps;
	vector<EnemyShip*> enemy;
};

void FinalProjectApp::prepareSettings( Settings *settings ){
	//settings->setWindowSize( 800, 600 );
    settings->setFrameRate( FPS );
    settings->setFullScreen();
}


void FinalProjectApp::setup()
{
	time = 0;
	dt = 1.0/60.0;
    enableAlphaBlending();
    hideCursor();
	createLevel();
    /*ps.pg.firing = false;
    ps.pg.t = 0;*/
}

void FinalProjectApp::mouseDown( MouseEvent event ) {
    ps.pg.firing = true;
    mMouseLoc = event.getPos();
}

void FinalProjectApp::mouseUp( MouseEvent event ){
    ps.pg.firing = false;
}

void FinalProjectApp::mouseMove( MouseEvent event ) {
    mMouseLoc = event.getPos();
}

void FinalProjectApp::mouseDrag( MouseEvent event ) {
    //mouseDown( event );
    //mouseMove( event );
    
    //ps.pg.firing = true;
    
    mMouseLoc = event.getPos();
    
    //ps.update(mMouseLoc);//to delete
}

void FinalProjectApp::update()
{
	time += dt;
    /*if(firing)
    {
        if(getElapsedSeconds() - t > 1.0/BPS)
        {
            bullets.push_back(PlayerBullet(mMouseLoc));
            t = getElapsedSeconds();
        }
    }
    
    for( list<PlayerBullet>::iterator p = bullets.begin(); p != bullets.end(); ++p ){
        p->update();
        if( !p->isAlive )
        {
            bullets.erase(p);
        }
    }*/
    for ( size_t i = 0; i < enemy.size(); ++i ) {
		EnemyShip* o = enemy[i];
		if(time >= o->arrivalTime){
			o->update(dt);
		}
	}
    ps.update(mMouseLoc);
}

void FinalProjectApp::draw()
{
	clear( Color( 0, 0, 0 ) );
    ps.draw();
	for(size_t i=0;i<enemy.size();++i){
		if(time >= enemy[i]->arrivalTime){
			enemy[i]->draw();
			enemy[i]->eg->firing=true;
		}
	}
    /*for( list<PlayerBullet>::iterator p = bullets.begin(); p != bullets.end(); ++p ){
        p->draw();
    }*/
}

void FinalProjectApp::createLevel()
{
	enemy.reserve(100);
	FILE * file;
	FILE * log;
	log = fopen("log.txt","w+");
	if(log == NULL){
		printf("Invalid logfile");
	}
	else{
		fprintf(log,"Start of Log File\n");
	}
	file = fopen("Stage1.lvl","r");
	if(file == NULL){
		fprintf(log,"Invalid Stagefile");
	}
	else{
		int type;
		int arrivalTime,bullet,hp;
		float atkspd, xpos,ypos,xvel,yvel; 
		bool go = true;
		EnemyShip* en1;
		int entries;
		fscanf(file,"%d",&entries);
		fprintf(log,"ENTRIES: %d \n",entries);
		while(entries > 0){
			fscanf(file,"%d",&type);
			fprintf(log,"TYPE: %d\n",type);
			fscanf(file,"%d, %d, %d",&arrivalTime,&bullet,&hp);
			fprintf(log,"TIME: %d BULLET: %d HP: %d\n",arrivalTime,bullet,hp);
			fscanf(file,"%f, %f, %f, %f, %f",&atkspd,&xpos,&ypos,&xvel,&yvel);
			fprintf(log,"ATKSPD: %f X: %f Y: %f XV: %f YV: %f\n",atkspd,xpos,ypos,xvel,yvel);
			float w,h;
			switch (type){
				case 1:
					fscanf(file,"%f",&w);
					h = w;
					fprintf(log,"RADIUS: %f\n",w);
					en1 = new EnemyShip(1,arrivalTime,bullet,hp,atkspd, xpos,ypos,xvel,yvel,w,h);
					enemy.push_back(en1);
					break;
				case 2:
					fscanf(file,"%f, %f",&w,&h);
					fprintf(log,"WIDTH: %f HEIGHT: %f\n",w,h);
					en1 = new EnemyShip(2,arrivalTime,bullet,hp,atkspd, xpos,ypos,xvel,yvel,w,h);
					enemy.push_back(en1);
					break;
				default:
					go = false;
					break;
			}
			entries--;
		}
		fclose(file);
		fclose(log);
	}
}

CINDER_APP_BASIC( FinalProjectApp, RendererGl )
