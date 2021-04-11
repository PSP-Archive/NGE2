#ifndef NGE_NET_COMMON_H_
#define NGE_NET_COMMON_H_
/**
 * ����һ��socket
 *@param int af,��ַ��ָ��,ͨ����дAF_INET
 *@param int type,socket����,����дSOCK_STREAM(TCP)��SOCK_DGRAM(UDP)
 *@param int protocol,Э���,ͨ����0
 *@return int,socket���,�ô˾������������,<=0�������
 */
int socket_create(int af,int type,int protocol);
/**
 * ����socketѡ��,ͨ���ǲ���Ҫ����ѡ���
 *@param int fd,socket handle,������socket_create()������handle
 *@param int level,ѡ���Ĳ��:Ŀǰ��֧��SOL_SOCKET��IPPROTO_TCP���.
 *@param int optname,�����õ�ѡ��,�ϳ��õ���SO_REUSEADDR
 *@param const char* optval,ָ����ѡ��ֵ�Ļ�����
 *@param int optval,�������ĳ���
 *@return int,����ֵС�ڵ���0����
 */
int socket_setopt(int fd,int level,int optname,const char* optval,int optlen);
/**
 * ��������Ϊ������ģʽ
 *@param int fd,socket handle,������socket_create()������handle
 *@return int, ����ֵС�ڵ���0����
 */
int socket_setnoblock(int fd);
/**
 *@param int fd,socket handle,������socket_create()������handle
 *@param const char* buf,����buf����
 *@param int len,buf�ĳ���
 *@return int, ����ʵ�ʽ��յĳ���,<=0Ϊ����,��TCP��˵(����0ΪClient�����Ͽ�����,С��0Ϊ������������)
 */
int socket_recv(int fd,const char *buf,int len);
/**
 *@param int fd,socket handle,������socket_create()������handle
 *@param const char* buf,����buf����
 *@param int len,buf�ĳ���
 *@return int, ����ʵ�ʷ��͵ĳ���,<=0Ϊ����,������noblock��ֱ�ӷ��ط���Ϊ��������
 */
int socket_send(int fd,const char *buf,int len);
/**
 * �ر�һ��socket
 *@param int fd,socket handle,������socket_create()������handle
 *@return int,����ֵ����0�ɹ�
 */
int socket_close(int fd);

#endif
