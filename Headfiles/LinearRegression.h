#pragma once
//ֱ�߷���Ϊy=k*x+b
#include<stdio.h>//ͷ�ļ�
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<graphics.h>
int R = 255, G = 255, B = 0;
typedef struct zb
{
	double x;
	double y;
	struct zb* next;
}xy;
xy* top;//����ͷ
xy* rear;//����β
double temp1 = 0, temp2 = 0;//�м���� �� k b
double tmp1 = 0, tmp2 = 0;//�м���� �� �����������
int i = 0;
int count = 0;//������
double k, b;//ֱ�߷��̵Ĳ���
double x00, y00, x11, y11;//ǰ������ĺ�������
double lr = 0.001;
double kp(double k, double b, xy* top);
double bp(double k, double b, xy* top);
void add_head(double x, double y);
void add_next(double x, double y);
int day;
void xianxing(double *kk,double*bb,int DAY)
{
	R = 0, G = 0, B = 0;
	count = 0;
	FILE* fp;
	day = DAY;
	fopen_s(&fp, ".\\Data\\LinearReggression.txt", "r");
	if (fp)
	{
		for (i=0; i < DAY; i++)
		{
			fscanf_s(fp, "%lf %lf\n", &tmp1, &tmp2);
			if (i == 0)
			{
				add_head(tmp1, tmp2);
			}
			else
			{
				add_next(tmp1, tmp2);
			}
		}
		fclose(fp);
	}
	x00 = top->x;
	y00 = top->y;
	x11 = (top->next)->x;
	y11 = (top->next)->y;
	*kk = (y11 - y00) / (x11 - x00);
	*bb = y00 - *kk * x00;//��ȡ��ǰ�����������Ϊk b����ֵ
	for (; count < 10000; count++)//����ѧϰ �ݶ��½����������Իع�
	{
		temp1 = *kk;
		temp2 = *bb;
		*kk = *kk - (kp(temp1, temp2, top)) * lr;
		*bb = *bb - (bp(temp1, temp2, top)) * lr;//���ڻ���ѧϰ�ٶȶ�б��Ӱ��̫С��������Ӱ��
		if (G == 255)
		{
			G = 0;
		}
		if (R == 255)
		{
			R = 0;
		}
		if (B == 255)
		{
			B = 0;
		}
		R++;
		G++;
		B++;
		setcolor(RGB(R, G, B));
		line(-390, (-*bb / 5) - 50, (31) * 25 - 390, ((-(*kk * (31) + *bb)) / 5) - 50);
		setlinestyle(PS_SOLID, 1);
		setlinecolor(BLACK);
	}
	xy* ptr;
	ptr = top;
	while (ptr)
	{
		xy* m = ptr;
		ptr = ptr->next;
		free(m);
	}
	top = NULL;
}
double kp(double k, double b, xy* top)//��в�ƽ���͹���k��ƫ����
{
	double m, n;
	double sum = 0;
	int i = 0;
	for (; i < day; i++)
	{
		m = top->x;
		n = top->y;
		sum += -1 * (2 * (n - k * m - b) * m);
		top = top->next;
	}
	return sum/day;
}
double bp(double k, double b, xy* top)//��в�ƽ���͹���b��ƫ����
{
	double m, n;
	double sum = 0;
	int i = 0;
	for (; i < day; i++)
	{
		m = top->x;
		n = top->y;
		sum += -1 * (2 * (n - k * m - b));
		top = top->next;
	}
	return sum/day;
}
void add_head(double x, double y)
{
	xy* p;
	p = (xy*)malloc(sizeof(xy));
	if (p)
	{
		p->x = x;
		p->y = y;
		p->next = NULL;
		top = p;
		rear = p;
	}
}
void add_next(double x, double y)
{
	xy* p;
	p = (xy*)malloc(sizeof(xy));
	if (p)
	{
		p->x = x;
		p->y = y;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
}