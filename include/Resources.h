#pragma once

#ifdef RC_INVOKED
	#define QUOTE_PATH(x) #x
	#define CINDER_RESOURCE( LOCALPREFIX, PATH, ID, TYPE ) \
		ID		TYPE 	QUOTE_PATH( LOCALPREFIX##PATH )
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
	#define CINDER_RESOURCE( LOCALPREFIX, PATH, ID, TYPE ) \
		ID,#TYPE
#else // MAC RESOURCE
	#define CINDER_RESOURCE( LOCALPREFIX, PATH, ID, TYPE ) #PATH
#endif

#define RES_ENEMY1			CINDER_RESOURCE( ../resources/, Enemy1.png, 130, ENEMY1 )
#define RES_ENEMY2			CINDER_RESOURCE( ../resources/, Enemy2.png, 131, ENEMY2 )
#define RES_ENEMY3			CINDER_RESOURCE( ../resources/, Enemy3.png, 132, ENEMY3 )
#define RES_ENEMY4			CINDER_RESOURCE( ../resources/, Enemy4.png, 133, ENEMY4 )
#define RES_ENEMY5			CINDER_RESOURCE( ../resources/, Enemy5.png, 134, ENEMY5 )
#define RES_ENEMY6			CINDER_RESOURCE( ../resources/, Enemy6.png, 135, ENEMY6 )
#define RES_BULLET			CINDER_RESOURCE( ../resources/, Bullet1.png, 141, BULLET )
#define RES_EBULLET1		CINDER_RESOURCE( ../resources/, Bullet2.png, 142, EBULLET1 )
#define RES_EBULLET2		CINDER_RESOURCE( ../resources/, Bullet3.png, 143, EBULLET2)
#define RES_SHIP			CINDER_RESOURCE( ../resources/, Ship.png, 128, SHIP )
#define RES_SHIPMAP			CINDER_RESOURCE( ../resources/, ShipMap.png, 129, SHIPMAP )

