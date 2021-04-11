#ifndef NGE_FONT_H_
#define NGE_FONT_H_
#include "nge_define.h"
#include "nge_io_file.h"
#include "nge_misc.h"


#ifdef __cplusplus
extern "C"{
#endif
/**
 *����һ��GBK(hzk)font,Ĭ��ΪGBK�ĵ���
 *@param const char* cname,�����ֿ�ͨ����GBKxx
 *@param const char* aname,Ӣ���ֿ�ͨ����ASCxx
 *@param int height,�߶�,�����ֿ�ΪGBK16,�������16
 *@param int disp,��ʾģʽ,4����ʾģʽ֮һ,�Ƽ�ʹ��5551,4444
 *@return PFont pfont,����fontָ��
 */
PFont create_font_hzk(const char* cname,const char* aname, int height,int disp);
/**
 *��һ���ڴ�buf�ϴ���һ��GBK(hzk)font,Ĭ��ΪGBK�ĵ���
 *@param const char *cfbuf,�����ֿ�bufͨ����GBKxx
 *@param int csize,����buf�Ĵ�С
 *@param const char *afbuf,�����ֿ�cbufͨ����ASCxx
 *@param int asize,����abuf�Ĵ�С
 *@param int height,�߶�,�����ֿ�ΪGBK16,�������16
 *@param int disp,��ʾģʽ,4����ʾģʽ֮һ,�Ƽ�ʹ��5551,4444
 *@return PFont pfont,����fontָ��
 */
PFont create_font_hzk_buf(const char *cfbuf,int csize,const char* afbuf,int asize, int height,int disp);
/**
 *����һ��ttf(freetype)font
 *@param const char* cname,freetype�ļ���
 *@param int height,�߶�����
 *@param int disp,��ʾģʽ,4����ʾģʽ֮һ,�Ƽ�ʹ��8888,4444
 *@return PFont pfont,����fontָ��
 */
PFont create_font_freetype(const char* ttfname, int height,int disp);
/**
 *��һ���ڴ�buf�ϴ���һ��ttf(freetype)font
 *@param const char *cfbuf,freetype���ڴ�buf
 *@param int csize,freetype���ڴ�buf
 *@param int height,�߶�����
 *@param int disp,��ʾģʽ,4����ʾģʽ֮һ,�Ƽ�ʹ��8888,4444
 *@return PFont pfont,����fontָ��
 */
PFont create_font_freetype_buf(const char *cfbuf,int csize, int height,int disp);

/**
 * ��ʾһ���ֵ��ڴ�ͼtextarea,ע�������create_image�����ڴ�ͼtextarea
 *@param PFont pf,����ָ��,��create_font_xxx����
 *@param const char* text,��ʾ������
 *@param int len,��ʾ���ֵĳ���,��strlen����
 *@param image_p textarea,�ڴ�ͼtextarea
 *@param int dx,�������ڴ�ͼ��xλ������
 *@param int dy,�������ڴ�ͼ��yλ������
 *@param int flag,��ʾ��־,Ŀǰֻ��0(����),1(��Ӱ)
 *@return ��
 */
void font_drawtext(PFont pf,const char* text,int len,image_p textarea,int dx,int dy,int flags);
/**
 *�������������
 *@param PFont pf,����ָ��
 *@param int attr,����ֵ
 *@param int setflag,��Ҫ���õ����Ա�־
 *@return ��
 */
void font_setattr(PFont pf,int attr,int setflag);
/**
 *�ͷ�һ������
 *@param PFont pf,���ͷŵ�����ָ��
 *@return ��
 */
void font_destory(PFont pf);
/**
 *����������ɫ
 *@param PFont pf,����ָ��
 *@param uint32 color,������ɫ����ɫֵ�뽨�������dtype��Ӧ,���罨����16λ5551,�������MAKE_RGBA5551����
 *@return int,��һ����ɫ
 */
int font_setcolor(PFont pf,uint32 color);
/**
 *��ǿ������������ɫ,��֧�ֶ���
 *@param PFont pf,����ָ��
 *@param uint32 color_fg,ǰ��ɫ(������ɫ)����ɫֵ�뽨�������dtype��Ӧ,���罨����16λ5551,�������MAKE_RGBA5551����
 *@param uint32 color_bg,����ɫ����ɫֵ�뽨�������dtype��Ӧ
 *@param uint32 color_sh,������Ӱɫ����ɫֵ�뽨�������dtype��Ӧ
 *@return int,��
 */
void font_setcolor_ex(PFont pfont, uint32 color_fg,uint32 color_bg ,uint32 color_sh );
/**
 *�õ�һ�����ֵķ�Χ
 *@param PFont pf,����ָ��
 *@param const void *text,����ָ��
 *@param int cc,���ֳ���
 *@param int *pwidth  ��
 *@param int *pheight ��
 *@param int *pbase   ����
 *@return 
 */
void font_textsize(PFont pfont, const void *text, int cc,int *pwidth, int *pheight,int *pbase);
#ifdef __cplusplus
}
#endif


#endif