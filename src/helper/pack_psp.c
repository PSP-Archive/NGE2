
#ifndef _PACK_PSP_C_
#define _PACK_PSP_C_

#include <stdlib.h>
#include <nge_io_file.h>
#include "pack_psp.h"

#ifdef __cplusplus
extern "C" {
#endif

int			fd			=		-1;
char*		name		=		NULL;
packInfo*	Info		=		NULL;
packItem*	Item		=		NULL;

void packCleanRes()	/* 清空资源 */
{
	packItem* temp;
	if(fd>0) {
		io_fclose(fd);
		fd = -1; }
	if(Info!=NULL) {
		free(Info);
		Info = NULL; }
	if(name!=NULL) {
		free(name);
		name = NULL; }
	if(Item!=NULL)
	{
		while(Item!=NULL) {
			temp = Item;
			Item = Item->next;
			free(temp);
			temp = NULL; }
		Item = NULL;
	}
}

int packInit(const char* filename)
{
	int i = 0;
	packItem* temp;
	packCleanRes();
	fd = io_fopen(filename,IO_RDONLY);
	if(fd <= 0)
		return -1;
	Info = (packInfo*) malloc (sizeof(packInfo));
	io_fseek(fd,-sizeof(packInfo),IO_SEEK_END);
	io_fread(Info,sizeof(packInfo),1,fd);
	if(Info->VER!=VERSION) {	// 如果不是pack压缩包则取消读取
		packCleanRes();
		return -1; }
	io_fseek(fd,-(sizeof(packInfo)+sizeof(packDate)*Info->nums),IO_SEEK_END);
	for(i=0;i<Info->nums;i++)
	{
		if(Item==NULL) {
			Item = (packItem*) malloc (sizeof(packItem));
			temp = Item;
			io_fread(&temp->date,sizeof(packDate),1,fd);
			temp->next = NULL; }
		if((i>0) && (temp->next==NULL)) {
			temp->next = (packItem*) malloc (sizeof(packItem));
			temp = temp->next;
			io_fread(&temp->date,sizeof(packDate),1,fd);
			temp->next = NULL; }
	}
	if(name==NULL) {
		name = (char*) malloc (strlen(filename)+1);
		strcpy(name,filename); }
	rewind((FILE*)fd);
	return fd;
}

int packOpen(const char* filename)
{
	packItem* temp = NULL;
	temp = Item;
	while( strcmp(filename,temp->date.name) ) {
		temp = temp->next;
		if(temp==NULL)
		return -1; }
	io_fseek(fd,temp->date.offset,IO_SEEK_SET);
	return fd;
}

int packOpenAsync(const char* filename)
{
	int fd = io_fopen(name,IO_RDONLY);
	packItem* temp = NULL;
	temp = Item;
	while( strcmp(filename,temp->date.name) ) {
		temp = temp->next;
		if(temp==NULL)
		return -1; }
	io_fseek(fd,temp->date.offset,IO_SEEK_SET);
	return fd;
}

long packSize(const char* filename)
{
	packItem* temp = NULL;
	temp = Item;
	while( strcmp(filename,temp->date.name) ) {
		temp = temp->next;
		if(temp==NULL)
		return -1; }
	return temp->date.size;
}

long packOffset(const char* filename)
{
	packItem* temp = NULL;
	temp = Item;
	while( strcmp(filename,temp->date.name) ) {
		temp = temp->next;
		if(temp==NULL)
		return -1; }
	return temp->date.offset;
}

void packFini(void)
{
	packCleanRes();
}

#ifdef __cplusplus
}
#endif

#endif