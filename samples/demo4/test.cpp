#include "libnge2.h"
#include "cAnimation.h"
/**
 * nge_test:��򵥵�nge����:��ʾһ��ͼƬ
 */

//�˳���ʶ
int game_quit = 0;
//����ͼƬ
image_p p_bg = NULL;







extern "C"
int main(int argc, char* argv[])
{
	//��ʼ��NGE��ΪVIDEO,AUDIO��������ֻ��ʼ��VIDEO�������ʼ��������INIT_VIDEO|INIT_AUDIO,����INIT_ALL
	NGE_Init(INIT_VIDEO);
	
	//���һ��������psp swizzle�Ż���ͨ����1
	p_bg = image_load("images/demo4_bg.png",DISPLAY_PIXEL_FORMAT_8888,1);
	if(p_bg == NULL)
		printf("can not open file!\n");
	CAnimation* ani = new CAnimation("images/demo4_man.png");
	while ( !game_quit )
	{
		ShowFps();
		ani->Input();
		ani->Update();
		//draw target
		BeginScene(1);
			ImageToScreen(p_bg,0,0);
			ani->Show();
		EndScene();
		LimitFps(60);
	}
	image_free(p_bg);
	NGE_Quit();
	delete ani;
	return 0;
}



