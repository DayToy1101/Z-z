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
//P:�����߳���Ϣ
void RP_ReaderThread(void *p)
{
	HANDLE h_Mutex;
	h_Mutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "mutex_for_readcount");
	DWORD wait_for_mutex;
	DWORD m_delay;
	DWORD m_persist;
	int m_serial;
	//�Ӳ����л����Ϣ
	m_serial = ((ThreadInfo *)(p))->serial;
	m_delay = (DWORD)(((ThreadInfo *)(p))->delay *INTE_PER_SEC);
	m_persist = (DWORD)(((ThreadInfo *)(p))->persist *INTE_PER_SEC);
	Sleep(m_delay);
	printf("���߳� %d ����������.\n", m_serial);
	wait_for_mutex = WaitForSingleObject(h_Mutex, -1);
	readcount++;
	if (readcount == 1)
	{
		EnterCriticalSection(&RP_Write);
	}
	ReleaseMutex(h_Mutex);
	//���ļ�
	printf("���߳� %d ��ʼ���ļ� .\n", m_serial);
	Sleep(m_persist);
	//�˳��߳�
	printf("���߳� %d �������ļ�.\n", m_serial);
	//�ȴ������ź�
	wait_for_mutex = WaitForSingleObject(h_Mutex, -1);
	//������Ŀ����
	readcount--;
	if (readcount == 0)
	{
		LeaveCriticalSection(&RP_Write);
	}
	ReleaseMutex(h_Mutex);
}
//p:д���߳���Ϣ
void RP_WriterThread(void *p)
{
	DWORD m_delay;
	DWORD m_persist;
	int m_serial;
	//�Ӳ����л����Ϣ
	m_serial = ((ThreadInfo *)(p))->serial;
	m_delay = (DWORD)(((ThreadInfo*)(p))->delay * INTE_PER_SEC);
	m_persist = (DWORD)(((ThreadInfo*)(p))->persist* INTE_PER_SEC);
	Sleep(m_delay);
	printf("д�߳� %d ����д����***.\n", m_serial);

	//�ȴ���Դ
	EnterCriticalSection(&RP_Write);
	//д�ļ�
	printf("д�߳� %d ��ʼд�ļ�.\n",m_serial);
	Sleep(m_persist);

	//�˳��߳�
	printf("д�߳� %d ����д�ļ�.\n",m_serial);
	//�ͷ���Դ
	LeaveCriticalSection(&RP_Write);
}
///////////////////////////////////////////
//�������ȴ�����
void ReaderPriority(char *file)
{
	DWORD n_thread=0;
	DWORD thread_ID;
	DWORD wait_for_all;

	//�������
	HANDLE h_Mutex;
	 h_Mutex=CreateMutex(NULL,FALSE,"mutex_for_readcount");
	 //�̶߳��������
	 HANDLE h_Thread[MAX_THREAD_NUM];
	 ThreadInfo thread_info[MAX_THREAD_NUM];

	 readcount=0;
	 InitializeCriticalSection(&RP_Write);
	 ifstream inFile;
	 inFile.open(file);
	 printf("�������ȣ�\n\n");
	 while(inFile)
	 {
		 //����ÿһ�����ߣ�д����Ϣ
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
			 //�������߽���
			 h_Thread[i]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(RP_ReaderThread),&thread_info[i],0,&thread_ID);
		 }
		 else
		 {
			 h_Thread[i]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(RP_WriterThread),&thread_info[i],0,&thread_ID);
		 }
	 }
		 //�ȴ����е��߳̽���
		 wait_for_all=WaitForMultipleObjects(n_thread,h_Thread,TRUE,-1);
		 //printf("all reader and writer have finished operating.\n");
		 printf("���еĶ�д�߳̽�������.\n");
	 }
int main(int argc,char *argv[])
	 {
		 ReaderPriority("input.txt");
		 printf("\n�������������");
		 getch();
		 return 0;
	 }
