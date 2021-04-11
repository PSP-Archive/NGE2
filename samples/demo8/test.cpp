#include "libnge2.h"
/**
 * nge_test:Polygons
 */

//�˳���ʶ
int game_quit = 0;

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
		//�������Ǽ���ͼ
		ScreenShot("screenshot.png");
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

int colors[]={
	MAKE_RGBA_8888(255,0,0,255),//��
	MAKE_RGBA_8888(255,128,0,255),//��
	MAKE_RGBA_8888(255,255,0,255),//��
	MAKE_RGBA_8888(0,255,0,255),//��
	MAKE_RGBA_8888(0,128,255,255),//��
	MAKE_RGBA_8888(0,0,255,255),//��
	MAKE_RGBA_8888(195,0,255,255)//��
};

//����DrawPolygon������ƽ��4����
//  -------------------\
//   \                  \
//    \                  \
//     \------------------\
//
float Polygons_x1[]={
	200.0f,
	300.0f,
	400.0f,
	300.0f
};
float Polygons_y1[]={
	10.0f,
	10.0f,
	70.0f,
	70.0f
};
//������FillPolygon����������
float Polygons_x2[]={
	200.0f,
	300.0f,
	400.0f
};
float Polygons_y2[]={
	80.0f,
	80.0f,
	160.0f
};
//
//������FillPolygonGrad��������������
float Polygons_x3[]={
	400.0f,
	450.0f,
	350.0f
};
float Polygons_y3[]={
	160.0f,
	250.0f,
	250.0f
};
//��ɫ
int tri_color[]={
	MAKE_RGBA_8888(255,0,0,255),//��
	MAKE_RGBA_8888(255,255,0,255),//��
	MAKE_RGBA_8888(0,0,255,255)//��
};

void DrawScene()
{

	BeginScene(1);
	DrawLine(0,0,480,272,colors[0],DISPLAY_PIXEL_FORMAT_8888);
	DrawRect(20,20,200,200,colors[1],DISPLAY_PIXEL_FORMAT_8888);
	FillRect(40,40,100,100,colors[2],DISPLAY_PIXEL_FORMAT_8888);
	DrawCircle(100,100,20,colors[3],DISPLAY_PIXEL_FORMAT_8888);
	FillCircle(150,150,20,colors[4],DISPLAY_PIXEL_FORMAT_8888);
	DrawEllipse(200,200,20,40,colors[5],DISPLAY_PIXEL_FORMAT_8888);
	FillEllipse(250,250,40,20,colors[6],DISPLAY_PIXEL_FORMAT_8888);
	DrawPolygon(Polygons_x1,Polygons_y1,4,colors[0],DISPLAY_PIXEL_FORMAT_8888);
	FillPolygon(Polygons_x2,Polygons_y2,3,colors[1],DISPLAY_PIXEL_FORMAT_8888);
	FillPolygonGrad(Polygons_x3,Polygons_y3,3,tri_color,DISPLAY_PIXEL_FORMAT_8888);
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
	//������Ļ��ɫΪ��ɫ
	SetScreenColor(255,255,255,255);
	while ( !game_quit )
	{
		ShowFps();
		InputProc();
		DrawScene();
		//����fpsΪ60
		LimitFps(60);
	}
	NGE_Quit();
	return 0;
}



