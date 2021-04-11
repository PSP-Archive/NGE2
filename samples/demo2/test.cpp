#include "libnge2.h"

/**
 * nge_test:����nge2�İ�����������
 * ������Դ�ļ�:��������ӦĿ¼��
 * fonts/GBK14��fonts/ASC14��fonts/simfang.ttf��images/demo1_bg.png��images/demo1_box.jpg
 * images/demo1_icon.jpg
 */

int game_quit = 0;
image_p pimage_text,pimage_bg,pimage_box;
image_p pimage_icon[2];
//���ֲ���
music_ops mp3_play;
music_ops wav_play;
//��ʼ����Ϊ128������ΧΪ��0-128��
int volume = 128;

int mask8888 = MAKE_RGBA_8888(255,255,255,255);
int mask4444 = MAKE_RGBA_4444(255,255,255,255);
//��͸����box
int maskbox = MAKE_RGBA_8888(255,255,255,128);
int wav_ret;
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
		//O���ָ�
		mp3_play.resume();
		break;
	case PSP_BUTTON_CROSS:
		//�����ͣ
		mp3_play.pause();
		break;
    case PSP_BUTTON_SQUARE:
		break;
	case PSP_BUTTON_SELECT:
		//ѡ������׸�,�������stop
		wav_ret = wav_play.load("music/simple3.wav");
		wav_play.playstop();
		break;
	case PSP_BUTTON_START:
		//��ʼ���˳�
		game_quit = 1;
		break;
    }
}

void btn_up(int keycode)
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
		break;
	case PSP_BUTTON_START:
		break;
    }
}

void DrawScene()
{

	BeginScene(1);
	ImageToScreen(pimage_bg,0,0);
	
	RenderQuad(pimage_box,0,0,0,0,70,185,1,1,0,maskbox);
	RenderQuad(pimage_box,0,0,0,0,70,5,1,1,0,maskbox);
	DrawImage(pimage_icon[0],0,0,0,0,-20,-37,128,128);
	DrawImage(pimage_icon[1],0,0,0,0,-20,143,128,128);
	ImageToScreen(pimage_text,0,0);
	
	//����2��ȼ�������2��
	//RenderQuad(bg,0,0,0,0,0,0,1,1,0,mask8888);
	//RenderQuad(pimage_text,0,0,0,0,0,0,1,1,0,mask4444);
	EndScene();
}

extern "C"
int main(int argc, char* argv[])
{
	NGE_Init(INIT_ALL);
	InitInput(btn_down,btn_up,1);
	PFont pf[2] ;
	int i;
	//����һ����ʾimage,�־���ʾ���������ע��DISPLAY_PIXEL_FORMAT�����봴�������DISPLAY_PIXEL_FORMATһ��
	pimage_text = image_create(512,512,DISPLAY_PIXEL_FORMAT_4444);
	//��������
	pf[0] = create_font_hzk("fonts/GBK14","fonts/ASC14",14,DISPLAY_PIXEL_FORMAT_4444);
	pf[1] = create_font_freetype("fonts/simfang.ttf",13,DISPLAY_PIXEL_FORMAT_4444);
	char str1[3][128]={"����ĻԱ��","���沥�ŵ�����ѩ���ݳ�����������","��ӭ���������"};
	char str2[3][128]={"��ѩ���˿��","�����ۡ�����̫���ˣ�","XXXXŮ��SAMA���Ұ��㡣"};
	//��ʾGBK Font
	font_setcolor(pf[0],MAKE_RGBA_4444(128,0,0,255));
	font_drawtext(pf[0],str2[0],strlen(str2[0]),pimage_text,100,195,FONT_SHOW_NORMAL);
	for(i = 1;i<3;i++){
		font_drawtext(pf[0],str2[i],strlen(str2[i]),pimage_text,120,200+i*20,FONT_SHOW_SHADOW);
		font_setcolor(pf[0],MAKE_RGBA_4444(255,0,0,255));
	}
	//��ʾfreetype
	font_setcolor(pf[1],MAKE_RGBA_4444(128,0,0,255));
	font_drawtext(pf[1],str1[0],strlen(str1[0]),pimage_text,100,30,FONT_SHOW_NORMAL);
	for(i =1;i<3;i++){
		font_drawtext(pf[1],str1[i],strlen(str1[i]),pimage_text,120,35+i*20,FONT_SHOW_NORMAL);
		font_setcolor(pf[1],MAKE_RGBA_4444(255,0,0,255));
	}
	
	pimage_bg = image_load("images/demo2_bg.jpg",DISPLAY_PIXEL_FORMAT_8888,1);
	if(pimage_bg == NULL)
		printf("can not open file\n");
	pimage_box = image_load("images/demo2_box.jpg",DISPLAY_PIXEL_FORMAT_8888,1);
	if(pimage_box == NULL)
		printf("can not open file\n");
	pimage_icon[0] = image_load_colorkey("images/demo2_icon1.png",DISPLAY_PIXEL_FORMAT_8888,MAKE_RGB(0,0,0),1);
    pimage_icon[1] = image_load_colorkey("images/demo2_icon0.bmp",DISPLAY_PIXEL_FORMAT_8888,MAKE_RGB(0,0,0),1);

	//��ʼ��Mp3���Žṹ
	MP3PlayInit(&mp3_play);
	PCMPlayInit(&wav_play);
	//��������
	mp3_play.volume(volume);
	//���� music/demo2.mp3
	int res = mp3_play.load("music/simple1.mp3");
	//��ʼ������play��Ҫ����stop�ͷ���Դ
	mp3_play.play();
	while ( !game_quit )
	{
		ShowFps();
		InputProc();
		DrawScene();
	}
	font_destory(pf[0]);
	font_destory(pf[1]);
	image_free(pimage_bg);
	image_free(pimage_text);
	image_free(pimage_box);
	//�˳�mp3ϵͳ
	MP3PlayFini();
	PCMPlayFini();
	NGE_Quit();
	return 0;
}



