#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
/*定义结构体*/
/*个人信息结构体*/
typedef struct 
{
	int Num;			 //编号
	char Name[20];		 //名字
	char Sex[5];		 //性别
	char DateB[10];	     //出生日期
	char Tel1[12]; 		 //电话1
	char Tel2[12]; 		 //电话2
	char Location[20];   //所在地
	int GroupsId;		 //分组编号
}elemtype;
typedef struct node
{
	elemtype data;
	struct node *next;
}linklist;
/*分组信息结构体*/
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

/*人员链表初始化*/
linklist *Initlist(linklist *p)
{
	p=(linklist*)malloc(sizeof(linklist));
	p->data.Num=-1;
	p->next=NULL;
	return p;
}
/*分组链表初始化*/
GList InitGList(GList g)
{
	g=(GList)malloc(sizeof(GNode));
	g->id=-1;
	g->num=0;
	g->next=NULL;
	return g;
}
/*添加分组信息*/
GList GAdd(GList g)
{
	printf("\t\t************ 进行添加分组的操作 ! ************\n");
	int n,i;
	GList p,q,r;
	p=g;
	printf("输入要添加分组的个数：");
	scanf("%d",&n);
	while(p->next!=NULL)
		p=p->next;
	printf("请输入添加的记录\n");
	printf("%s\n","组名");
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
	printf("\n添加记录成功！\n");
	printf("请注意保存！\n");
	getch();
	system("cls");
	return g;
}
/*添加人员信息*/
linklist *PAdd(linklist *l,GList g)
{
	printf("\t\t************ 进行添加信息的操作 ! ************\n");
	int n,i;
	linklist *p,*q,*r;
	GList s;
	s=g->next;
	p=l;
	printf("输入要添加信息的条数：");
	scanf("%d",&n);
	while(p->next!=NULL)
		p=p->next;
	printf("请输入添加的记录\n");
	printf("分组:");
	while(s!=NULL)
	{
		printf("%d--%s  ",s->id,s->name);
		s=s->next;
	}
	printf("\n(每项都不能为空，若电话没有则填写0)\n例如：张三 男 0101 13131313131 15678456453 武汉 1\n");
	printf("%s%10s%10s%10s%10s%10s%10s\n","姓名","性别","生日","电话1","电话2","所在地","分组");

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
	printf("\n添加记录成功！\n");
	printf("请注意保存！\n");
	getch();
	system("cls");
	return l;
}
/*删除人员信息*/
int PDelete(linklist *l,GList g)
{
	int a;
	char c;
	ShowAllP(l);
	linklist *p,*q;
	q=l;
	p=l->next;
	printf("请输入要删除的信息编号：");
	scanf("%d",&a);
	printf("确定要删除编号为%d的信息?(Y/N):",a);
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
				printf("\n\t\t*********** 删除成功!是否继续删除?(Y/N)!***********\n");
				c=getch();
				system("cls");
				if(c=='Y'||c=='y')
					PDelete(l,g);
				return 1;
			}
			p=p->next;
			q=q->next;
		}
		printf("\n没有此信息!删除失败!任意键返回!\n");
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
/*删除分组信息*/
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
	printf("请输入要删除的分组编号：");
	scanf("%d",&a);
	printf("确定要删除编号为%d的分组?(Y/N):",a);
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
				printf("\n\t\t*********** 删除成功!是否继续删除?(Y/N)!***********\n");
				c=getch();
				system("cls");
				if(c=='Y'||c=='y')
					GDelete(l,g);
				return 1;
			}
			p=p->next;
			q=q->next;
		}
		printf("\n没有此信息!删除失败!任意键返回!\n");
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
/*人员信息加载*/
linklist* FLoad(linklist *l)//数据加载
{
	FILE *fp;
	linklist *p,*q,*t;
	p=Initlist(p);
	l=Initlist(l);
	t=l;
	fp=fopen("info.txt","a");
	if((fp=fopen("info.txt","r"))==NULL)//判断文件是否打开成功 
	{
		printf("\t\t*********** 文件info.txt打开失败 ! ***********\n"); 
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
/*分组信息加载*/
GList GLoad(GList g)
{
	char *a[]={"未分组","家人","朋友","同学","同事","老师"};
	FILE *fp;
	GList p,q,t;
	p=InitGList(p);
	g=InitGList(g);
	t=g;
	if((fp=fopen("groups.txt","r"))==NULL)//判断文件是否打开成功 
	{
		GList x,y;
		y=g;
		fp=fopen("groups.txt","a");
		fprintf(fp,"%4s%10s%10s\n","编号","组名","人数");
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
/*信息读取*/
int FRead(linklist *l,GList g)
{
	printf("\t\t**********正在读取文件信息,请稍后! ************\n");
	char a;
	FILE *fp,*gfp;
	/*人员信息读取*/
	FLoad(l);
	if((fp=fopen("info.txt","r"))==NULL)//判断文件是否打开成功 
	{
	printf("\t\t*********** 文件info.txt打开失败 ! ************\n"); 
		return 0;
	}
	printf("\t\t************* info.txt数据读入成功 !***********\n"); 
	while(!feof(fp))
	{
		a=fgetc(fp);
		printf("%c",a);
	}
	fclose(fp);
	/*分组信息读取*/
	GLoad(g);
	if((gfp=fopen("groups.txt","r"))==NULL)//判断文件是否打开成功 
	{
	printf("\t\t*********** 文件groups.txt打开失败 ! **********\n"); 
		return 0;
	}
	printf("\t\t*********** groups.txt数据读入成功 !***********\n"); 
	while(!feof(gfp))
	{
		a=fgetc(gfp);
		printf("%c",a);
	}
	fclose(gfp);

	printf("\t\t************* 任意键返回主菜单 !***************\n");
	getch();
	system("cls");
	return 1;
}
/*信息写入*/
void FWrite(linklist *l,GList g)
{
	int y;
	FILE *fp,*gfp;
	printf("\t\t**********正在保存文件信息,请稍后! ************\n");
	/*人员信息写入*/
	y=remove("info.txt");
	if((fp=fopen("info.txt","w+"))==NULL)//判断文件是否打开成功 
	{
		printf("\t\t*********** 文件info.txt保存失败 ! ************\n"); 
	}
	linklist *p;
	p=l->next;
	if(p==NULL)
	{
		printf("\t\t*********** 没有数据, 请输入信息 ! ************\n");
	}
	else
	{
		fseek(fp,0L,0);
		fprintf(fp,"%4s%10s%5s%15s%15s%15s%8s%5s\n","编号","姓名","性别","生日","电话1","电话2","所在地","分组");	
		while(p!=NULL)
		{
			fprintf(fp,"%4d%10s%5s%15s%15s%15s%8s%5d\n",p->data.Num,p->data.Name,p->data.Sex,p->data.DateB,p->data.Tel1,p->data.Tel2,p->data.Location,p->data.GroupsId);
			p=p->next;
		}
		printf("\t\t*********** 文件info.txt保存成功 ! ************\n");
	}
	fclose(fp);
	/*分组信息写入*/
	y=remove("groups.txt");
	if((gfp=fopen("groups.txt","w+"))==NULL)//判断文件是否打开成功 
	{
		printf("\t\t*********** 文件groups.txt保存失败 ! **********\n"); 
	}
	GList q;
	q=g->next;
	if(q==NULL)
	{
		fprintf(gfp,"%4s%10s%10s\n","编号","组名","人数");
		printf("\t\t*********** 文件gropus.txt保存成功 ! **********\n");
	}
	else
	{
		fseek(gfp,0L,0);
		fprintf(gfp,"%4s%10s%10s\n","编号","组名","人数");	
		while(q!=NULL)
		{
			fprintf(gfp,"%4d%10s%10d\n",q->id,q->name,q->num);
			q=q->next;
		}
		printf("\t\t*********** 文件gropus.txt保存成功 ! **********\n");
	}
	fclose(gfp);

	printf("\t\t************** 任意键返回上一级 !**************\n");
	getch();
	system("cls");
}
/*显示所有人员*/
void ShowAllP(linklist *l)
{
	linklist *p;
	p=l->next;
	if(p==NULL)
		printf("\t\t*********** 没有数据, 请输入信息 ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","编号","姓名","性别","生日","电话1","电话2","所在地","分组");
		while(p!=NULL)
		{
			printf("%4d%10s%5s%15s%15s%15s%8s%5d\n",p->data.Num,p->data.Name,p->data.Sex,p->data.DateB,p->data.Tel1,p->data.Tel2,p->data.Location,p->data.GroupsId);
			p=p->next;
		}
	}
}
/*显示所有分组*/
void ShowAllG(GList g)
{
	GList p;
	p=g->next;
	if(p==NULL)
		printf("\t\t*********** 没有数据, 请输入信息 ! ***********\n");
	else
	{
		printf("\t\t\t%6s%10s%10s\n","编号","组名","人数");
		while(p!=NULL)
		{
			printf("\t\t\t%6d%10s%10d\n",p->id,p->name,p->num);
			p=p->next;
		}
	}	
}
/*查询所有分组*/
void Select_all(GList g)
{
	printf("\t\t*****************分组查询*********************\n");
	ShowAllG(g);
	printf("\t\t************** 任意键返回上一级 !*************\n");
	getch();
	system("cls");
}
/*查询所有人员*/
void Select_all(linklist *l)
{
	printf("\t\t*****************人员查询*********************\n");
	ShowAllP(l);
	printf("\t\t************** 任意键返回上一级 !*************\n");
	getch();
	system("cls");
}
/*按姓名查找人员*/
int SelectByName(linklist *l,GList g)
{
	int flag=0;
	char a[20],c;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	p=l->next;
	printf("\t\t*****************人员查询*********************\n");
	printf("请输入需要查找人员的姓名:");
	scanf("%s",a);
	if(p==NULL)
		printf("\t\t*********** 没有数据, 请输入信息 ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","编号","姓名","性别","生日","电话1","电话2","所在地","分组");
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
			printf("没有姓名为%s的数据!\n",a);
		printf("是否继续筛选?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}
	}
	printf("\t\t************** 任意键返回上一级 !*************\n");
	getch();
	system("cls");
}
/*按性别查找人员*/
int SelectBySex(linklist *l,GList g)
{
	int flag=0;
	char a[5],c;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	p=l->next;
	printf("\t\t*****************人员查询*********************\n");
	printf("请输入需要查找人员的性别（男/女）:");
	scanf("%s",a);
	if(p==NULL)
		printf("\t\t*********** 没有数据, 请输入信息 ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","编号","姓名","性别","生日","电话1","电话2","所在地","分组");
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
			printf("没有性别为%s的数据!\n",a);
		printf("是否继续筛选?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}
	}
	printf("\t\t************** 任意键返回上一级 !*************\n");
	getch();
	system("cls");
}
/*按电话查找人员*/
int SelectByTel(linklist *l,GList g)
{
	int flag=0;
	char a[12],c;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	p=l->next;
	printf("\t\t*****************人员查询*********************\n");
	printf("请输入需要查找人员的电话号码:");
	scanf("%s",a);
	if(p==NULL)
		printf("\t\t*********** 没有数据, 请输入信息 ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","编号","姓名","性别","生日","电话1","电话2","所在地","分组");
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
			printf("没有电话号码为%s的数据!\n",a);
		printf("是否继续筛选?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}
	}
	printf("\t\t************** 任意键返回上一级 !*************\n");
	getch();
	system("cls");
}
/*按地区查找人员*/
int SelectByLoc(linklist *l,GList g)
{
	int flag=0;
	char a[20],c;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	printf("\t\t*****************人员查询*********************\n");
	printf("请输入需要查找人员的地区:");
	scanf("%s",a);
	if(p==NULL)
		printf("\t\t*********** 没有数据, 请输入信息 ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","编号","姓名","性别","生日","电话1","电话2","所在地","分组");
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
			printf("没有地区为%s的数据!\n",a);
		printf("是否继续筛选?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}
	}
	printf("\t\t************** 任意键返回上一级 !*************\n");
	getch();
	system("cls");
}
/*按分组查找人员*/
int SelectByGroup(linklist *l,GList g)
{
	char c;
	int flag=0,a;
	linklist *p,*q,*t,*s;
	q=Initlist(q);
	s=Initlist(s);
	q=s;
	p=l->next;
	printf("\t\t*****************人员查询*********************\n");
	ShowAllG(g);
	printf("请输入需要查找人员所在的分组编号:");
	scanf("%d",&a);
	if(p==NULL)
		printf("\t\t*********** 没有数据, 请输入信息 ! ***********\n");
	else
	{
		printf("%s%10s%5s%15s%15s%15s%8s%5s\n","编号","姓名","性别","生日","电话1","电话2","所在地","分组");
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
			printf("没有分组为%d的数据!\n",a);
		printf("是否继续筛选?(Y/N)\n");
		c=getch();
		if(c=='y'||c=='Y')
		{
			listmean(s,g);
			return 1;
		}	
	}
	printf("\t\t************** 任意键返回上一级 !*************\n");
	getch();
	system("cls");
}
/*人员查询菜单*/
int listmean(linklist *l,GList g)
{
	int control;
	while(l)
	{
		printf("\t\t*******************人员查询*******************\n");
		printf("\t\t*                1--查 询 所 有              *\n");
		printf("\t\t*                2--按 姓 名 查 找           *\n");
		printf("\t\t*                3--按 性 别 查 找           *\n");
		printf("\t\t*                4--按 电 话 查 找           *\n");
		printf("\t\t*                5--按 地 区 查 找           *\n");
		printf("\t\t*                6--按 分 组 查 找           *\n");
		printf("\t\t*                0--退 出 查 询              *\n");
		printf("\t\t**********************************************\n");
		printf("\t\t\t请输入相应操作数操作(0~6): ");
		scanf("%d",&control);
		system("cls");
		switch(control)
		{
			case 1:Select_all(l);break;		//查询所有 
			case 2:SelectByName(l,g);break;  	//按姓名查找
			case 3:SelectBySex(l,g);break;	//按性别查找
			case 4:SelectByTel(l,g);break;	//按电话查找
			case 5:SelectByLoc(l,g);break;	//按地区查找
			case 6:SelectByGroup(l,g);break;//按分组查找
			case 0:return 0;break;			//退出查询
			default: printf("\t\t************输入数字有误，请重新输入**********\n");break; 
		} 
	}
	return 1;
}
/*人员信息修改*/
int Modify(linklist *l,GList g)
{
	int a,b,x;
	char c[20],f;
	linklist *p;
	printf("\t\t*****************修改人员*********************\n");
	ShowAllP(l);
	do{
		p=l->next;
		if(p==NULL)
		{
			printf("\t\t*********** 没有数据, 请输入信息 ! ***********\n");
			getch();
			system("cls");
			return 1;
		}
		else
		{
			printf("请输入要修改信息人员的编号:");
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
			printf("没有此编号的人员，请重新输入!\n");
		}
	}while(p==NULL);
	do{
		printf("请输入要修改的信息序号(1-姓名 2-性别 3--生日 4-电话1 5-电话2 6-地区  7-分组): ");
		scanf("%d",&b);
		switch(b)
		{
		case 1:
			printf("请输入需要修改后的姓名：");
			scanf("%s",c);
			strcpy(p->data.Name,c);
			printf("\t\t****************** 修改成功 !*****************\n");
			break;
		case 2:
			printf("请输入需要修改后的性别：");
			scanf("%s",c);
			strcpy(p->data.Sex,c);
			printf("\t\t****************** 修改成功 !*****************\n");
			break;
		case 3:
			printf("请输入需要修改后的生日：");
			scanf("%s",c);
			strcpy(p->data.DateB,c);
			printf("\t\t****************** 修改成功 !*****************\n");
			break;
		case 4:
			printf("请输入需要修改后的电话1：");
			scanf("%s",c);
			strcpy(p->data.Tel1,c);	
			printf("\t\t****************** 修改成功 !*****************\n");
			break;
		case 5:
			printf("请输入需要修改后的电话2：");
			scanf("%s",c);
			strcpy(p->data.Tel2,c);	
			printf("\t\t****************** 修改成功 !*****************\n");
			break;
		case 6:
			printf("请输入需要修改后的地区：");
			scanf("%s",c);
			strcpy(p->data.Location,c);	
			printf("\t\t****************** 修改成功 !*****************\n");
			break;
		case 7:
			ShowAllG(g);	
			printf("请输入需要修改后的分组：");
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
			printf("\t\t****************** 修改成功 !*****************\n");
			break;	
		default:
			printf("\t\t****************** 输入有误 !*****************\n");
			break;
		}	
		printf("是否继续修改？(Y/N):\n");
		f=getch();
	}while(f=='y'||f=='Y');
	printf("\t\t************** 任意键返回上一级 !*************\n");
	getch();
	system("cls");
}
/*分组信息修改*/
void Modify(GList g)
{
	int a;
	char c[20];
	GList p;
	printf("\t\t*****************修改分组*********************\n");
	ShowAllG(g);
	do{
		p=g->next;
		printf("请输入要修改分组的编号:");
		scanf("%d",&a);
		if(p==NULL)
		{
			printf("\t\t*********** 没有数据, 请输入信息 ! ***********\n");
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
			printf("没有此编号的分组，请重新输入!\n");
		}
	}while(p==NULL);
	printf("请输入需要修改后的分组名： ");
	scanf("%s",c);
	strcpy(p->name,c);
	printf("\t\t****************** 修改成功 !*****************\n");
	printf("\t\t************** 任意键返回上一级 !*************\n");
	getch();
	system("cls");
}
void Exit(linklist *l,GList g)
{
	char c;
	printf("即将退出，是否确认信息已保存？(Y/N):");
	c=getch();
	if(c=='y'||c=='Y')
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t**********************************************\n");
		printf("\t\t*--------------------------------------------*\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*         感谢使用通讯录管理系统V1.1!        *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                任意键继续..                *\n");
		printf("\t\t*                           Power by WanGzhE *\n");
		printf("\t\t**********************************************\n");
	}
	else
	{
		system("cls");
		printf("是否保存信息？(Y/N)");
		c=getch();
		system("cls");
		if(c=='y'||c=='Y')
			FWrite(l,g);
		printf("\n\n\n\n");
		printf("\t\t**********************************************\n");
		printf("\t\t*--------------------------------------------*\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*         感谢使用通讯录管理系统V1.1!        *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*                任意键继续..                *\n");
		printf("\t\t*                           Power by WanGzhE *\n");
		printf("\t\t**********************************************\n");
	}
	getch();
}
/*主菜单*/
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
		printf("\t\t*                1--读 取 信 息              *\n");
		printf("\t\t*                2--保 存 信 息              *\n");
		printf("\t\t*                3--添 加 人 员              *\n");
		printf("\t\t*                4--添 加 分 组              *\n");
		printf("\t\t*                5--删 除 人 员              *\n");
		printf("\t\t*                6--删 除 分 组              *\n");
		printf("\t\t*                7--查 询 人 员              *\n");
		printf("\t\t*                8--查 询 分 组              *\n");
		printf("\t\t*                9--修 改 人 员              *\n");
		printf("\t\t*               10--修 改 分 组              *\n");
		printf("\t\t*                0--退 出 系 统              *\n");
		printf("\t\t**********************************************\n");	
		printf("\t\t\t请输入相应操作数操作(0~10): ");
		scanf("%d",&control);
		system("cls");
		switch(control)
		{
			case 1:FRead(l,g);break;		//读取信息
			case 2:FWrite(l,g);break;		//保存信息
			case 3:PAdd(l,g);break;			//添加人员
			case 4:GAdd(g);break;			//添加分组
			case 5:PDelete(l,g);break;		//删除人员
			case 6:GDelete(l,g);break;		//删除分组
			case 7:listmean(l,g);break;		//查询人员
			case 8:Select_all(g);break;		//查询分组
			case 9:Modify(l,g);break;		//更改人员
			case 10:Modify(g);break;		//更改分组
			case 0:Exit(l,g);return 1;break;//退出系统
			default: printf("\t\t************输入数字有误，请重新输入**********\n");break; 
		} 
	}
	return 1;
 } 
/*欢迎界面*/
int main() //主函数
{
	printf("\n\n\n\n");
	printf("\t\t**********************************************\n");
	printf("\t\t*--------------------------------------------*\n");
	printf("\t\t*                                            *\n");
	printf("\t\t*                                            *\n");
	printf("\t\t*         欢迎使用通讯录管理系统V1.1!        *\n");
	printf("\t\t*                                            *\n");
	printf("\t\t*                                            *\n");
	printf("\t\t*                任意键继续..                *\n");
	printf("\t\t*                           Power by WanGzhE *\n");
	printf("\t\t**********************************************\n");
	getch();
	system("cls");
	mean();
	return 0;
}
/*
人员信息测试数据

测试01 男 0101 15671654043 13131311235 武汉 1
测试02 女 0101 15671654043 13131311235 十堰 2
测试03 男 0101 15671654043 13131311235 襄阳 3
测试04 男 0101 15671654043 13131311235 北京 4
测试05 男 0101 15671654043 13131311235 深圳 5
测试06 女 0101 15671654043 13131311235 深圳 0
测试07 男 0101 15671654043 13131311235 十堰 0
测试08 男 0101 15671654043 13131311235 武汉 0
*/