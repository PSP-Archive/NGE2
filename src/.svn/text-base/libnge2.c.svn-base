#include "libnge2.h"


static int inited = 0;

void NGE_Init(int flags)
{
	
	if(inited==0){	
		#ifdef WIN32
		flags |= SDL_INIT_JOYSTICK;
			if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
   				exit(1);
			SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
			SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,SDL_OPENGL|SDL_GL_DOUBLEBUFFER );
		#endif
		InitGrahics();
		if(flags&INIT_AUDIO)
			CoolAudioDefaultInit();
		inited = 1;
	}
}
void NGE_Quit()
{
	if(inited){
		FiniGrahics();
		FiniInput();
		CoolAudioDefaultFini();
		#ifdef WIN32
			SDL_Quit();
			#ifdef MMGR
				m_dumpMemoryReport();
			#endif
		#endif
	}
}



