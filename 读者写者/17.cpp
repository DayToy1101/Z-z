#include "stdafx.h"
#include "windows.h"
#include <conio.h>
#include <stdlib.h>
#include <fstream.h>
#include <io.h>
#include <string.h>
#include <stdio.h>
#define READER 'R'
#define WRITER 'W'
#define INTE_PER_SEC 1000
#define MAX_THREAD_NUM 64
#define MAX_FILE_NUM 32
#define MAX_STR_LEN 32
int readcount = 0;
int writecount = 0;
CRITICAL_SECTION RP_Write;
CRITICAL_SECTION cs_Write;

CRITICAL_SECTION cs_Read;
struct ThreadInfo
{
	int serial;
	char entity;
	double delay;
	double persist;
};
//P:读者线程信息
void RP_ReaderThread(void *p)
{
	HANDLE h_Mutex;
	h_Mutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "mutex_for_readcount");
	DWORD wait_for_mutex;
	DWORD m_delay;
	DWORD m_persist;
	int m_serial;
	//从参数中获得信息
	m_serial = ((ThreadInfo *)(p))->serial;
	m_delay = (DWORD)(((ThreadInfo *)(p))->delay *INTE_PER_SEC);
	m_persist = (DWORD)(((ThreadInfo *)(p))->persist *INTE_PER_SEC);
	Sleep(m_delay);
	printf("读线程 %d 发出读请求.\n", m_serial);
	wait_for_mutex = WaitForSingleObject(h_Mutex, -1);
	readcount++;
	if (readcount == 1)
	{
		EnterCriticalSection(&RP_Write);
	}
	ReleaseMutex(h_Mutex);
	//读文件
	printf("读线程 %d 开始读文件 .\n", m_serial);
	Sleep(m_persist);
	//退出线程
	printf("读线程 %d 结束读文件.\n", m_serial);
	//等待互斥信号
	wait_for_mutex = WaitForSingleObject(h_Mutex, -1);
	//读者数目减少
	readcount--;
	if (readcount == 0)
	{
		LeaveCriticalSection(&RP_Write);
	}
	ReleaseMutex(h_Mutex);
}
//p:写者线程信息
void RP_WriterThread(void *p)
{
	DWORD m_delay;
	DWORD m_persist;
	int m_serial;
	//从参数中获得信息
	m_serial = ((ThreadInfo *)(p))->serial;
	m_delay = (DWORD)(((ThreadInfo*)(p))->delay * INTE_PER_SEC);
	m_persist = (DWORD)(((ThreadInfo*)(p))->persist* INTE_PER_SEC);
	Sleep(m_delay);
	printf("写线程 %d 发出写请求***.\n", m_serial);

	//等待资源
	EnterCriticalSection(&RP_Write);
	//写文件
	printf("写线程 %d 开始写文件.\n",m_serial);
	Sleep(m_persist);

	//退出线程
	printf("写线程 %d 结束写文件.\n",m_serial);
	//释放资源
	LeaveCriticalSection(&RP_Write);
}
///////////////////////////////////////////
//读者优先处理函数
void ReaderPriority(char *file)
{
	DWORD n_thread=0;
	DWORD thread_ID;
	DWORD wait_for_all;

	//互斥对象
	HANDLE h_Mutex;
	 h_Mutex=CreateMutex(NULL,FALSE,"mutex_for_readcount");
	 //线程对象的数组
	 HANDLE h_Thread[MAX_THREAD_NUM];
	 ThreadInfo thread_info[MAX_THREAD_NUM];

	 readcount=0;
	 InitializeCriticalSection(&RP_Write);
	 ifstream inFile;
	 inFile.open(file);
	 printf("读者优先：\n\n");
	 while(inFile)
	 {
		 //读入每一个读者，写者信息
		 inFile>>thread_info[n_thread].serial;
		 inFile>>thread_info[n_thread].entity;
		 inFile>>thread_info[n_thread].delay;
		 inFile>>thread_info[n_thread++].persist;
		 inFile.get();
	 }
	 for(int i=0;i<(int)(n_thread);i++)
	 {
		 if(thread_info[i].entity==READER||thread_info[i].entity=='r')
		 {
			 //创建读者进程
			 h_Thread[i]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(RP_ReaderThread),&thread_info[i],0,&thread_ID);
		 }
		 else
		 {
			 h_Thread[i]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(RP_WriterThread),&thread_info[i],0,&thread_ID);
		 }
	 }
		 //等待所有的线程结束
		 wait_for_all=WaitForMultipleObjects(n_thread,h_Thread,TRUE,-1);
		 //printf("all reader and writer have finished operating.\n");
		 printf("所有的读写线程结束操作.\n");
	 }
int main(int argc,char *argv[])
	 {
		 ReaderPriority("input.txt");
		 printf("\n按任意键结束：");
		 getch();
		 return 0;
	 }
