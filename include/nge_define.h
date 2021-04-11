#ifndef NGE_DEFINE_H_
#define NGE_DEFINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#ifdef WIN32
	#ifdef MMGR
		//for win32 debug
		#include "debug/mmgr.h"
	#endif
#endif



#ifndef uint32
#define uint32 unsigned int
#endif

#ifndef sint32
#define sint32 int
#endif

#ifndef uint16
#define uint16 unsigned short
#endif

#ifndef sint16
#define sint16 short
#endif

#ifndef uint8
#define uint8  unsigned char
#endif

#ifndef sint8
#define sint8  char
#endif

#ifndef BOOL
#define BOOL uint8
#endif

/* color define */
#ifdef WIN32
#define GL_UNSIGNED_SHORT_5_6_5_REV   0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define HACK_GL_UNSIGNED_BYTE         0x1401
#define DISPLAY_PIXEL_FORMAT_565  GL_UNSIGNED_SHORT_5_6_5_REV
#define DISPLAY_PIXEL_FORMAT_5551 GL_UNSIGNED_SHORT_1_5_5_5_REV
#define DISPLAY_PIXEL_FORMAT_4444 GL_UNSIGNED_SHORT_4_4_4_4_REV
#define DISPLAY_PIXEL_FORMAT_8888 HACK_GL_UNSIGNED_BYTE
//blend method hack to fuck with <windows.h>,this is copy from <gl/gl.h>

#define BLEND_ZERO					0
#define BLEND_ONE					1
#define BLEND_SRC_COLOR				0x0300
#define BLEND_ONE_MINUS_SRC_COLOR	0x0301
#define BLEND_SRC_ALPHA				0x0302
#define BLEND_ONE_MINUS_SRC_ALPHA	0x0303
#define BLEND_DST_ALPHA				0x0304
#define BLEND_ONE_MINUS_DST_ALPHA	0x0305
#define BLEND_DST_COLOR				0x0306
#define BLEND_ONE_MINUS_DST_COLOR	0x0307
#define BLEND_SRC_ALPHA_SATURATE	0x0308
//define for psp compatiable,no use on WIN32
#define PSM_5551 0
#define PSM_565  1
#define PSM_4444 2
#define PSM_8888 3
#else
#include <pspgu.h>
#define DISPLAY_PIXEL_FORMAT_565  GU_COLOR_5650
#define DISPLAY_PIXEL_FORMAT_5551 GU_COLOR_5551
#define DISPLAY_PIXEL_FORMAT_4444 GU_COLOR_4444
#define DISPLAY_PIXEL_FORMAT_8888 GU_COLOR_8888
//blend methord
#define BLEND_ZERO					0x1000
#define BLEND_ONE					0x1002 
#define BLEND_SRC_COLOR				GU_SRC_COLOR
#define BLEND_ONE_MINUS_SRC_COLOR	GU_ONE_MINUS_SRC_COLOR
#define BLEND_SRC_ALPHA				GU_SRC_ALPHA
#define BLEND_ONE_MINUS_SRC_ALPHA	GU_ONE_MINUS_SRC_ALPHA
#define BLEND_DST_ALPHA				GU_DST_ALPHA
#define BLEND_ONE_MINUS_DST_ALPHA	GU_ONE_MINUS_DST_ALPHA
#define BLEND_DST_COLOR				GU_DST_COLOR
#define BLEND_ONE_MINUS_DST_COLOR	GU_ONE_MINUS_DST_COLOR
#define BLEND_SRC_ALPHA_SATURATE	BLEND_ONE

#define PSM_5551 GU_PSM_5551
#define PSM_565  GU_PSM_5650
#define PSM_4444 GU_PSM_4444
#define PSM_8888 GU_PSM_8888

#endif


