#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
/*����ṹ��*/
/*������Ϣ�ṹ��*/
typedef struct 
{
	int Num;			 //���
	char Name[20];		 //����
	char Sex[5];		 //�Ա�
	char DateB[10];	     //��������
	char Tel1[12]; 		 //�绰1
	char Tel2[12]; 		 //�绰2
	char Location[20];   //���ڵ�
	int GroupsId;		 //������
}elemtype;
typedef struct node
{
	elemtype data;
	struct node *next;
}linklist;
/*������Ϣ�ṹ��*/
typedef struct Groups
{
	int id;
	char name[20];
	int num;
	struct Groups *next;
}GNode,*GList;

void ShowAllP(linklist *l);
void ShowAllG(GList g);
int listmean(linklist *l,GList g);

/*��Ա�����ʼ��*/
linklist *Initlist(linklist *p)
{
	p=(linklist*)malloc(sizeof(linklist));
	p->data.Num=-1;
	p->next=NULL;
	return p;
}
/*���������ʼ��*/
GList InitGList(GList g)
{
	g=(GList)malloc(sizeof(GNode));
	g->id=-1;
	g->num=0;
	g->next=NULL;
	return g;
}
/*��ӷ�����Ϣ*/
GList GAdd(GList g)
{
	printf("\t\t************ ������ӷ���Ĳ��� ! ************\n");
	int n,i;
	GList p,q,r;
	p=g;
	printf("����Ҫ��ӷ���ĸ�����");
	scanf("%d",&n);
	while(p->next!=NULL)
		p=p->next;
	printf("��������ӵļ�¼\n");
	printf("%s\n","����");
	for(i=1;i<=n;i++)
	{
		q=(GList)malloc(sizeof(GNode));
		r=g;
		while(r->next)
			r=r->next;
		if(r->id==-1)
			q->id=1;
		else q->id=r->id+1;
		scanf("%s",&q->name);
		q->num=0;
		q->next=NULL;
		p->next=q;
		p=p->next;
	}
	printf("\n��Ӽ�¼�ɹ���\n");
	printf("��ע�Ᵽ�棡\n");
	getch();
	system("cls");
	return g;
}
/*�����Ա��Ϣ*/
linklist *PAdd(linklist *l,GList g)
{
	printf("\t\t************ ���������Ϣ�Ĳ��� ! ************\n");
	int n,i;
	linklist *p,*q,*r;
	GList s;
	s=g->next;
	p=l;
	printf("����Ҫ�����Ϣ��������");
	scanf("%d",&n);
	while(p->next!=NULL)
		p=p->next;
	printf("��������ӵļ�¼\n");
	printf("����:");
	while(s!=NULL)
	{
		printf("%d--%s  ",s->id,s->name);
		s=s->next;
	}
	printf("\n(ÿ�����Ϊ�գ����绰û������д0)\n���磺���� �� 0101 13131313131 15678456453 �人 1\n");
	printf("%s%10s%10s%10s%10s%10s%10s\n","����","�Ա�","����","�绰1","�绰2","���ڵ�","����");

	for(i=1;i<=n;i++)
	{
		q=(linklist*)malloc(sizeof(linklist));
		r=l;
		s=g->next;
		while(r->next)
			r=r->next;
		if(r->data.Num==-1)
			q->data.Num=1;
		else q->data.Num=r->data.Num+1;
		scanf("%s%5s%15s%15s%15s%8s%5d",&q->data.Name,&q->data.Sex,&q->data.DateB,&q->data.Tel1,&q->data.Tel2,&q->data.Location,&q->data.GroupsId);
		while(s!=NULL)
		{
			if(q->data.GroupsId==s->id)
				s->num++;
			s=s->next;
		}		
		q->next=NULL;
		p->next=q;
		p=p->next;
	}
	printf("\n��Ӽ�¼�ɹ���\n");
	printf("��ע�Ᵽ�棡\n");
	getch();
	system("cls");
	return l;
}
/*ɾ����Ա��Ϣ*/
int PDelete(linklist *l,GList g)
{
	int a;
	char c;
	ShowAllP(l);
	linklist *p,*q;
	q=l;
	p=l->next;
	printf("������Ҫɾ������Ϣ��ţ�");
	scanf("%d",&a);
	printf("ȷ��Ҫɾ�����Ϊ%d����Ϣ?(Y/N):",a);
	c=getch();
	if(c=='Y'||c=='y')
	{
		while(p!=NULL)
		{
			GList s;
			s=g->next;
			if(p->data.Num==a)
			{
				while(s!=NULL)
				{
					if(q->data.GroupsId==s->id)
						s->num--;
					s=s->next;
				}		
				q->next=p->next;
				p->next=NULL;
				printf("\n\t\t*********** ɾ���ɹ�!�Ƿ����ɾ��?(Y/N)!***********\n");
				c=getch();
				system("cls");
				if(c=='Y'||c=='y')
					PDelete(l,g);
				return 1;
			}
			p=p->next;
			q=q->next;
		}
		printf("\nû�д���Ϣ!ɾ��ʧ��!���������!\n");
		getch();
		system("cls");
		return 0;		
	}
	else 
	{
		system("cls");
		PDelete(l,g);
	}	
	return 1;
}
/*ɾ��������Ϣ*/
int GDelete(linklist *l,GList g)
{
	int a;
	char c;
	ShowAllG(g);
	GList p,q;
	linklist *s;
	s=l->next;
	q=g;
	p=g->next;
	printf("������Ҫɾ���ķ����ţ�");
	scanf("%d",&a);
	printf("ȷ��Ҫɾ�����Ϊ%d�ķ���?(Y/N):",a);
	c=getch();
	if(c=='Y'||c=='y')
	{
		while(p!=NULL)
		{
			while(s!=NULL)
			{
				if(s->data.GroupsId==a)
				{
					s->data.GroupsId=0;
					g->next->num++;
				}
				s=s->next;
			}		
			if(p->id==a)
			{	
				
				q->next=p->next;
				p->next=NULL;
				printf("\n\t\t*********** ɾ���ɹ�!�Ƿ����ɾ��?(Y/N)!***********\n");
				c=getch();
				system("cls");
				if(c=='Y'||c=='y')
					GDelete(l,g);
				return 1;
			}
			p=p->next;
			q=q->next;
		}
		printf("\nû�д���Ϣ!ɾ��ʧ��!���������!\n");
		getch();
		system("cls");
		return 0;		
	}
	else
	{
		system("cls");
		GDelete(l,g);
	}
	return 1;
}
/*��Ա��Ϣ����*/
linklist* FLoad(linklist *l)//���ݼ���
{
	FILE *fp;
	linklist *p,*q,*t;
	p=Initlist(p);
	l=Initlist(l);
	t=l;
	fp=fopen("info.txt","a");
	if((fp=fopen("info.txt","r"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ� 
	{
		printf("\t\t*********** �ļ�info.txt��ʧ�� ! ***********\n"); 
		return 0;
	}
	fseek(fp,77L,0);
	while(fscanf(fp,"%4d%10s%5s%15s%15s%15s%8s%5d\n",&p->data.Num,&p->data.Name,&p->data.Sex,&p->data.DateB,&p->data.Tel1,&p->data.Tel2,&p->data.Location,&p->data.GroupsId)!=EOF)
	{
		q=(linklist *)malloc(sizeof(linklist));
		q->next=NULL;
		q->data=p->data;
		t->next=q;
		t=t->next;
	}
	fclose(fp);
	return l;
}
/*������Ϣ����*/
GList GLoad(GList g)
{
	char *a[]={"δ����","����","����","ͬѧ","ͬ��","��ʦ"};
	FILE *fp;
	GList p,q,t;
	p=InitGList(p);
	g=InitGList(g);
	t=g;
	if((fp=fopen("groups.txt","r"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ� 
	{
		GList x,y;
		y=g;
		fp=fopen("groups.txt","a");
		fprintf(fp,"%4s%10s%10s\n","���","����","����");
		for(int i=0;i<6;i++)
		{
			fprintf(fp,"%4d%10s%10d\n",i,a[i],0);
			x=(GList)malloc(sizeof(GNode));
			x->next=NULL;
			x->id=i;
			strcpy(x->name,a[i]);
			x->num=0;
			y->next=x;
			y=y->next;
		} 
		fclose(fp);
	}
	fseek(fp,24L,0);
	while(fscanf(fp,"%4d%10s%10d\n",&p->id,&p->name,&p->num)!=EOF)
	{
		q=(GList)malloc(sizeof(GNode));
		q->next=NULL;
		q->id=p->id;
		strcpy(q->name,p->name);
		q->num=p->num;
		t->next=q;
		t=t->next;
	}
	fclose(fp);
	return g;
}
/*��Ϣ��ȡ*/
int FRead(linklist *l,GList g)
{
	printf("\t\t**********���ڶ�ȡ�ļ���Ϣ,���Ժ�! ************\n");
	char a;
	FILE *fp,*gfp;
	/*��Ա��Ϣ��ȡ*/
	FLoad(l);
	if((fp=fopen("info.txt","r"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ� 
	{
	printf("\t\t*********** �ļ�info.txt��ʧ�� ! ************\n"); 
		return 0;
	}
	printf("\t\t************* info.txt���ݶ���ɹ� !***********\n"); 
	while(!feof(fp))
	{
		a=fgetc(fp);
		printf("%c",a);
	}
	fclose(fp);
	/*������Ϣ��ȡ*/
	GLoad(g);
	if((gfp=fopen("groups.txt","r"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ� 
	{
	printf("\t\t*********** �ļ�groups.txt��ʧ�� ! **********\n"); 
		return 0;
	}
	printf("\t\t*********** groups.txt���ݶ���ɹ� !***********\n"); 
	while(!feof(gfp))
	{
		a=fgetc(gfp);
		printf("%c",a);
	}
	fclose(gfp);

	printf("\t\t************* ������������˵� !***************\n");
	getch();
	system("cls");
	return 1;
}
/*��Ϣд��*/
void FWrite(linklist *l,GList g)
{
	int y;
	FILE *fp,*gfp;
	printf("\t\t**********���ڱ����ļ���Ϣ,���Ժ�! ************\n");
	/*��Ա��Ϣд��*/
	y=remove("info.txt");
	if((fp=fopen("info.txt","w+"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ� 
	{
		printf("\t\t*********** �ļ�info.txt����ʧ�� ! ************\n"); 
	}
	linklist *p;
	p=l->next;
	if(p==NULL)
	{
		printf("\t\t*********** û������, ��������Ϣ ! ************\n");
	}
	else
	{
		fseek(fp,0L,0);
		fprintf(fp,"%4s%10s%5s%15s%15s%15s%8s%5s\n","���","����","�Ա�","����","�绰1","�绰2","���ڵ�","����");	
		while(p!=NULL)
		{
			fprintf(fp,"%4d%10s%5s%15s%15s%15s%8s%5d\n",p->data.Num,p->data.Name,p->data.Sex,p->data.DateB,p->data.Tel1,p->data.Tel2,p->data.Location,p->data.GroupsId);
			p=p->next;
		}
		printf("\t\t*********** �ļ�info.txt����ɹ� ! ************\n");
	}
	fclose(fp);
	/*������Ϣд��*/
	y=remove("groups.txt");
	if((gfp=fopen("groups.txt","w+"))==NULL)//�ж��ļ��Ƿ�򿪳ɹ� 
	{
		printf("\t\t*********** �ļ�groups.txt����ʧ�� ! **********\n"); 
	}
	GList q;
	q=g->next;
	if(q==NULL)
	{
		fprintf(gfp,"%4s%10s%10s\n","���","����","����");
		printf("\t\t*********** �ļ�gropus.txt����ɹ� ! **********\n");
	}
	else
	{
		fseek(gfp,0L,0);
		fprintf(gfp,"%4s%10s%10s\n","���","����","����");	
		while(q!=NULL)
		{
			fprintf(gfp,"%4d%10s%10d\n",q->id,q->name,q->num);
			q=q->next;
		}
		printf("\t\t*********** �ļ�gropus.txt����ɹ� ! **********\n");
	}
	fclose(gfp);

	printf("\t\t************** �����������һ�� !**************\n");
	getch();
	system("cls");
}
/*��ʾ������Ա*/
void ShowAllP(linklist *l)
{
	linklist *p;
	p=l->next;
	if(p==NULL)
		printf("\t\t*********** û������, ��������Ϣ ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","���","����","�Ա�","����","�绰1","�绰2","���ڵ�","����");
		while(p!=NULL)
		{
			printf("%4d%10s%5s%15s%15s%15s%8s%5d\n",p->data.Num,p->data.Name,p->data.Sex,p->data.DateB,p->data.Tel1,p->data.Tel2,p->data.Location,p->data.GroupsId);
			p=p->next;
		}
	}
}
/*��ʾ���з���*/
void ShowAllG(GList g)
{
	GList p;
	p=g->next;
	if(p==NULL)
		printf("\t\t*********** û������, ��������Ϣ ! ***********\n");
	else
	{
		printf("\t\t\t%6s%10s%10s\n","���","����","����");
		while(p!=NULL)
		{
			printf("\t\t\t%6d%10s%10d\n",p->id,p->name,p->num);
			p=p->next;
		}
	}	
}
/*��ѯ���з���*/
void Select_all(GList g)
{
	printf("\t\t*****************�����ѯ*********************\n");
	ShowAllG(g);
	printf("\t\t************** �����������һ�� !*************\n");
	getch();
	system("cls");
}
/*��ѯ������Ա*/
void Select_all(linklist *l)
{
	printf("\t\t*****************��Ա��ѯ*********************\n");
	ShowAllP(l);
	printf("\t\t************** �����������һ�� !*************\n");
	getch();
	system("cls");
}
/*������������Ա*/
int SelectByName(linklist *l,GList g)
{
	int flag=0;
	char a[20],c;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	p=l->next;
	printf("\t\t*****************��Ա��ѯ*********************\n");
	printf("��������Ҫ������Ա������:");
	scanf("%s",a);
	if(p==NULL)
		printf("\t\t*********** û������, ��������Ϣ ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","���","����","�Ա�","����","�绰1","�绰2","���ڵ�","����");
		while(p!=NULL)
		{
			if(strcmp(a,p->data.Name)==0)
			{
				t=(linklist*)malloc(sizeof(linklist));
				t->data=p->data;
				t->next=NULL;
				q->next=t;
				q=q->next;
				printf("%4d%10s%5s%15s%15s%15s%8s%5d\n",p->data.Num,p->data.Name,p->data.Sex,p->data.DateB,p->data.Tel1,p->data.Tel2,p->data.Location,p->data.GroupsId);
				flag=1;
			}
			p=p->next;
		}
		if(!flag)
			printf("û������Ϊ%s������!\n",a);
		printf("�Ƿ����ɸѡ?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}
	}
	printf("\t\t************** �����������һ�� !*************\n");
	getch();
	system("cls");
}
/*���Ա������Ա*/
int SelectBySex(linklist *l,GList g)
{
	int flag=0;
	char a[5],c;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	p=l->next;
	printf("\t\t*****************��Ա��ѯ*********************\n");
	printf("��������Ҫ������Ա���Ա���/Ů��:");
	scanf("%s",a);
	if(p==NULL)
		printf("\t\t*********** û������, ��������Ϣ ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","���","����","�Ա�","����","�绰1","�绰2","���ڵ�","����");
		while(p!=NULL)
		{
			if(strcmp(a,p->data.Sex)==0)
			{
				t=(linklist*)malloc(sizeof(linklist));
				t->data=p->data;
				t->next=NULL;
				q->next=t;
				q=q->next;
				printf("%4d%10s%5s%15s%15s%15s%8s%5d\n",p->data.Num,p->data.Name,p->data.Sex,p->data.DateB,p->data.Tel1,p->data.Tel2,p->data.Location,p->data.GroupsId);
				flag=1;
			}
			p=p->next;
		}
		if(!flag)
			printf("û���Ա�Ϊ%s������!\n",a);
		printf("�Ƿ����ɸѡ?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}
	}
	printf("\t\t************** �����������һ�� !*************\n");
	getch();
	system("cls");
}
/*���绰������Ա*/
int SelectByTel(linklist *l,GList g)
{
	int flag=0;
	char a[12],c;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	p=l->next;
	printf("\t\t*****************��Ա��ѯ*********************\n");
	printf("��������Ҫ������Ա�ĵ绰����:");
	scanf("%s",a);
	if(p==NULL)
		printf("\t\t*********** û������, ��������Ϣ ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","���","����","�Ա�","����","�绰1","�绰2","���ڵ�","����");
		while(p!=NULL)
		{
			if(strcmp(a,p->data.Tel1)==0||strcmp(a,p->data.Tel2)==0)
			{
				t=(linklist*)malloc(sizeof(linklist));
				t->data=p->data;
				t->next=NULL;
				q->next=t;
				q=q->next;
				printf("%4d%10s%5s%15s%15s%15s%8s%5d\n",p->data.Num,p->data.Name,p->data.Sex,p->data.DateB,p->data.Tel1,p->data.Tel2,p->data.Location,p->data.GroupsId);
				flag=1;
			}
			p=p->next;
		}
		if(!flag)
			printf("û�е绰����Ϊ%s������!\n",a);
		printf("�Ƿ����ɸѡ?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}
	}
	printf("\t\t************** �����������һ�� !*************\n");
	getch();
	system("cls");
}
/*������������Ա*/
int SelectByLoc(linklist *l,GList g)
{
	int flag=0;
	char a[20],c;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	printf("\t\t*****************��Ա��ѯ*********************\n");
	printf("��������Ҫ������Ա�ĵ���:");
	scanf("%s",a);
	if(p==NULL)
		printf("\t\t*********** û������, ��������Ϣ ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","���","����","�Ա�","����","�绰1","�绰2","���ڵ�","����");
		while(p!=NULL)
		{
			if(strcmp(a,p->data.Location)==0)
			{
				t=(linklist*)malloc(sizeof(linklist));
				t->data=p->data;
				t->next=NULL;
				q->next=t;
				q=q->next;
				printf("%4d%10s%5s%15s%15s%15s%8s%5d\n",p->data.Num,p->data.Name,p->data.Sex,p->data.DateB,p->data.Tel1,p->data.Tel2,p->data.Location,p->data.GroupsId);
				flag=1;
			}
			p=p->next;
		}
		if(!flag)
			printf("û�е���Ϊ%s������!\n",a);
		printf("�Ƿ����ɸѡ?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}
	}
	printf("\t\t************** �����������һ�� !*************\n");
	getch();
	system("cls");
}
/*�����������Ա*/
int SelectByGroup(linklist *l,GList g)
{
	char c;
	int flag=0,a;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	p=l->next;
	printf("\t\t*****************��Ա��ѯ*********************\n");
	ShowAllG(g);
	printf("��������Ҫ������Ա���ڵķ�����:");
	scanf("%d",&a);
	if(p==NULL)
		printf("\t\t*********** û������, ��������Ϣ ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","���","����","�Ա�","����","�绰1","�绰2","���ڵ�","����");
		while(p!=NULL)
		{
			if(a==p->data.GroupsId)
			{
				t=(linklist*)malloc(sizeof(linklist));
				t->data=p->data;
				t->next=NULL;
				q->next=t;
				q=q->next;
				printf("%4d%10s%5s%15s%15s%15s%8s%5d\n",p->data.Num,p->data.Name,p->data.Sex,p->data.DateB,p->data.Tel1,p->data.Tel2,p->data.Location,p->data.GroupsId);
				flag=1;
			}
			p=p->next;
		}
		if(!flag)
			printf("û�з���Ϊ%d������!\n",a);
		printf("�Ƿ����ɸѡ?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}	
	}
	printf("\t\t************** �����������һ�� !*************\n");
	getch();
	system("cls");
}
/*��Ա��ѯ�˵�*/
int listmean(linklist *l,GList g)
{
	int control;
	while(l)
	{
		printf("\t\t*******************��Ա��ѯ*******************\n");
		printf("\t\t*                1--�� ѯ �� ��              *\n");
		printf("\t\t*                2--�� �� �� �� ��           *\n");
		printf("\t\t*                3--�� �� �� �� ��           *\n");
		printf("\t\t*                4--�� �� �� �� ��           *\n");
		printf("\t\t*                5--�� �� �� �� ��           *\n");
		printf("\t\t*                6--�� �� �� �� ��           *\n");
		printf("\t\t*                0--�� �� �� ѯ              *\n");
		printf("\t\t**********************************************\n");
		printf("\t\t\t��������Ӧ����������(0~6): ");
		scanf("%d",&control);
		system("cls");
		switch(control)
		{
			case 1:Select_all(l);break;		//��ѯ���� 
			case 2:SelectByName(l,g);break;  	//����������
			case 3:SelectBySex(l,g);break;	//���Ա����
			case 4:SelectByTel(l,g);break;	//���绰����
			case 5:SelectByLoc(l,g);break;	//����������
			case 6:SelectByGroup(l,g);break;//���������
			case 0:return 0;break;			//�˳���ѯ
			default: printf("\t\t************����������������������**********\n");break; 
		} 
	}
	return 1;
}
/*��Ա��Ϣ�޸�*/
int Modify(linklist *l,GList g)
{
	int a,b,x;
	char c[20],f;
	linklist *p;
	printf("\t\t*****************�޸���Ա*********************\n");
	ShowAllP(l);
	do{
		p=l->next;
		if(p==NULL)
		{
			printf("\t\t*********** û������, ��������Ϣ ! ***********\n");
			getch();
			system("cls");
			return 1;
		}
		else
		{
			printf("������Ҫ�޸���Ϣ��Ա�ı��:");
			scanf("%d",&a);
			while(p!=NULL)
			{
				if(a==p->data.Num)
					break;
				p=p->next;
			}
		}
		if(p==NULL)
		{
			printf("û�д˱�ŵ���Ա������������!\n");
		}
	}while(p==NULL);
	do{
		printf("������Ҫ�޸ĵ���Ϣ���(1-���� 2-�Ա� 3--���� 4-�绰1 5-�绰2 6-����  7-����): ");
		scanf("%d",&b);
		switch(b)
		{
		case 1:
			printf("��������Ҫ�޸ĺ��������");
			scanf("%s",c);
			strcpy(p->data.Name,c);
			printf("\t\t****************** �޸ĳɹ� !*****************\n");
			break;
		case 2:
			printf("��������Ҫ�޸ĺ���Ա�");
			scanf("%s",c);
			strcpy(p->data.Sex,c);
			printf("\t\t****************** �޸ĳɹ� !*****************\n");
			break;
		case 3:
			printf("��������Ҫ�޸ĺ�����գ�");
			scanf("%s",c);
			strcpy(p->data.DateB,c);
			printf("\t\t****************** �޸ĳɹ� !*****************\n");
			break;
		case 4:
			printf("��������Ҫ�޸ĺ�ĵ绰1��");
			scanf("%s",c);
			strcpy(p->data.Tel1,c);	
			printf("\t\t****************** �޸ĳɹ� !*****************\n");
			break;
		case 5:
			printf("��������Ҫ�޸ĺ�ĵ绰2��");
			scanf("%s",c);
			strcpy(p->data.Tel2,c);	
			printf("\t\t****************** �޸ĳɹ� !*****************\n");
			break;
		case 6:
			printf("��������Ҫ�޸ĺ�ĵ�����");
			scanf("%s",c);
			strcpy(p->data.Location,c);	
			printf("\t\t****************** �޸ĳɹ� !*****************\n");
			break;
		case 7:
			ShowAllG(g);	
			printf("��������Ҫ�޸ĺ�ķ��飺");
			scanf("%d",&x);
			GList s;
			s=g->next;
			while(s!=NULL)
			{
				if(p->data.GroupsId==s->id)
					s->num--;
				else if(x==s->id)
					s->num++;
				s=s->next;
			}
			p->data.GroupsId=x;	
			printf("\t\t****************** �޸ĳɹ� !*****************\n");
			break;	
		default:
			printf("\t\t****************** �������� !*****************\n");
			break;
		}	
		printf("�Ƿ�����޸ģ�(Y/N):\n");
		f=getch();
	}while(f=='y'||f=='Y');
	printf("\t\t************** �����������һ�� !*************\n");
	getch();
	system("cls");
}
/*������Ϣ�޸�*/
void Modify(GList g)
{
	int a;
	char c[20];
	GList p;
	printf("\t\t*****************�޸ķ���*********************\n");
	ShowAllG(g);
	do{
		p=g->next;
		printf("������Ҫ�޸ķ���ı��:");
		scanf("%d",&a);
		if(p==NULL)
		{
			printf("\t\t*********** û������, ��������Ϣ ! ***********\n");
			exit(-1);
		}
		else
			while(p!=NULL)
			{
				if(a==p->id)
					break;
				p=p->next;
			}
		if(p==NULL)
		{
			printf("û�д˱�ŵķ��飬����������!\n");
		}
	}while(p==NULL);
	printf("��������Ҫ�޸ĺ�ķ������� ");
	scanf("%s",c);
	strcpy(p->name,c);
	printf("\t\t****************** �޸ĳɹ� !*****************\n");
	printf("\t\t************** �����������һ�� !*************\n");
	getch();
	system("cls");
}
void Exit(linklist *l,GList g)
{
	char c;
	printf("�����˳����Ƿ�ȷ����Ϣ�ѱ��棿(Y/N):");
	c=getch();
	if(c=='y'||c=='Y')
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t**********************************************\n");
		printf("\t\t*--------------------------------------------*\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*         ��лʹ��ͨѶ¼����ϵͳV1.1!        *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                ���������..                *\n");
		printf("\t\t*                           Power by WanGzhE *\n");
		printf("\t\t**********************************************\n");
	}
	else
	{
		system("cls");
		printf("�Ƿ񱣴���Ϣ��(Y/N)");
		c=getch();
		system("cls");
		if(c=='y'||c=='Y')
			FWrite(l,g);
		printf("\n\n\n\n");
		printf("\t\t**********************************************\n");
		printf("\t\t*--------------------------------------------*\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*         ��лʹ��ͨѶ¼����ϵͳV1.1!        *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                ���������..                *\n");
		printf("\t\t*                           Power by WanGzhE *\n");
		printf("\t\t**********************************************\n");
	}
	getch();
}
/*���˵�*/
int mean()
{
	linklist *l;
	GList g;
	l=FLoad(l);
	g=GLoad(g);
	while(l)
	{
		int control;
		printf("\t\t**********************************************\n");
		printf("\t\t*                1--�� ȡ �� Ϣ              *\n");
		printf("\t\t*                2--�� �� �� Ϣ              *\n");
		printf("\t\t*                3--�� �� �� Ա              *\n");
		printf("\t\t*                4--�� �� �� ��              *\n");
		printf("\t\t*                5--ɾ �� �� Ա              *\n");
		printf("\t\t*                6--ɾ �� �� ��              *\n");
		printf("\t\t*                7--�� ѯ �� Ա              *\n");
		printf("\t\t*                8--�� ѯ �� ��              *\n");
		printf("\t\t*                9--�� �� �� Ա              *\n");
		printf("\t\t*               10--�� �� �� ��              *\n");
		printf("\t\t*                0--�� �� ϵ ͳ              *\n");
		printf("\t\t**********************************************\n");	
		printf("\t\t\t��������Ӧ����������(0~10): ");
		scanf("%d",&control);
		system("cls");
		switch(control)
		{
			case 1:FRead(l,g);break;		//��ȡ��Ϣ
			case 2:FWrite(l,g);break;		//������Ϣ
			case 3:PAdd(l,g);break;			//�����Ա
			case 4:GAdd(g);break;			//��ӷ���
			case 5:PDelete(l,g);break;		//ɾ����Ա
			case 6:GDelete(l,g);break;		//ɾ������
			case 7:listmean(l,g);break;		//��ѯ��Ա
			case 8:Select_all(g);break;		//��ѯ����
			case 9:Modify(l,g);break;		//������Ա
			case 10:Modify(g);break;		//���ķ���
			case 0:Exit(l,g);return 1;break;//�˳�ϵͳ
			default: printf("\t\t************����������������������**********\n");break; 
		} 
	}
	return 1;
 } 
/*��ӭ����*/
int main() //������
{
	printf("\n\n\n\n");
	printf("\t\t**********************************************\n");
	printf("\t\t*--------------------------------------------*\n");
	printf("\t\t*                                            *\n");
	printf("\t\t*                                            *\n");
	printf("\t\t*         ��ӭʹ��ͨѶ¼����ϵͳV1.1!        *\n");
	printf("\t\t*                                            *\n");
	printf("\t\t*                                            *\n");
	printf("\t\t*                ���������..                *\n");
	printf("\t\t*                           Power by WanGzhE *\n");
	printf("\t\t**********************************************\n");
	getch();
	system("cls");
	mean();
	return 0;
}
/*
��Ա��Ϣ��������

����01 �� 0101 15671654043 13131311235 �人 1
����02 Ů 0101 15671654043 13131311235 ʮ�� 2
����03 �� 0101 15671654043 13131311235 ���� 3
����04 �� 0101 15671654043 13131311235 ���� 4
����05 �� 0101 15671654043 13131311235 ���� 5
����06 Ů 0101 15671654043 13131311235 ���� 0
����07 �� 0101 15671654043 13131311235 ʮ�� 0
����08 �� 0101 15671654043 13131311235 �人 0
*/