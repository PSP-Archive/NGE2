
#ifndef _PACK_PSP_H_
#define _PACK_PSP_H_

#include <stdio.h>
#include "libnge2.h"

#define VERSION		0x1000
#define NORMALSIZE	64

typedef struct packDate		/* �ļ����������� */
{
	char name[NORMALSIZE-8];	/* �ļ��� */
	long offset;	/* �ļ�λ�� */
	long size;		/* �ļ���С */
} packDate;

typedef struct packInfo		/* �ļ�ͷ */
{
	int VER;	/* ��汾 */
	int nums;	/* �ļ���Ŀ */
	char password[6];	/* ��������,������ */
	char info[128];	/* д��ϻ�,����������ʾʲô�� */
} packInfo;

typedef struct packItem		/* ���������� */
{
	packDate date;	/* ���� */
	struct packItem* next;	/* ���� */
}  packItem;

#ifdef __cplusplus
extern "C" {
#endif
/*
 *	����:��ʼ��ϵͳ��������Դ������,�������
 *	const char* filename ��Ҫ���صĴ���ļ�
 *	return �ļ�����ʧ�ܷ���-1,�ɹ������ļ�ָ��fd
 */
int		packInit		(const char* filename);
/*
 *	����:�򿪴���ļ�����Ϊfilename���ļ�,���ɽ����ļ��رղ���
 *			�ļ��رղ�����ϵͳ���,ֻ�ǵ�����õ�ĳ���ļ������ô˺���
 *	{
 *		packInit("DATA.BIN");
 *		int fd = packOpen("image001.jpg");
 *		int size = packSize("image001.jpg");
 *		.....;
 *		packFini();
 *	}
 *	const char* filename ��Ҫ�򿪵��ļ���
 *	return ��ʧ�ܷ���-1,�򿪳ɹ������ļ�ָ��fd
 */
int		packOpen		(const char* filename);
/*
 *	����:�첽�򿪴���ļ�����Ϊfilename���ļ�,����ȡ�����ô˺���,
 *			ʹ�������Ҫ���н����ļ��رղ���,����:
 *	{
 *		packInit("DATA.BIN");
 *		int fd = packOpenAsync("bgmusic.mp3");
 *		int size = packSize("bgmusic.mp3");
 *		.....;
 *		io_fclose(fd);
 *		packFini();
 *	}
 *	const char* filenmae ��Ҫ�򿪵��ļ���
 *	return ��ʧ�ܷ���-1,�򿪳ɹ������ļ�ָ��fd
 */
int		packOpenAsync	(const char* filename);
/*
 *	����:�õ�����ļ�����Ϊfilename���ļ���С
 *	const char* filename ��Ҫ�򿪵��ļ���
 *	return ��ʧ�ܷ���-1,�򿪳ɹ������ļ���С
 */
long	packSize		(const char* filename);
/*
 *	����:�õ�����ļ�����Ϊfilename���ļ�ƫ����
 *	const char* filename ��Ҫ�򿪵��ļ���
 *	return ��ʧ�ܷ���-1,�򿪳ɹ������ļ�ƫ����offset
 */
long	packOffset		(const char* filename);
/*
 *	����:�ر�ϵͳ�������Դ
 *	return ��
 */
void	packFini		(void);

#ifdef __cplusplus
}
#endif

#endif