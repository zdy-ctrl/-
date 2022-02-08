#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define leafnum 27
#define hufnum 2*leafnum 
#define maxdouble 9999.9

//���������ڵ�洢�ṹ
typedef struct tnode  
{
	char name;
	double weight;
	int lchild,rchild,parent;
}huftree;

//�����������ṹ
typedef struct cnode      
{
	char bits[leafnum+1];
	int start;
	char ch;
}hufcode;

hufcode code[leafnum+1];
huftree tree[hufnum+1];
char huffmancode[1000];
//����ȫ�������������Щ�ַ����ƺͶ�ӦƵ��
char ch[] = {'\0',' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
float w[] = {0,186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};

//������������
void creattreehuffman(huftree tree[]) 
{
	int i, j, p1, p2;
	double least1, least2;
	for (i=1; i<=hufnum; i++)
	{
		tree[i].name = '\0';
		tree[i].parent = 0;
		tree[i].lchild = 0;
		tree[i].rchild = 0;
		tree[i].weight = 0.0;
	}
	for (i=1; i<=leafnum; i++)
	{
		tree[i].name = ch[i];
		tree[i].weight = w[i];
	}
	for (i=leafnum+1; i<=hufnum; i++)
	{
		p1=0; p2=0; least1=least2=maxdouble;
		for (j=1; j<i; j++)
			if (tree[j].parent==0)
				if (tree[j].weight<least1)
				{
					least2=least1;
					least1=tree[j].weight;
					p2=p1;
					p1=j;
				}
				else
				{
					if(tree[j].weight<least2)
					{
						least2=tree[j].weight;
						p2=j;
					}
				}
		tree[p1].parent=i;
		tree[p2].parent=i;
		tree[i].lchild=p1;
		tree[i].rchild=p2;
		tree[i].weight=tree[p1].weight+tree[p2].weight;
	}
	tree[hufnum-1].parent=0;
}
// ��������������
void creatcodehuffman(hufcode code[], huftree tree[])   
{
	int i, c, p;
	hufcode buf;
	for (i=1; i<=leafnum; i++)
	{
		buf.ch=ch[i];
		buf.start=leafnum;
		c=i;
		p=tree[i].parent;
		while (p != 0)
		{
			buf.start--;
			if (tree[p].lchild==c)
				buf.bits[buf.start]='0';
			else buf.bits[buf.start]='1';
			c=p;
			p=tree[p].parent;
		}
		code[i]=buf;
	}
}
//����������
void writecodehuffman(hufcode code[], huftree tree[])
{
	int i, j, k, n=0;
	char c[100];
	printf("�������ַ���:\n");
	gets(c);
	printf("\n");
	printf("���ַ����Ĺ���������Ϊ:\n");
	for(i=0;i<strlen(c);i++)
	{
		for (j=1; j<=leafnum; j++)
			if (c[i]==tree[j].name)
				for(k=code[j].start; k<leafnum; k++)
					{
						printf("%c", code[j].bits[k]);
						huffmancode[n] = code[j].bits[k];
						n++;
					}
	}
} 
//����������
void transcodehuffman(hufcode code[], huftree tree[], char s[]) 
{
	int i;
	char *q=NULL;
	i=hufnum-1; q=s;
	while (*q!='\0')
	{
		if (*q=='0') i=tree[i].lchild;
		if (*q=='1') i=tree[i].rchild;
		if ((tree[i].lchild==0)&&(tree[i].rchild==0))
		{
			printf("%c",code[i].ch);
			i = hufnum - 1;
		}
		q++;
	}
	printf("\n");
}
//�����������
void printtreehuffman(huftree tree[])    
{
	int i;
	printf("�����ַ���ʹ�ø����������Ĺ�������Ϊ:\n");
	printf( "�ַ����   �ַ�����      �ַ�Ƶ��    ˫��λ��    ����  �Һ���\n");
	for (i = 1; i < hufnum; i++)
	{
		printf("\t %d \t %c \t ",i,tree[i].name);
		printf(" %f \t %d \t %d \t %d \n", tree[i].weight,tree[i].parent,tree[i].lchild,tree[i].rchild) ;	
	}
}
//���ÿ���ַ��Ĺ���������
void printcodehuffman(hufcode code[])                
{
	int i, j;
	printf( "���ݹ����������ַ��������Ĺ���������Ϊ:\n");
	printf( "�ַ����   �ַ�����   �ַ����� \n");
	for (i =1; i <= leafnum; i++)
	{
		printf("\t %d \t %c ",i,code[i].ch);
		for(j=code[i].start;j <leafnum;j++)
			printf("%c",code[i].bits[j]);
		printf("\t \t \n");
	}
}
//������
main( )
{
	FILE *fp;
	int i;
	char buffer[1000];
	creattreehuffman(tree);
	printtreehuffman(tree);
	creatcodehuffman(code, tree);
	printcodehuffman(code);
	writecodehuffman(code, tree);
	if((fp=fopen("e:\\codefile.txt","w"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(0);
	}
	fprintf(fp,"����������Ϊ: %s",huffmancode);

	for(i=0;i<strlen(huffmancode);i++)
	{
		buffer[i] = huffmancode[i];
	}
	printf("\n");
	printf( "codefile�ļ��еĴ�������:\n" );
	printf( "����������Ϊ: %s \n\n",huffmancode );
	printf( "codefile�ļ��д�������Ϊ:" );
	transcodehuffman(code, tree, buffer);

}
