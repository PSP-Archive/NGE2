
#ifndef _PACK_PSP_H_
#define _PACK_PSP_H_

#include <stdio.h>
#include "libnge2.h"

#define VERSION		0x1000
#define NORMALSIZE	64

typedef struct packDate		/* 文件索引表数据 */
{
	char name[NORMALSIZE-8];	/* 文件名 */
	long offset;	/* 文件位移 */
	long size;		/* 文件大小 */
} packDate;

typedef struct packInfo		/* 文件头 */
{
	int VER;	/* 库版本 */
	int nums;	/* 文件数目 */
	char password[6];	/* 密码密文,救命用 */
	char info[128];	/* 写点废话,例如密码提示什么的 */
} packInfo;

typedef struct packItem		/* 索引表链表 */
{
	packDate date;	/* 数据 */
	struct packItem* next;	/* 链表 */
}  packItem;

#ifdef __cplusplus
extern "C" {
#endif
/*
 *	功能:初始化系统并加载资源到缓冲,必须操作
 *	const char* filename 需要加载的打包文件
 *	return 文件加载失败返回-1,成功返回文件指针fd
 */
int		packInit		(const char* filename);
/*
 *	功能:打开打包文件中名为filename的文件,不可进行文件关闭操作
 *			文件关闭操作由系统完成,只是单纯想得到某个文件建议用此函数
 *	{
 *		packInit("DATA.BIN");
 *		int fd = packOpen("image001.jpg");
 *		int size = packSize("image001.jpg");
 *		.....;
 *		packFini();
 *	}
 *	const char* filename 需要打开的文件名
 *	return 打开失败返回-1,打开成功返回文件指针fd
 */
int		packOpen		(const char* filename);
/*
 *	功能:异步打开打包文件中名为filename的文件,流读取建议用此函数,
 *			使用完毕需要自行进行文件关闭操作,例如:
 *	{
 *		packInit("DATA.BIN");
 *		int fd = packOpenAsync("bgmusic.mp3");
 *		int size = packSize("bgmusic.mp3");
 *		.....;
 *		io_fclose(fd);
 *		packFini();
 *	}
 *	const char* filenmae 需要打开的文件名
 *	return 打开失败返回-1,打开成功返回文件指针fd
 */
int		packOpenAsync	(const char* filename);
/*
 *	功能:得到打包文件中名为filename的文件大小
 *	const char* filename 需要打开的文件名
 *	return 打开失败返回-1,打开成功返回文件大小
 */
long	packSize		(const char* filename);
/*
 *	功能:得到打包文件中名为filename的文件偏移量
 *	const char* filename 需要打开的文件名
 *	return 打开失败返回-1,打开成功返回文件偏移量offset
 */
long	packOffset		(const char* filename);
/*
 *	功能:关闭系统并清空资源
 *	return 无
 */
void	packFini		(void);

#ifdef __cplusplus
}
#endif

#endif