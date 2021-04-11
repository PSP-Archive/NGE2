#include "hge/hgeparticle.h"
#include "libnge2.h"

/**
 * nge_test:nge����:��ʾ����
 */
//�˳���ʶ
int game_quit = 0;
//����ͼƬ
image_p p_logo = NULL;
image_p p_par = NULL;
hgeParticleSystem*	mParticleSys;
sprite_p mParticle = NULL;

nge_timer* timer;
//last tick;	
int mlast = 0;
//dt��Ϊ��λ
float dt = 0;


void btn_down(int keycode)
{
	switch(keycode)
    {
	case PSP_BUTTON_UP:
		break;
	case PSP_BUTTON_DOWN:
		break;
	case PSP_BUTTON_LEFT:
		break;
	case PSP_BUTTON_RIGHT: 
		break;
	case PSP_BUTTON_TRIANGLE:
		break;
	case PSP_BUTTON_CIRCLE:
		break;
	case PSP_BUTTON_CROSS:
		break;
    case PSP_BUTTON_SQUARE:
		break;
	case PSP_BUTTON_SELECT:
		//����ѡ����˳�
		game_quit = 1;
		break;
	case PSP_BUTTON_START:
		//���¿�ʼ���˳�
		game_quit = 1;
		break;
    }
}

void Update()
{
	//ע��,����������ϵͳupdate������.������Ҫ��1000
	float dt = (float)((timer->get_ticks(timer)-mlast)/1000.0);
	mlast = timer->get_ticks(timer);
	mParticleSys->Update(dt);
}

void DrawScene()
{
	BeginScene(1);
	RenderQuad(p_logo,0,0,0,0,(480-p_logo->w)/2,(272-p_logo->h)/2,1,1,0,MAKE_RGBA_8888(255,255,255,40));
	mParticleSys->Render();
	EndScene();
}

extern "C"
int main(int argc, char* argv[])
{
	//��ʼ��NGE��ΪVIDEO,AUDIO��������ֻ��ʼ��VIDEO�������ʼ��������INIT_VIDEO|INIT_AUDIO,����INIT_ALL
	NGE_Init(INIT_VIDEO);
	//��ʼ����������btn_down�ǰ�����Ӧ,�����ǵ���ʱ����Ӧ��0����nge����home��Ϣ(ֱ���˳�),��1������PSPϵͳ����
	//home��Ϣ,ͨ����1�����˳���1.50������Ƴ�����Ҫ��0��
	InitInput(btn_down,NULL,1);
	//���һ��������psp swizzle�Ż���ͨ����1
	p_logo = image_load("images/nge2logo.png",DISPLAY_PIXEL_FORMAT_8888,1);
	if(p_logo == NULL)
		printf("can not open file\n");
	p_par = image_load("par/particles.png",DISPLAY_PIXEL_FORMAT_8888,1);
	if(p_par == NULL)
		printf("can not open file\n");
	//����sprite��ͼ
	mParticle = (sprite_p)malloc(sizeof(sprite_t));
	memset(mParticle,0,sizeof(sprite_t));
	mParticle->sprite_image = p_par;
	mParticle->sprite_clip.left= 0.0f;
	mParticle->sprite_clip.top= 0.0f;
	mParticle->sprite_clip.right= 32.0f;
	mParticle->sprite_clip.bottom = 32.0f;
	mParticle->sprite_center.x = 16.0f; 
	mParticle->sprite_center.y = 16.0f;

	mParticleSys = new hgeParticleSystem("par/particle1.psi", mParticle);
	mParticleSys->MoveTo(480.0f/2, 272.0f/2,0);
	mParticleSys->Fire();
	timer = timer_create();
	timer->start(timer);
	while ( !game_quit )
	{
		ShowFps();
		InputProc();
		Update();
		DrawScene();
		LimitFps(60);
	}
	image_free(p_logo);
	image_free(p_par);
	SAFE_FREE(mParticle);
	delete mParticleSys;
	NGE_Quit();
	return 0;
}



