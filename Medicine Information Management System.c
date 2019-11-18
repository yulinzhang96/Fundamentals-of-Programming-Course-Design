#include "stdafx.h"
#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
#include "string"
#include <stdio.h>
typedef struct lian {
	char a[20];//名称
	char b[20];//编号
	int c;//生产日期
	float d;//有效日期
	int e;//失效日期
	int f;//主治病症类别代号
	int g;//服用方法代号
	int  h[6];//h[1] h[2]代表次数范围  h[3] h[4]代表用量范围
	char j[6];//单位
	int k;//每日最大用量
	struct lian *next;
} biao;



int shuchu(lian *p)//输出函数
{
	int n;
	if (p == NULL)
	{
		printf("无药品信息。\n");
		return 0;
	}
	while ((p->next) != NULL){
		for (n = 1; n <= 62; n++)
			printf("~");
		printf("\n");
		printf("名称:%s\n编号:%s\n生产日期:%d\n有效期【月】:%f\n失效日期:%d\n", p->a, p->b, p->c, p->d, p->e);
		printf("主治病症：");
		if (p->f == 1)
			printf("感冒药\n");
		if (p->f == 2)
			printf("胃药\n");
		if (p->f == 3)
			printf("消炎药\n");
		if (p->f == 4)
			printf("滴眼液\n");
		printf("服用方法：");
		if (p->g == 1)
			printf("口服\n");
		if (p->g == 2)
			printf("外用\n");
		if (p->g == 3)
			printf("饭后服用\n");
		printf("如何使用：");
		if (p->h[1] == 0)
		{
			printf("每日%d次，", p->h[2]);
		}
		else
		{
			printf("每日%d-%d次， ", p->h[1], p->h[2]);
		}
		if (p->h[3] == 0)
		{
			printf("每次%d%s,", p->h[4], p->j);
		}
		else
		{
			printf("每次%d-%d%s", p->h[3], p->h[4], p->j);
		}
		if (p->k != 0)
			printf(",一日最多%d%s\n", p->k, p->j);
		else printf("\n");
		p = p->next;
	}
	for (n = 1; n <= 80; n++)
		printf("~");
	printf("\n");
	printf("名称:%s\n编号:%s\n生产日期:%d\n有效期【月】%f\n失效日期:%d\n", p->a, p->b, p->c, p->d, p->e);        //为了能读取到最后一个结点里的信息
	printf("主治病症：");
	if (p->f == 1)
		printf("感冒药\n");
	if (p->f == 2)
		printf("胃药\n");
	if (p->f == 3)
		printf("消炎药\n");
	if (p->f == 4)
		printf("滴眼液\n");
	printf("服用方法：");
	if (p->g == 1)
		printf("口服\n");
	if (p->g == 2)
		printf("外用\n");
	if (p->g == 3)
		printf("饭后服用\n");
	printf("如何使用：");
	if (p->h[1] == 0)
	{
		printf("每日%d次, ", p->h[2]);
	}
	else
	{
		printf("每日%d-%d次, ", p->h[1], p->h[2]);
	}
	if (p->h[3] == 0)
	{
		printf("每次%d%s", p->h[4], p->j);
	}
	else
	{
		printf("每次%d-%d%s", p->h[3], p->h[4], p->j);
	}
	if (p->k != 0)
		printf(",一日最多%d%s\n", p->k, p->j);
	else printf("\n");
	return 0;
}
int f(int i)      //用来美化界面
{
	for (int n = 1; n <= i + 60; n++)
	{
		printf("~");
	}
	printf("\n");
	return 0;
}
typedef biao *point;
point h, t, p, g;
int paixu(lian *top)      //将链表按照编号顺序排序
{
	int i, n, x, m;
	char b[20];//字符
	point q;
	h = top;
	if (top->next == NULL)    //检查该链表是否为空
		return 0;
	for (m = 1; m < 1000; m++)
	{
		h = top;
		p = h->next;
		x = 0;
		for (i = 1; i <= 1000; i++)
		{
			if (strcmp(h->b, p->b) > 0)//判断相邻结点里的编号大小
			{
				x = 1;//标志
				strcpy(b, h->a);
				strcpy(h->a, p->a);
				strcpy(p->a, b);//换名称
				strcpy(b, h->b);
				strcpy(h->b, p->b);
				strcpy(p->b, b);//换编号
				n = p->c;
				p->c = h->c;
				h->c = n;//换生产日期
				n = p->d;
				p->d = h->d;
				h->d = n;//换保质日期
				n = p->e;
				p->e = h->e;
				h->e = n;//换有效日期
				n = p->f;
				p->f = h->f;
				h->f = n;//换药物类别
				n = p->f;
				p->f = h->f;
				h->f = n;//换服用方法
				n = p->h[1];
				p->h[1] = h->h[1];
				h->h[1] = n;
				n = p->h[2];
				p->h[2] = h->h[2];
				h->h[2] = n;//换服用次数
				n = p->h[3];
				p->h[3] = h->h[3];
				h->h[3] = n;
				n = p->h[4];
				p->h[4] = h->h[4];
				h->h[4] = n;//换用量
				strcpy(b, h->j);
				strcpy(h->j, p->j);
				strcpy(p->j, b);//换单位
				n = p->k;
				p->k = h->k;
				h->k = n;//换最多用量
			}
			if (p->next != NULL)
			{
				h = p;
				p = p->next;
			}
			else if (p->next == NULL&&x == 0)
				return 0;
			else if (p->next == NULL&&x == 1)
				break;;
		}
	}
	return 0;
}
int j(int n)//显示功能界面
{
	for (n = 1; n <= 80; n++)
		printf("~");
	printf("\n");
	printf("【增加功能请输入】          1\n【修改功能】                2\n【删除功能】                3\n【计算药品失效日期功能】    4\n【计算药品一日用量】        5\n【查询某种药品信息】        6\n【查询药品主治病情】        7\n【输出所有药品信息】        8\n【存储药品信息】            9\n【输出过期药品信息】        10\n【输出即将过期药品信息】    11\n【退出药品管理系统】        0\n请输入的选择功能:\n");
	return  0;
}
void jiancebianhao(lian *p)//检测并修改编号
{
	int length = 0;
	length = strlen(p->b);//获取指针当前所指节点的编号的长度，并赋值给length
	while (length != 12)   //检测编号长度
	{
		printf("\n");
		f(20);
		printf("\n");
		printf("药品【%s】的编号位数不对！请检查并修改（12位）：", p->a);
		scanf("%s", p->b);
		length = strlen(p->b);
		if (length == 12)//再次判断编号长度是否为12位，是则退出循环，否则继续让用户输入直到正确为止
		{
			printf("编号位数修改成功！\n");
		}
	}
}
int jiancebianhaochongfu(lian *p)//检测编号是否有重复
{
	t = p;//t为首节点
	h = p;//h为外层循环的节点，p为内层函数的节点
	while (h != NULL)
	{
		char code[20];
		strcpy(code, h->b);//将外循环指针h所指节点的编号赋值给code[20]
		while (p->next != NULL)
		{
			p = p->next;//从h所指节点的下一节点开始循环，直到末尾
			if ((strcmp(p->b, code)) == 0)//判断外循环指针h所指节点的编号是否与内循环的重复
			{
				f(20);        //美化
				printf("\n");
				int xp;
				printf("药品【%s】与药品【%s】编号重复，请检查并修改（12位）（修改%s请按1，修改%s请按2）：", h->a, p->a, h->a, p->a);
				scanf("%d", &xp);
				if (xp == 1)//修改外循环，即h所指节点的编号
				{
					printf("\n请输入药品【%s】的正确编号：", h->a);
					scanf("%s", h->b);
					p = t->next;
					h = t;//从头开始循环，逐个判断，避免修改过后的编号与前面已判断过的编号重复
					break;
				}
				else if (xp == 2)//修改内循环编号
				{
					printf("\n请输入药品【%s】的正确编号：", p->a);
					scanf("%s", p->b);
				}
			}
		}
		h = h->next;     //循环控制
	}
	return 0;
}
int jiancuoriqi(lian *p)     //日期检错
{
	int c, d, e, y;
	while ((p->c == 0 && p->d == 0 && p->e == 0))//纠错日期，是否数据齐全
	{
		printf("\n");
		printf("该药品日期信息错误1，药品数据不齐全，请重新输入。\n");
		printf("请输入药品生产日期（如没有请输入0）：");
		scanf("%d", &(p->c));
		printf("请输入药品有效日期（如没有请输入0）：");
		scanf("%f", &(p->d));
		printf("请输入药品失效期（如没有请输入0）：");
		scanf("%d", &(p->e));
	}
	while ((p->d == 0 && p->e == 0))//纠错日期，是否数据齐全
	{
		printf("\n");
		printf("该药品日期信息错误1，药品数据不齐全，请重新输入。\n");
		printf("请输入药品生产日期（如没有请输入0）：");
		scanf("%d", &(p->c));
		printf("请输入药品有效期（如没有请输入0）【月】： ");
		scanf("%f", &(p->d));
		printf("请输入药品失效日期（如没有请输入0）：");
		scanf("%d", &(p->e));
	}
	while ((p->c == 0 && p->e == 0))//纠错日期，是否数据齐全
	{
		printf("\n");
		printf("该药品日期信息错误1，药品数据不齐全，请重新输入。\n");
		printf("请输入药品生产日期（如没有请输入0）：");
		scanf("%d", &(p->c));
		printf("请输入药品有效期（如没有请输入0）【月】：");
		scanf("%f", &(p->d));
		printf("请输入药品失效日期（如没有请输入0）：");
		scanf("%d", &(p->e));
	}
	while (p->d == 0)//纠错日期，数据是否合理
	{
		printf("\n");
		if (p->c >= p->e)
		{
			printf("该药品日期信息错误2，请修改。\n");
			printf("请输入药品生产日期（如没有请输入0）：");
			scanf("%d", &(p->c));
			printf("请输入药品有效期（如没有请输入0）【月】：");
			scanf("%f", &(p->d));
			printf("请输入药品失效日期（如没有请输入0）：");
			scanf("%d", &(p->e));
		}
	}
	while ((p->c) != 0 && (p->c) % 100>30 || (p->c % 10000) / 100>12 || p->c / 10000000 == 0)//检测日期是否合理
	{
		printf("\n");
		if (p->c == 0)
		{
			break;
		}
		printf("该药品生产日期错误，请修改。\n");
		printf("（如没有请输入0）请输入药品生产日期：");
		scanf("%d", &(p->c));
	}
	while ((p->d) * 10000 != ((p->d) / 1) * 10000)
	{
		printf("\n");
		printf("保质日期格式不对，请修改。\n");
		scanf("%f", &p->d);
	}
	while (p->d<0)
	{
		printf("\n");
		printf("该药品保质期有错，请修改。\n");
		printf("请输入药品有效期（如没有请输入0）【月】：");
		scanf("%f", &(p->d));
	}
	while ((p->e) != 0 && p->e % 100>30 || (p->e % 10000) / 100>12 || p->e / 10000000 == 0)//检测日期是否合理
	{
		printf("\n");
		if (p->e == 0)
		{
			break;
		}
		printf("该药品失效日期错误，请修改。\n");
		printf("（如没有请输入0）请输入药品失效日期：");
		scanf("%d", &(p->e));
	}
	while (p->c != 0 && p->d != 0 && p->e != 0)//日期安排是否合理
	{
		printf("\n");
		c = p->c;
		d = p->d / 1;
		e = p->e;
		y = 1;
		y = (c % 10000) / 100;
		c = c - y * 100;
		d = d + y;
		c = c + 10000 * (d / 12) + d % 12 * 100;
		if (e != c)
		{
			printf("该药品日期数据不对，请重新输入。\n");
			printf("请输入药品生产日期（如没有请输入0）：");
			scanf("%d", &(p->c));
			printf("请输入药品有效期（如没有请输入0）【月】：");
			scanf("%f", &(p->d));
			printf("请输入药品失效日期（如没有请输入0）：");
			scanf("%d", &(p->e));
		}
		else break;
	}
	while (p->f != 1 && p->f != 2 && p->f != 3 && p->f != 4)//药品主治类别
	{
		printf("\n");
		printf("该药品主治病症有误，请修改。\n");
		printf("请选择病症\n（1：感冒药2:胃药3：消炎药4：滴眼药）：");
		scanf("%d", &(p->f));
	}
	while (p->g != 1 && p->g != 2 && p->g != 3)
	{
		printf("\n");
		printf("该药品服用方法有误，请修改。\n");
		printf("请输入药用方法\n（1:口服2：外用3:饭后服用）             ：");
		scanf("%d", &(p->g));
	}
	return 0;
}
int jiancuoyongfa(lian *p)          //     用法检错与修改
{
	int i;
	while (((p->h[1])>=(p->h[2])) || ((p->h[3])>=(p->h[4])) || ((p->h[1]) % 1 != 0) || ((p->h[2] % 1) != 0) || ((p->h[3]) % 1 != 0) || ((p->h[4] % 1) != 0))      //循环控制
	{
		f(20);       //美化
		printf("\n");
		if ((p->h[1])>=(p->h[2]))
		{
			printf("药品【%s】（编号：%s)每日使用范围必须是前小后大，请重新输入:\n", p->a, p->b);
			scanf("%d%d", &p->h[1], &p->h[2]);
		}
		if ((p->h[3])>=(p->h[4]))
		{
			printf("药品【%s】（编号：%s)用量的范围必须是前小后大，请重新输入\n", p->a, p->b);
			scanf("%d%d", &p->h[3], &p->h[4]);
		}

	}
	if ((p->k) != 0)        //判断是否有每日最大用量
	{
		while ((p->k)<((p->h[2])*(p->h[4])))        //我们假定若每日最大允许用量小于每日使用范围的最大值与每次用量的最大值的乘积则不符合
		{
			f(20);
			printf("\n");
			printf("药品【%s】（编号：%s)超出最大用量,请重新输入用法用量信息\n", p->a,p->b);
			printf("请重新输入每日使用次数范围（如是范围请输入两个数，如果是规定次数请先输入0，再输入次数）:\n");
			scanf("%d%d", &p->h[1], &p->h[2]);
			printf("请重新输入每次用量的范围（如是范围请输入两个数，如果是规定次数请先输入0，再输入次数）:\n");
			scanf("%d%d", &p->h[3], &p->h[4]);
			printf("请重新输入每日最大用量:\n");
			scanf("%d", &(p->k));
		}

	}
	//printf("恭喜你，修改成功啦，啦啦啦！\n");
	return 0;
}
int shuchu1(lian *p)     //输出当前结点内的数据
{
	f(20);
	printf("\n");
	printf("名称:%s\n编号:%s\n生产日期:%d\n有效期【月】:%f\n失效日期:%d\n", p->a, p->b, p->c, p->d, p->e);
	printf("主治病症：");
	if (p->f == 1)
		printf("感冒药\n");
	if (p->f == 2)
		printf("胃药\n");
	if (p->f == 3)
		printf("消炎药\n");
	if (p->f == 4)
		printf("滴眼液\n");
	printf("服用方法：");
	if (p->g == 1)
		printf("口服\n");
	if (p->g == 2)
		printf("外用\n");
	if (p->g == 3)
		printf("饭后服用\n");
	printf("如何使用：");
	if (p->h[1] == 0)
	{
		printf("每日%d次, ", p->h[2]);
	}
	else
	{
		printf("每日%d-%d次, ", p->h[1], p->h[2]);
	}
	if (p->h[3] == 0)
	{
		printf("每次%d%s", p->h[4], p->j);
	}
	else
	{
		printf("每次%d-%d%s", p->h[3], p->h[4], p->j);
	}
	if (p->k != 0)
		printf(",一日最多%d%s\n", p->k, p->j);
	else printf("\n");
	return 0;
}
int main()
{
	int x, n = 1, y, z;
	char a[20], b[12];
	point top, rear;
	g = (point)malloc(sizeof(biao));
	t = (point)malloc(sizeof(biao));
	h = (point)malloc(sizeof(biao));
	top = (point)malloc(sizeof(biao));
	rear = (point)malloc(sizeof(biao));
	top = rear = NULL;
	p = top;
	printf("\n");
	printf("\t\t\t\t欢迎使用药品信息管理系统\n\n");
	f(20);
	printf("无药品信息，请增加药品信息！！\n");
	j(n);
	while (scanf("%d", &n) != EOF)       //使功能循环下去
	{
		f(20);
		if (n == 0)
		{
			exit(0);//退出系统
		}
		if (n == 1)
		{
			printf("\n");
			printf("请选择输入方式\n1：手动输入\n2：文件输入\n");
			while (scanf("%d", &x) != EOF)
			{
				if (x == 1)
				{
					p = top;
					while (top != NULL&&p != NULL)
					{
						if (p->next == NULL)
						{
							rear = p;
							p = p->next;
							p = (point)malloc(sizeof(biao));
							break;
						}
						p = p->next;
					}
					p = (point)malloc(sizeof(biao));
					printf("请输入药品名称：\n");
					scanf("%s", p->a);
					printf("请输入药品编号：\n");
					scanf("%s", p->b);
					printf("请输入药品生产日期（如没有请输入0）：");
					scanf("%d", &(p->c));
					printf("请输入药品有效期（如没有请输入0）【月】：");
					scanf("%f", &(p->d));
					printf("（如没有请输入0）请输入药品失效日期：");
					scanf("%d", &(p->e));
					printf("请选择病症\n（1：感冒药2:胃药3：消炎药4：滴眼药）：");
					scanf("%d", &(p->f));
					printf("请输入药用方法\n（1:口服2：外用3:饭后服用）          ：");
					scanf("%d", &(p->g));
					printf("请输入每日服用次数（如是范围请输入两个数，如果是固定次数请先输入0，再输入次数）：\n");
					scanf("%d%d", &(p->h[1]), &(p->h[2]));
					printf("请输入每次服用用量（如是范围请输入两个数，如果是固定用量请先输入0，再输入次数）：\n");
					scanf("%d%d", &(p->h[3]), &(p->h[4]));
					printf("请输入药品服用单位：  ");
					scanf("%s", p->j);
					printf("请输入药品一日最多用量(如没有一日最多用量，请输入0)：\n");
					scanf("%d", &(p->k));
					p->next = NULL;
					if (rear == NULL)
					{
						top = p;
						rear = p;
						rear->next = NULL;
					}
					else
					{
						rear->next = p;
						rear = p;
						rear->next = NULL;
					}
					break;
				}
				else	if (x == 2)     //从文件中录入
				{
					FILE *fp;
					char filename[100];
					printf("\n");
					printf("请输入要录入药品相关信息的文件名：");
					scanf("%s", filename);
					while ((fp = fopen(filename, "r")) == NULL)
					{
						printf("该文件无法打开或不存在！\n");
						printf("请重新输入要录入药品相关信息的文件名：");
						scanf("%s", filename);
					}
					if (top != NULL)
					{
						for (p = top;; p = p->next)
						{

							if (p->next == NULL)
							{
								h = p;
								break;
							}
						}//将指针指向链表末尾
					}
					rewind(fp);
					while (!feof(fp))
					{
						p = (point)malloc(sizeof(biao));
						if (top == NULL)
						{
							top = (point)malloc(sizeof(biao));
							fscanf(fp, "%s", top->a);
							if (strcmp(top->a, "结束") == 0)    //文件遇到“结束”时令头指针等于NULL
							{
								top = NULL;
								break;
							}
							fscanf(fp, "%s%d%f%d%d%d%d%d%d%d%s%d", &(top->b), &(top->c), &(top->d), &(top->e), &(top->f), &(top->g), &(top->h[1]), &(top->h[2]), &(top->h[3]), &(top->h[4]), &(top->j), &(top->k));
							top->next = p;
						}
						fscanf(fp, "%s", &(p->a));
						if (strcmp(p->a, "结束") == 0)
						{
							if (top->next == p)
							{
								top->next = NULL;
							}
							free(p);
							h->next = NULL;
							break;
						}
						fscanf(fp, "%s%d%f%d%d%d%d%d%d%d%s%d", &(p->b), &(p->c), &(p->d), &(p->e), &(p->f), &(p->g), &(p->h[1]), &(p->h[2]), &(p->h[3]), &(p->h[4]), &(p->j), &(p->k));
						h->next = p;
						h = p;
					}
					fclose(fp);
				}
				if (x == 2)
				{
					break;
				}
			}
		}
		if (top == NULL&&n != 1)
		{
			printf("已无药品信息,请输入信息!!!\n");
			continue;
		}
		if (n == 2 && top != NULL)   //功能2
		{
			printf("\n");
			printf("请输入需要修改的药品编号\n");
			scanf("%s", b);
			p = top;
			h = NULL;
			while (p != NULL)
			{
				if (strcmp(p->b, b) == 0)
				{
					break;
				}
				else if (p->next == NULL)
				{
					printf("无此编号：请再次输入编号:\n");
					scanf("%s", b);
					p = top;
				}
				else p = p->next;
			}
			printf("请选择药品信息修改类型：\n");
			printf("1；药品名称\n2；药品编号\n3；药品生产日期\n4：药品有效期\n5：药品失效日期\n6；药品病症\n7：药品药用方法\n8：药品用法\n9：药品用量\n10：药品单位\n");
			scanf("%d", &x);
			if (x == 1)
			{
				printf("请输入要修改药品的名称\n");
				scanf("%s", p->a);
			}
			if (x == 2)
			{
				printf("请输入要修改药品的编号\n");
				scanf("%s", p->b);
			}
			if (x == 3)
			{
				printf("如没有请输入0）请输入该药品生产日期：");
				scanf("%d", &(p->c));
			}
			if (x == 4)
			{
				printf("如没有请输入0）请输入该药品有效期：");
				scanf("%f", &(p->d));
			}
			if (x == 5)
			{
				printf("如没有请输入0）请修改该药品失效日期：");
				scanf("%d", &(p->e));
			}
			if (x == 6)
			{
				printf("请选择该药品病症\n（1：感冒药2:胃药3：消炎药4：滴眼药）：\n");
				scanf("%d", &(p->f));
			}
			if (x == 7)
			{
				printf("请选择该药品药用方法 \n(1:口服  2：外用  3:饭后服用 :        \n");
				scanf("%d", &(p->g));
			}
			if (x == 8)
			{
				printf("请修改用法：\n请输入每日服用次数（如是范围请输入两个数，如果是规定次数请先输入0，再输入次数）\n");
				scanf("%d%d", &(p->h[1]), &(p->h[2]));
			}
			if (x == 9)
			{
				printf("请修改用量：\n请输入每次服用用量（如是范围请输入两个数，如果是规定用量请先输入0，再输入次数）\n");
				scanf("%d%d", &(p->h[3]), &(p->h[4]));
			}
			if (x == 10)
			{
				printf("请修改该药品单位\n");
				scanf("%s", p->j);
			}
		}
		if (n == 3 && top != NULL)     //功能3
		{
			h = NULL;
			printf("\n");
			printf("请输入要删除的药品名称或编号：\n");
			scanf("%s", a);
			x = 0;
			p = top;
			while (p != NULL)
			{
				y = 0;
				if (strcmp((p->a), a) == 0 || strcmp((p->b), a) == 0)
				{
					x++;
					y = 1;
					if (p == top&&top->next != NULL)
					{

						top = p->next;
						free(p);
						p = top;
						continue;
					}
					else if (p == top&&top->next == NULL)
					{
						printf("已无药品信息!!!\n");
						free(top);
						rear = top = NULL;
						x = -1;//结束标志
						break;
					}
					else if (p->next == NULL)
					{
						if (top->next == p)
							top->next = NULL;
						else h->next = NULL;//改了这里
						free(p);
						x = -1;//x=-1为结束标志
						break;
					}
					else //在中间找到
					{

						h->next = p->next;
						free(p);
						p = h->next;
						continue;
					}
				}
				else //如果本次节点未找到
				{
					if (p->next != NULL)
					{
						h = p;
						p = p->next;
						y = 3;
					}
					if (p->next == NULL)
					{
						if (x > 0)
						{
							x = -1;
							y = 3;
						}
					}
				}
				if (y == 3)
					continue;
				if (x == -1)
					break;
				if (x == 0 && p->next == NULL)
				{
					printf("无此名称或编号，请重新输入：\n");
					scanf("%s", a);
					h = NULL;
					p = top;
				}
			}
		}
		if (n == 4 && top != NULL)      //功能4
		{
			int y;//y代表当前日期
			bool judge = false;//judge代表判断输入信息是否有误
			char w[20];
			printf("\n");
			printf("请输入当前日期：");
			scanf("%d", &y);
			printf("请输入药品编号或名称：");
			scanf("%s", w);//w代表输入的名称或编号
			for (h = top; h != NULL; h = h->next){
				if (strcmp(h->b, w) == 0 || strcmp(h->a, w) == 0){
					judge = true;
					if (h->e != 0)//有失效日期的情况
					{
						int days;
						days = (y / 10000 - (h->e) / 10000) * 360 + ((y / 100) % 100 - ((h->e) / 100) % 100) * 30 + y % 100 - (h->e) % 100;
						if (days >= 0)
							printf("【%s】(编号：%s)药品已过期%d天\n", h->a, h->b, days);
						else if (days < 0)
							printf("【%s】(编号：%s)药品距离过期还有%d天\n", h->a, h->b, (-1)*days);
					}
					else if (h->c != 0 && h->d != 0)//无失效日期，但生产日期和有效日期都有的情况
					{
						int mon;//mon代表生产日期的月份与有效日期相加之和
						mon = (h->c / 100) % 100 + h->d;
						if (mon>12)
						{
							h->e = ((h->c / 10000) + mon / 12) * 10000 + (mon % 12) * 100 + (h->c % 100);
						}
						else
						{
							h->e = h->c + h->d * 100;
						}
						int days;
						days = (y / 10000 - (h->e) / 10000) * 360 + ((y / 100) % 100 - ((h->e) / 100) % 100) * 30 + y % 100 - (h->e) % 100;
						if (days >= 0)
							printf("【%s】(编号：%s)药品已过期%d天\n", h->a, h->b, days);
						else if (days < 0)
							printf("【%s】(编号：%s)药品距离过期还有%d天\n", h->a, h->b, (-1)*days);
					}
					else
					{
						printf("【%s】(编号：%s)药品相关信息缺失，无法计算当前失效日期！\n", h->a, h->b);
					}
				}
			}
			if (judge == false)
			{
				printf("输入药品信息有误（该药品不存在）！\n");
			}
		}//n=4结束
		if (n == 5 && top != NULL)     //功能5
		{
			printf("\n");
			printf("请输入名称或者编号：\n");
			p = top;
			scanf("%s", a);
			while (p != NULL)
			{
				if (strcmp((p->a), a) == 0 || strcmp((p->b), a) == 0)
				{
					printf("名称：%s\n编号：%s\n", p->a, p->b);
					if (p->h[1] != 0 && p->h[3] != 0)
					{
						x = (p->h[1])*(p->h[3]);
						y = (p->h[2])*(p->h[4]);
					}
					if (p->h[1] != 0 && p->h[3] == 0)
					{
						x = (p->h[1])*(p->h[4]);
						y = (p->h[2])*(p->h[4]);
					}
					if (p->h[1] == 0 && p->h[3] != 0)
					{
						x = (p->h[2])*(p->h[3]);
						y = (p->h[2])*(p->h[4]);
					}
					if (p->h[1] == 0 && p->h[3] == 0)
					{
						x = (p->h[1])*(p->h[3]);
						y = (p->h[2])*(p->h[4]);
					}
					if (x != 0 && y != 0)
					{
						if (y > p->k)
							y = p->k;
						printf("一日用量为%d--%d%s\n", x, y, p->j);
					}
					else printf("一日%d%s\n", y, p->j);
				}
				p = p->next;
			}
		}
		if (n == 6 && top != NULL)      //功能6
		{
			printf("\n");
			printf("请输入药品编号或名称：");
			char w[20];//w代表输入的名称或编号
			scanf("%s", w);//w代表输入的名称或编号
			for (p = top; p != NULL; p = p->next){
				if (strcmp(p->b, w) == 0 || strcmp(p->a, w) == 0){
					for (n = 1; n <= 62; n++)
						printf("~");
					printf("\n");
					printf("名称:%s\n编号:%s\n生产日期:%d\n有效期【月】:%f\n失效日期:%d\n", p->a, p->b, p->c, p->d, p->e);
					printf("主治病症：");
					if (p->f == 1)
						printf("感冒药\n");
					if (p->f == 2)
						printf("胃药\n");
					if (p->f == 3)
						printf("消炎药\n");
					if (p->f == 4)
						printf("滴眼液\n");
					printf("服用方法：");
					if (p->g == 1)
						printf("口服\n");
					if (p->g == 2)
						printf("外用\n");
					if (p->g == 3)
						printf("饭后服用\n");
					printf("如何使用：");
					if (p->h[1] == 0)
					{
						printf("每日%d次,", p->h[2]);
					}
					else
					{
						printf("每日%d-%d次， ", p->h[1], p->h[2]);
					}
					if (p->h[3] == 0)
					{
						printf("每次%d%s", p->h[4], p->j);
					}
					else
					{
						printf("每次%d-%d%s", p->h[3], p->h[4], p->j);
					}
					if (p->k != 0)
						printf("，一日最多%d%s\n", p->k, p->j);
					else
						printf("\n");
				}
			}
		}//n=6结束
		if (n == 7 && top != NULL)
		{
			printf("\n");
			paixu(top);
			printf("请输入要查询的主治病症的药品类别【1：感冒药2:胃药3：消炎药4：滴眼药】\n输入：");
			int type;//type代表类别代号
			printf("\n");
			while (scanf("%d", &type) != EOF)
			{
				if (type == 1 || type == 2 || type == 3 || type == 4)
					break;
				else
					printf("无此类别，请输入合法类别：\n");
			}
			printf("\n");
			x = 0;
			for (p = top; p != NULL; p = p->next)
			{
				if (p->f == type)
					x++;
				if (type == 1 && x == 1)
				{

					printf("【主治病症：感冒药】\n");

				}
				else if (type == 2 && x == 1)
				{
					printf("【主治病症：胃药】\n");

				}
				else if (type == 3 && x == 1)
				{
					printf("【主治病症：消炎药】\n");
				}

				else if (type == 4 && x == 1)
				{
					printf("【主治病症：滴眼药】\n");
				}

				if (p->f == type)
				{
					printf("药品名称:%s\t药品编号:%s\n", p->a, p->b);
					if (p->g == 1)
						printf("用法:口服\n");
					if (p->g == 2)
						printf("用法:外用\n");
					if (p->g == 3)
						printf("用法:饭后服用\n");
					if (p->h[1] == 0)
					{
						printf("用量:每日%d次\n", p->h[2]);
					}
					else
					{
						printf("用量:每日%d-%d次\n ", p->h[1], p->h[2]);
					}
					if (p->h[3] == 0)
					{
						printf("用量:每次%d%s\n", p->h[4], p->j);
					}
					else
					{
						printf("用量:每次%d-%d%s\n", p->h[3], p->h[4], p->j);
					}
					if (p->k != 0)
						printf("一日最多%d%s\n", p->k, p->j);
					else
						printf("\n");
				}
				if (x == 0 && p->next == NULL)
					printf("无此类病症药品\n此功能操作结束\n");
			}
		}//n==7结束
		if (n == 8)
		{
			paixu(top);
			printf("排序成功后的所有药品信息：\n");
			shuchu(top);
		}//n==8结束
		if (n == 9 && top != NULL)    //功能9
		{
			FILE *fp;
			bool judge = false;//judge代表文件是否成功打开
			char file_name[50];
			printf("\n");
			printf("请输入要保存药品信息的文件名：");
			scanf("%s", file_name);
			while ((fp = fopen(file_name, "w")) == NULL)
			{
				printf("文件：【%s】无法打开!\n", file_name);
				printf("请重新输入要保存药品信息的文件名：");
				scanf("%s", file_name);
			}
			judge = true;
			fprintf(fp, "名称\t\t     编号\t\t生产日期\t    有效期\t\t  失效日期\t主治病症\t\t\t服用方法         ");
			for (p = top; p != NULL; p = p->next)
			{
				fprintf(fp, "\n%s\t %s\t\t%d\t %f\t\t %d\t", p->a, p->b, p->c, p->d, p->e);
				if (p->f == 1)
					fprintf(fp, "感冒药\t\t");
				if (p->f == 2)
					fprintf(fp, "胃药\t\t");
				if (p->f == 3)
					fprintf(fp, "消炎药\t\t");
				if (p->f == 4)
					fprintf(fp, "滴眼液\t\t");
				if (p->g == 1)
					fprintf(fp, "口服，");
				if (p->g == 2)
					fprintf(fp, "外用，");
				if (p->g == 3)
					fprintf(fp, "饭后服用，");
				if (p->h[1] == 0)
				{
					fprintf(fp, "每日%d次,", p->h[2]);
				}
				else
				{
					fprintf(fp, "每日%d-%d次， ", p->h[1], p->h[2]);
				}
				if (p->h[3] == 0)
				{
					fprintf(fp, "每次%d%s", p->h[4], p->j);
				}
				else
				{
					fprintf(fp, "每次%d-%d%s", p->h[3], p->h[4], p->j);
				}
				if (p->k != 0)
					fprintf(fp, "，一日最多%d%s\n\r", p->k, p->j);
				else
					fprintf(fp, "\n\r");

			}
			if (judge == true)
			{
				printf("保存成功！\n");
			}
			fclose(fp);
		}//n=9结束
		if (n == 10 && top != NULL)     //功能10
		{
			int date;
			printf("\n");
			printf("请输入当前日期：");
			scanf("%d", &date);
			for (y = 1; y <= 62; y++)
				printf("~");
			printf("\n");
			int pro = 0;               //pro统计过期药品个数
			for (p = top; p != NULL; p = p->next)
			{
				if (((p->e) - date)<0 || (((p->c) + ((p->e) * 30) - date)<0))   //根据失效日期以及保质期和有效日期来判断是否过期
				{
					pro++;
					printf("%d.【%s】（编号：%s）已过期\n", pro, p->a, p->b);
				}
			}
			if (pro == 0)
				printf("无过期药品\n");
		}//n==10结束
		if (n == 11 && top != NULL)      //功能11
		{
			int date;
			printf("\n");
			printf("请输入当前日期：");
			scanf("%d", &date);
			int One_Month = 30;//One_Month代表过期前提醒天数30天
			for (y = 1; y <= 62; y++)
				printf("~");
			printf("\n即将过期药品清单：\n");
			int pro = 0;//pro统计即将过期药品个数
			for (p = top; p != NULL; p = p->next){
				int days;
				days = ((p->e) / 10000 - date / 10000) * 360 + (((p->e) / 100) % 100 - (date / 100) % 100) * 30 + (p->e) % 100 - date % 100;
				if (days >= 0 && days <= 30){
					pro++;
					printf("%d.【%s】（编号：%s）距离过期还有%d天\n", pro, p->a, p->b, days);
				}
			}
			if (pro == 0)
				printf("无\n");
		}//n=11结束
		printf("正在检查信息是否有误！\n");
		
		if (n == 1 || n == 2)
		{
			jiancebianhaochongfu(top);//检测药品编号是否有重复
			p = top;
			while (p != NULL)
			{
				f(20);
				jiancebianhao(p);//检测编号位数是否为12位
				shuchu1(p);
				jiancuoriqi(p);
				jiancuoyongfa(p);
				p = p->next;
			}
		}
		printf("药品信息无误！\n");
		printf("请问是否需要为你展示所有药品信息？需要请输入【1】，不需要请输入【2】：\n");
		if (top != NULL)
		{
			paixu(top);
		}
		scanf("%d", &z);
		if (z == 1)
			shuchu(top);
		j(n);
	}
	return 0;
}


