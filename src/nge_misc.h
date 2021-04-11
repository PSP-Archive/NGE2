#ifndef NGE_MISC_H_
#define NGE_MISC_H_


#ifdef WIN32
#include <SDL.h>
//���ߺ�����
#define nge_sleep(tick) SDL_Delay(tick)
#else
#include <pspdebug.h>
#include <pspthreadman.h>
//���ߺ�����
#define nge_sleep(tick) sceKernelDelayThread((tick)*1000)
#endif

#ifdef __cplusplus
extern "C"{
#endif
/**
 *��GBK������ַ�ת��Ϊunicode�ַ�
 *ע��outbuffer��ҪԤ�ȷ����㹻��С.
 *@param unsigned short* out,ת����unicode�ַ�����������,ע����ҪԤ�ȷ����㹻��С
 *@param const char* in,�����ַ�����
 *@param int n,GBK�ַ��������ֽڼ�,strlen����ĸ���(����һ������Ϊ2���ַ�)
 *@return int n,ת����unicode�ַ�����
 */
int gbk_to_unicode(unsigned short* out,const char* in,int n);

#ifdef __cplusplus
}
#endif

#endif
