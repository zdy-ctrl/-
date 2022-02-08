#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <stdio.h> 


using namespace std;


typedef struct
{
	char no[20];	//ͼ���� 
	char name[20];	//ͼ������ 
	int price;	//ͼ��۸� 
}Book;

typedef struct
{
	Book *elem;		
	int length;
}SqList;

typedef struct                            
{
    char reader_num[10];                           //���߿��� 
    char reader_name[10];                         //������
} BO;

//����ģ��
typedef struct                            
{
	BO *elem;
	int length;
} RD;

int IntList(SqList &L);
int GetList(SqList &L);
int LocalList(SqList L);
int NumberList(SqList L);
int InsertList(SqList &L);
int DeleteList(SqList &L);
void  ShowList(SqList L);

int IntRD(RD &R);
int GetRD(RD &R);
int LocalRD(RD &R);
int Borrow_book(RD &R,SqList &L);
int also_book(RD &R,SqList &L) ;

void writeBook(SqList &L) ;
void writeReader(RD &R); 
void readBook(SqList &L);
void readReader(RD &R);

int main(){

//	SqList buffer[1000];
	int n,i;
	SqList L;
	RD R;
	IntList(L);
	IntRD(R);
	while(1)
	{
		printf("***********************************\n");
		printf("--------��ӭ����ͼ�����ϵͳ-------\n");
		printf("-------   1��¼��ͼ����Ϣ  --------\n");
		printf("-------   2��¼�������Ϣ  --------\n");
		printf("-------   3������ͼ����Ϣ  --------\n");
		printf("-------   4��ɾ��ͼ����Ϣ  --------\n");
		printf("-------   5��ͳ��ͼ������  --------\n");
		printf("-------   6������ͼ����Ϣ --------\n");
		printf("-------   7�����Ҷ�����Ϣ --------\n");
		printf("-------   8������ģ��      --------\n");
		printf("-------   9������ģ��      --------\n");
		printf("-------   10����ȡͼ��ģ��  --------\n");
		printf("-------   11����ȡ����ģ��  --------\n");
		printf("-------   0���˳�ͼ�����ϵͳ------\n");
		printf("��ѡ����Ҫִ�еĲ���:");
		scanf("%d",&n);
		switch(n)
		{

		case 1:
			GetList(L);
			writeBook(L);
			break;
		case 2:
			GetRD(R);
			writeReader(R); 
			break;
		case 3:
			InsertList(L);
			break;
		case 4:
			DeleteList(L);
			break;
		case 5:
			NumberList(L);
			break;
		case 6:
			LocalList(L);
			break;
		case 7:
			LocalRD(R);
			break;
		case 8:
			Borrow_book(R,L); 
			break;
		case 9:
			also_book(R,L);
			break; 
		case 10:
			readBook(L);
			break;
		case 11:
			readReader(R);
			break;
		case 0:
			printf("--------   ллʹ��ͼ�����ϵͳ!   --------\n");
			exit(0);
			break;
		default:
			printf("������������д�������0`6��ִ�����֡�\n");
			break;
		}
	}
	return 0 ; 
} 

/************************************************


******************ͼ���************************* 


************************************************/ 
//˳���ĳ�ʼ��
int IntList(SqList &L)
{
	L.elem=new Book[3000];
	if(!L.elem){
		printf("˳�����ʧ��!\n");
	exit(-1);
	}
	L.length=0;
	printf("˳�����ɹ�!\n");
	return 1;
}

//˳����ȡֵ
int GetList(SqList &L)
{	
	int x,i;
	printf("��������Ҫ¼���ͼ������:");
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		printf("���:"); 
		scanf("%s",L.elem[i].no);
		printf("����:");
		scanf("%s",L.elem[i].name);
		printf("ͼ��۸�");
		//scanf("%d",L.elem[i].price);
		cin>>L.elem[i].price;
			++L.length;
	}
	return 0;
}

//˳����Ԫ����ʾ
void  ShowList(SqList L)
{
	int i=1;
	cout<<"���\t\t"<<"����\t\t"<<"ͼ��۸�"<<endl;
	for(i;i<=L.length;i++){
		cout<<L.elem[i].no<<"\t\t"<<L.elem[i].name<<"\t\t"<<L.elem[i].price<<endl;
	}
}


