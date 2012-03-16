#include "MainScene.hpp"

bool paused = false;

void MainScene::onLoad()
{
    ps.init();
	enShip1 = Texture(loadImage(loadResource(RES_ENEMY1)));
	enShip2 = Texture(loadImage(loadResource(RES_ENEMY2)));
	enShip3 = Texture(loadImage(loadResource(RES_ENEMY3)));
	enShip4 = Texture(loadImage(loadResource(RES_ENEMY4)));
	enShip5 = Texture(loadImage(loadResource(RES_ENEMY5)));
	enShip6 = Texture(loadImage(loadResource(RES_ENEMY6)));
	enBul1 = Texture(loadImage(loadResource(RES_EBULLET1)));
	enBul2 = Texture(loadImage(loadResource(RES_EBULLET2)));
	time = 0;
	dt = 1.0/FPS;
	createLevel();
}

void MainScene::mouseDown( MouseEvent &event ) {
	if(ps.remainingLife > 0)
		ps.pg.firing = true;
    mMouseLoc = event.getPos();
}

void MainScene::mouseUp( MouseEvent &event ){
	if(ps.remainingLife > 0)
		ps.pg.firing = false;
}

void MainScene::mouseMove( MouseEvent &event ) {
    mMouseLoc = event.getPos();
}

void MainScene::mouseDrag( MouseEvent &event ) {
    mMouseLoc = event.getPos();
}

void MainScene::update()
{
	time += dt;
    for ( size_t i = 0; i < enemy.size(); ++i ) {
		if(time >= enemy[i]->arrivalTime){
			enemy[i]->update();
			enemy[i]->collide();
			if(enemy[i]->hp <= 0 || enemy[i]->pos.y > 650){
				if(enemy[i]->eg->bullets.size() <= 0){
					delete enemy[i];
					enemy.erase(enemy.begin()+i);
				}
				else{
					enemy[i]->eg->firing = false;
				}
			}
		}
	}
    ps.update(mMouseLoc);
}

void MainScene::draw()
{
	gl::color(1.f,1.f,1.f);
	if(ps.remainingLife > 0)
		ps.draw();
	for(size_t i=0;i<enemy.size();++i){
		if(time >= enemy[i]->arrivalTime){
			if(enemy[i]->hp > 0)
				enemy[i]->draw();
			if(enemy[i]->pos.x > mMouseLoc.x - 100 && enemy[i]->pos.x < mMouseLoc.x + 100){
				if(enemy[i]->pos.y < mMouseLoc.y)
					enemy[i]->eg->firing=true;
			}
			else
				enemy[i]->eg->firing=false;
		}
	}
}

void MainScene::onKeyUp(KeyEvent &e){
    if ( e.getCode() == KeyEvent::KEY_SPACE ) {
        paused = true;
        getManager()->push(&pause);
    }
}

void MainScene::createLevel()
{
	ofstream logfile;
	logfile.open ("log.txt");
	if (logfile.is_open()) {
		ifstream infile("Stage1.lvl");
		if (infile.is_open()){
			int num;
			infile >> num;
			for(int i=0;i<num;i++){
				int type;
				int arrivalTime, hp;
				float atkspd, xpos, ypos, xvel, yvel;
				infile >> type;
				switch(type){
				case 1:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip1(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps,enShip1,enBul1));
					logfile << "Added Ship 1" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 2:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip2(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps,enShip2,enBul1));
					logfile << "Added Ship 2" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 3:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip3(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps,enShip3,enBul1));
					logfile << "Added Ship 3" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 4:
					infile >> arrivalTime >> hp >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip4(arrivalTime,hp,xpos,ypos,xvel,yvel,&ps,enShip4,enShip6));
					logfile << "Added Ship 4" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 5:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip5(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps,enShip5,enBul1));
					logfile << "Added Ship 5" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				default:
					break;
				}
			}
		}
		infile.close();
	}
	logfile.close();
}
