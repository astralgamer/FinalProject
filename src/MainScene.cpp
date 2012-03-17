#include "MainScene.hpp"

bool paused = false;

void MainScene::onLoad()
{
	createLevel();
    ps.init();
	for(int i=0;i<enemy.size();i++)
		enemy[i]->init();
	time = 0;
	dt = 1.0/FPS;
	
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
	if(ps.remainingLife > 0){
		time += dt;
		for ( size_t i = 0; i < enemy.size(); ++i ) {
			if(time >= enemy[i]->arrivalTime){
				enemy[i]->update();
				if(enemy[i]->hp > 0)
					enemy[i]->collide();
				if(enemy[i]->hp <= 0 || enemy[i]->pos.y > 650){
					bool del = true;
					for(int j = 0; j < enemy[i]->eg.size(); j++){
						if(enemy[i]->eg[0]->bullets.size() > 0)
							del = false;
					}
					if(del){
						delete enemy[i];
						enemy.erase(enemy.begin()+i);
					}
					else{
						enemy[i]->firing = false;
					}
				}
			}
		}
		ps.update(mMouseLoc);
	}
}

void MainScene::draw()
{
	gl::color(1.f,1.f,1.f);
	if(ps.remainingLife > 0)
		ps.draw();
	else
		gl::drawString("GAME OVER",Vec2f(350,300));
	for(size_t i=0;i<enemy.size();++i){
		if(time >= enemy[i]->arrivalTime){
			enemy[i]->draw();
		}
	}
	string s = "Life: ";
	if(ps.remainingLife > 0){
		char life[10];
		itoa(ps.remainingLife,life,10);
		s += life;
	}
	else{
		s+="0";
	}
	gl::drawString(s,Vec2f(50,550));
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
					enemy.push_back(new EnemyShip1(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps));
					logfile << "Added Ship 1" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 2:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip2(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps));
					logfile << "Added Ship 2" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 3:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip3(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps));
					logfile << "Added Ship 3" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 4:
					infile >> arrivalTime >> hp >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip4(arrivalTime,hp,xpos,ypos,xvel,yvel,&ps));
					logfile << "Added Ship 4" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 5:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip5(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps));
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