//˳���Ĳ���
int LocalList(SqList L)
{
	int i=1;
	int x,c;
	char a[20];
	char b[20];
	printf("1������Ų���:");
	printf("2������������:");
	printf("3����ͼ��۸����:");
	scanf("%d",&x);
	switch(x)
	{
	case 1:
		printf("��������Ҫ��ѯ�����:\n") ;
		scanf("%s",&a);
		for(i;i<=L.length;i++)
		{
			if(!strcmp(L.elem[i].no,a))
			{
				printf("���\t\t����\t\tͼ��۸�\n");
				printf("%s\t\t%s\t\t%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
			}else{
				printf("���鲻������У�\n");
			} 
			break;
		}
		break;
	case 2:
		printf("��������Ҫ��ѯ������:\n");
		scanf("%s",&b);
		for(i;i<=L.length;i++)
		{
			if(!strcmp(L.elem[i].name,b))
			{
				printf("���\t\t����\t\tͼ��۸�\n");
				printf("%s\t\t%s\t\t%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
			}else{
				printf("���鲻������У�\n");
			}
			break;
		}
		break;
	case 3:
		printf("��������Ҫ��ѯ��ͼ��۸�:");
		scanf("%s",&c);
		for(i;i<=L.length;i++)
		{
			if(L.elem[i].price==c)
			{
				printf("���\t\t����\t\tͼ��۸�\n");
				printf("%s\t\t%s\t\t%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
			}else{
				printf("���鲻������У�\n");
			}
			break;
		}
		break;
	default:
		printf("���������ѡ���д���!\n");
		break;
	}
	return 0;
}

//˳���Ĳ���
int InsertList(SqList &L)
{
	int i;
	char a[20];
	char b[20];
	int  s;
	printf("��������Ҫ�����λ��:");
	scanf("%d",i);
	if(i<1||i>L.length+1)
	{
		printf("����λ�ò��Ϸ�!\n");
		return 0;
	}
	if(L.length==30)
	{
		printf("˳����Ѿ�����!\n");
		return 0;
	}
	for(int j=L.length;j>=i-1;j--)
	{
		L.elem[j+1].price=L.elem[j].price;
		strcpy(L.elem[j+1].name,L.elem[j].name);
		strcpy(L.elem[j+1].no,L.elem[j].no);
	}
	printf("��������Ҫ��ӵ�ͼ����Ϣ:\n");
	printf("���");
	scanf("%s",&a);
	strcpy(L.elem[i-1].no,a);
	printf("����:");
	scanf("%s",&b);
	strcpy(L.elem[i-1].name,b);
	printf("ͼ��۸�:");
	scanf("%s",&b);
	L.elem[i-1].price=s;
	L.length++;
	return 0;
}

//˳����ɾ��
int DeleteList(SqList &L)
{
	int i;
	printf("��������Ҫɾ����λ��:") ;
	scanf("%d",&i);
	if(i<1||i>L.length)
	{	
		printf("�����λ�ò��Ϸ�!");
		return 0;
	}
	for(int j=i-1;j<L.length;j++)
	{
		L.elem[j].price=L.elem[j+1].price;
		strcpy(L.elem[j].name,L.elem[j+1].name);
		strcpy(L.elem[j].no,L.elem[j+1].no);
	}
	L.length--;
	return 1;
}

//˳���洢��ͼ������
int NumberList(SqList L)
{	
	printf("����ͼ���������Ϊ:%d\n",L.length);
	return 0;
}
/************************************************


******************���߱�************************* 


************************************************/ 

//��ʼ�����߱�
int IntRD(RD &R)
{
	R.elem=new BO[3000];
	if(!R.elem)
	{	
		printf("���߱���ɹ���\n");
		exit(1); 
	}
	R.length=0;
	printf("���߱���ɹ���\n");
	return 1;
} 
/**/ 
//���߱��ȡֵ�����ߵǼ���Ϣ�� 
int GetRD(RD &R)
{	
	int x,i; 
	printf("�������뼸λ����:\n");
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{	
		printf("�������������\n");
		scanf("%s",R.elem[i].reader_name);
		printf("��������߿���\n");
		scanf("%s",R.elem[i].reader_num);
			++R.length; 
	}
	return 0;
 } 
//���Ҷ���
int LocalRD(RD &R){
	int i=1;
	int x;
	char a[20];
	char b[20];
	printf("1����������������:");
	printf("2�������߿��Ų���:");
	scanf("%d",&x);
	switch(x)
	{
	case 1:
		printf("��������Ҫ��ѯ�Ķ�������:\n") ;
		scanf("%s",&a);
		for(i;i<=R.length;i++)
		{
			if(!strcmp(R.elem[i].reader_name,a))
			{
				printf("��������\t\t���߿���\n");
				printf("%s\t\t%s\n",R.elem[i].reader_name,R.elem[i].reader_num);
			}else{
				printf("���߲����ڣ�\n");
			} 
			break;
		}
		break;
	case 2:
		printf("��������Ҫ��ѯ�Ķ��߿���:\n");
		scanf("%s",&b);
		for(i;i<=R.length;i++)
		{
			if(!strcmp(R.elem[i].reader_num,b))
			{
				printf("��������\t\t���߿���\n");
				printf("%s\t\t%s\n",R.elem[i].reader_name,R.elem[i].reader_num);
			}else{
				printf("���߲����ڣ�\n");
			}
			break;
		}
		break;
	default:
		printf("���������ѡ���д���!\n");
		break;
	}
	return 0;
} 
// ����ģ�� 
int Borrow_book(RD &R,SqList &L) 
{
	int i;
	char re_num[10]; 
	char bo_num[20]; 
	printf("��������Ľ��鿨��\n");
	scanf("%s",&re_num);
	for(i=1;i<=R.length;i++)
	{
		if(!strcmp(R.elem[i].reader_num,re_num))	//ѭ���ȽϿ��� 
		{
			printf("��������Ҫ��ѯ������:");
			scanf("%s",&bo_num);
			for(i=1;i<=L.length;i++)
			{
				if(!strcmp(L.elem[i].name,bo_num))
				{
					printf("���\t\t����\t\tͼ��۸�\n");
					scanf("%s\t\t%s\t\t%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
					printf("����ɹ���"); 
				}else{
					printf("�Բ���û���Ȿ�飡\n");
				}
				break;
			}	
		}else{
			printf("�Բ��𣬴˿��Ų����ڣ�\n");
		}
		break;
	}
	return 0;
}
// ����ģ�� 
int also_book(RD &R,SqList &L) 
{
	int i;
	char re_num[10]; 
	char bo_name[20]; 
	printf("��������Ľ��鿨��\n");
	scanf("%s",&re_num);
	for(i=1;i<=R.length;i++)
	{
		if(!strcmp(R.elem[i].reader_num,re_num))	//ѭ���ȽϿ��� 
		{
			printf("��������Ҫ��������:");
			scanf("%s",&bo_name);
			//L.elem[L.length+1].name=bo_name;
			printf("����ɹ���"); 
		}else{
			printf("�Բ��𣬴˿��Ų����ڣ�\n");
		}
		break;
	}
	return 0;
}

/******************************************


�ļ����� 


*******************************************/


//д��ͼ���ļ�
void writeBook(SqList &L) {
    if(L.length == 0) {
        printf("ͼ������Ϊ��!\n");
        return ;
    }
    FILE *fp = fopen("E://book.txt", "w");
    if(fp == NULL){
        printf("��ȡ�ļ�ʧ��");
        return ;
    }
    for(int i = 1;i <= L.length;i++) {
    	//printf("%s,%s,%d",L.elem[i].no,L.elem[i].name,L.elem[i].price);
        fprintf(fp,"%10s%10s%10d",L.elem[i].no,L.elem[i].name,L.elem[i].price);
    }
    fclose(fp); 
    printf("ͼ��д��ɹ�!\n");
}
//д������ļ�
void writeReader(RD &R) {
    if(R.length == 0) {
        printf("��������Ϊ��!\n");
        return;
    }
    FILE *fp = fopen("E:\\reader.txt", "w");
    if(fp == NULL){
        printf("��ȡ�ļ�ʧ��");
        return ;
    }
    for(int i = 1;i <=R.length;i++) {
        fprintf(fp, "%10s%10s",R.elem[i].reader_name,R.elem[i].reader_num);
    }
    fclose(fp);
    printf("������Ϣд��ɹ�!\n");
}
//��ȡͼ���ļ� 
void readBook(SqList &L) {
    FILE *fp = fopen("E://book.txt", "r");
    if(!fp){
        printf("��ȡ�ļ�ʧ��");
        return ;
    }
	int i= 1; 
    while (1) {
        fscanf(fp, "%10s%10s%10d",L.elem[i].no,L.elem[i].name,&L.elem[i].price);
        ++L.length;
        if(feof(fp)) break;
        i++; 
    }
    fclose(fp); 
    printf("ͼ����Ϣ��ȡ�ɹ�!\n");
}
//��ȡ�����ļ� 
void readReader(RD &R) {
    FILE *fp = fopen("E:\\reader.txt", "r");
    
    if(fp == NULL){
        printf("��ȡ�ļ�ʧ��");
        return ;
    }
    int i=1; 
    while (!feof(fp)) {
        fscanf(fp, "%10s%10s",&R.elem[i].reader_name,&R.elem[i].reader_num);
        ++R.length;
        if(feof(fp)) break;
        i++; 
    }
    fclose(fp);
    printf("������Ϣ��ȡ�ɹ�!\n");
}