#define MAKE_RGB(r,g,b) (r | (g << 8) | (b << 16)|((0xff)<<24))
#define MAKE_RGBA_5551(r,g,b,a)  ((r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10) | ((a >> 7) << 15))
#define MAKE_RGBA_4444(r,g,b,a)  ((r >> 4) | ((g >> 4) << 4) | ((b >> 4) << 8) | ((a >> 4) << 12))
#define MAKE_RGBA_565(r,g,b,a)   ((r >> 3) | ((g >> 2) << 5) | ((b >> 3) << 11))
#define MAKE_RGBA_8888(r,g,b,a)  (r | (g << 8) | (b << 16) | (a << 24))
#define GET_RGBA_565(col,r,g,b,a)	{ \
	a=0xFF;\
	b=(((col>>11)&0x1F)*255/31);\
	g=(((col>>5)&0x3F)*255/63);\
	r=((col&0x1F)*255/31);\
}
#define GET_RGBA_5551(col,r,g,b,a)  { \
	a=((col>>15)==0?0:0xFF);\
	b=(((col>>10)&0x1F)*255/31);\
	g=(((col>>5)&0x1F)*255/31);\
	r=((col&0x1F)*255/31);\
}
#define GET_RGBA_4444(col,r,g,b,a)	{ \
	a=(((col>>12)&0xF)*255/15);\
	b=(((col>>8)&0xF)*255/15);\
	g=(((col>>4)&0xF)*255/15);\
	r=((col&0xF)*255/15);\
}
#define GET_RGBA_8888(col,r,g,b,a)	{ \
	a=(col>>24)&0xFF;\
	b=(col>>16)&0xFF;\
	g=(col>>8)&0xFF;\
	r=(col&0xFF);\
}
#define MAKE_RGBA(r,g,b,a)  (r | (g << 8) | (b << 16) | (a << 24))
#define GET_RGBA_R(col)	(col&0xFF)
#define GET_RGBA_G(col)	((col>>8)&0xFF)
#define GET_RGBA_B(col)	((col>>16)&0xFF)
#define GET_RGBA_A(col)	((col>>24)&0xFF)

/* some color define */
#define BLACK		MAKE_RGB( 0  , 0  , 0   )
#define BLUE		MAKE_RGB( 0  , 0  , 128 )
#define GREEN		MAKE_RGB( 0  , 128, 0   )
#define CYAN		MAKE_RGB( 0  , 128, 128 )
#define RED			MAKE_RGB( 128, 0  , 0   )
#define MAGENTA		MAKE_RGB( 128, 0  , 128 )
#define BROWN		MAKE_RGB( 128, 64 , 0   )
#define LTGRAY		MAKE_RGB( 192, 192, 192 )
#define GRAY		MAKE_RGB( 128, 128, 128 )
#define LTBLUE		MAKE_RGB( 0  , 0  , 255 )
#define LTGREEN		MAKE_RGB( 0  , 255, 0   )
#define LTCYAN		MAKE_RGB( 0  , 255, 255 )
#define LTRED		MAKE_RGB( 255, 0  , 0   )
#define LTMAGENTA	MAKE_RGB( 255, 0  , 255 )
#define YELLOW		MAKE_RGB( 255, 255, 0   )
#define WHITE		MAKE_RGB( 255, 255, 255 )
#define DKGRAY		MAKE_RGB( 32,  32,  32)

/* some color define */
#define BLACK_5551		MAKE_RGBA_5551( 0  , 0  , 0   ,255)
#define BLUE_5551		MAKE_RGBA_5551( 0  , 0  , 128 ,255)
#define GREEN_5551		MAKE_RGBA_5551( 0  , 128, 0   ,255)
#define CYAN_5551		MAKE_RGBA_5551( 0  , 128, 128 ,255)
#define RED_5551		MAKE_RGBA_5551( 128, 0  , 0   ,255)
#define MAGENTA_5551	MAKE_RGBA_5551( 128, 0  , 128 ,255)
#define BROWN_5551		MAKE_RGBA_5551( 128, 64 , 0   ,255)
#define LTGRAY_5551		MAKE_RGBA_5551( 192, 192, 192 ,255)
#define GRAY_5551		MAKE_RGBA_5551( 128, 128, 128 ,255)
#define LTBLUE_5551		MAKE_RGBA_5551( 0  , 0  , 255 ,255)
#define LTGREEN_5551	MAKE_RGBA_5551( 0  , 255, 0   ,255)
#define LTCYAN_5551		MAKE_RGBA_5551( 0  , 255, 255 ,255)
#define LTRED_5551		MAKE_RGBA_5551( 255, 0  , 0   ,255)
#define LTMAGENTA_5551	MAKE_RGBA_5551( 255, 0  , 255 ,255)
#define YELLOW_5551		MAKE_RGBA_5551( 255, 255, 0   ,255)
#define WHITE_5551		MAKE_RGBA_5551( 255, 255, 255 ,255)
#define DKGRAY_5551		MAKE_RGBA_5551( 32,  32,  32  ,255)

