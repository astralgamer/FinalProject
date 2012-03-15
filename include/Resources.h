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

#define RES_ENEMY			CINDER_RESOURCE( ../resources/, enemy1.png, 130, ENEMY1 )
#define RES_ENEMY1			CINDER_RESOURCE( ../resources/, enemy2.png, 131, ENEMY2 )
#define RES_BULLET			CINDER_RESOURCE( ../resources/, bullet1.png, 128, BULLET )
#define RES_EBULLET1		CINDER_RESOURCE( ../resources/, bullet2.png, 128, EBULLET1 )
#define RES_EBULLET2		CINDER_RESOURCE( ../resources/, bullet3.png, 128, EBULLET2)
#define RES_SHIP			CINDER_RESOURCE( ../resources/, ship.png, 129, SHIP )

