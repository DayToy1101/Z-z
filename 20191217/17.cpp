#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip.h>
typedef struct node{
	char name[50];
	int type;
	struct node *next;
	struct node *sub;
	struct node *father;
	int size;
}dirNode;
dirNode *workDir;
dirNode root;
char path[100];
void initial()
{
	strcpy(root.name,"root");
	root.type=0;
	root.next=NULL;
	root.sub=NULL;
	root.father=NULL;
	root.size=0;
	workDir=&root;
	strcpy(path,"root");
}
dirNode *init()
{
	dirNode *p;
	p=new dirNode;
	strcpy(root.name,"");
	root.type=0;
	root.next=NULL;
	root.sub=NULL;
	root.father=NULL;
	root.size=0;
	return p;
}
void CD(char dirName[])
{
	dirNode *p;
	int flag=0;
	p=workDir->sub;
	if(p==NULL)
	{
		cout<<"错误,\""<<dirName<<"\"子目录不存在"<<endl;
	}
	else
	{
		while(p)
		{
			if(p->type==0)
			{
				if(!strcmp(p->name,dirName))
				{
					flag=1;
					break;
				}
			}
			p=p->next;
		}
		if(flag==1)
		{
			workDir=p;
			strcat(path,"\\");
			strcat(path,p->name);
			cout<<"工作目录已进入\""<<dirName<<"\""<<endl;
		}
		else
		{
			cout<<"错误,\""<<dirName<<"\"子目录不存在"<<endl;
		}
	}
}
void CREATE(char fileName[],int fileSize)
{
	int flag;
	dirNode *p,*q;
	q=new dirNode;
	strcpy(q->name,fileName);
	q->sub=NULL;
	q->type=1;
	q->next=NULL;
	q->father=workDir;
	q->size=fileSize;
	p=workDir->sub;
	if(p==NULL)
	{
		workDir->sub=q;
		cout<<"\""<<fileName<<"\"文件创建成功"<<endl;
	}
	else
	{
		flag=0;
		while(p)
		{
			if(p->type==1)
			{
				if(!strcmp(p->name,fileName))
				{
					flag=1;
					cout<<"错误,\""<<fileName<<"\"文件已存在"<<endl;
				}
			}
			p=p->next;
		}
		if(flag==0)
		{
			p=workDir->sub;
			while(p->next)
			{
				p=p->next;
			}
			p->next=q;
			cout<<"\""<<fileName<<"\"文件创建成功"<<endl;
		}
	}
}
void DEL(char fileName[])
{
	dirNode *p,*q;
	int flag=0;
	p=workDir->sub;
	if(p==NULL)
	{
		cout<<"错误,\""<<fileName<<"\"文件不存在"<<endl;
	}
	else
	{
		while(p)
		{
			if(p->type==1)
			{
				if(!strcmp(p->name,fileName))
				{
					flag=1;
					break;
				}
			}
			p=p->next;
		}
		if(flag==1)
		{
			if(p==workDir->sub)
			{
				workDir->sub=p->next;
			}
			else
			{
				q=workDir->sub;
				while(q->next!=p)
				{
					q=q->next;
				}
				q->next=p->next;
				delete p;
			}
			cout<<"\""<<fileName<<"\"文件已删除"<<endl;
		}
		else
		{
			cout<<"错误,\""<<fileName<<"\"文件不存在"<<endl;
		}
	}
}
void dir(dirNode *p)
{
	while(p)
	{
		if(p->type==0)
		{
			cout.setf(2);
			cout<<setw(14)<<p->name<<setw(12)<<"<DIR>"<<endl;
		}
		else
		{
			cout.setf(2);
			cout<<setw(14)<<p->name<<setw(12)<<"<FILE>"<<setw(10)<<p->size<<endl;
		}
		p=p->next;
	}
}
void dirs(dirNode *p,char str[])
{
	char newstr[100];
	dirNode *q;
	cout<<str<<"下子目录及文件:"<<endl;
	dir(p);
	q=p;
	if(q->sub)
	{
		strcpy(newstr," ");
		strcat(newstr,str);
		strcat(newstr,"\\");
		strcat(newstr,q->name);
		dirs(q->sub,newstr);
	}
	q=p;
	while(q->next)
	{
		if(q->next->sub)
		{
			strcpy(newstr," ");
			strcat(newstr,str);
			strcat(newstr,"\\");
			strcat(newstr,q->next->name);
			dirs(q->next->sub,newstr);
		}
		q=q->next;
	}
}
void LSALL()
{
	dirNode *p;
	cout<<"显示所有目录结构";
	cout<<endl<<"---------------------------------"<<endl;
	p=root.sub;
	if(p!=NULL)
		dirs(p,"root");
	else
		cout<<"目录为空"<<endl;
}
void MD(char dirName[])
{
	int flag;
	dirNode *p,*q;
	q=new dirNode;
	strcpy(q->name,dirName);
	q->sub=NULL;
	q->type=0;
	q->next=NULL;
	q->father=workDir;
	q->size=0;
	p=workDir->sub;
	if(p==NULL)
	{
		workDir->sub=q;
		cout<<"\""<<dirName<<"\"子目录创建成功"<<endl;
	}
	else
	{
		flag=0;
		while(p)
		{
			if(p->type==0)
			{
				if(!strcmp(p->name,dirName))
				{
					flag=1;
					cout<<"错误,\""<<dirName<<"\"子目录已存在"<<endl;
				}
			}
			p=p->next;
		}
		if(flag==0)
		{
			p=workDir->sub;
			while(p->next)
			{
				p=p->next;
			}
			p->next=q;
			cout<<"\""<<dirName<<"\"子目录创建成功"<<endl;
		}
	}
}
void RD(char dirName[])
{
	dirNode *p,*q;
	int flag=0;
	p=workDir->sub;
	if(p==NULL)
	{
		cout<<"错误,\""<<dirName<<"\"子目录不存在"<<endl;
	}
	else
	{
		while(p)
		{
			if(p->type==0)
			{
				if(!strcmp(p->name,dirName))
				{
					flag=1;
					break;
				}
			}
			p=p->next;
		}
		if(flag==1)
		{
			if(p==workDir->sub)
			{
				workDir->sub=p->next;
			}
			else
			{
				q=workDir->sub;
				while(q->next!=p)
				{
					q=q->next;
				}
				q->next=p->next;
				delete p;
			}
			cout<<"\""<<dirName<<"\"子目录已删除"<<endl;
		}
		else
		{
			cout<<"错误,\""<<dirName<<"\"子目录不存在"<<endl;
		}
	}
}
void main()
{
	int len,fileSize,flag,comm;
	char string[50];
	char command[10];
	char name[40];
	char *s,*s1;
	initial();
	flag=1;
	while(flag)
	{
		cout<<endl<<"模拟文件管理模拟系统"<<endl;
		cout<<endl<<"cd改变目录create创建文件del删除文件"<<endl<<"dir显示目录md创建目录rd删除目录"<<endl<<"exit退出"<<endl;
		cout<<endl<<"---------------------------------------------------------------------"<<endl;
		printf("%s:>#",path);
		gets(string);
		len=strlen(string);
		if(len==0)
		{
			strcpy(command,"errer");
		}
		else
		{
			s=NULL;
			s=strchr(string,' ');
			if(s!=NULL)
			{
				*s='\0';
			}
			strcpy(command,string);
			if((!strcmp(command,"CD"))||!strcmp(command,"cd"))
			{
				comm=1;
			}
			else
			{
				if((!strcmp(command,"CREATE"))||!strcmp(command,"create"))
				{
					comm=2;
				}
				else
				{
					if((!strcmp(command,"DEL"))||!strcmp(command,"del"))
					{
						comm=3;
					}
					else
					{
						if((!strcmp(command,"DIR"))||!strcmp(command,"dir"))
						{
							comm=4;
						}
						else
						{
							if((!strcmp(command,"MD"))||!strcmp(command,"md"))
							{
								comm=5;
							}
							else
							{
								if((!strcmp(command,"RD"))||!strcmp(command,"rd"))
								{
									comm=6;
								}
								else
								{
									if((!strcmp(command,"EXIT"))||!strcmp(command,"exit"))
									{
										comm=0;
									}
									else
									{
										comm=100;
									}
								}
							}
						}
					}
				}
			}
			switch(comm)
			{
			case 1:
				strcpy(name,s+1);
				CD(name);
				break;
			case 2:
				s1=strchr(s+1,' ');
				*s1='\0';
				strcpy(name,s+1);
				fileSize=atoi(s1+1);
				CREATE(name,fileSize);
				break;
			case 3:
				strcpy(name,s+1);
				DEL(name);
				break;
			case 4:
				LSALL();
				break;
			case 5:
				strcpy(name,s+1);
				MD(name);
				break;
			case 6:
				strcpy(name,s+1);
				RD(name);
				break;
			case 0:
				flag=0;
				break;
			default:
				cout<<"命令错误"<<endl;
			}
		}
		}
		}