#define FONT_BG_5551 MAKE_RGBA_5551(0xff,0xff,0xff,0x00)
#define FONT_FG_5551 MAKE_RGBA_5551(0x00,0x00,0x00,0xff)
#define FONT_SH_5551 MAKE_RGBA_5551(0x7f,0x7f,0x7f,0xff)
#define FONT_BG_4444 MAKE_RGBA_4444(0xff,0xff,0xff,0x00)
#define FONT_FG_4444 MAKE_RGBA_4444(0x00,0x00,0x00,0xff)
#define FONT_SH_4444 MAKE_RGBA_4444(0x7f,0x7f,0x7f,0xff)
#define FONT_BG_565  MAKE_RGBA_565(0xff,0xff,0xff,0x00)
#define FONT_FG_565  MAKE_RGBA_565(0x00,0x00,0x00,0xff)
#define FONT_SH_565  MAKE_RGBA_565(0x7f,0x7f,0x7f,0xff)
#define FONT_BG_8888 MAKE_RGBA_8888(0xff,0xff,0xff,0x00)
#define FONT_FG_8888 MAKE_RGBA_8888(0x00,0x00,0x00,0xff)
#define FONT_SH_8888 MAKE_RGBA_8888(0x7f,0x7f,0x7f,0xff)


typedef struct tagImage{
	uint32  w;        /**< ͼƬԭ�� */
	uint32  h;        /**< ͼƬԭ�� */
	uint32  texw;     /**< ͼƬ��ͼ�� */
	uint32  texh;     /**< ͼƬ��ͼ�� */
	uint8   bpb;      /**< ÿ�����ֽ���(16λ2�ֽ�,32λ4�ֽ�) */
	uint8   swizzle;  /**< �Ƿ��data swizzle �Ż�*/
	uint32  mode;     /**< GSM��ʾmode for psp */
	uint32  dtype;    /**< ��ʾģʽ(DISPLAY_PIXEL_FORMAT_XXX��һ��) */
	uint8*  data;     /**< ͼ������ */
	float   rcentrex; /**< ͼ������x */
	float   rcentrey; /**< ͼ������y */
	uint32  texid;    /**< ͼ��id */
	uint8   modified; /**< ǿ�Ƹ����Դ�*/
	uint8   dontswizzle; /**ǿ�Ʋ�swizzle �Ż�*/
	int     mask;     /**< ��ɫ����,������ʾ����Ч��*/
}image_t,*image_p;

typedef struct{
	uint8 r;
	uint8 g;
	uint8 b;
	uint8 a;
}color4ub;


typedef struct {
    /**
    * Maximum advance width of any character.
	*/
	int maxwidth;
	/**
	* Height of "most characters" in the font. This does not include any
	* leading (blank space between lines of text).
	* Always equal to (baseline+descent).
	*/
	int height;
	/**
	* The ascent (height above the baseline) of "most characters" in
	* the font.
	*
	* Note: This member variable should be called "ascent", to be
	* consistent with FreeType 2, and also to be internally consistent
	* with the "descent" member.  It has not been renamed because that
	* would break backwards compatibility.  FIXME
	*/
	int baseline;
	/**
	* The descent (height below the baseline) of "most characters" in
	* the font.
	*
	* Should be a POSITIVE number.
	*/
	int descent;
	/**
	* Maximum height of any character above the baseline.
	*/
	int maxascent;
	/**
	* Maximum height of any character below the baseline.
	* Should be a POSITIVE number.
	*/
	int maxdescent;
	/**
	* The distance between the baselines of two consecutive lines of text.
	* This is usually height plus some font-specific "leading" value.
	*/
	int linespacing;
	/**
	* First character in the font.
	*/
	int firstchar;
	/**
	* Last character in the font.
	*/
	int lastchar;
	/**
	* True (nonzero) if font is fixed width.  In that case, maxwidth
	* gives the width for every character in the font.
	*/
	BOOL fixed;
	/**
	* Table of character advance widths for characters 0-255.
	* Note that fonts can contain characters with codes >255 - in that
	* case this table contains the advance widths for some but not all
	* characters.  Also note that if the font contains kerning
	* information, the advance width of the string "AV" may differ from
	* the sum of the advance widths for the characters 'A' and 'V'.
	*/
	uint8 widths[256];
} FontInfo, *PFontInfo;

