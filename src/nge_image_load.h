#ifndef NGE_IMAGE_LOAD_H_
#define NGE_IMAGE_LOAD_H_
#include "nge_define.h"

extern uint32 image_tid;

#ifdef __cplusplus
extern "C"{
#endif
/**
 *����pngͼƬ,���ļ�����
 *@param const char* filename,ͼƬ�ļ���
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����ͼƬ���˽ṹ
 */
image_p image_load_png(const char* filename, int displaymode);
/**
 *����pngͼƬ,���ڴ����
 *@param const char* mbuf,�ڴ��ַ
 *@param int bsize,����buffer��С
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_png_buf(const char* mbuf,int bsize, int displaymode);
/**
 *����pngͼƬ,���ļ�ָ�����
 *@param int handle,�ļ�ָ��
 *@param int fsize,�����ļ���С
 *@param int autoclose,�Ƿ�ر��ļ�,0���ر�,1�ر�
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_png_fp(int handle,int fsize, int autoclose,int displaymode);
/**
 * ͬimage_load_png����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_png_colorkey(const char* filename, int displaymode,int colorkey);
/**
 * ͬimage_load_png_buf����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_png_colorkey_buf(const char* mbuf, int bsize, int displaymode,int colorkey);
/**
 * ͬimage_load_png_fp����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_png_colorkey_fp(int handle,int fsize, int autoclose,int displaymode,int colorkey);
/**
 *����tgaͼƬ,���ļ�����
 *@param const char* filename,ͼƬ�ļ���
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_tga(const char* filename, int displaymode);
/**
 *����tgaͼƬ,���ڴ����
 *@param const char* mbuf,�ڴ��ַ
 *@param int bsize,����buffer��С
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_tga_buf(const char* mbuf,int bsize, int displaymode);
/**
 *����tgaͼƬ,���ļ�ָ�����
 *@param int handle,�ļ�ָ��
 *@param int fsize,�����ļ���С
 *@param int autoclose,�Ƿ�ر��ļ�,�Ƿ�ر��ļ�,0���ر�,1�ر�
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_tga_fp(int handle,int fsize, int autoclose,int displaymode);
/**
 * ͬimage_load_tga����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_tga_colorkey(const char* filename, int displaymode,int colorkey);
/**
 * ͬimage_load_tga_buf����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_tga_colorkey_buf(const char* mbuf,int bsize, int displaymode,int colorkey);
/**
 * ͬimage_load_png_fp����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_tga_colorkey_fp(int handle,int fsize, int autoclose,int displaymode,int colorkey);
/**
 *����jpgͼƬ,���ļ�����
 *@param const char* filename,ͼƬ�ļ���
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_jpg(const char* filename, int displaymode);
/**
 *����jpgͼƬ,���ڴ����
 *@param const char* mbuf,�ڴ��ַ
 *@param int bsize,����buffer��С
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_jpg_buf(const char* mbuf,int bsize, int displaymode);
/**
 *����jpgͼƬ,���ļ�ָ�����
 *@param int handle,�ļ�ָ��
 *@param int fsize,�����ļ���С
 *@param int autoclose,�Ƿ�ر��ļ�,�Ƿ�ر��ļ�,0���ر�,1�ر�
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_jpg_fp(int handle,int fsize, int autoclose,int displaymode);
/**
 * ͬimage_load_jpg����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_jpg_colorkey(const char* filename, int displaymode,int colorkey);
/**
 * ͬimage_load_jpg_buf����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_jpg_colorkey_buf(const char* mbuf,int bsize, int displaymode,int colorkey);
/**
 * ͬimage_load_jpg_fp����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_jpg_colorkey_fp(int handle,int fsize, int autoclose,int displaymode,int colorkey);
/**
 *����bmpͼƬ,���ļ�����
 *@param const char* filename,ͼƬ�ļ���
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_bmp(const char* filename, int displaymode);
/**
 *����bmpͼƬ,���ڴ����
 *@param const char* mbuf,�ڴ��ַ
 *@param int bsize,����buffer��С
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_bmp_buf(const char* mbuf,int bsize, int displaymode);
/**
 *����bmpͼƬ,���ļ�ָ�����
 *@param int handle,�ļ�ָ��
 *@param int fsize,�����ļ���С
 *@param int autoclose,�Ƿ�ر��ļ�,�Ƿ�ر��ļ�,0���ر�,1�ر�
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_bmp_fp(int handle,int fsize, int autoclose,int displaymode);
/**
 * ͬimage_load_bmp����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_bmp_colorkey(const char* filename, int displaymode,int colorkey);
/**
 * ͬimage_load_bmp_buf����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_bmp_colorkey_buf(const char* mbuf,int bsize, int displaymode,int colorkey);
/**
 * ͬimage_load_bmp_fp����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_bmp_colorkey_fp(int handle,int fsize, int autoclose,int displaymode,int colorkey);

/**
 *����ͼƬ,���ļ�����
 *@param const char* filename,ͼƬ�ļ���
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@param int swizzle,�Ƿ����Ż�,��0�����Ż�,ͨ����1
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load(const char* filename, int displaymode,int swizzle);
/**
 *����ͼƬ,���ڴ����
 *@param const char* mbuf,�ڴ��ַ
 *@param int bsize,����buffer��С
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@param int swizzle,�Ƿ����Ż�,��0�����Ż�,ͨ����1
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_buf(const char* mbuf,int bsize, int displaymode,int swizzle);
/**
 *����ͼƬ,���ļ�ָ�����
 *@param int handle,�ļ�ָ��
 *@param int fsize,�����ļ���С
 *@param int autoclose,�Ƿ�ر��ļ�,�Ƿ�ر��ļ�,0���ر�,1�ر�
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@param int swizzle,�Ƿ����Ż�,��0�����Ż�,ͨ����1
 *@return image_p,����0(����ʧ��),����ͼƬ���˽ṹ
 */
image_p image_load_fp(int handle,int fsize, int autoclose,int displaymode,int swizzle);
/**
 * ͬimage_load����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_colorkey(const char* filename, int displaymode,int colorkey,int swizzle);
/**
 * ͬimage_load_buf����,ֻ�Ƕ���һ�����ùؼ�ɫ,colorkey��MAKE_RGB�趨
 */
image_p image_load_colorkey_buf(const char* mbuf,int bsize, int displaymode,int colorkey,int swizzle);



/**
 *�洢pngͼƬ,��image_p�ṹ���ݴ洢Ϊpng�ļ�
 *@param image_p,image_p�ṹָ��,���汣��Ϊimage_t������
 *@param const char*,�����ļ���
 *@param uint8,�Ƿ񱣴�Ϊ��alphaͨ����ͼƬ
 *@return int,����0(����ʧ��)��1(���سɹ�)
 */
int image_save_png(image_p pimage,const char* filename,uint8 alpha);
/**
 *�洢tgaͼƬ,��image_p�ṹ���ݴ洢Ϊtga�ļ�
 *@param image_p,image_p�ṹָ��,���汣��Ϊimage_t������
 *@param const char*,�����ļ���
 *@param uint8,�Ƿ񱣴�Ϊ��alphaͨ����ͼƬ
 *@param uint8,�Ƿ����rle����ѹ��
 *@return int,����0(����ʧ��)��1(���سɹ�)
 */
int image_save_tga(image_p pimage,const char* filename,uint8 alpha,uint8 rle);
/**
 *����һ��image�ṹ,��ʾģʽ��displaymode
 *@param int w,image�Ŀ�
 *@param int h,image�ĸ�
 *@param int displaymode,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return image_p pimage,����imageָ��
 */
image_p image_create(int w,int h,int displaymode);
/**
 *�ͷ�һ��image
 *@param image_p pimage,���ͷŵ�imageָ��
 *@return void,�޷���
 */
void image_free(image_p pimage);
/**
 *cloneһ��image,����image_p����һ��pimage�����
 *@param image_p pimage,��clone��imageָ��
 *@return image_p,pimage�����
 */
image_p image_clone(image_p pimage);
/**
 *��Դimage_p src������image_p des.ע��˺���ͨ��ֻ������������ʹ��
 *ͨ��ֱ����DrawImage��screen��Ӳ������.
 *@param const image_p src,Դ�ڴ�ͼ
 *@param const image_p des,Ŀ���ڴ�ͼ
 *@param uint32 dx,Ŀ���ڴ�ͼ��x����
 *@param uint32 dy,Ŀ���ڴ�ͼ��y����
 *@return
 */
void image_to_image(const image_p src,const image_p des,uint32 dx,uint32 dy);
/**
 *��Դimage_p src��sx,sh,sw,sh������image_p des.ע��˺���ͨ��ֻ������������ʹ��
 *ͨ��ֱ����DrawImage��screen��Ӳ������.
 *@param const image_p src,Դ�ڴ�ͼ
 *@param const image_p des,Ŀ���ڴ�ͼ
 *@param uint32 sx,Դ�ڴ�ͼ��x����
 *@param uint32 sy,Դ�ڴ�ͼ��y����
 *@param uint32 sw,Դ�ڴ�ͼ�Ŀ�
 *@param uint32 sh,Դ�ڴ�ͼ�ĸ�
 *@param uint32 dx,Ŀ���ڴ�ͼ��x����
 *@param uint32 dy,Ŀ���ڴ�ͼ��y����
 *@return
 */
void image_to_image_ex(const image_p src,const image_p des,uint32 sx,uint32 sy,uint32 sw,uint32 sh,uint32 dx,uint32 dy);
/**
 *��Դimage_p src������image_p des ��alpha���.ע��˺���ͨ��ֻ������������ʹ��
 *ͨ��ֱ����DrawImage��screen��Ӳ������.
 *@param const image_p src,Դ�ڴ�ͼ
 *@param const image_p des,Ŀ���ڴ�ͼ
 *@param uint32 dx,Ŀ���ڴ�ͼ��x����
 *@param uint32 dy,Ŀ���ڴ�ͼ��y����
 *@param int alpha,alpha���ֵ,0-255(͸��->��͸��),����128���ǰ�͸��
 *@return
 */
void image_to_image_alpha(const image_p src,const image_p des,uint32 dx,uint32 dy,int alpha);
/**
 *��Դimage_p src��sx,sh,sw,sh������image_p des.ע��˺���ͨ��ֻ������������ʹ��
 *ͨ��ֱ����DrawImage��screen��Ӳ������.
 *@param const image_p src,Դ�ڴ�ͼ
 *@param const image_p des,Ŀ���ڴ�ͼ
 *@param uint32 sx,Դ�ڴ�ͼ��x����
 *@param uint32 sy,Դ�ڴ�ͼ��y����
 *@param uint32 sw,Դ�ڴ�ͼ�Ŀ�
 *@param uint32 sh,Դ�ڴ�ͼ�ĸ�
 *@param uint32 dx,Ŀ���ڴ�ͼ��x����
 *@param uint32 dy,Ŀ���ڴ�ͼ��y����
 *@param int alpha,alpha���ֵ,0-255(͸��->��͸��),����128���ǰ�͸��
 *@return
 */
void image_to_image_alpha_ex(const image_p src,const image_p des,uint32 sx,uint32 sy,uint32 sw,uint32 sh,uint32 dx,uint32 dy,int alpha);

/**
 *��ԭʼλͼ��ʽ���ݿ�����image,���ǵ�Ч������,ֻ֧��ͬ��displaymode,
 *ע��˴�δ���ж�,������Ҫ��֤data������ȷ��
 *@param void* data,λͼ����
 *@param image_p ,imageָ��,Ŀ��image
 *@param int x,������image�ϵ�dxλ��
 *@param int y,������image�ϵ�dyλ��
 *@param int w,data��w
 *@param int h,data��h
 *@return void,�޷���
 */
void rawdata_to_image(void* data,const image_p des,uint32 x,uint32 y,uint32 w,uint32 h);

/**
 * ��ͼ����ˮƽ��ת��ͼ������x����
 *@param image_p pimage,����תͼ��
 *@return int,�ɹ�1,ʧ��0
 */
int image_fliph(image_p pimage);


/**
 * ��ͼ������ֱ��ת����ת��x��Գ�
 *@param image_p pimage,����תͼ��
 *@return int,�ɹ�1,ʧ��0
 */
int image_flipv(image_p pimage); 


/**
 *������ɫ��������һ��dtype��Ӧ��ɫ��
 *@param uint8 r,r��ɫ����
 *@param uint8 g,g��ɫ����
 *@param uint8 b,b��ɫ����
 *@param uint8 a,a��ɫ����
 *@param int dtype,��ʾģʽ,(DISPLAY_PIXEL_FORMAT_XXX��һ��)
 *@return int ,��ɫֵ
 */
int CreateColor(uint8 r,uint8 g,uint8 b,uint8 a,int dtype);



//���º���Ϊ�ڲ�ʹ��
int GET_PSM_COLOR_MODE(int dtype);
void swizzle_swap(image_p pimage);
void unswizzle_swap(image_p pimage);
//for TH2 debug do not use
int buffer2tga(const char* filename, const char* mbuf,int size,int texw,int texh,int bpb);
int buffer2png(const char* filename, const char* mbuf,int size,int texw,int texh,int bpb);
int file2image(image_p pimg,const char* filename,int texw,int texh,int bpb);
int buffer2image(image_p pimg,char* mbuf,int size,int texw,int texh,int bpb);

#ifdef __cplusplus
}
#endif

#endif