struct _fontproc;
typedef struct _pfont{		/* common hdr for all font structures*/
	struct _fontproc*	    procs;	/* font-specific rendering routines*/
	int		        size;	/* font height in pixels*/
	int		        rotation;	/* font rotation*/
	uint32		    disp;	/* font attributes: kerning/antialias*/
	/* font-specific rendering data here*/
}TFont,*PFont;

typedef struct _fontproc{
	int	    encoding;	/* routines expect this encoding*/
	BOOL	(*GetFontInfo)(PFont pfont, PFontInfo pfontinfo);
	void 	(*GetTextSize)(PFont pfont, const void *text, int cc,int flags, int *pwidth, int *pheight,int *pbase);
	void	(*GetTextBits)(PFont pfont, int ch, const uint8 **retmap,int *pwidth, int *pheight,int *pbase);
	void	(*DestroyFont)(PFont pfont);
	void	(*DrawText)(PFont pfont, image_p pimage, int x, int y,const void *str, int count, int flags);
	void	(*DrawTextShadow)(PFont pfont, image_p pimage, int x, int y,const void *str, int count, int flags);
	uint32  (*SetFontColor)(PFont pfont, uint32 color);
	void    (*SetFontSize)(PFont pfont, int fontsize);
	void    (*SetFontRotation)(PFont pfont, int rot);
	void    (*SetFontAttr)(PFont pfont, int setflags, int clrflags);
	PFont   (*Duplicate) (PFont psrcfont, int fontsize);
	void    (*SetFlags)(PFont pfont,int flags);
	void    (*SetShadowColor)(PFont pfont, uint32 color_fg,uint32 color_bg,uint32 color_sh);
}FontProcs,*PFontProcs;

#ifndef MAX_PATH
#define MAX_PATH 256
#endif
//encoding flags
#define ENCODING_ASCII   0 
#define ENCODING_UNICODE 1
#define ENCODING_GBK     2
//type flags
#define FONT_TYPE_HZK      1
#define FONT_TYPE_GBK      2
#define FONT_TYPE_FREETYPE 4
//show flags
#define FONT_SHOW_NORMAL   0
#define FONT_SHOW_SHADOW   1
//freetype private flags
#define FONT_ANTIALIAS 32
#define FONT_KERNING   64
#define FLAGS_FREETYPE_BOLDER 1
#define FLAGS_FREETYPE_NORMAL 0



#define SAFE_FREE(ptr) do{ \
	if(ptr){           \
		free(ptr); \
		ptr = NULL; \
	} \
}while(0);
//for graphics
#define SCREEN_WIDTH  480
#define SCREEN_HEIGHT 272
#define SCREEN_BPP    32
#define TEXTRUE_MAX_WIDTH 512
#define TEXTRUE_MAX_HEIGHT 512

typedef struct{
	float x;
	float y;
}pointf;

typedef struct{
	float top;
	float left;
	float right;
	float bottom;
}rectf;


//input proc define
#ifdef WIN32
#include <SDL.h>
#define PSP_BUTTON_UP            SDLK_w
#define PSP_BUTTON_DOWN          SDLK_s
#define PSP_BUTTON_LEFT          SDLK_a
#define PSP_BUTTON_RIGHT         SDLK_d
#define PSP_BUTTON_TRIANGLE      SDLK_i
#define PSP_BUTTON_CIRCLE        SDLK_l
#define PSP_BUTTON_CROSS         SDLK_k
#define PSP_BUTTON_SQUARE        SDLK_j
#define PSP_BUTTON_LEFT_TRIGGER  SDLK_e
#define PSP_BUTTON_RIGHT_TRIGGER SDLK_u
#define PSP_BUTTON_SELECT        SDLK_v
#define PSP_BUTTON_START         SDLK_b
#define PSP_BUTTON_HOME          SDLK_n
#define PSP_BUTTON_HOLD          SDLK_m  
#else
#define PSP_BUTTON_UP            8
#define PSP_BUTTON_DOWN          6
#define PSP_BUTTON_LEFT          7
#define PSP_BUTTON_RIGHT         9
#define PSP_BUTTON_TRIANGLE      0
#define PSP_BUTTON_CIRCLE        1
#define PSP_BUTTON_CROSS         2
#define PSP_BUTTON_SQUARE        3
#define PSP_BUTTON_LEFT_TRIGGER  4
#define PSP_BUTTON_RIGHT_TRIGGER 5
#define PSP_BUTTON_SELECT        10
#define PSP_BUTTON_START         11
#define PSP_BUTTON_HOME          12
#define PSP_BUTTON_HOLD          13  
#endif




#endif