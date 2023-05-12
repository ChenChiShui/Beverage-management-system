#include"..\Headfiles\GraphPage.h"
#include"..\Headfiles\loginFunction.h"
#include"..\Headfiles\RecordChain.h"
#include"..\Headfiles\GetTime.h"
#include"..\Headfiles\InputCheck.h"
#include"..\Headfiles\ClientChain.h"
#include"..\Headfiles\ChainOpt.h"
#include"..\Headfiles\CommodityChain.h"
#include"..\Headfiles\CartChain.h"
#include"..\Headfiles\MD5.h"
#include"..\Headfiles\LinearRegression.h"
#include"..\Headfiles\StrSimilar.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<graphics.h>

#define strnlen_s strnlen
#define pi 3.1415926

//--------------------
//�ȼ��궨��
#define zeroToOne0 100
#define oneToTwo0 500
#define twoToThree0 1000
#define threeToFour0 2000
#define fourToFive0 5000
// --------------------

//--------------------
//�ۿ۶���
double discount = 1;
double tempDiscount = 1;
//--------------------

//-------------------
//�����ⲿ����
extern char userCurrentName[50];
extern char adminCurrentName[50];
extern struct ClientNode* clientHead;
extern struct ClientNode* clientTail;
extern struct CommodityNode* commodityHead;
extern struct CommodityNode* commodityTail;
extern struct CartNode* cartHead;
extern struct CartNode* cartTail;
extern struct RecordNode* recordHead;
extern struct RecordNode* recordTail;
extern struct userRecordNode* userRecordHead;
extern struct userRecordNode* userRecordTail;
extern struct userRecordNode* userRecordHeadT;
extern struct userRecordNode* userRecordTailT;
extern struct userRecordNode* userRecordHeadC;
extern struct userRecordNode* userRecordTailC;
//--------------------

//��ΪһЩ�м����������
//------------
//�û���¼
char userLoginName[50];
char userLoginNameTmp[50];
char userLoginPwd[50];
char userLoginPwdTmp[50];
//����Ա��½
char adminLoginName[50];
char adminLoginNameTmp[50];
char adminLoginPwd[50];
char adminLoginPwdTmp[50];

//�û�ע��
char userSignupName[50];
char userSignupNameTmp[50];
char userSignupPwd1[50];
char userSignupPwd1Tmp[50];
char userSignupPwd2[50];
char userSignupPwd2Tmp[50];
char userIdentifyTmp[50];

//����
double MMONEY[31];
MOUSEMSG m;//���������� m
extern int auth;//�û���� Դͷ��main.cpp
extern int auth1;
extern int auth2;
extern HWND hWnd;//����api Դͷ��main.cpp
extern IMAGE background;
//------------

//--------------------
//ͼ����ʾ
void pict(void)
{
	putimage(-500, -500, &background);
	setbkmode(TRANSPARENT);
}
//--------------------

//--------------------
//��ʾ��½ϵͳ���
void xian(void)
{
	char temp[50];
	outtextxy(-240, -430, "��ǰʱ��:");
	int year, month, day;
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d��%d��%d��", year, month, day);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o�汾:1.0");
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(40, -400, 40, -440);
}
//backcolor 243 230 0
//--------------------

//--------------------
//��ʾ�û�ϵͳ���
void xianuser(void)
{
	int shenfen=0,i=0, year, month, day;
	char discountStr[50],BALANCE[50], LV[50],temp[50],temp1[50];
	struct ClientNode* nowClient = getClientPtrFromName(userCurrentName);
	shenfen = nowClient->isCostumer;
	strcpy_s(temp1, userCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(discountStr, "�ۿ�:%.2lf", discount);
	sprintf_s(temp, "%d��%d��%d��", year, month, day);
	sprintf_s(BALANCE, "�������:%.2lfԪ", nowClient->balance);
	sprintf_s(LV, "���ĵȼ�%d��", nowClient->lv);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-375, 200, -375, 240);
	line(375, 200, 375, 240);
	line(-375, 240, 375, 240);
	line(-250, 200, -250, 240);
	line(250, 200, 250, 240);
	line(250, -480, 250, -440);
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
	outtextxy(-365, -470, "��ǰ�û�:");
	outtextxy(-240, -430, "��ǰʱ��:");
	outtextxy(260, -470, discountStr);
	outtextxy(-240,210,BALANCE);
	outtextxy(110, 210, LV);
	outtextxy(-245, -470, temp1);
	outtextxy(-120, -430, temp);
	if (shenfen == 0)
	{
		outtextxy(45, -430, "o(^_^)o�û�����");
	}
	else
	{
		outtextxy(45, -430, "o(^_^)o����������");
	}
}
//backcolor 243 230 0
//--------------------

//--------------------
//��ʾ����Աϵͳ���
void xianadmin(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year=0, month=0, day=0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d��%d��%d��", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o����Ա���");
	outtextxy(-240, -430, "��ǰʱ��:");
	outtextxy(-365, -470, "��ǰ����Ա:");
	outtextxy(-235, -470, temp1);
	for (; i < 640; i=i+20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430  + i, 250, -440  + i);
		line(375, -440  + i , 250, -430 +  i);
	}
}
//backcolor 243 230 0
//--------------------

//--------------------
//��ʾ����Ա�鿴�û�ҳ����
void xianadminLookUser(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d��%d��%d��", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(-230, -340, 230, -340);
	line(-230, -240, 0, -240);
	line(0, -340, 50, -290);
	line(0, -240, 50, -290);
	line(0, -240, 50, -190);
	line(50, -290, 230, -290);
	line(50, -190, 230, -190);
	line(95, -176, 185, -176);
	line(95, -14, 185, -14);
	line(50, -95, 95, -176);
	line(50, -95, 95, -14);
	line(230, -95, 185, -176);
	line(230, -95, 185, -14);
	line(0,0,0,180);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o����Ա���");
	outtextxy(-240, -430, "��ǰʱ��:");
	outtextxy(-365, -470, "��ǰ����Ա:");
	outtextxy(-235, -470, temp1);
	outtextxy(-220, -370, "�û���:");
	outtextxy(-220, -300, "���:");
	outtextxy(50, -330,"�ȼ�:");
	outtextxy(50,-280,"���:");
	outtextxy(-210,-40,"���");
	outtextxy(-110, -40, "���");
	outtextxy(115,-85,"���");
	outtextxy(-210, 50, "��");
	outtextxy(-210, 90, "һ");
	outtextxy(-210, 130, "��");
	outtextxy(-140, 50, "��");
	outtextxy(-140, 90, "һ");
	outtextxy(-140, 130, "��");
	outtextxy(-70, 20, "ɾ");
	outtextxy(-70, 60, "��");
	outtextxy(-70, 100, "��");
	outtextxy(-70, 140, "��");
	outtextxy(45, 20, "��");
	outtextxy(45, 60, "��");
	outtextxy(45, 100, "һ");
	outtextxy(45, 140, "��");
	outtextxy(115, 20, "��");
	outtextxy(115, 60, "��");
	outtextxy(115, 100, "��");
	outtextxy(115, 140, "¼");
	outtextxy(185, 90, "��");
	outtextxy(185, 130, "��");
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------

//--------------------
//��ʾ����Ա�鿴�û�ҳ����
void xianadminLookUserG(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d��%d��%d��", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(-230, -340, 230, -340);
	line(-230, -240, 0, -240);
	line(0, -340, 50, -290);
	line(0, -240, 50, -290);
	line(0, -240, 50, -190);
	line(50, -290, 230, -290);
	line(50, -190, 230, -190);
	line(95, -176, 185, -176);
	line(95, -14, 185, -14);
	line(50, -95, 95, -176);
	line(50, -95, 95, -14);
	line(230, -95, 185, -176);
	line(230, -95, 185, -14);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o����Ա���");
	outtextxy(-240, -430, "��ǰʱ��:");
	outtextxy(-365, -470, "��ǰ����Ա:");
	outtextxy(-235, -470, temp1);
	outtextxy(-220, -370, "�û���:");
	outtextxy(-220, -300, "���:");
	outtextxy(50, -330, "�ȼ�:");
	outtextxy(50, -280, "���:");
	outtextxy(115, -85, "���");
	outtextxy(-25, 90, "����");
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------


//--------------------
//��ʾ����Ա�鿴��Ʒҳ����
void xianadminLookCommodity(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d��%d��%d��", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(0, 0, 0, 180);
	line(-230, -300, 100, -300);
	line(100, -300, 230, -380);
	line(100, -300, 100, -260);
	line(100, -260, 230, -260);
	line(-230, -220, 50, -220);
	line(50, -220, 100, -260);
	line(50, -220, 230, 0);
	line(50, -220, 50, 0);
	line(-110, -110, -10, -110);
	circle(-110,-110, 100);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o����Ա���");
	outtextxy(-240, -430, "��ǰʱ��:");
	outtextxy(-365, -470, "��ǰ����Ա:");
	outtextxy(-235, -470, temp1);
	outtextxy(-210, 50, "��");
	outtextxy(-210, 90, "һ");
	outtextxy(-210, 130, "��");
	outtextxy(-140, 50, "��");
	outtextxy(-140, 90, "һ");
	outtextxy(-140, 130, "��");
	outtextxy(-70, 20, "ɾ");
	outtextxy(-70, 60, "��");
	outtextxy(-70, 100, "��");
	outtextxy(-70, 140, "��");
	outtextxy(45, 20, "��");
	outtextxy(45, 60, "��");
	outtextxy(45, 100, "һ");
	outtextxy(45, 140, "��");
	outtextxy(115, 20, "��");
	outtextxy(115, 60, "��");
	outtextxy(115, 100, "��");
	outtextxy(115, 140, "¼");
	outtextxy(185, 90, "��");
	outtextxy(185, 130, "��");
	outtextxy(120, -290, "����");
	outtextxy(-220,-350,"��Ʒ����:");
	outtextxy(-220, -270, "ʣ����:");
	outtextxy(80,-210,"�ۼ�:");
	outtextxy(60, -130, "��");
	outtextxy(60,-90,"��");

	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------

//--------------------
//��ʾ����Ա�鿴��Ʒҳ����
void xianadminLookCommodityG(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d��%d��%d��", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(-230, -300, 100, -300);
	line(100, -300, 230, -380);
	line(100, -300, 100, -260);
	line(100, -260, 230, -260);
	line(-230, -220, 50, -220);
	line(50, -220, 100, -260);
	line(50, -220, 230, 0);
	line(50, -220, 50, 0);
	line(-110, -110, -10, -110);
	circle(-110, -110, 100);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o����Ա���");
	outtextxy(-240, -430, "��ǰʱ��:");
	outtextxy(-365, -470, "��ǰ����Ա:");
	outtextxy(-235, -470, temp1);
	outtextxy(-220, -350, "��Ʒ����:");
	outtextxy(-220, -270, "ʣ����:");
	outtextxy(80, -210, "�ۼ�:");
	outtextxy(60, -130, "��");
	outtextxy(60, -90, "��");
	outtextxy(-25, 90, "����");
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------


//--------------------
//��ʾ����Ա�鿴��¼��ҳ����
void xianadminLookRecord(void)
{
	
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d��%d��%d��", year, month, day);
	line(52, -200,230, -200);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(0, 0, 0, 180);
	line(-230, -340, 230, -340);
	line(50, -380, 50, -340);
	line(-230, -260, 50, -260);
	line(50, -340, 50, -260);
	line(50, -300, 230, -300);
	line(50, -260, 80, -240);
	line(80, -240, 230, -240);
	line(-230, -130, 0, -130);
	line(0, -130, 80, -240);
	line(0, -130, 0, 0);
	line(0, -130, 230, -130);
	outtextxy(-120, -430, temp);
	outtextxy(-220, -370, "�û���:");
	outtextxy(60,-370,"��ʷ�ȼ�:");
	outtextxy(-140, -330, "��Ʒ����:");
	outtextxy(60,-330,"����:");
	outtextxy(60,-280,"�ۼ�:");
	outtextxy(-140, -250, "��������:");
	outtextxy(-220, -120, "״̬:");
	outtextxy(80,-230,"�ۺ�:");
	outtextxy(80, -190, "���:");
	outtextxy(10,-120,"����ʱ��:");
	outtextxy(-210, 50, "��");
	outtextxy(-210, 90, "һ");
	outtextxy(-210, 130, "��");
	outtextxy(-140, 50, "��");
	outtextxy(-140, 90, "һ");
	outtextxy(-140, 130, "��");
	outtextxy(-70, 20, "ɾ");
	outtextxy(-70, 60, "��");
	outtextxy(-70, 100, "��");
	outtextxy(-70, 140, "��");
	outtextxy(45, 20, "��");
	outtextxy(45, 60, "��");
	outtextxy(45, 100, "��");
	outtextxy(45, 140, "��");
	outtextxy(115, 20, "��");
	outtextxy(115, 60, "��");
	outtextxy(115, 100, "��");
	outtextxy(115, 140, "Ʒ");
	outtextxy(185, 90, "��");
	outtextxy(185, 130, "��");
	outtextxy(45, -430, "o(^_^)o����Ա���");
	outtextxy(-240, -430, "��ǰʱ��:");
	outtextxy(-365, -470, "��ǰ����Ա:");
	outtextxy(-235, -470, temp1);
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------

//--------------------
//��ʾ����Ա������ҳ����
void xianzonglan(void)
{
	rectangle(-450, -450, 450, 450);
	rectangle(-400, -400, 400, 300);
}
//--------------------

//--------------------
//��¼ϵͳҳ��
void loginPage(void)
{
	char usernameTmpcpy[50];
	memset(usernameTmpcpy, 0, sizeof(usernameTmpcpy));
	int situation1=0;//״̬---�û���¼
	int situation2 = 0;//״̬---����Ա��½
	int situation3 = 0;//״̬---�û�ע��
	int identify = 0;
	int count = 0;//�����û����������

	//--------------------
	// �ַ����м����������
	int user_1=0, user_2=0;
	int _user_1 = 0, _user_2 = 0;
	int admin_1 = 0, admin_2 = 0;
	int _admin_1 = 0, _admin_2 = 0;
	int userl_1 = 0,userl_2=0, userl_3=0;
	int _userl_1 = 0, _userl_2 = 0, _userl_3 = 0;
	int _len_ = 0;
	//--------------------
	//����Ϊҳ��һ
	pict();
	while (TRUE)
	{
		/*��Ϊ��ʼ�ĵ�½����*/
		setcolor(BLACK);    //����������ɫ
		xian();//��½������
		outtextxy(-100, -300, "����ưɹ���ϵͳ");
		outtextxy(-50, -200, "�û���¼");
		outtextxy(-62.5, -100, "����Ա��¼");
		outtextxy(-50, 0, "�û�ע��");
		outtextxy(-25, 100, "�˳�");
		rectangle(-110, -310, 110, -270);//---�ⷽ��
		rectangle(-120, -320, 120, -260);
		m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
		//����ƶ����û���¼
		if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
		{
			setlinecolor(BLACK);
			rectangle(-60, -210, 60, -170);
			//������û���¼
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				count = 0;
				user_1 = 0, user_2 = 0;
				_user_1 = 0, _user_2 = 0;
				memset(usernameTmpcpy, 0, sizeof(usernameTmpcpy));
				memset(userCurrentName, 0, sizeof(userCurrentName));
				memset(userLoginName, 0, sizeof(userLoginName));
				memset(userLoginNameTmp, 0, sizeof(userLoginNameTmp));
				memset(userLoginPwd, 0, sizeof(userLoginPwd));
				memset(userLoginPwdTmp, 0, sizeof(userLoginPwdTmp));
				cleardevice(); pict();                                                                            //----------------------------�û���¼
				//ҳ�����1��
				while (TRUE)
				{
					setcolor(BLACK);
					xian();
					outtextxy(-100, -300, "����ưɹ���ϵͳ");
					outtextxy(130, -300, "(�û�)");
					outtextxy(-50, -200, "�����˺�");
					outtextxy(-62.5, -100, "����������");
					outtextxy(-50, 0, "���Ե�¼");
					outtextxy(-25, 100, "����");
					rectangle(-110, -310, 110, -270);
					rectangle(-120, -320, 120, -260);
					//�п�
					if (user_1 != 0)
					{
						outtextxy(150, -200, "_/");
					}
					//�п�
					if (user_2 != 0)
					{
						outtextxy(150, -100, "_/");
					}
					m = GetMouseMsg();
					//����ƶ��������˺�
					if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
					{
						setlinecolor(BLACK);
						rectangle(-60, -210, 60, -170);
						//����������˺�
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(userLoginNameTmp, 50, "��д���û��˺ţ�40λ����,��ֻ�����ַ������֣�",NULL, NULL, 0, 0, false);
							_user_1 = strnlen(userLoginNameTmp,sizeof(userLoginNameTmp));
							if (isStdInput(userLoginNameTmp)&&_user_1<=40)
							{
								strcpy_s(userLoginName, userLoginNameTmp);
								user_1 = strnlen_s(userLoginName, sizeof(userLoginName));
								if (strcmp(usernameTmpcpy, userLoginName) == 0)
								{
									;
								}
								else
								{
									count = 0;
									strcpy_s(usernameTmpcpy, userLoginName);
								}
							}
							else
							{
								MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
							}
						}
					}
                    //����ƶ�����������
					else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
					{
						setlinecolor(BLACK);
						rectangle(-72.5, -110, 72.5, -70);
						//�������������
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (getClientPtrFromName(userLoginName)==NULL)
							{
								InputBox(userLoginPwdTmp, 50, "��д���û����루40λ���ڣ���ֻ�����ַ������֣�",NULL, NULL, 0, 0, false);
								_user_2 = strnlen(userLoginPwdTmp, sizeof(userLoginPwdTmp));
								if (isStdInput(userLoginPwdTmp) && _user_2 <= 40)
								{
									strcpy_s(userLoginPwd, userLoginPwdTmp);
									user_2 = strnlen_s(userLoginPwd, sizeof(userLoginPwd));
								}
								else
								{
									MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
								}
							}
							else
							{
								if (getClientPtrFromName(userLoginName)->situation == 1)
								{
									MessageBox(hWnd, "��Ǹ,���ѱ����,�벦��13894980185��ϵ����Ա�Խ��", " ", MB_OKCANCEL);
								}
								else
								{
									InputBox(userLoginPwdTmp, 50, "��д���û����루40λ���ڣ���ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
									_user_2 = strnlen(userLoginPwdTmp, sizeof(userLoginPwdTmp));
									if (isStdInput(userLoginPwdTmp) && _user_2 <= 40)
									{
										strcpy_s(userLoginPwd, userLoginPwdTmp);
										user_2 = strnlen_s(userLoginPwd, sizeof(userLoginPwd));
									}
									else
									{
										MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
									}
								}
							}
						}
					}
					//����ƶ������Ե�¼
					else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
					{
						setlinecolor(BLACK);
						rectangle(-60, -10, 60, 30);
						//��������Ե�½
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							//�п�
							if (user_1 == 0 && user_2 != 0)
							{
								MessageBox(hWnd, "�������û��˺�", " ", MB_OKCANCEL);
							}
							//�п�
							else if (user_1 != 0 && user_2 == 0)
							{
								MessageBox(hWnd, "�������û�����", " ", MB_OKCANCEL);
							}
							//�п�
							else if (user_1 == 0 && user_2 == 0)
							{
								MessageBox(hWnd, "�������û��˺ź�����", " ", MB_OKCANCEL);
							}
							//��ʽ����
							else
							{
								if (getClientPtrFromName(userLoginName)==NULL)
								{
									situation1 = loginUser(userLoginName, userLoginPwd);
									if (situation1 == 1)
									{
										auth = 1;
										strcpy_s(userCurrentName, userLoginName);
										break;
									}
									else
									{
										count++;
										MessageBox(hWnd, "�û��˺Ż��������", " ", MB_OKCANCEL);
									}
								}
								else
								{
									if (getClientPtrFromName(userLoginName)->situation == 1)
									{
										MessageBox(hWnd, "��Ǹ,���ѱ����,�벦��13894980185��ϵ����Ա���", " ", MB_OKCANCEL);
									}
									else if ((getClientPtrFromName(userLoginName)->situation == 0) && count >= 5)
									{
										getClientPtrFromName(userLoginName)->situation = 1;
										rebuildClientFile(clientHead);
										MessageBox(hWnd, "��Ǹ,���ڲ���Ƶ�������ѱ�������벦��13894980185��ϵ����Ա���", " ", MB_OKCANCEL);
									}
									else
									{
										situation1 = loginUser(userLoginName, userLoginPwd);
										if (situation1 == 1)
										{
											auth = 1;
											strcpy_s(userCurrentName, userLoginName);
											break;
										}
										else
										{
											count++;
											MessageBox(hWnd, "�û��˺Ż��������", " ", MB_OKCANCEL);
										}
									}
								}
							}
						}
					}
					//����ƶ�������
					else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
					{
						setlinecolor(BLACK);
						rectangle(-35, 90, 35, 130);
						//���������
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					//����ƶ���������
					else
					{
						setlinecolor(WHITE);
						rectangle(-60, -210, 60, -170);
						rectangle(-72.5, -110, 72.5, -70);
						rectangle(-60, -10, 60, 30);
						rectangle(-35, 90, 35, 130);
					}

				}
			}
		}
		//����ƶ�������Ա��¼
		else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
		{
			setlinecolor(BLACK);
			rectangle(-72.5, -110, 72.5, -70);
			//���������Ա��¼
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				admin_1 = 0, admin_2 = 0;
				memset(adminCurrentName, 0, sizeof(adminCurrentName));
				memset(adminLoginName, 0, sizeof(adminLoginName));
				memset(adminLoginNameTmp, 0, sizeof(adminLoginNameTmp));
				memset(adminLoginPwd, 0, sizeof(adminLoginPwd));
				memset(adminLoginPwdTmp, 0, sizeof(adminLoginPwdTmp));
				cleardevice(); pict();                                                                            //----------------------------����Ա��¼
				//ҳ�����2��
				while (TRUE)
				{
					setcolor(BLACK);
					xian();
					outtextxy(-100, -300, "����ưɹ���ϵͳ");
					outtextxy(130, -300, "(����Ա)");
					rectangle(-110, -310, 110, -270);
					rectangle(-120, -320, 120, -260);
					outtextxy(-50, -200, "�����˺�");
					outtextxy(-62.5, -100, "����������"); 
					outtextxy(-50, 0, "���Ե�¼");
					outtextxy(-25, 100, "����");
					//�п�
					if (admin_1 != 0)
					{
						outtextxy(150, -200, "_/");
					}
					//�п�
					if (admin_2 != 0)
					{
						outtextxy(150, -100, "_/");
					}
					m = GetMouseMsg();
					//����ƶ����������Ա�˺�
					if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
					{
						setlinecolor(BLACK);
						rectangle(-60, -210, 60, -170);
						//������������Ա�˺�
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(adminLoginNameTmp, 50, "��д�����Ա�˺ţ�40λ���ڣ���ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
							_admin_1 = strnlen(adminLoginNameTmp, sizeof(adminLoginNameTmp));
							if (isStdInput(adminLoginNameTmp)&&_admin_1<=40)
							{
								strcpy_s(adminLoginName, adminLoginNameTmp);
								admin_1 = strnlen_s(adminLoginName, sizeof(adminLoginName));
							}
							else
							{
								MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
							}
						}
					}
					//����ƶ����������Ա����
					else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
					{
						setlinecolor(BLACK);
						rectangle(-72.5, -110, 72.5, -70);
						//������������Ա����
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(adminLoginPwdTmp, 50, "��д�����Ա���루40λ���ڣ���ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
							_admin_2 = strnlen(adminLoginPwdTmp, sizeof(adminLoginPwdTmp));
							if (isStdInput(adminLoginPwdTmp)&&_admin_2<=40)
							{
								strcpy_s(adminLoginPwd, adminLoginPwdTmp);
								admin_2 = strnlen_s(adminLoginPwd, sizeof(adminLoginPwd));
							}
							else
							{
								MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
							}
						}
					}
					//����ƶ������Ե�½
					else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
					{
						setlinecolor(BLACK);
						rectangle(-60, -10, 60, 30);
						//��������Ե�¼
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							//�п�
							if (admin_1==0&&admin_2!=0)
							{
								MessageBox(hWnd, "���������Ա�˺�", " ", MB_OKCANCEL);
							}
							//�п�
							else if (admin_1 != 0 && admin_2 == 0)
							{
								MessageBox(hWnd, "���������Ա����", " ", MB_OKCANCEL);
							}
							//�п�
							else if (admin_1 == 0 && admin_2 == 0)
							{
								MessageBox(hWnd, "���������Ա�˺ź�����", " ", MB_OKCANCEL);
							}
							//��ʽ����
							else
							{
								situation2 = loginAdmin(adminLoginName, adminLoginPwd);
								if (situation2 == 1)
								{
									auth = 2;
									strcpy_s(adminCurrentName, adminLoginName);
									break;
								}
								else
								{
									MessageBox(hWnd, "����Ա�˺Ż��������", " ", MB_OKCANCEL);
								}
							}
						}
					}
					//����ƶ�������
					else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
					{
						setlinecolor(BLACK);
						rectangle(-35, 90, 35, 130);
						//���������
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					//����ƶ���������
					else
					{
						setlinecolor(WHITE);
						rectangle(-60, -210, 60, -170);
						rectangle(-72.5, -110, 72.5, -70);
						rectangle(-60, -10, 60, 30);
						rectangle(-35, 90, 35, 130);
					}

				}
			}
		}
        //����ƶ����û�ע��
		else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
		{
			setlinecolor(BLACK);
			rectangle(-60, -10, 60, 30);
			//��������û�ע��
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				userl_1 = 0;
				userl_2 = 0;
				userl_3 = 0;//���ȳ�ʼ��
				identify = 0;
				_len_ = 0;
				memset(userSignupName, 0, sizeof(userSignupName));//���ַ�����Ϊ��
				memset(userSignupNameTmp, 0, sizeof(userSignupNameTmp));
				memset(userSignupPwd1, 0, sizeof(userSignupPwd1));
				memset(userSignupPwd1Tmp, 0, sizeof(userSignupPwd1Tmp));
				memset(userSignupPwd2, 0, sizeof(userSignupPwd2));
				memset(userSignupPwd2Tmp, 0, sizeof(userSignupPwd2Tmp));
				memset(userIdentifyTmp,0, sizeof(userIdentifyTmp));
				cleardevice(); pict();//�����һ����Ļ����                                                                                 //----------------------------�û�ע��
				//ҳ�����3��
				while (TRUE)
				{
					setcolor(BLACK);
					xian();
					outtextxy(-100, -300, "������ϲ�����˺�");
					outtextxy(-50, -200, "��������");
					outtextxy(-62.5, -100, "����������");
					outtextxy(-50, 0, "�ύע��");
					outtextxy(-25, 100, "����");
					//�пղ���
					if (userl_1 != 0)
					{
						outtextxy(150,-300,"_/");
					}
					//�пղ���
					if (userl_2 != 0)
					{
						outtextxy(150, -200, "_/");
					}
					//�пղ���
					if (userl_3 != 0)
					{
						outtextxy(150, -100, "_/");
					}
					m = GetMouseMsg();
					//����ƶ���---������ϲ�����˺�
					if (m.x >= 390 && m.x <= 610 && m.y >= 190 && m.y <= 230)
					{
						setlinecolor(BLACK);
						rectangle(-110, -310, 110, -270);
						//�����---������ϲ�����˺�
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(userSignupNameTmp, 50, "��д����ϲ�����˺ţ�14λ���ڣ���ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
							_userl_1 = strnlen_s(userSignupNameTmp,sizeof(userSignupNameTmp));
							if ((isStdInput(userSignupNameTmp)&&_userl_1<=14)||_userl_1==0)
							{
								strcpy_s(userSignupName, userSignupNameTmp);
								userl_1 = strnlen_s(userSignupName, sizeof(userSignupName));
							}
							else
							{
								MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
							}
						}
					}
					//����ƶ���---��������
					else if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
					{
						setlinecolor(BLACK);
						rectangle(-60, -210, 60, -170);
						//�����---��������
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(userSignupPwd1Tmp, 50, "��д�����루40λ���ڣ���ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
							_userl_2 = strnlen_s(userSignupPwd1Tmp, sizeof(userSignupPwd1Tmp));
							if (isStdInput(userSignupPwd1Tmp)&&_userl_2<=40)
							{
								strcpy_s(userSignupPwd1, userSignupPwd1Tmp);
								userl_2 = strnlen_s(userSignupPwd1, sizeof(userSignupPwd1));
							}
							else
							{
								MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
							}
						}
					}
					//����ƶ����ٴ���������
					else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
					{
						setlinecolor(BLACK);
						rectangle(-72.5, -110, 72.5, -70);
						//������ٴ���������
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(userSignupPwd2Tmp, 50, "���ٴ�д�����루40λ���ڣ���ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
							_userl_3 = strnlen_s(userSignupPwd2Tmp, sizeof(userSignupPwd2Tmp));
							if (isStdInput(userSignupPwd2Tmp)&&_userl_3<=40)
							{
								strcpy_s(userSignupPwd2, userSignupPwd2Tmp);
								userl_3 = strnlen_s(userSignupPwd2, sizeof(userSignupPwd2));
							}
							else
							{
								MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
							}
						}
					}
					//����ƶ����ύע��
					else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
					{
						setlinecolor(BLACK);
						rectangle(-60, -10, 60, 30);
						//������ύע��
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							//�п�
							if (userl_1 != 0 && userl_2 == 0 && userl_3 == 0)
							{
								MessageBox(hWnd, "�����������û�����", " ", MB_OKCANCEL);
							}
							//�п�
							else if (userl_1 == 0 && userl_2 != 0 && userl_3 == 0)
							{
								MessageBox(hWnd, "�������˺Ų��ٴ���������", " ", MB_OKCANCEL);
							}//�п�
							//�п�
							else if (userl_1 == 0 && userl_2 == 0 && userl_3 != 0)
							{
								MessageBox(hWnd, "�������˺ź�����", " ", MB_OKCANCEL);
							}
							//�п�
							else if (userl_1 == 0 && userl_2 != 0 && userl_3 != 0)
							{
								MessageBox(hWnd, "�������˺�", " ", MB_OKCANCEL);
							}
							//�п�
							else if (userl_1 != 0 && userl_2 == 0 && userl_3 != 0)
							{
								MessageBox(hWnd, "����������", " ", MB_OKCANCEL);
							}
							//�п�
							else if (userl_1 != 0 && userl_2 != 0 && userl_3 == 0)
							{
								MessageBox(hWnd, "���ٴ���������", " ", MB_OKCANCEL);
							}
							//�п�
							else if (userl_1 == 0 && userl_2 == 0 && userl_3 == 0)
							{
								MessageBox(hWnd, "�������˺Ų�������������", " ", MB_OKCANCEL);
							}
							//��ʽ����
							else 
							{
								if (MessageBox(hWnd, "�Ƿ��Ϊ������?\n���ȡ�������ͨ�û�\nע�⣬�����̵�ÿ����ͽ��׶�Ϊ100", "", MB_OKCANCEL) == IDOK)
								{
									identify = 1;
								}
								else
								{
									identify = 0;
								}
								situation3 = registerUser(userSignupName, userSignupPwd1, userSignupPwd2,identify);
								if (situation3 == -1)
								{
									MessageBox(hWnd, "�����������벻һ�£�������", " ", MB_OKCANCEL);
								}
								else if (situation3 == 0)
								{
									MessageBox(hWnd, "�û��Ѵ��ڣ������������˺�", " ", MB_OKCANCEL);
								}
								else
								{
									cleardevice(); pict();
									MessageBox(hWnd, "ע��ɹ������¼", " ", MB_OKCANCEL);
									break;
								}
							}
						}
					}
					//����ƶ�������
					else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
					{
						setlinecolor(BLACK);
						rectangle(-35, 90, 35, 130);
						//���������
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					//����ƶ�������֮��
					else
					{
						setlinecolor(WHITE);
						rectangle(-60, -210, 60, -170);
						rectangle(-72.5, -110, 72.5, -70);
						rectangle(-60, -10, 60, 30);
						rectangle(-35, 90, 35, 130);
						rectangle(-110, -310, 110, -270);
					}
				}
			}
		}
		//����ƶ����˳�
		else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(-35, 90, 35, 130);
			//������˳�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				/*
				MessageBox(hWnd, "��л����ʹ�� �ټ�", " ", MB_OKCANCEL);
				*/
				auth = 0;
			}
		}
		//����ƶ���������
		else
		{
			setlinecolor(WHITE);
			rectangle(-60, -210, 60, -170);
			rectangle(-72.5, -110, 72.5, -70);
			rectangle(-60, -10, 60, 30);
			rectangle(-35, 90, 35, 130);
		}
		//����Ϊ�˳�����---�û���ݿ�ʼ������ֵ
		if (auth == 0||auth==1||auth==2)
		{
			cleardevice(); pict();
			break;
		}
	}                         
}
//--------------------

//--------------------
//�û�ϵͳҳ��
void userPage(void)
{
	buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, userCurrentName);
	char ttemp[50], TempStr1[50], TempStr2[50], TempStr3[50], TempStr1_[50], TempStr2_[50], TempStr3_[50], targetMd5[50], originMd5[50], finalMd5[50], levelStandard[50], commodityName[50], chooseNumber[50], commodityName_[50], money[50], userCommodityName[50], TempStr1__[50], TempStr2__[50], TempStr3__[50], pwdTmp[50], changePwd[50], userNameMd5[50], idTmp_[50] = { 0 }, pwdTmp_[50] = { 0 }, userCurrentName_[50],tmpptr[50],userText[220];
	double tempNumSum = 0,soldPrice=0,soldPriceOrigin = 0,soldPriceDiscount = 0, userOriginMoneyTmp = 0, userFinalMoneyTmp = 0;
	int flag = 1,tempNumber1 = 0, tempNumber2 = 0, tempNumber3 = 0,_lengh_ = 0,_level_ = 0,count = 0,tempLevel = 0,unitCount,unitCount_ = 0,_chooseNumber_ = 0,yearTmp=0,monthTmp=0,dayTmp=0,userBuyNumber=0,pwdLen=0,fflag=0,lenText=0,year__=0,month__=0,day__=0;
	struct ClientNode* nowClient = getClientPtrFromName(userCurrentName);
	struct CartNode* temp=NULL;
	struct CartNode* qingkong = NULL;
	struct CommodityNode* tempCommodityPtr=NULL;
	struct CommodityNode* tempPtr = NULL;
	struct CartNode* tempPtr_ = NULL;
	struct userRecordNode* tempPtr__;
	tempPtr = commodityHead;
	cartHead = NULL;
	cartTail = NULL;
	discount = 1;
	if (nowClient->isCostumer == 0)
	{
		if (nowClient->lv == 0)
		{
			discount = 1;
		}
		else if (nowClient->lv == 1)
		{
			discount = 0.95;
		}
		else if (nowClient->lv == 2)
		{
			discount = 0.9;
		}
		else if (nowClient->lv == 3)
		{
			discount = 0.85;
		}
		else if (nowClient->lv == 4)
		{
			discount = 0.8;
		}
		else
		{
			discount = 0.75;
		}
	}
	else
	{
		if (nowClient->lv == 0)
		{
			discount = 1;
		}
		else if (nowClient->lv == 1)
		{
			discount = 0.9;
		}
		else if (nowClient->lv == 2)
		{
			discount = 0.85;
		}
		else if (nowClient->lv == 3)
		{
			discount = 0.8;
		}
		else if (nowClient->lv == 4)
		{
			discount = 0.75;
		}
		else
		{
			discount = 0.7;
		}
	}
	while (TRUE)
	{
		setcolor(BLACK);
		xianuser();
		outtextxy(-100, -300, "�鿴����������Ʒ");
		outtextxy(-50, -200, "������ʷ");
		outtextxy(-62.5, -100, "�鿴���ﳵ");
		outtextxy(-50, 0, "ע���˻�");
		outtextxy(-25, 100, "�˳�");
		outtextxy(-340, 210, "��ֵ");
		outtextxy(290, 210, "����");
		outtextxy(110, 100, "�޸�����");
		outtextxy(-210, 100, "�ύ����");
		//����ƶ���---�鿴����������Ʒ
		m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
		if (m.x >= 390 && m.x <= 610 && m.y >= 190 && m.y <= 230)
		{
			setlinecolor(BLACK);
			rectangle(-110, -310, 110, -270);
			//�����---�鿴����������Ʒ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				tempPtr = commodityHead;
				memset(chooseNumber, 0, sizeof(chooseNumber));
				_chooseNumber_ = 0;
				if (tempPtr == NULL)
				{
					MessageBox(hWnd, "������Ʒ����,������б�Ǹ", " ", MB_OKCANCEL);
				}
				else
				{
					cleardevice(); pict();
					while (TRUE)
					{
						setcolor(BLACK);
						xianuser();
						strcpy_s(commodityName, tempPtr->commodityName);
						soldPrice = tempPtr->soldPrice;
						unitCount = tempPtr->unitCount;
						if (unitCount <= 0)
						{
							strcpy_s(TempStr3, "��Ʒ����ȱ��״̬");
						}
						else
						{
							sprintf_s(TempStr3, "��Ʒʣ��:%d��", unitCount);
						}
						sprintf_s(TempStr1, "��Ʒ����:%s",commodityName);
						sprintf_s(TempStr2, "��Ʒ�۸�:%.2lfԪ", soldPrice);
						outtextxy(-100, -300,TempStr1);
						outtextxy(-100, -200, TempStr2);
						outtextxy(-100, -100, TempStr3);
						outtextxy(-200, 30, "��һ����Ʒ");
						outtextxy(-200, 90, "���뵽���ﳵ");
						outtextxy(50, 30, "��һ����Ʒ");
						outtextxy(50, 90, "���ص���ҳ");
						line(-230, 0, 230, 0);
						m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
						if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(-210, 20, -40, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr->preCommodity == NULL)
								{
									MessageBox(hWnd, "���ǵ�һ����Ʒ", " ", MB_OKCANCEL);
								}
								else
								{
									tempPtr = tempPtr->preCommodity;
								}
							}
						}
						else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(-210, 80, -40, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								InputBox(chooseNumber, 50, "����������Ҫ����Ʒ���������ν�������������10000", NULL, NULL, 0, 0, false);
								_chooseNumber_ = strnlen(chooseNumber, sizeof(chooseNumber));
								if (_chooseNumber_ == 0)
								{
									;
								}
								else
								{
									if (isFullDigit(chooseNumber) && _chooseNumber_ <= 5 && _chooseNumber_ > 0 && isStdInput(chooseNumber) && strToInt(chooseNumber) <= 10000 && strToInt(chooseNumber) > 0)
									{
										if (strToInt(chooseNumber) > unitCount)
										{
											MessageBox(hWnd, "��������Ʒ����,����������", " ", MB_OKCANCEL);
										}
										else
										{
											if (nowClient->isCostumer == 0)
											{
												addCart(&cartHead, &cartTail, tempPtr->soldPrice, strToInt(chooseNumber), tempPtr->commodityName,nowClient->lv);
												MessageBox(hWnd, "�ɹ����빺�ﳵ", " ", MB_OKCANCEL);
												cleardevice(); pict();
												putimage(-500, -500, &background);
												setbkmode(TRANSPARENT);
											}
											else
											{
												if (strToInt(chooseNumber) <100)
												{
													MessageBox(hWnd, "�����̹�������õ���100", " ", MB_OKCANCEL);
												}
												else
												{
													addCart(&cartHead, &cartTail, tempPtr->soldPrice, strToInt(chooseNumber), tempPtr->commodityName,nowClient->lv);
													MessageBox(hWnd, "�ɹ����빺�ﳵ", " ", MB_OKCANCEL);
													cleardevice(); pict();
												}
											}
										}
									}
									else
									{
										MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
									}
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(40, 20, 210, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr->nextCommodity == NULL)
								{
									MessageBox(hWnd, "�������һ����Ʒ", " ", MB_OKCANCEL);
								}

								else
								{
									tempPtr = tempPtr->nextCommodity;
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(40, 80, 210, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-210, 20, -40, 60);
							rectangle(-210, 80, -40, 120);
							rectangle(40, 20, 210, 60);
							rectangle(40, 80, 210, 120);
						}
					}
				}
			}
		}
		//����ƶ���---������ʷ
		else if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
		{
			setlinecolor(BLACK);
			rectangle(-60, -210, 60, -170);
			//�����---������ʷ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				tempPtr__ = userRecordHead;
				yearTmp = 0;
				monthTmp = 0;
				dayTmp = 0;
				userOriginMoneyTmp = 0;
				userFinalMoneyTmp = 0;
				userBuyNumber = 0;
				memset(userCommodityName, 0, sizeof(userCommodityName));
				memset(TempStr1__, 0, sizeof(TempStr1__));
				memset(TempStr1__, 0, sizeof(TempStr1__));
				memset(TempStr1__, 0, sizeof(TempStr1__));
			    LLLoop:
				if (tempPtr__==NULL)
				{
					MessageBox(hWnd, "���޹����¼", " ", MB_OKCANCEL);
				}
				else
				{
					cleardevice(); pict();
					while (TRUE)
					{
						setcolor(BLACK);
						xianuser();
						yearTmp = tempPtr__->ptr->year;
						monthTmp = tempPtr__->ptr->month;
						dayTmp = tempPtr__->ptr->day;
						userOriginMoneyTmp = tempPtr__->ptr->soldPrice;
						if (nowClient->isCostumer == 0)
						{
							if (tempPtr__->ptr->historyLv == 0)
							{
								tempDiscount = 1;
							}
							else if (tempPtr__->ptr->historyLv == 1)
							{
								tempDiscount = 0.95;
							}
							else if (tempPtr__->ptr->historyLv == 2)
							{
								tempDiscount = 0.9;
							}
							else if (tempPtr__->ptr->historyLv == 3)
							{
								tempDiscount = 0.85;
							}
							else if (tempPtr__->ptr->historyLv == 4)
							{
								tempDiscount = 0.8;
							}
							else
							{
								tempDiscount = 0.75;
							}
						}
						else
						{
							if (tempPtr__->ptr->historyLv == 0)
							{
								tempDiscount = 1;
							}
							else if (tempPtr__->ptr->historyLv == 1)
							{
								tempDiscount = 0.9;
							}
							else if (tempPtr__->ptr->historyLv == 2)
							{
								tempDiscount = 0.85;
							}
							else if (tempPtr__->ptr->historyLv == 3)
							{
								tempDiscount = 0.8;
							}
							else if (tempPtr__->ptr->historyLv == 4)
							{
								tempDiscount = 0.75;
							}
							else
							{
								tempDiscount = 0.7;
							}
						}
						userFinalMoneyTmp = userOriginMoneyTmp*tempDiscount;
						userBuyNumber = tempPtr__->ptr->unitCount;
						strcpy_s(userCommodityName,tempPtr__->ptr->commodityName);
						sprintf_s(TempStr1__, "��Ʒ����:%s", userCommodityName);
						if (userOriginMoneyTmp < 100 && userFinalMoneyTmp < 100)
						{
							sprintf_s(TempStr2__, "�ۼ�:%.2lfԪ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmp, userFinalMoneyTmp, userBuyNumber);
						}
						else if (userOriginMoneyTmp < 100 && userFinalMoneyTmp >= 100&& userFinalMoneyTmp<1000)
						{
							sprintf_s(TempStr2__, "�ۼ�:%.2lfԪ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmp, userFinalMoneyTmp/100, userBuyNumber);
						}
						else if (userOriginMoneyTmp < 100 && userFinalMoneyTmp >=1000)
						{
							sprintf_s(TempStr2__, "�ۼ�:%.2lfԪ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmp, userFinalMoneyTmp/1000, userBuyNumber);
						}
						else if (userOriginMoneyTmp >= 100&& userOriginMoneyTmp <1000&& userFinalMoneyTmp < 100)
						{
							sprintf_s(TempStr2__, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmp/100, userFinalMoneyTmp, userBuyNumber);
						}
						else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp >= 100 && userFinalMoneyTmp < 1000)
						{
							sprintf_s(TempStr2__, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmp/100, userFinalMoneyTmp/100, userBuyNumber);
						}
						else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp >=1000)
						{
							sprintf_s(TempStr2__, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmp/100, userFinalMoneyTmp/1000, userBuyNumber);
						}
						else if (userOriginMoneyTmp >=1000&& userFinalMoneyTmp < 100)
						{
							sprintf_s(TempStr2__, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmp/1000, userFinalMoneyTmp, userBuyNumber);
						}
						else if (userOriginMoneyTmp>=1000&& userFinalMoneyTmp >= 100&& userFinalMoneyTmp<1000)
						{
							sprintf_s(TempStr2__, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmp/1000, userFinalMoneyTmp/100, userBuyNumber);
						}
						else
						{
							sprintf_s(TempStr2__, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmp/1000, userFinalMoneyTmp/1000, userBuyNumber);
						}
						sprintf_s(TempStr3__, "%d��%d��%d��", yearTmp,monthTmp,dayTmp);
						outtextxy(-100, -300, TempStr1__);
						outtextxy(-220, -200, TempStr2__);
						outtextxy(-100, -100, TempStr3__);
						line(-230, 0, 230, 0);
						outtextxy(-200, 30, "��һ����Ʒ");
						outtextxy(-200, 90, "�����ۺ�");
						outtextxy(50, 30, "��һ����Ʒ");
						outtextxy(50, 90, "���ص���ҳ");
						if (tempPtr__->ptr->situation == 1)
						{
							outtextxy(-200, -40, "���ƽ�����Ա����");
						}
						else if (tempPtr__->ptr->situation == 2)
						{
							outtextxy(-200, -40, "������ɣ����˿�");
						}
						else
						{
							;
						}
						m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
						if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(-210, 20, -40, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr__->preRecord == NULL)
								{
									MessageBox(hWnd, "���ǵ�һ����¼", " ", MB_OKCANCEL);
								}
								else
								{
									tempPtr__ = tempPtr__->preRecord;
								}
							}
						}
						else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(-210, 80, -40, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (getCommodityPtrFromName(tempPtr__->ptr->commodityName))
								{
									if (tempPtr__->ptr->situation == 0)
									{
										tempPtr__->ptr->situation = 1;
										rebuildRecordFile(recordHead);
										MessageBox(hWnd, "��Ϊ�������Ա�ݽ����룬�����ĵȴ�", " ", MB_OKCANCEL);
										MessageBox(hWnd, "�����������⣬�벦��ͷ�����13894980185", " ", MB_OKCANCEL);
										cleardevice(); pict();
									}
									else if (tempPtr__->ptr->situation == 1)
									{
										MessageBox(hWnd, "����Ա���ڴ�����ϵ�绰13894980185", " ", MB_OKCANCEL);
									}
									else
									{
										MessageBox(hWnd, "�˿�����ɣ��޷����������ۺ�", " ", MB_OKCANCEL);
									}
								}
								else
								{
									MessageBox(hWnd, "��Ʒ���¼ܣ��޷����������ۺ�", " ", MB_OKCANCEL);
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(40, 20, 210, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr__->nextRecord == NULL)
								{
									MessageBox(hWnd, "�������һ����¼", " ", MB_OKCANCEL);
								}

								else
								{
									tempPtr__ = tempPtr__->nextRecord;
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(40, 80, 210, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-210, 20, -40, 60);
							rectangle(-210, 80, -40, 120);
							rectangle(40, 20, 210, 60);
							rectangle(40, 80, 210, 120);
						}
					}
				}
			}
		}
		//����ƶ����鿴���ﳵ
		else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
		{
			setlinecolor(BLACK);
			rectangle(-72.5, -110, 72.5, -70);
			//������鿴���ﳵ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(TempStr1_, 0, sizeof(TempStr1_));
				memset(TempStr2_, 0, sizeof(TempStr2_));
				memset(TempStr3_, 0, sizeof(TempStr3_));
				memset(commodityName_, 0, sizeof(commodityName_));
				unitCount_ = 0;
				soldPriceOrigin = 0;
				soldPriceDiscount = 0;
				tempPtr_ = cartHead;
				LLoop:
				if (tempPtr_ == NULL)
				{
					MessageBox(hWnd, "���ﳵ�ǿյ�", " ", MB_OKCANCEL);
				}
				else
				{
					cleardevice(); pict();
					while (TRUE)
					{
						setcolor(BLACK);
						xianuser();
						strcpy_s(commodityName_, tempPtr_->unitName);
						soldPriceOrigin = tempPtr_->soldPrice_Original;
						soldPriceDiscount = tempPtr_->soldPrice_Discount;
						unitCount_= tempPtr_->unitCount;
						sprintf_s(TempStr3_, "��Ʒ����:%d��", unitCount_);
						sprintf_s(TempStr1_, "��Ʒ����:%s", commodityName_);
						if (soldPriceOrigin < 100 && soldPriceDiscount < 100)
						{
							sprintf_s(TempStr2_, "ԭ��:%.2lfԪ ���ۺ�:%.2lfԪ", soldPriceOrigin, soldPriceDiscount);
						}
						else if (soldPriceOrigin < 100 && soldPriceDiscount >= 100 && soldPriceDiscount < 1000)
						{
							sprintf_s(TempStr2_, "ԭ��:%.2lfԪ ���ۺ�:%.2lf��Ԫ", soldPriceOrigin, soldPriceDiscount/100);
						}
						else if (soldPriceOrigin < 100 && soldPriceDiscount >= 1000)
						{
							sprintf_s(TempStr2_, "ԭ��:%.2lfԪ ���ۺ�:%.2lfǧԪ", soldPriceOrigin, soldPriceDiscount/1000);
						}
						else if (soldPriceOrigin >= 100 && soldPriceOrigin < 1000 && soldPriceDiscount < 100)
						{
							sprintf_s(TempStr2_, "ԭ��:%.2lf��Ԫ ���ۺ�:%.2lfԪ", soldPriceOrigin/100, soldPriceDiscount);
						}
						else if (soldPriceOrigin >= 100 && soldPriceOrigin < 1000 && soldPriceDiscount >= 100 && soldPriceDiscount < 1000)
						{
							sprintf_s(TempStr2_, "ԭ��:%.2lf��Ԫ ���ۺ�:%.2lf��Ԫ", soldPriceOrigin/100, soldPriceDiscount/100);
						}
						else if (soldPriceOrigin >= 100 && soldPriceOrigin < 1000 && soldPriceDiscount >= 1000)
						{
							sprintf_s(TempStr2_, "ԭ��:%.2lf��Ԫ ���ۺ�:%.2lfǧԪ", soldPriceOrigin/100, soldPriceDiscount/1000);
						}
						else if (soldPriceOrigin >= 1000 && soldPriceDiscount < 100)
						{
							sprintf_s(TempStr2_, "ԭ��:%.2lfǧԪ ���ۺ�:%.2lfԪ", soldPriceOrigin/1000, soldPriceDiscount);
						}
						else if (soldPriceOrigin >= 1000 && soldPriceDiscount >= 100 && soldPriceDiscount < 1000)
						{
							sprintf_s(TempStr2_, "ԭ��:%.2lfǧԪ ���ۺ�:%.2lf��Ԫ", soldPriceOrigin/1000, soldPriceDiscount/100);
						}
						else
						{
							sprintf_s(TempStr2_, "ԭ��:%.2lfǧԪ ���ۺ�:%.2lfǧԪ", soldPriceOrigin/1000, soldPriceDiscount/1000);
						}
						outtextxy(-100, -300, TempStr1_);
						outtextxy(-220, -200, TempStr2_);
						outtextxy(-100, -100, TempStr3_);
						line(-230, 0, 230, 0);
						outtextxy(-200, 30, "��һ����Ʒ");
						outtextxy(-200, 90, "�ӹ��ﳵ�Ƴ�");
						outtextxy(50, 30, "��һ����Ʒ");
						outtextxy(50, 90, "���ص���ҳ");
						outtextxy(-340, 210, "֧��");
						outtextxy(290, 210, "���");
						tempCommodityPtr = getCommodityPtrFromName(tempPtr_->unitName);
						m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
						if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(-210, 20, -40, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr_->preCart == NULL)
								{
									MessageBox(hWnd, "���ǵ�һ����Ʒ", " ", MB_OKCANCEL);
								}
								else
								{
									tempPtr_ = tempPtr_->preCart;
								}
							}
						}
						else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(-210, 80, -40, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								temp = tempPtr_;
								delCart(&cartHead, &cartTail, temp);
								tempPtr_ = cartHead;
								MessageBox(hWnd, "ɾ���ɹ�", " ", MB_OKCANCEL);
								cleardevice(); pict();
								goto LLoop;
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(40, 20, 210, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr_->nextCart == NULL)
								{
									MessageBox(hWnd, "�������һ����Ʒ", " ", MB_OKCANCEL);
								}

								else
								{
									tempPtr_ = tempPtr_->nextCart;
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(40, 80, 210, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else if (m.x >= 125 && m.x <= 250 && m.y >= 700 && m.y <= 740)
						{
							setlinecolor(BLACK);
							rectangle(-365, 205, -260, 235);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								memset(ttemp, 0, sizeof(ttemp));
								if ((tempPtr_->soldPrice_Discount > nowClient->balance) || (tempPtr_->unitCount > tempCommodityPtr->unitCount))
								{
									if (tempPtr_->soldPrice_Discount > nowClient->balance && !(tempPtr_->unitCount > tempCommodityPtr->unitCount))
									{
										MessageBox(hWnd, "����", " ", MB_OKCANCEL);
									}
									else if (!(tempPtr_->soldPrice_Discount > nowClient->balance) && tempPtr_->unitCount > tempCommodityPtr->unitCount)
									{
										MessageBox(hWnd, "��Ʒ��������", " ", MB_OKCANCEL);
									}
									else
									{
										MessageBox(hWnd, "���㲢����Ʒ��������", " ", MB_OKCANCEL);
									}

								}
								else
								{
									nowClient->balance = nowClient->balance - tempPtr_->soldPrice_Discount;
									rebuildClientFile(clientHead);
									tempCommodityPtr->unitCount = tempCommodityPtr->unitCount - tempPtr_->unitCount;
									rebuildCommodityFile(commodityHead);
									sprintf_s(ttemp, "%d", tempPtr_->unitCount);
									addRecord(&recordHead, &recordTail, '1', tempPtr_->unitName, nowClient->clientName, tempCommodityPtr->soldPrice, tempCommodityPtr->purchasePrice, ttemp, tempPtr_->historylv);
									rebuildRecordFile(recordHead);
									temp = tempPtr_;
									delCart(&cartHead, &cartTail, temp);
									tempPtr_ = cartHead;
									buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, userCurrentName);
									MessageBox(hWnd, "֧���ɹ�", " ", MB_OKCANCEL);
									cleardevice(); pict();
									goto LLoop;
								}
							}
						}
						else if (m.x >= 750 && m.x <= 875 && m.y >= 700 && m.y <= 740)
						{
							setlinecolor(BLACK);
							rectangle(260, 205, 365, 235);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								memset(tmpptr, 0, sizeof(tmpptr));
								memset(ttemp, 0, sizeof(ttemp));
								qingkong = NULL;
								flag = 1;
								qingkong = cartHead;
								tempNumSum = 0;
								while (qingkong)
								{
									if (qingkong->unitCount > getCommodityPtrFromName(qingkong->unitName)->unitCount)
									{
										flag = 0;
									}
									tempNumSum += qingkong->soldPrice_Discount;
									qingkong = qingkong->nextCart;
								}
								if ((nowClient->balance < tempNumSum) || flag == 0)
								{
									if (nowClient->balance < tempNumSum&&flag!=0)
									{
										MessageBox(hWnd, "����", " ", MB_OKCANCEL);
									}
									else if (!(nowClient->balance < tempNumSum) && flag == 0)
									{
										MessageBox(hWnd, "ĳ����Ʒ��治�㣬�޷���չ��ﳵ", " ", MB_OKCANCEL);
									}
									else
									{
										MessageBox(hWnd, tmpptr, " ", MB_OKCANCEL);
									}
								}
								else
								{
									qingkong = cartHead;
									while (qingkong)
									{
										if (getCommodityPtrFromName(qingkong->unitName)->unitCount <qingkong->unitCount)
										{
											sprintf_s(tmpptr, "%s��治�㣬�޷���չ��ﳵ",qingkong->unitName );
											MessageBox(hWnd, tmpptr, " ", MB_OKCANCEL);
											tempPtr_ = cartHead;
											buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, userCurrentName);
											goto LLoop;
										}
										else
										{
											getCommodityPtrFromName(qingkong->unitName)->unitCount = getCommodityPtrFromName(qingkong->unitName)->unitCount - qingkong->unitCount;
											rebuildCommodityFile(commodityHead);
										}
										nowClient->balance = nowClient->balance - qingkong->soldPrice_Discount;
										rebuildClientFile(clientHead);
										sprintf_s(ttemp, "%d", qingkong->unitCount);
										addRecord(&recordHead, &recordTail, '1', qingkong->unitName, nowClient->clientName, getCommodityPtrFromName(qingkong->unitName)->soldPrice, getCommodityPtrFromName(qingkong->unitName)->purchasePrice, ttemp, qingkong->historylv);
										rebuildRecordFile(recordHead);
										temp = qingkong;
										delCart(&cartHead, &cartTail, temp);
										qingkong= cartHead;
									}
									buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, userCurrentName);
									MessageBox(hWnd, "�ɹ���չ��ﳵ", " ", MB_OKCANCEL);
									cleardevice(); pict();
									tempPtr_ = cartHead;
									goto LLoop;
								}
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(260, 205, 365, 235);
							rectangle(-365, 205, -260, 235);
							rectangle(-210, 20, -40, 60);
							rectangle(-210, 80, -40, 120);
							rectangle(40, 20, 210, 60);
							rectangle(40, 80, 210, 120);
						}
					}
				}
			}
		}
		//����ƶ���ע���˻�
		else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
		{
			setlinecolor(BLACK);
			rectangle(-60, -10, 60, 30);
			//�����ע���˻�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(userCurrentName, 0, sizeof(userCurrentName));
				memset(userLoginName, 0, sizeof(userLoginName));
				memset(userLoginNameTmp, 0, sizeof(userLoginNameTmp));
				memset(userLoginPwd, 0, sizeof(userLoginPwd));
				memset(userLoginPwdTmp, 0, sizeof(userLoginPwdTmp));
				auth1 = 0;
			}
		}
		//����ƶ����˳�
		else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(-35, 90, 35, 130);
			//������˳�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				auth1 = 1;
			}
		}
		////����ƶ�����ֵ
		else if (m.x >= 125 && m.x <= 250 && m.y >= 700 && m.y <= 740)
		{
			setlinecolor(BLACK);
			rectangle(-365,205, -260, 235 );
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice(); pict();
				_lengh_ = 0;
				memset(originMd5, 0, sizeof(originMd5));
				memset(targetMd5, 0, sizeof(targetMd5));
				memset(finalMd5, 0, sizeof(finalMd5));
				memset(money, 0, sizeof(money));
				tempNumber1 = 0;
				tempNumber2 = 0;
				tempNumber3 = 0;
				count = 0;
				tempNumber1 = rand() % 10;
				tempNumber2 = rand() % 10;
				tempNumber3 = rand() % 10;
				sprintf_s(originMd5, 50, "jnfcu%dombhf%dplkhg%d", tempNumber1, tempNumber2, tempNumber3);
				MD5Function((unsigned char*)originMd5, targetMd5);
				InputBox(money, 50, "��д���ֵǮ����ֻ��Ϊ���������γ�ֵ������10000Ԫ", NULL, NULL, 0, 0, false);
				_lengh_ = strnlen_s(money, sizeof(money));
				if (_lengh_ == 0)
				{
					;
				}
				else
				{
					if (isFullDigit(money) && _lengh_ <= 5 && _lengh_ > 0 && isStdInput(money) && strToInt(money) <= 10000 && strToInt(money) > 0)
					{
						MessageBox(hWnd, "������Ϊ�����ṩ���������Ժ�", " ", MB_OKCANCEL);
						for (; count < strToInt(money); count++)
						{
							MD5Function((unsigned char*)targetMd5, targetMd5);
						}
						sprintf_s(finalMd5, "����������%s", targetMd5);
						MessageBox(hWnd, finalMd5, " ", MB_OKCANCEL);
						nowClient->balance = nowClient->balance + strToInt(money);
						rebuildClientFile(clientHead);
						MessageBox(hWnd, "��ϲ������ֵ�ɹ�", " ", MB_OKCANCEL);
					}
					else
					{
						MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
					}
				}
				cleardevice(); pict();

			}
		}
		//����ƶ�������
		else if (m.x >= 750 && m.x <= 875 && m.y >= 700 && m.y <= 740)
		{
			setlinecolor(BLACK);
			rectangle(260,205,365,235 );
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice(); pict();
				tempLevel = 0;
				_level_ = 0;
				memset(levelStandard, 0, sizeof(levelStandard));
				tempLevel = nowClient->lv;
				if (tempLevel == 0)
				{
					if (MessageBox(hWnd, "�Ƿ�������1��", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "����", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "�����ɹ�", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				}
				else if (tempLevel == 1)
				{
					if (MessageBox(hWnd, "�Ǵ�1��������2��", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "����", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "�����ɹ�", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				}
				else if (tempLevel == 2)
				{
					if (MessageBox(hWnd, "�Ƿ��2��������3��", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "����", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "�����ɹ�", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				}
				else if (tempLevel == 3)
				{
					
					if (MessageBox(hWnd, "�Ƿ���3��������4��", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "����", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "�����ɹ�", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				
				}
				else if (tempLevel == 4)
				{
					if (MessageBox(hWnd, "�Ƿ��4��������5��", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "����", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "�����ɹ�", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				}
				else
				{
					MessageBox(hWnd, "��������", " ", MB_OKCANCEL);
				}
				if (nowClient->isCostumer == 0)
				{
					if (nowClient->lv == 0)
					{
						discount = 1;
					}
					else if (nowClient->lv == 1)
					{
						discount = 0.95;
					}
					else if (nowClient->lv == 2)
					{
						discount = 0.9;
					}
					else if (nowClient->lv == 3)
					{
						discount = 0.85;
					}
					else if (nowClient->lv == 4)
					{
						discount = 0.8;
					}
					else
					{
						discount = 0.75;
					}
				}
				else
				{
					if (nowClient->lv == 0)
					{
						discount = 1;
					}
					else if (nowClient->lv == 1)
					{
						discount = 0.9;
					}
					else if (nowClient->lv == 2)
					{
						discount = 0.85;
					}
					else if (nowClient->lv == 3)
					{
						discount = 0.8;
					}
					else if (nowClient->lv == 4)
					{
						discount = 0.75;
					}
					else
					{
						discount = 0.7;
					}
				}
			}
		}
		//����ƶ����޸�����
		else if (m.x >= 600 && m.x <= 720 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(100, 90, 220, 130);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				fflag = 0;
				memset(pwdTmp, 0, sizeof(pwdTmp));
				memset(changePwd, 0, sizeof(changePwd));
				memset(userNameMd5, 0, sizeof(userNameMd5));
				memset(idTmp_, 0, sizeof(idTmp_));
				memset(pwdTmp_, 0, sizeof(pwdTmp_));
				strcpy_s(userCurrentName_, userCurrentName);
				MD5Function((unsigned char*)userCurrentName_, userNameMd5);
				pwdLen = 0;
				InputBox(pwdTmp, 50, "��д���û����루40λ���ڣ���ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
				pwdLen = strnlen(pwdTmp, sizeof(pwdTmp));
				if (isStdInput(pwdTmp) && pwdLen <= 40)
				{
					strcpy_s(changePwd, pwdTmp);
					MD5Function((unsigned char*)changePwd, changePwd);
					if (pwdLen == 0)
					{
						;
					}
					else
					{
						FILE* fp, * fp1;
						fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "r");
						fopen_s(&fp1, ".\\Data\\loginData\\operationTmpData.txt", "w");
						if ((fp != NULL) && (fp1 != NULL))
						{
							while (fscanf_s(fp, "%s %s\n", idTmp_, 50, pwdTmp_, 50) != EOF)
							{ // ѭ����ȡ�ļ��е����ݣ�ֱ���ļ�ĩ
								if (strcmp(idTmp_, userNameMd5) == 0)
								{ // ���������˺ź��������ļ��е�����ƥ�䣬�����ñ�־Ϊ1��������ѭ��
									if (strcmp(pwdTmp_, changePwd) == 0)
									{
										MessageBox(hWnd, "�¾����벻����ͬ", " ", MB_OKCANCEL);
										fflag = 1;
										break;
									}
									else
									{
										fprintf_s(fp1, "%s %s\n", idTmp_, changePwd);
									}
								}
								else
								{
								fprintf_s(fp1, "%s %s\n", idTmp_, pwdTmp_);
								}
							}
							fclose(fp); fclose(fp1);
						}
						fp = NULL; fp1 = NULL;
						if (fflag == 0)
						{
							fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "w");
							fopen_s(&fp1, ".\\Data\\loginData\\operationTmpData.txt", "r");
							if ((fp != NULL) && (fp1 != NULL))
							{
								while (fscanf_s(fp1, "%s %s\n", idTmp_, 50, pwdTmp_, 50) != EOF)
								{ // ѭ����ȡ�ļ��е����ݣ�ֱ���ļ�ĩ
									fprintf_s(fp, "%s %s\n", idTmp_, pwdTmp_);
								}
								fclose(fp); fclose(fp1);
							}
							fp = NULL; fp1 = NULL;
							MessageBox(hWnd, "�����޸ĳɹ�,�����µ�¼", " ", MB_OKCANCEL);
							memset(userCurrentName, 0, sizeof(userCurrentName));
							memset(userLoginName, 0, sizeof(userLoginName));
							memset(userLoginNameTmp, 0, sizeof(userLoginNameTmp));
							memset(userLoginPwd, 0, sizeof(userLoginPwd));
							memset(userLoginPwdTmp, 0, sizeof(userLoginPwdTmp));
							auth1 = 0;
						}
						else
						{
							;
						}
					}
				}
				else
				{
					MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
				}
			}
		}
		//����ƶ����ύ����
		else if (m.x >= 280 && m.x <= 400 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(-220, 90, -100, 130);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				year__ = 0, month__ = 0, day__ = 0;
				getCurrentTime(&year__, &month__, &day__);
				memset(userText, 0, sizeof(userText));
				InputBox(userText, 200, "�˹��������ɹ���Ա��������д��������󣬰�����Ķ�����Ϣ�Լ���ϵ��ʽ(100������)",NULL,NULL,300,400,false);
				lenText = strnlen_s(userText, sizeof(userText));
				if (lenText == 0)
				{
					;
				}
				else
				{
					FILE* feedback;
					fopen_s(&feedback, ".\\Data\\RecordChainData\\feedback.txt", "a+");
					if (feedback)
					{
						fprintf(feedback, "%s\n", nowClient->clientName);
						fprintf(feedback, "%d_%d_%d\n", year__, month__, day__);
						fprintf(feedback, "%s\n", userText);
						fprintf(feedback, "%s\n", "--------------------------------------------------------------------------------------------");
						fclose(feedback);
						feedback = NULL;
					}
					MessageBox(hWnd, "�����ύ�ɹ�", " ", MB_OKCANCEL);
				}
			}
		}
		//����ƶ�������֮��
		else
		{
			setlinecolor(WHITE);
			rectangle(-365, 205, -260, 235);
			rectangle(260, 205, 365, 235);
			rectangle(-60, -210, 60, -170);
			rectangle(-72.5, -110, 72.5, -70);
			rectangle(-60, -10, 60, 30);
			rectangle(-35, 90, 35, 130);
			rectangle(-110, -310, 110, -270);
			rectangle(100, 90, 220, 130);
			rectangle(-220, 90, -100, 130);
		}
		if (auth1 == 0 || auth1 == 1)
		{
			cleardevice(); pict();
			break;
		}
	}
}
//--------------------

//--------------------
//����Աϵͳҳ��
void adminPage(void)
{
	char str1[50], str2[50], str3[50], str4[50], str5[50], str6[50], str7[50], str8[50], str9[50], idTmp_[50], pwdTmp_[50], userNameMd5[50], userCommodityName[50], userCommodityNameT[50], str10[50], str11[50], str12[50], TEXTtmp[220], TEXT[10000], str13[50], str14[50], str15[50], str16[50], SumNumber[50], tempZB[50], str17[50], str18[50], str19[50], str20[50], str21[50], str22[50], str23[50], str24[50], str25[50], str26[50], str27[50], str28[50],PROFILE[50],TIME[50],str29[50],str30[50],str31[50],STR1[50],STR2[50],STR3[50];
	int yearTmp1=0, monthTmp1=0, dayTmp1=0, yearTmp2 = 0,monthTmp2 = 0,dayTmp2 = 0,userBuyNumber = 0, yearTmp3 = 0,monthTmp3 = 0,dayTmp3 = 0, userBuyNumberT = 0,_sum=0,userBuyNumber1 = 0,YEAR=0,MONTH=0,DAY=0;
	//--------------------
	int userl_1 = 0,userl_2 = 0,userl_3 = 0,identify = 0,_len_ = 0, _userl_1 = 0, _userl_2 = 0, _userl_3 = 0,situationTmp=0,i=0,ii=0,iii=0,iiii=0,judgeNum=0;
	int Xuserl_1 = 0, Xuserl_2 = 0, Xuserl_3 = 0, Xidentify = 0, X_len_ = 0, X_userl_1 = 0, X_userl_2 = 0, X_userl_3 = 0, XsituationTmp = 0;
	//--------------------
	double userOriginMoneyTmp = 0, userFinalMoneyTmp = 0, userOriginMoneyTmpT = 0, userFinalMoneyTmpT = 0, M = 0, N = 0, userOriginMoneyTmp1 = 0, userFinalMoneyTmp1 = 0,profile=0,tempPoint=0;
	double k = 0, b = 0;
	struct ClientNode* ptr1=NULL;
	struct userRecordNode* ptr2 = NULL;
	struct userRecordNode* ptr3 = NULL;
	struct CommodityNode* ptr4 = NULL;
	struct userRecordNode* ptr5 = NULL;
	struct RecordNode* ptr6 = NULL;
	struct ClientNode* ptr7=NULL;
	struct CommodityNode* ptr8=NULL,*judge = NULL;
	struct ClientNode* ptr9 = NULL,*ptr10=NULL;
	struct RecordNode* temp = NULL, * calculate = NULL, * calculate1 = NULL;
	while (TRUE)
	{
		setcolor(BLACK);
		xianadmin();
		outtextxy(-100, -300, "����Ա--�����ն�");
		outtextxy(-150, -200, "�鿴�ͻ�");
		outtextxy(50, -200, "�鿴��Ʒ");
		outtextxy(-150, -100, "���ۼ�¼");
		outtextxy(50, -100, "�˻�����");
		outtextxy(-150, 0, "����ҳ��");
		outtextxy(50, 0, "������ҳ");
		outtextxy(-150, 100, "�鿴����");
		outtextxy(50, 100, "�˳�����");
		rectangle(-110, -310, 110, -270);//---�ⷽ��
		rectangle(-120, -320, 120, -260);
		m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
		//����ƶ����鿴�ͻ�
		if (m.x >= 340 && m.x <= 460 && m.y >= 290 && m.y <= 330)
		{
			setlinecolor(BLACK);
			rectangle(-160, -210, -40, -170);
			//������鿴�ͻ�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
			loop1:
				memset(str1, 0, sizeof(str1));
				memset(str2, 0, sizeof(str2));
				memset(str3, 0, sizeof(str3));
				ptr1 = clientHead;
				if (ptr1 == NULL)
				{
					MessageBox(hWnd, "�����û�", " ", MB_OKCANCEL);
				}
				else
				{ 
				cleardevice(); pict();
				while (TRUE)
				{
					sprintf_s(str1, "%s", ptr1->clientName);
					sprintf_s(str2, "%d��", ptr1->lv);
					sprintf_s(str3, "%.2lfԪ", ptr1->balance);
					sprintf_s(str4, "%d��", ptr1->year);
					sprintf_s(str5, "%d��", ptr1->month);
					sprintf_s(str6, "%d��", ptr1->day);
					setcolor(BLACK);
					xianadminLookUser();
					outtextxy(-120, -370, str1);
					outtextxy(115, -330, str2);
					outtextxy(-145, -300, str3);
					outtextxy(-120, -210, "ע������");
					outtextxy(-120, -170, str4);
					outtextxy(-120, -130, str5);
					outtextxy(-120, -90, str6);
					outtextxy(-25, -40, "��ѯ");
					if (ptr1->isCostumer == 0)
					{
						outtextxy(125, -280, "�û�");
					}
					else
					{
						outtextxy(125, -280, "������");
					}
					if (ptr1->situation == 0)
					{
						outtextxy(115, -125, "δ��");
					}
					else
					{
						outtextxy(115, -125, "�ѱ�");
					}
					m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
					if (m.x >= 280 && m.x <= 325 && m.y >= 540 && m.y <= 660)
					{
						setlinecolor(BLACK);
						rectangle(-220, 40, -175, 160);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (ptr1->preClient == NULL)
							{
								MessageBox(hWnd, "���ǵ�һ���û�", " ", MB_OKCANCEL);
							}
							else
							{
								ptr1 = ptr1->preClient;
							}
							cleardevice(); pict();
						}
					}
					else if (m.x >= 350 && m.x <= 395 && m.y >= 540 && m.y <= 660)
					{
						setlinecolor(BLACK);
						rectangle(-150, 40, -105, 160);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (ptr1->nextClient == NULL)
							{
								MessageBox(hWnd, "�������һ���û�", " ", MB_OKCANCEL);
							}
							else
							{
								ptr1 = ptr1->nextClient;
							}
							cleardevice(); pict();
						}
					}
					else if (m.x >= 420 && m.x <= 465 && m.y >= 510 && m.y <= 670)
					{
						setlinecolor(BLACK);
						rectangle(-80, 10, -35, 170);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							MD5Function((unsigned char*)(ptr1->clientName), userNameMd5);
							FILE* fp, * fp1;
							fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "r");
							fopen_s(&fp1, ".\\Data\\loginData\\operationTmpData.txt", "w");
							if ((fp != NULL) && (fp1 != NULL))
							{
								while (fscanf_s(fp, "%s %s\n", idTmp_, 50, pwdTmp_, 50) != EOF)
								{ // ѭ����ȡ�ļ��е����ݣ�ֱ���ļ�ĩ
									if (strcmp(idTmp_, userNameMd5) == 0)
									{ // ���������˺ź��������ļ��е�����ƥ�䣬�����ñ�־Ϊ1��������ѭ��
										;
									}
									else
									{
										fprintf_s(fp1, "%s %s\n", idTmp_, pwdTmp_);
									}
								}
								fclose(fp); fclose(fp1);
							}
							fp = NULL; fp1 = NULL;
							fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "w");
							fopen_s(&fp1, ".\\Data\\loginData\\operationTmpData.txt", "r");
							if ((fp != NULL) && (fp1 != NULL))
							{
								while (fscanf_s(fp1, "%s %s\n", idTmp_, 50, pwdTmp_, 50) != EOF)
								{ // ѭ����ȡ�ļ��е����ݣ�ֱ���ļ�ĩ
									fprintf_s(fp, "%s %s\n", idTmp_, pwdTmp_);
								}
								fclose(fp); fclose(fp1);
							}
							fp = NULL; fp1 = NULL;
							delClient(&clientHead, &clientTail, ptr1);
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "ɾ���ɹ�", " ", MB_OKCANCEL);
							cleardevice(); pict();
							goto loop1;
						}
					}
					else if (m.x >= 535 && m.x <= 580 && m.y >= 510 && m.y <= 670)
					{
						setlinecolor(BLACK);
						rectangle(35, 10, 80, 170);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							userl_1 = 0;
							userl_2 = 0;
							userl_3 = 0;//���ȳ�ʼ��
							identify = 0;
							_len_ = 0;
							memset(userSignupName, 0, sizeof(userSignupName));//���ַ�����Ϊ��
							memset(userSignupNameTmp, 0, sizeof(userSignupNameTmp));
							memset(userSignupPwd1, 0, sizeof(userSignupPwd1));
							memset(userSignupPwd1Tmp, 0, sizeof(userSignupPwd1Tmp));
							memset(userSignupPwd2, 0, sizeof(userSignupPwd2));
							memset(userSignupPwd2Tmp, 0, sizeof(userSignupPwd2Tmp));
							memset(userIdentifyTmp, 0, sizeof(userIdentifyTmp));
							cleardevice(); pict();
							while (TRUE)
							{
								setcolor(BLACK);
								xianadmin();
								outtextxy(-100, -300, "������ϲ�����˺�");
								outtextxy(-50, -200, "��������");
								outtextxy(-62.5, -100, "����������");
								outtextxy(-50, 0, "����û�");
								outtextxy(-25, 100, "����");
								//�пղ���
								if (userl_1 != 0)
								{
									outtextxy(150, -300, "_/");
								}
								//�пղ���
								if (userl_2 != 0)
								{
									outtextxy(150, -200, "_/");
								}
								//�пղ���
								if (userl_3 != 0)
								{
									outtextxy(150, -100, "_/");
								}
								m = GetMouseMsg();
								//����ƶ���---������ϲ�����˺�
								if (m.x >= 390 && m.x <= 610 && m.y >= 190 && m.y <= 230)
								{
									setlinecolor(BLACK);
									rectangle(-110, -310, 110, -270);
									//�����---������ϲ�����˺�
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										InputBox(userSignupNameTmp, 50, "��д����ϲ�����˺ţ�14λ���ڣ���ֻ�����ַ�������,��һλ�������ַ���", NULL, NULL, 0, 0, false);
										_userl_1 = strnlen_s(userSignupNameTmp, sizeof(userSignupNameTmp));
										if ((isStdInput(userSignupNameTmp) && _userl_1 <= 14 && isCharacter(userSignupNameTmp[0])) || _userl_1 == 0)
										{
											strcpy_s(userSignupName, userSignupNameTmp);
											userl_1 = strnlen_s(userSignupName, sizeof(userSignupName));
										}
										else
										{
											MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
										}
									}
								}
								//����ƶ���---��������
								else if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
								{
									setlinecolor(BLACK);
									rectangle(-60, -210, 60, -170);
									//�����---��������
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										InputBox(userSignupPwd1Tmp, 50, "��д�����루40λ���ڣ���ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
										_userl_2 = strnlen_s(userSignupPwd1Tmp, sizeof(userSignupPwd1Tmp));
										if (isStdInput(userSignupPwd1Tmp) && _userl_2 <= 40)
										{
											strcpy_s(userSignupPwd1, userSignupPwd1Tmp);
											userl_2 = strnlen_s(userSignupPwd1, sizeof(userSignupPwd1));
										}
										else
										{
											MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
										}
									}
								}
								//����ƶ����ٴ���������
								else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
								{
									setlinecolor(BLACK);
									rectangle(-72.5, -110, 72.5, -70);
									//������ٴ���������
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										InputBox(userSignupPwd2Tmp, 50, "���ٴ�д�����루40λ���ڣ���ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
										_userl_3 = strnlen_s(userSignupPwd2Tmp, sizeof(userSignupPwd2Tmp));
										if (isStdInput(userSignupPwd2Tmp) && _userl_3 <= 40)
										{
											strcpy_s(userSignupPwd2, userSignupPwd2Tmp);
											userl_3 = strnlen_s(userSignupPwd2, sizeof(userSignupPwd2));
										}
										else
										{
											MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
										}
									}
								}
								//����ƶ����ύע��
								else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
								{
									setlinecolor(BLACK);
									rectangle(-60, -10, 60, 30);
									//������ύע��
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										//�п�
										if (userl_1 != 0 && userl_2 == 0 && userl_3 == 0)
										{
											MessageBox(hWnd, "�����������û�����", " ", MB_OKCANCEL);
										}
										//�п�
										else if (userl_1 == 0 && userl_2 != 0 && userl_3 == 0)
										{
											MessageBox(hWnd, "�������˺Ų��ٴ���������", " ", MB_OKCANCEL);
										}//�п�
										//�п�
										else if (userl_1 == 0 && userl_2 == 0 && userl_3 != 0)
										{
											MessageBox(hWnd, "�������˺ź�����", " ", MB_OKCANCEL);
										}
										//�п�
										else if (userl_1 == 0 && userl_2 != 0 && userl_3 != 0)
										{
											MessageBox(hWnd, "�������˺�", " ", MB_OKCANCEL);
										}
										//�п�
										else if (userl_1 != 0 && userl_2 == 0 && userl_3 != 0)
										{
											MessageBox(hWnd, "����������", " ", MB_OKCANCEL);
										}
										//�п�
										else if (userl_1 != 0 && userl_2 != 0 && userl_3 == 0)
										{
											MessageBox(hWnd, "���ٴ���������", " ", MB_OKCANCEL);
										}
										//�п�
										else if (userl_1 == 0 && userl_2 == 0 && userl_3 == 0)
										{
											MessageBox(hWnd, "�������˺Ų�������������", " ", MB_OKCANCEL);
										}
										//��ʽ����
										else
										{
											if (MessageBox(hWnd, "�Ƿ��Ϊ������?\n���ȡ�������ͨ�û�\nע�⣬�����̵�ÿ����ͽ��׶�Ϊ100", "", MB_OKCANCEL) == IDOK)
											{
												identify = 1;
											}
											else
											{
												identify = 0;
											}
											situationTmp = registerUser(userSignupName, userSignupPwd1, userSignupPwd2, identify);
											if (situationTmp == -1)
											{
												MessageBox(hWnd, "�����������벻һ�£�������", " ", MB_OKCANCEL);
											}
											else if (situationTmp == 0)
											{
												MessageBox(hWnd, "�û��Ѵ��ڣ������������˺�", " ", MB_OKCANCEL);
											}
											else
											{
												cleardevice(); pict();
												MessageBox(hWnd, "��ӳɹ�", " ", MB_OKCANCEL);
												goto loop1;
											}
										}
									}
								}
								//����ƶ�������
								else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
								{
									setlinecolor(BLACK);
									rectangle(-35, 90, 35, 130);
									//���������
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										cleardevice(); pict();
										break;
									}
								}
								//����ƶ�������֮��
								else
								{
									setlinecolor(WHITE);
									rectangle(-60, -210, 60, -170);
									rectangle(-72.5, -110, 72.5, -70);
									rectangle(-60, -10, 60, 30);
									rectangle(-35, 90, 35, 130);
									rectangle(-110, -310, 110, -270);
								}
							}

						}
					}
					else if (m.x >= 605 && m.x <= 650 && m.y >= 510 && m.y <= 670)
					{
						setlinecolor(BLACK);
						rectangle(105, 10, 150, 170);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
						loop2:
							cleardevice(); pict();
							buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, ptr1->clientName);
							memset(userCommodityName, 0, sizeof(userCommodityName));
							yearTmp1 = 0;
							monthTmp1 = 0;
							dayTmp1 = 0;
							userOriginMoneyTmp = 0;
							userFinalMoneyTmp = 0;
							userBuyNumber = 0;
							memset(str7, 0, sizeof(str7));
							memset(str8, 0, sizeof(str8));
							memset(str9, 0, sizeof(str9));
							ptr2 = userRecordHead;
							if (ptr2 == NULL)
							{
								MessageBox(hWnd, "���޹����¼", " ", MB_OKCANCEL);
							}
							else
							{
								while (TRUE)
								{
									setcolor(BLACK);
									xianadmin();
									yearTmp1 = ptr2->ptr->year;
									monthTmp1 = ptr2->ptr->month;
									dayTmp1 = ptr2->ptr->day;
									userOriginMoneyTmp = ptr2->ptr->soldPrice;
									if (ptr1->isCostumer==0)
									{
										if (ptr2->ptr->historyLv== 0)
										{
											tempDiscount = 1;
										}
										else if (ptr2->ptr->historyLv==1)
										{
											tempDiscount = 0.95;
										}
										else if (ptr2->ptr->historyLv==2)
										{
											tempDiscount = 0.9;
										}
										else if (ptr2->ptr->historyLv==3)
										{
											tempDiscount = 0.85;
										}
										else if (ptr2->ptr->historyLv==4)
										{
											tempDiscount = 0.8;
										}
										else
										{
											tempDiscount = 0.75;
										}
									}
									else
									{
										if (ptr2->ptr->historyLv==0)
										{
											tempDiscount = 1;
										}
										else if (ptr2->ptr->historyLv==1)
										{
											tempDiscount = 0.9;
										}
										else if (ptr2->ptr->historyLv==2)
										{
											tempDiscount = 0.85;
										}
										else if (ptr2->ptr->historyLv==3)
										{
											tempDiscount = 0.8;
										}
										else if (ptr2->ptr->historyLv==4)
										{
											tempDiscount = 0.75;
										}
										else
										{
											tempDiscount = 0.7;
										}
									}
									userFinalMoneyTmp = userOriginMoneyTmp * tempDiscount;
									userBuyNumber = ptr2->ptr->unitCount;
									strcpy_s(userCommodityName, ptr2->ptr->commodityName);
									sprintf_s(str7, "��Ʒ����:%s", userCommodityName);
									if (userOriginMoneyTmp < 100 && userFinalMoneyTmp < 100)
									{
										sprintf_s(str8, "�ۼ�:%.2lfԪ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmp, userFinalMoneyTmp, userBuyNumber);
									}
									else if (userOriginMoneyTmp < 100 && userFinalMoneyTmp >= 100 && userFinalMoneyTmp < 1000)
									{
										sprintf_s(str8, "�ۼ�:%.2lfԪ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmp, userFinalMoneyTmp / 100, userBuyNumber);
									}
									else if (userOriginMoneyTmp < 100 && userFinalMoneyTmp >= 1000)
									{
										sprintf_s(str8, "�ۼ�:%.2lfԪ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmp, userFinalMoneyTmp / 1000, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp < 100)
									{
										sprintf_s(str8, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmp / 100, userFinalMoneyTmp, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp >= 100 && userFinalMoneyTmp < 1000)
									{
										sprintf_s(str8, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmp / 100, userFinalMoneyTmp / 100, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp >= 1000)
									{
										sprintf_s(str8, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmp / 100, userFinalMoneyTmp / 1000, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 1000 && userFinalMoneyTmp < 100)
									{
										sprintf_s(str8, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmp / 1000, userFinalMoneyTmp, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 1000 && userFinalMoneyTmp >= 100 && userFinalMoneyTmp < 1000)
									{
										sprintf_s(str8, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmp / 1000, userFinalMoneyTmp / 100, userBuyNumber);
									}
									else
									{
										sprintf_s(str8, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmp / 1000, userFinalMoneyTmp / 1000, userBuyNumber);
									}
									sprintf_s(str9, "%d��%d��%d��", yearTmp1, monthTmp1, dayTmp1);
									outtextxy(-100, -300, str7);
									outtextxy(-220, -200, str8);
									outtextxy(-100, -100, str9);
									line(-230, 0, 230, 0);
									outtextxy(-200, 30, "��һ����¼");
									outtextxy(-200, 90, "ɾ����¼");
									outtextxy(50, 30, "��һ����¼");
									outtextxy(50, 90, "�����ϼ�");
									if (ptr2->ptr->situation== 1)
									{
										outtextxy(-200, -40, "�������촦�����˿�����");
									}
									else if (ptr2->ptr->situation == 2)
									{
										outtextxy(-200, -40, "������ɣ����˿�");
									}
									else
									{
										outtextxy(-200, -40, "δ�����ۺ�");
									}
									m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
									if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
									{
										setlinecolor(BLACK);
										rectangle(-210, 20, -40, 60);
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											cleardevice(); pict();
											if (ptr2->preRecord == NULL)
											{
												MessageBox(hWnd, "���ǵ�һ����¼", " ", MB_OKCANCEL);
											}
											else
											{
												ptr2= ptr2->preRecord;
											}
										}
									}
									else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
									{
										setlinecolor(BLACK);
										rectangle(-210, 80, -40, 120);
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											temp = ptr2->ptr;
											delRecord(&recordHead, &recordTail, temp);
											rebuildRecordFile(recordHead);
											buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, ptr1->clientName);
											ptr2 = userRecordHead;
											MessageBox(hWnd, "ɾ���ɹ�", " ", MB_OKCANCEL);
											cleardevice(); pict();
											goto loop2;
										}
									}
									else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
									{
										setlinecolor(BLACK);
										rectangle(40, 20, 210, 60);
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											cleardevice(); pict();
											if (ptr2->nextRecord==NULL)
											{
												MessageBox(hWnd, "�������һ����¼", " ", MB_OKCANCEL);
											}

											else
											{
												ptr2 = ptr2->nextRecord;
											}
										}
									}
									else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
									{
										setlinecolor(BLACK);
										rectangle(40, 80, 210, 120);
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											cleardevice(); pict();
											break;
										}
									}
									else
									{
										setlinecolor(WHITE);
										rectangle(-210, 20, -40, 60);
										rectangle(-210, 80, -40, 120);
										rectangle(40, 20, 210, 60);
										rectangle(40, 80, 210, 120);
									}
								}
							}
						}
					}
					else if (m.x >= 675 && m.x <= 720 && m.y >= 580 && m.y <= 660)
					{
						setlinecolor(BLACK);
						rectangle(175, 80, 220, 160);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					else if (m.x >= 280 && m.x <= 370 && m.y >= 450 && m.y <= 490)
					{
						setlinecolor(BLACK);
						rectangle(-220, -50, -130, -10);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (ptr1->situation == 0)
							{
								MessageBox(hWnd, "���û�δ�����", " ", MB_OKCANCEL);
							}
							else
							{
								ptr1->situation = 0;
								rebuildClientFile(clientHead);
								MessageBox(hWnd, "���ɹ�", " ", MB_OKCANCEL);
								cleardevice(); pict();
							}
						}
					}
					else if (m.x >= 380 && m.x <= 460&& m.y >= 450 && m.y <= 490)
					{
						setlinecolor(BLACK);
						rectangle(-120, -50, -40, -10);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (ptr1->situation == 1)
							{
								MessageBox(hWnd, "���û��ѱ����", " ", MB_OKCANCEL);
							}
							else
							{
								ptr1->situation = 1;
								rebuildClientFile(clientHead);
								MessageBox(hWnd, "����ɹ�", " ", MB_OKCANCEL);
								cleardevice(); pict();
							}
						}
					}
					else if (m.x >= 472 && m.x <= 570 && m.y >= 450 && m.y <= 490)
					{
						setlinecolor(BLACK);
						rectangle(-28, -50, 70, -10);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							memset(str30, 0, sizeof(str30));
							memset(str31, 0, sizeof(str31));
							memset(STR1, 0, sizeof(STR1));
							memset(STR2, 0, sizeof(STR2));
							memset(STR3, 0, sizeof(STR3));
							InputBox(str30, 50, "��д���û��˺ţ�40λ����,��ֻ�����ַ������֣�", NULL, NULL, 0, 0, false);
							if (strnlen_s(str30, sizeof(str30)) == 0)
							{
								;
							}
							else if (isStdInput(str30) && strnlen_s(str30, sizeof(str30)) <= 40 && strnlen_s(str30, sizeof(str30)) > 0)
							{
								strcpy_s(str31, str30);
								ptr9 = clientHead;
								ptr10 = clientHead;
								while (ptr9)
								{
									strcpy_s(STR1,str31);
									strcpy_s(STR2, ptr9->clientName);
									strcpy_s(STR3, ptr10->clientName);
									strToLower(STR1);
									strToLower(STR2);
									strToLower(STR3);
									if (getStrSimilarity(STR1, STR2) >= getStrSimilarity(STR1, STR3))
									{
										ptr10 = ptr9;
									}
									ptr9 = ptr9->nextClient;
								}
								MessageBox(hWnd, "������Ϊ��չʾ�����Ƶ��û�����ϸ��Ϣ", " ", MB_OKCANCEL);
								memset(str1, 0, sizeof(str1));
								memset(str2, 0, sizeof(str2));
								memset(str3, 0, sizeof(str3));
								if (ptr10)
								{
									cleardevice(); pict();
									while (TRUE)
									{
										sprintf_s(str1, "%s", ptr10->clientName);
										sprintf_s(str2, "%d��", ptr10->lv);
										sprintf_s(str3, "%.2lfԪ", ptr10->balance);
										sprintf_s(str4, "%d��", ptr10->year);
										sprintf_s(str5, "%d��", ptr10->month);
										sprintf_s(str6, "%d��", ptr10->day);
										setcolor(BLACK);
										xianadminLookUserG();
										outtextxy(-120, -370, str1);
										outtextxy(115, -330, str2);
										outtextxy(-145, -300, str3);
										outtextxy(-120, -210, "ע������");
										outtextxy(-120, -170, str4);
										outtextxy(-120, -130, str5);
										outtextxy(-120, -90, str6);
										if (ptr10->isCostumer == 0)
										{
											outtextxy(125, -280, "�û�");
										}
										else
										{
											outtextxy(125, -280, "������");
										}
										if (ptr10->situation == 0)
										{
											outtextxy(115, -125, "δ��");
										}
										else
										{
											outtextxy(115, -125, "�ѱ�");
										}
										m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
										if (m.x >= 465 && m.x <= 535 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(-35, 80, 35, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												ptr1 = ptr10;
												MessageBox(hWnd, "�������жԸ��û��Ĳ���", " ", MB_OKCANCEL);
												cleardevice(); pict();
												break;
											}
										}
										else
										{
											setlinecolor(WHITE);
											rectangle(-35, 80, 35, 120);
										}
									}
								}
							}
							else
							{
								MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
							}
						}
					}
					else
					{
						setlinecolor(WHITE);
						rectangle(-220, 40, -175, 160);
						rectangle(-150, 40, -105, 160);
						rectangle(-80, 10, -35, 170);
						rectangle(35, 10, 80, 170);
						rectangle(105, 10, 150, 170);
						rectangle(175, 80, 220, 160);
						rectangle(-220, -50, -130, -10);
						rectangle(-120, -50, -40, -10);
						rectangle(-28, -50, 70, -10);
					}
				}
				}
				
			}
		}
		//����ƶ����鿴��Ʒ
		else if (m.x >= 540 && m.x <= 660 && m.y >= 290 && m.y <= 330)
		{
			setlinecolor(BLACK);
			rectangle(40, -210, 160, -170);
			//������鿴��Ʒ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
			loop4:
				memset(str13, 0, sizeof(str13));
				memset(str14, 0, sizeof(str14));
				memset(str15, 0, sizeof(str15));
				memset(str16, 0, sizeof(str16));
				memset(tempZB, 0, sizeof(tempZB));
				ptr4 = commodityHead;
				if (ptr4 == NULL)
				{
					MessageBox(hWnd, "������Ʒ���ۣ��������Ʒ", " ", MB_OKCANCEL);
				}
				else
				{
					cleardevice(); pict();
					while (TRUE)
					{
						M = 0;
						N = 0;
						sprintf_s(str13, "%s", ptr4->commodityName);
						sprintf_s(str14, "%d��", ptr4->unitCount);
						if (ptr4->purchasePrice < 100)
						{
							sprintf_s(str15, "%.2lfԪ", ptr4->purchasePrice);
						}
						else if (ptr4->purchasePrice >= 100&& ptr4->purchasePrice<1000)
						{
							sprintf_s(str15, "%.2lf��Ԫ", ptr4->purchasePrice/100);
						}
						else
						{
							sprintf_s(str15, "%.2lfǧԪ", ptr4->purchasePrice/1000);
						}
						if (ptr4->soldPrice < 100)
						{
							sprintf_s(str16, "%.2lfԪ", ptr4->soldPrice);
						}
						else if (ptr4->soldPrice >= 100 && ptr4->soldPrice < 1000)
						{
							sprintf_s(str16, "%.2lf��Ԫ", ptr4->soldPrice / 100);
						}
						else
						{
							sprintf_s(str16, "%.2lfǧԪ", ptr4->soldPrice / 1000);
						}
						setcolor(BLACK);
						xianadminLookCommodity();
						outtextxy(-100, -350, str13);
						outtextxy(-125, -270, str14);
						outtextxy(90, -30, str15);
						outtextxy(140, -210, str16);
						calculate = recordHead;
						while (calculate)
						{
							if (calculate->situation == 0 || calculate->situation == 1)
							{
								M += calculate->unitCount;
							}
							calculate = calculate->nextRecord;
						}
						calculate = recordHead;
						while (calculate)
						{
							if ((calculate->situation == 0 || calculate->situation == 1)&& strcmp(calculate->commodityName,ptr4->commodityName) == 0)
							{
								N += calculate->unitCount;
							}
							calculate = calculate->nextRecord;
						}
						if (N == 0)
						{
							outtextxy(0, -200, "δ");
							outtextxy(0, -170, "��");
							outtextxy(0, -140, "��");
						}
						else
						{
							line(-20, -115, 0, -115);
							line(0, -115, 0, -50);
							line(-110, -110, 100 * cos(2 * pi * (N / M)) - 110, -100 * sin(2 * pi * (N / M)) - 110);
							outtextxy(10, -170, "��");
							outtextxy(10, -140, "��");
							outtextxy(10, -110, "ռ");
							outtextxy(10, -80, "��");
							sprintf_s(tempZB, "%.2lf",(N/M)*100);
							outtextxy(-40, -30, tempZB);
							outtextxy(20, -30, '%');
							floodfill(-60, -108, BLACK, FLOODFILLBORDER);

						}
						m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
						if (m.x >= 280 && m.x <= 325 && m.y >= 540 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(-220, 40, -175, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (ptr4->preCommodity == NULL)
								{
									MessageBox(hWnd, "���ǵ�һ����Ʒ", " ", MB_OKCANCEL);
								}
								else
								{
									ptr4 = ptr4->preCommodity;
								}
								cleardevice(); pict();
							}
						}
						else if (m.x >= 350 && m.x <= 395 && m.y >= 540 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(-150, 40, -105, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (ptr4->nextCommodity == NULL)
								{
									MessageBox(hWnd, "�������һ����Ʒ", " ", MB_OKCANCEL);
								}
								else
								{
									ptr4 = ptr4->nextCommodity;
								}
								cleardevice(); pict();
							}
						}
						else if (m.x >= 420 && m.x <= 465 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(-80, 10, -35, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								delCommodity(&commodityHead, &commodityTail, ptr4);
								rebuildCommodityFile(commodityHead);
								MessageBox(hWnd, "ɾ���ɹ�", " ", MB_OKCANCEL);
								cleardevice(); pict();
								goto loop4;
							}
						}
						else if (m.x >= 535 && m.x <= 580 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(35, 10, 80, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								Xuserl_1 = 0;
								Xuserl_2 = 0;
								Xuserl_3 = 0;//���ȳ�ʼ��
								Xidentify = 0;
								X_len_ = 0;
								judgeNum = 0;
								memset(userSignupName, 0, sizeof(userSignupName));//���ַ�����Ϊ��
								memset(userSignupNameTmp, 0, sizeof(userSignupNameTmp));
								memset(userSignupPwd1, 0, sizeof(userSignupPwd1));
								memset(userSignupPwd1Tmp, 0, sizeof(userSignupPwd1Tmp));
								memset(userSignupPwd2, 0, sizeof(userSignupPwd2));
								memset(userSignupPwd2Tmp, 0, sizeof(userSignupPwd2Tmp));
								memset(userIdentifyTmp, 0, sizeof(userIdentifyTmp));
								cleardevice(); pict();
								while (TRUE)
								{
									setcolor(BLACK);
									xianadmin();
									outtextxy(-100, -300, "����������Ʒ����");
									outtextxy(-50, -200, "�������");
									outtextxy(-62.5, -100, "�������ۼ�");
									outtextxy(-50, 0, "�����Ʒ");
									outtextxy(-25, 100, "����");
									//�пղ���
									if (Xuserl_1 != 0)
									{
										outtextxy(150, -300, "_/");
									}
									//�пղ���
									if (Xuserl_2 != 0)
									{
										outtextxy(150, -200, "_/");
									}
									//�пղ���
									if (Xuserl_3 != 0)
									{
										outtextxy(150, -100, "_/");
									}
									m = GetMouseMsg();
									//����ƶ���---������Ʒ��
									if (m.x >= 390 && m.x <= 610 && m.y >= 190 && m.y <= 230)
									{
										setlinecolor(BLACK);
										rectangle(-110, -310, 110, -270);
										//�����---������Ʒ��
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											InputBox(userSignupNameTmp, 50, "��д����Ʒ���ƣ�14λ����,14���ַ���7�����֣��������ַ������ֺͺ��֣�", NULL, NULL, 0, 0, false);
											X_userl_1 = strnlen_s(userSignupNameTmp, sizeof(userSignupNameTmp));
											if ((isStandardText(userSignupNameTmp) && (X_userl_1 <= 14) )|| X_userl_1 == 0)
											{
												strcpy_s(userSignupName, userSignupNameTmp);
												Xuserl_1 = strnlen_s(userSignupName, sizeof(userSignupName));
											}
											else
											{
												MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
											}
										}
									}
									//����ƶ���---�������
									else if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
									{
										setlinecolor(BLACK);
										rectangle(-60, -210, 60, -170);
										//�����---�������
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											InputBox(userSignupPwd1Tmp, 50, "��д����ۣ�40λ���ڣ������Ǵ�С����ĸ�����)", NULL, NULL, 0, 0, false);
											X_userl_2 = strnlen_s(userSignupPwd1Tmp, sizeof(userSignupPwd1Tmp));
											if (isStandardFloat(userSignupPwd1Tmp) && X_userl_2 <= 40)
											{
												if (strToDouble(userSignupPwd1Tmp) >= 10000)
												{
													MessageBox(hWnd, "�۸��ܹ����ڵ���10000", " ", MB_OKCANCEL);
												}
												else
												{
													strcpy_s(userSignupPwd1, userSignupPwd1Tmp);
													Xuserl_2 = strnlen_s(userSignupPwd1, sizeof(userSignupPwd1));
												}
											}
											else
											{
												MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
											}
										}
									}
									//����ƶ������ۼ�
									else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
									{
										setlinecolor(BLACK);
										rectangle(-72.5, -110, 72.5, -70);
										//����������ۼ�
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											InputBox(userSignupPwd2Tmp, 50, "��д���ۼۣ�40λ���ڣ������Ǵ�С����ĸ�����)", NULL, NULL, 0, 0, false);
											X_userl_3 = strnlen_s(userSignupPwd2Tmp, sizeof(userSignupPwd2Tmp));
											if (isStandardFloat(userSignupPwd2Tmp) && X_userl_3 <= 40)
											{
												if (strToDouble(userSignupPwd2Tmp) >= 10000)
												{
													MessageBox(hWnd, "�۸��ܹ����ڵ���10000", " ", MB_OKCANCEL);
												}
												else
												{
													strcpy_s(userSignupPwd2, userSignupPwd2Tmp);
													Xuserl_3 = strnlen_s(userSignupPwd2, sizeof(userSignupPwd2));
												}
											}
											else
											{
												MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
											}
										}
									}
									//����ƶ��������Ʒ
									else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
									{
										setlinecolor(BLACK);
										rectangle(-60, -10, 60, 30);
										//����������Ʒ
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											judgeNum = 0;
											//�п�
											if (Xuserl_1 != 0 && Xuserl_2 == 0 && Xuserl_3 == 0)
											{
												MessageBox(hWnd, "��������ۺ��ۼ�", " ", MB_OKCANCEL);
											}
											//�п�
											else if (Xuserl_1 == 0 && Xuserl_2 != 0 && Xuserl_3 == 0)
											{
												MessageBox(hWnd, "��������Ʒ���������ۼ�", " ", MB_OKCANCEL);
											}//�п�
											//�п�
											else if (Xuserl_1 == 0 && Xuserl_2 == 0 && Xuserl_3 != 0)
											{
												MessageBox(hWnd, "��������Ʒ���ͽ���", " ", MB_OKCANCEL);
											}
											//�п�
											else if (Xuserl_1 == 0 && Xuserl_2 != 0 && Xuserl_3 != 0)
											{
												MessageBox(hWnd, "��������Ʒ��", " ", MB_OKCANCEL);
											}
											//�п�
											else if (Xuserl_1 != 0 && Xuserl_2 == 0 && Xuserl_3 != 0)
											{
												MessageBox(hWnd, "���������", " ", MB_OKCANCEL);
											}
											//�п�
											else if (Xuserl_1 != 0 && Xuserl_2 != 0 && Xuserl_3 == 0)
											{
												MessageBox(hWnd, "���ٴ������ۼ�", " ", MB_OKCANCEL);
											}
											//�п�
											else if (Xuserl_1 == 0 && Xuserl_2 == 0 && Xuserl_3 == 0)
											{
												MessageBox(hWnd, "��������Ʒ�������ۺ��ۼ�", " ", MB_OKCANCEL);
											}
											//��ʽ����
											else
											{
												if (strToDouble(userSignupPwd2Tmp) <= strToDouble(userSignupPwd1Tmp))
												{
													MessageBox(hWnd, "�ۼ۲���С�ڵ��ڽ���", " ", MB_OKCANCEL);
												}
												else
												{
													judge = commodityHead;
													while (judge)
													{
														if (strcmp(userSignupName, judge->commodityName) == 0)
														{
															judgeNum = 1;
														}
														judge = judge->nextCommodity;
													}
													judge = NULL;
													if (judgeNum == 0)
													{
														addCommodity(&commodityHead, &commodityTail, userSignupName, strToDouble(userSignupPwd2), strToDouble(userSignupPwd1), 0);
														rebuildCommodityFile(commodityHead);
														MessageBox(hWnd, "��ӳɹ�", " ", MB_OK);
														cleardevice(); pict();
														goto loop4;
													}
													else
													{
														MessageBox(hWnd, "��Ʒ�Ѵ���", " ", MB_OK);
													}
												}
											}
										}
									}
									//����ƶ�������
									else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
									{
										setlinecolor(BLACK);
										rectangle(-35, 90, 35, 130);
										//���������
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											cleardevice(); pict();
											break;
										}
									}
									//����ƶ�������֮��
									else
									{
										setlinecolor(WHITE);
										rectangle(-60, -210, 60, -170);
										rectangle(-72.5, -110, 72.5, -70);
										rectangle(-60, -10, 60, 30);
										rectangle(-35, 90, 35, 130);
										rectangle(-110, -310, 110, -270);
									}
								}

							}
						}
						else if (m.x >= 605 && m.x <= 650 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(105, 10, 150, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
							loop5:
								cleardevice(); pict();
								buildUserRecordChainC(recordHead, &userRecordHeadC, &userRecordTailC, ptr4->commodityName);
								yearTmp3 = 0;
								monthTmp3 = 0;
								dayTmp3 = 0;
								userOriginMoneyTmp1 = 0;
								userFinalMoneyTmp1 = 0;
								userBuyNumber1 = 0;
								memset(str17, 0, sizeof(str17));
								memset(str18, 0, sizeof(str18));
								memset(str19, 0, sizeof(str19));
								ptr5 = userRecordHeadC;
								if (ptr5 == NULL)
								{
									MessageBox(hWnd, "������ؼ�¼", " ", MB_OKCANCEL);
								}
								else
								{
									while (TRUE)
									{
										setcolor(BLACK);
										xianadmin();
										yearTmp3 = ptr5->ptr->year;
										monthTmp3 = ptr5->ptr->month;
										dayTmp3 = ptr5->ptr->day;
										userOriginMoneyTmp1 = ptr5->ptr->soldPrice;
										if (getClientPtrFromName(ptr5->ptr->clientName)->isCostumer == 0)
										{
											if (ptr5->ptr->historyLv == 0)
											{
												tempDiscount = 1;
											}
											else if (ptr5->ptr->historyLv == 1)
											{
												tempDiscount = 0.95;
											}
											else if (ptr5->ptr->historyLv == 2)
											{
												tempDiscount = 0.9;
											}
											else if (ptr5->ptr->historyLv == 3)
											{
												tempDiscount = 0.85;
											}
											else if (ptr5->ptr->historyLv == 4)
											{
												tempDiscount = 0.8;
											}
											else
											{
												tempDiscount = 0.75;
											}
										}
										else
										{
											if (ptr5->ptr->historyLv == 0)
											{
												tempDiscount = 1;
											}
											else if (ptr5->ptr->historyLv == 1)
											{
												tempDiscount = 0.9;
											}
											else if (ptr5->ptr->historyLv == 2)
											{
												tempDiscount = 0.85;
											}
											else if (ptr5->ptr->historyLv == 3)
											{
												tempDiscount = 0.8;
											}
											else if (ptr5->ptr->historyLv == 4)
											{
												tempDiscount = 0.75;
											}
											else
											{
												tempDiscount = 0.7;
											}
										}
										userFinalMoneyTmp1 = userOriginMoneyTmp1 * tempDiscount;
										userBuyNumber1 = ptr5->ptr->unitCount;
										sprintf_s(str17, "��Ʒ����:%s", ptr5->ptr->commodityName);
										if (userOriginMoneyTmp1 < 100 && userFinalMoneyTmp1 < 100)
										{
											sprintf_s(str18, "�ۼ�:%.2lfԪ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmp1, userFinalMoneyTmp1, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 < 100 && userFinalMoneyTmp1 >= 100 && userFinalMoneyTmp1 < 1000)
										{
											sprintf_s(str18, "�ۼ�:%.2lfԪ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmp1, userFinalMoneyTmp1/ 100, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 < 100 && userFinalMoneyTmp1 >= 1000)
										{
											sprintf_s(str18, "�ۼ�:%.2lfԪ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmp1, userFinalMoneyTmp1 / 1000, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 100 && userOriginMoneyTmp1 < 1000 && userFinalMoneyTmp1 < 100)
										{
											sprintf_s(str18, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmp1 / 100, userFinalMoneyTmp1, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 100 && userOriginMoneyTmp1< 1000 && userFinalMoneyTmp1 >= 100 && userFinalMoneyTmp1 < 1000)
										{
											sprintf_s(str18, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmp1 / 100, userFinalMoneyTmp1 / 100, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 100 && userOriginMoneyTmp1 < 1000 && userFinalMoneyTmp1 >= 1000)
										{
											sprintf_s(str18, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmp1 / 100, userFinalMoneyTmp1 / 1000, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 1000 && userFinalMoneyTmp1 < 100)
										{
											sprintf_s(str18, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmp1 / 1000, userFinalMoneyTmp1, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 1000 && userFinalMoneyTmp1>= 100 && userFinalMoneyTmp1 < 1000)
										{
											sprintf_s(str18, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmp1 / 1000, userFinalMoneyTmp1 / 100, userBuyNumber1);
										}
										else
										{
											sprintf_s(str18, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmp1 / 1000, userFinalMoneyTmp1 / 1000, userBuyNumber1);
										}
										sprintf_s(str19, "%d��%d��%d��", yearTmp3, monthTmp3, dayTmp3);
										outtextxy(-100, -300, str17);
										outtextxy(-220, -200, str18);
										outtextxy(-100, -100, str19);
										line(-230, 0, 230, 0);
										outtextxy(-200, 30, "��һ����¼");
										outtextxy(-200, 90, "ɾ����¼");
										outtextxy(50, 30, "��һ����¼");
										outtextxy(50, 90, "�����ϼ�");
										outtextxy(0, -40, ptr5->ptr->clientName);
										if (ptr5->ptr->situation == 1)
										{
											outtextxy(-200, -350, "�������촦�����˿�����");
										}
										else if (ptr5->ptr->situation == 2)
										{
											outtextxy(-200, -350, "������ɣ����˿�");
										}
										else
										{
											outtextxy(-200, -350, "δ�����ۺ�");
										}
										m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
										if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
										{
											setlinecolor(BLACK);
											rectangle(-210, 20, -40, 60);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												if (ptr5->preRecord == NULL)
												{
													MessageBox(hWnd, "���ǵ�һ����¼", " ", MB_OKCANCEL);
												}
												else
												{
													ptr5 = ptr5->preRecord;
												}
											}
										}
										else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(-210, 80, -40, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												temp = ptr5->ptr;
												delRecord(&recordHead, &recordTail, temp);
												rebuildRecordFile(recordHead);
												buildUserRecordChainC(recordHead, &userRecordHeadC, &userRecordTailC, ptr4->commodityName);
												ptr5 = userRecordHeadC;
												MessageBox(hWnd, "ɾ���ɹ�", " ", MB_OKCANCEL);
												cleardevice(); pict();
												goto loop5;
											}
										}
										else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
										{
											setlinecolor(BLACK);
											rectangle(40, 20, 210, 60);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												if (ptr5->nextRecord == NULL)
												{
													MessageBox(hWnd, "�������һ����¼", " ", MB_OKCANCEL);
												}
												else
												{
													ptr5 = ptr5->nextRecord;
												}
											}
										}
										else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(40, 80, 210, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												break;
											}
										}
										else
										{
											setlinecolor(WHITE);
											rectangle(-210, 20, -40, 60);
											rectangle(-210, 80, -40, 120);
											rectangle(40, 20, 210, 60);
											rectangle(40, 80, 210, 120);
										}
									}
								}
							}
						}
						else if (m.x >= 675 && m.x <= 720 && m.y >= 580 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(175, 80, 220, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else if (m.x >= 610 && m.x <= 670 && m.y >= 195 && m.y <= 235)
						{
							setlinecolor(BLACK);
							rectangle(110, -300, 170, -265);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								InputBox(SumNumber, 50, "��д���������,С��10000", NULL, NULL, 0, 0, false);
								_sum = strnlen_s(SumNumber,sizeof(SumNumber));
								if (_sum == 0)
								{
									;
								}
								else
								{
									if (isFullDigit(SumNumber)&& strToInt(SumNumber)>0&&_sum<=4)
									{
										ptr4->unitCount = ptr4->unitCount + strToInt(SumNumber);
										rebuildCommodityFile(commodityHead);
										MessageBox(hWnd, "�����ɹ�", " ", MB_OKCANCEL);
										cleardevice(); pict();
									}
									else
									{
										MessageBox(hWnd, "�Ƿ����룬������", " ", MB_OKCANCEL);
									}
								}
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-220, 40, -175, 160);
							rectangle(-150, 40, -105, 160);
							rectangle(-80, 10, -35, 170);
							rectangle(35, 10, 80, 170);
							rectangle(105, 10, 150, 170);
							rectangle(175, 80, 220, 160);
							rectangle(110, -300, 170, -265);
					    }
					}
				}
			}
		}
		//����ƶ������ۼ�¼
		else if (m.x >= 340 && m.x <= 460 && m.y >= 390 && m.y <= 430)
		{
			setlinecolor(BLACK);
			rectangle(-160, -110, -40, -70);
			//����������ۼ�¼
			if (m.uMsg == WM_LBUTTONDOWN)
			{
			loop6:
				ptr6 = recordHead;
				cleardevice(); pict();
				memset(str20, 0, sizeof(str20));
				memset(str21, 0, sizeof(str21));
				memset(str22, 0, sizeof(str22));
				memset(str23, 0, sizeof(str23));
				memset(str24, 0, sizeof(str24));
				memset(str25, 0, sizeof(str25));
				memset(str26, 0, sizeof(str26));
				memset(str27, 0, sizeof(str27));
				if (ptr6 == NULL)
				{
					MessageBox(hWnd, "�������ۼ�¼", " ", MB_OKCANCEL);
				}
				else
				{
					while (TRUE)
					{
						setcolor(BLACK);
						xianadminLookRecord();
						sprintf_s(str20, "%d��", ptr6->historyLv);
						if (ptr6->purchasePrice < 100)
						{
							sprintf_s(str21, "%.2lfԪ", ptr6->purchasePrice);
						}
						else if (ptr6->purchasePrice >= 100 && ptr6->purchasePrice < 1000)
						{
							sprintf_s(str21, "%.2lf��Ԫ", ptr6->purchasePrice / 100);
						}
						else
						{
							sprintf_s(str21, "%.2lfǧԪ", ptr6->purchasePrice / 1000);
						}
						if (ptr6->soldPrice < 100)
						{
							sprintf_s(str22, "%.2lfԪ", ptr6->soldPrice);
						}
						else if (ptr6->soldPrice >= 100 && ptr6->soldPrice < 1000)
						{
							sprintf_s(str22, "%.2lf��Ԫ", ptr6->soldPrice / 100);
						}
						else
						{
							sprintf_s(str22, "%.2lfǧԪ", ptr6->soldPrice / 1000);
						}
						sprintf_s(str24, "%d��", ptr6->unitCount);
						if (getClientPtrFromName(ptr6->clientName))
						{
							if (getClientPtrFromName(ptr6->clientName)->isCostumer == 0)
							{
								if (ptr6->historyLv == 0)
								{
									tempDiscount = 1;
								}
								else if (ptr6->historyLv == 1)
								{
									tempDiscount = 0.95;
								}
								else if (ptr6->historyLv == 2)
								{
									tempDiscount = 0.9;
								}
								else if (ptr6->historyLv == 3)
								{
									tempDiscount = 0.85;
								}
								else if (ptr6->historyLv == 4)
								{
									tempDiscount = 0.8;
								}
								else
								{
									tempDiscount = 0.75;
								}
							}
							else
							{
								if (ptr6->historyLv == 0)
								{
									tempDiscount = 1;
								}
								else if (ptr6->historyLv == 1)
								{
									tempDiscount = 0.9;
								}
								else if (ptr6->historyLv == 2)
								{
									tempDiscount = 0.85;
								}
								else if (ptr6->historyLv == 3)
								{
									tempDiscount = 0.8;
								}
								else if (ptr6->historyLv == 4)
								{
									tempDiscount = 0.75;
								}
								else
								{
									tempDiscount = 0.7;
								}
							}
						}
						sprintf_s(str23, "%.2lfԪ", ptr6->soldPrice * tempDiscount);
						sprintf_s(str25, "%d��", ptr6->year);
						sprintf_s(str26, "%d��", ptr6->month);
						sprintf_s(str27, "%d��", ptr6->day);
						outtextxy(-130, -370, ptr6->clientName);
						outtextxy(-120, -290, ptr6->commodityName);
						outtextxy(-120, -210, str24);
						outtextxy(130, -120, str25);
						outtextxy(130, -80, str26);
						outtextxy(130, -40, str27);
						if (getClientPtrFromName(ptr6->clientName))
						{
							if (getClientPtrFromName(ptr6->clientName)->isCostumer == 0)
							{
								outtextxy(80, -160, "��ͨ�û�");
							}
							else
							{
								outtextxy(80, -160, "������");
							}
							if (ptr6->situation == 1)
							{
								outtextxy(-220, -70, "�봦���˿�����");
							}
							else if (ptr6->situation == 2)
							{
								outtextxy(-220, -70, "������ɣ����˿�");
							}
							else
							{
								outtextxy(-220, -70, "δ�����ۺ�");
							}
						}
						else
						{
							outtextxy(-220, -70, "�û���ע��");
							memset(str21, 0, sizeof(str21));
							memset(str22, 0, sizeof(str22));
							memset(str23, 0, sizeof(str23));
							memset(str20, 0, sizeof(str20));
						}
						outtextxy(180, -370, str20);
						outtextxy(120, -330, str21);
						outtextxy(120, -280, str22);
						outtextxy(140, -230, str23);
						if (getCommodityPtrFromName(ptr6->commodityName) == NULL)
						{
							outtextxy(-220, -40, "��Ʒ���¼�");
						}
						m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
						if (m.x >= 280 && m.x <= 325 && m.y >= 540 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(-220, 40, -175, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (ptr6->preRecord == NULL)
								{
									MessageBox(hWnd, "���ǵ�һ����¼", " ", MB_OKCANCEL);
								}
								else
								{
									ptr6 = ptr6->preRecord;
								}
								cleardevice(); pict();
							}
						}
						else if (m.x >= 350 && m.x <= 395 && m.y >= 540 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(-150, 40, -105, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (ptr6->nextRecord == NULL)
								{
									MessageBox(hWnd, "�������һ����¼", " ", MB_OKCANCEL);
								}
								else
								{
									ptr6 = ptr6->nextRecord;
								}
								cleardevice(); pict();
							}
						}
						else if (m.x >= 420 && m.x <= 465 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(-80, 10, -35, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								temp = ptr6;
								delRecord(&recordHead, &recordTail, temp);
								rebuildRecordFile(recordHead);
								MessageBox(hWnd, "ɾ���ɹ�", " ", MB_OKCANCEL);
								cleardevice(); pict();
								goto loop6;
							}
						}
						else if (m.x >= 535 && m.x <= 580 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(35, 10, 80, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								memset(str1, 0, sizeof(str1));
								memset(str2, 0, sizeof(str2));
								memset(str3, 0, sizeof(str3));
								ptr7 = NULL;
								ptr7 = getClientPtrFromName(ptr6->clientName);
								if (ptr7)
								{
									cleardevice(); pict();
									while (TRUE)
									{
										sprintf_s(str1, "%s", ptr7->clientName);
										sprintf_s(str2, "%d��", ptr7->lv);
										sprintf_s(str3, "%.2lfԪ", ptr7->balance);
										sprintf_s(str4, "%d��", ptr7->year);
										sprintf_s(str5, "%d��", ptr7->month);
										sprintf_s(str6, "%d��", ptr7->day);
										setcolor(BLACK);
										xianadminLookUserG();
										outtextxy(-120, -370, str1);
										outtextxy(115, -330, str2);
										outtextxy(-145, -300, str3);
										outtextxy(-120, -210, "ע������");
										outtextxy(-120, -170, str4);
										outtextxy(-120, -130, str5);
										outtextxy(-120, -90, str6);
										if (ptr7->isCostumer == 0)
										{
											outtextxy(125, -280, "�û�");
										}
										else
										{
											outtextxy(125, -280, "������");
										}
										if (ptr7->situation == 0)
										{
											outtextxy(115, -125, "δ��");
										}
										else
										{
											outtextxy(115, -125, "�ѱ�");
										}
										m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
										if (m.x >= 465 && m.x <= 535 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(-35, 80, 35, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												break;
											}
										}
										else
										{
											setlinecolor(WHITE);
											rectangle(-35, 80, 35, 120);
										}
									}
								}
								else
								{
									MessageBox(hWnd, "���û���ע��", " ", MB_OKCANCEL);
								}
							}
						}
						else if (m.x >= 605 && m.x <= 650 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(105, 10, 150, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								memset(str13, 0, sizeof(str13));
								memset(str14, 0, sizeof(str14));
								memset(str15, 0, sizeof(str15));
								memset(str16, 0, sizeof(str16));
								memset(tempZB, 0, sizeof(tempZB));
								ptr8 = NULL;
								ptr8 = getCommodityPtrFromName(ptr6->commodityName);
								if (ptr8)
								{
									cleardevice(); pict();
									while (TRUE)
									{
										M = 0;
										N = 0;
										sprintf_s(str13, "%s", ptr8->commodityName);
										sprintf_s(str14, "%d��", ptr8->unitCount);
										if (ptr8->purchasePrice < 100)
										{
											sprintf_s(str15, "%.2lfԪ", ptr8->purchasePrice);
										}
										else if (ptr8->purchasePrice >= 100 && ptr8->purchasePrice < 1000)
										{
											sprintf_s(str15, "%.2lf��Ԫ", ptr8->purchasePrice / 100);
										}
										else
										{
											sprintf_s(str15, "%.2lfǧԪ", ptr8->purchasePrice / 1000);
										}
										if (ptr8->soldPrice < 100)
										{
											sprintf_s(str16, "%.2lfԪ", ptr8->soldPrice);
										}
										else if (ptr8->soldPrice >= 100 && ptr8->soldPrice < 1000)
										{
											sprintf_s(str16, "%.2lf��Ԫ", ptr8->soldPrice / 100);
										}
										else
										{
											sprintf_s(str16, "%.2lfǧԪ", ptr8->soldPrice / 1000);
										}
										setcolor(BLACK);
										xianadminLookCommodityG();
										outtextxy(-100, -350, str13);
										outtextxy(-125, -270, str14);
										outtextxy(90, -30, str15);
										outtextxy(150, -210, str16);
										calculate = recordHead;
										while (calculate)
										{
											if (calculate->situation == 0 || calculate->situation == 1)
											{
												M += calculate->unitCount;
											}
											calculate = calculate->nextRecord;
										}
										calculate = recordHead;
										while (calculate)
										{
											if ((calculate->situation == 0 || calculate->situation == 1) && strcmp(calculate->commodityName, ptr6->commodityName) == 0)
											{
												N += calculate->unitCount;
											}
											calculate = calculate->nextRecord;
										}
										if (N == 0)
										{
											outtextxy(0, -200, "δ");
											outtextxy(0, -170, "��");
											outtextxy(0, -140, "��");
										}
										else
										{
											line(-20, -115, 0, -115);
											line(0, -115, 0, -50);
											line(-110, -110, 100 * cos(2 * pi * (N / M)) - 110, -100 * sin(2 * pi * (N / M)) - 110);
											outtextxy(10, -170, "��");
											outtextxy(10, -140, "��");
											outtextxy(10, -110, "ռ");
											outtextxy(10, -80, "��");
											sprintf_s(tempZB, "%.2lf", (N / M) * 100);
											outtextxy(-40, -30, tempZB);
											outtextxy(20, -30, '%');
											floodfill(-60, -112, BLACK, FLOODFILLBORDER);
										}
										m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
										if (m.x >= 465 && m.x <= 535 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(-35, 80, 35, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												break;
											}
										}
										else
										{
											setlinecolor(WHITE);
											rectangle(-35, 80, 35, 120);
										}
									}
								}
								else
								{
									MessageBox(hWnd, "����Ʒ���¼�", " ", MB_OKCANCEL);
								}
							}
						}
						else if (m.x >= 675 && m.x <= 720 && m.y >= 580 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(175, 80, 220, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-220, 40, -175, 160);
							rectangle(-150, 40, -105, 160);
							rectangle(-80, 10, -35, 170);
							rectangle(35, 10, 80, 170);
							rectangle(105, 10, 150, 170);
							rectangle(175, 80, 220, 160);
						}
					}
				}
			}
		}
		//����ƶ����˻�����
		else if (m.x >= 540 && m.x <= 660 && m.y >=390 && m.y <= 430)
		{
			setlinecolor(BLACK);
			rectangle(40, -110, 160, -70);
			//������˻�����
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				buildUserRecordChainT(recordHead, &userRecordHeadT, &userRecordTailT);
			loop3:
				cleardevice(); pict();
				memset(userCommodityNameT, 0, sizeof(userCommodityNameT));
				yearTmp2 = 0;
				monthTmp2 = 0;
				dayTmp2 = 0;
				userOriginMoneyTmpT = 0;
				userFinalMoneyTmpT = 0;
				userBuyNumberT = 0;
				memset(str10, 0, sizeof(str10));
				memset(str11, 0, sizeof(str11));
				memset(str12, 0, sizeof(str12));
				ptr3 = userRecordHeadT;
				if (ptr3 == NULL)
				{
					MessageBox(hWnd, "�����˻�����", " ", MB_OKCANCEL);
				}
				else
				{
					while (TRUE)
					{
						setcolor(BLACK);
						xianadmin();
						yearTmp2 = ptr3->ptr->year;
						monthTmp2 = ptr3->ptr->month;
						dayTmp2 = ptr3->ptr->day;
						userOriginMoneyTmpT = ptr3->ptr->soldPrice;
						if (getClientPtrFromName(ptr3->ptr->clientName)->isCostumer==0)
						{
							if (ptr3->ptr->historyLv == 0)
							{
								tempDiscount = 1;
							}
							else if (ptr3->ptr->historyLv==1)
							{
								tempDiscount = 0.95;
							}
							else if (ptr3->ptr->historyLv==2)
							{
								tempDiscount = 0.9;
							}
							else if (ptr3->ptr->historyLv==3)
							{
								tempDiscount = 0.85;
							}
							else if (ptr3->ptr->historyLv==4)
							{
								tempDiscount = 0.8;
							}
							else
							{
								tempDiscount = 0.75;
							}
						}
						else
						{
							if (ptr3->ptr->historyLv==0)
							{
								tempDiscount = 1;
							}
							else if (ptr3->ptr->historyLv==1)
							{
								tempDiscount = 0.9;
							}
							else if (ptr3->ptr->historyLv==2)
							{
								tempDiscount = 0.85;
							}
							else if (ptr3->ptr->historyLv==3)
							{
								tempDiscount = 0.8;
							}
							else if (ptr3->ptr->historyLv==4)
							{
								tempDiscount = 0.75;
							}
							else
							{
								tempDiscount = 0.7;
							}
						}
						userFinalMoneyTmpT = userOriginMoneyTmpT * tempDiscount;
						userBuyNumberT = ptr3->ptr->unitCount;
						strcpy_s(userCommodityNameT, ptr3->ptr->commodityName);
						sprintf_s(str10, "��Ʒ����:%s", userCommodityNameT);
						if (userOriginMoneyTmpT < 100 && userFinalMoneyTmpT < 100)
						{
							sprintf_s(str11, "�ۼ�:%.2lfԪ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmpT, userFinalMoneyTmpT,userBuyNumberT);
						}
						else if (userOriginMoneyTmpT < 100 && userFinalMoneyTmpT >= 100 && userFinalMoneyTmpT < 1000)
						{
							sprintf_s(str11, "�ۼ�:%.2lfԪ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmpT, userFinalMoneyTmpT / 100, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT < 100 && userFinalMoneyTmpT >= 1000)
						{
							sprintf_s(str11, "�ۼ�:%.2lfԪ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmpT, userFinalMoneyTmpT / 1000, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 100 && userOriginMoneyTmpT < 1000 && userFinalMoneyTmpT < 100)
						{
							sprintf_s(str11, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmpT / 100, userFinalMoneyTmpT, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 100 && userOriginMoneyTmpT < 1000 && userFinalMoneyTmpT >= 100 && userFinalMoneyTmpT < 1000)
						{
							sprintf_s(str11, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmpT / 100, userFinalMoneyTmpT/ 100, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 100 && userOriginMoneyTmpT < 1000 && userFinalMoneyTmpT >= 1000)
						{
							sprintf_s(str11, "�ۼ�:%.2lf��Ԫ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmpT / 100, userFinalMoneyTmpT / 1000, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 1000 && userFinalMoneyTmpT < 100)
						{
							sprintf_s(str11, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lfԪ ����:%d��", userOriginMoneyTmpT / 1000, userFinalMoneyTmpT, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 1000 && userFinalMoneyTmpT >= 100 && userFinalMoneyTmpT < 1000)
						{
							sprintf_s(str11, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lf��Ԫ ����:%d��", userOriginMoneyTmpT / 1000, userFinalMoneyTmpT / 100, userBuyNumberT);
						}
						else
						{
							sprintf_s(str11, "�ۼ�:%.2lfǧԪ �ۺ�:%.2lfǧԪ ����:%d��", userOriginMoneyTmpT / 1000, userFinalMoneyTmpT / 1000, userBuyNumberT);
						}
						sprintf_s(str12, "%d��%d��%d��", yearTmp2, monthTmp2, dayTmp2);
						outtextxy(-100, -300, str10);
						outtextxy(-220, -200, str11);
						outtextxy(-100, -100, str12);
						outtextxy(-200, -40, ptr3->ptr->clientName);
						line(-230, 0, 230, 0);
						outtextxy(-200, 30, "��һ������");
						outtextxy(-200, 90, "׼���˿�");
						outtextxy(50, 30, "��һ������");
						outtextxy(50, 90, "�����ϼ�");
						m = GetMouseMsg();//--��ѭ���ڻ�ȡ���
						if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(-210, 20, -40, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (ptr3->preRecord == NULL)
								{
									MessageBox(hWnd, "���ǵ�һ����¼", " ", MB_OKCANCEL);
								}
								else
								{
									ptr3 = ptr3->preRecord;
								}
							}
						}
						else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(-210, 80, -40, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								getClientPtrFromName(ptr3->ptr->clientName)->balance = getClientPtrFromName(ptr3->ptr->clientName)->balance + userFinalMoneyTmpT * userBuyNumberT;
								rebuildClientFile(clientHead);
								getCommodityPtrFromName(ptr3->ptr->commodityName)->unitCount = getCommodityPtrFromName(ptr3->ptr->commodityName)->unitCount + userBuyNumberT;
								rebuildCommodityFile(commodityHead);
								ptr3->ptr->situation = 2;
								rebuildRecordFile(recordHead);
								buildUserRecordChainT(recordHead, &userRecordHeadT, &userRecordTailT);
								MessageBox(hWnd, "�˿�ɹ�", " ", MB_OKCANCEL);
								cleardevice(); pict();
								goto loop3;
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(40, 20, 210, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (ptr3->nextRecord == NULL)
								{
									MessageBox(hWnd, "�������һ����¼", " ", MB_OKCANCEL);
								}

								else
								{
									ptr3 = ptr3->nextRecord;
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(40, 80, 210, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-210, 20, -40, 60);
							rectangle(-210, 80, -40, 120);
							rectangle(40, 20, 210, 60);
							rectangle(40, 80, 210, 120);
						}
					}
				}

			}
		}
		//����ƶ�������ҳ��
		else if (m.x >= 340 && m.x <= 460 && m.y >= 490 && m.y <= 530)
		{
			setlinecolor(BLACK);
			rectangle(-160, -10, -40, 30);
			//���������ҳ��
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(TIME, 0, sizeof(TIME));
				YEAR = 0;
				MONTH = 0;
				DAY = 0;
				tempPoint = 0;
				getCurrentTime(&YEAR, &MONTH, &DAY);
				sprintf_s(TIME, "%d��%d��%d��", YEAR, MONTH, DAY);
				cleardevice(); pict();
				while (TRUE)
				{
					setcolor(BLACK);
					xianzonglan();
					settextstyle(125, 60, "����", 0, 0, 500, 0, 0, 0);
					outtextxy(-390,-350," (@-@)");
					outtextxy(-390,-150, TIME);
					settextstyle(25, 12, "����", 0, 0, 500, 0, 0, 0);
					outtextxy(-390, 365, "�鿴����ӯ����ϸ");
					outtextxy(190, 365, "Ԥ������ӯ�����");
					outtextxy(-25, 365, "����");
					m = GetMouseMsg();
					if (m.x >= 100 && m.x <= 320 && m.y >= 855 && m.y <= 895)
					{
						setlinecolor(BLACK);
						rectangle(-400, 355, -180, 395);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							YEAR = 0;
							MONTH = 0;
							DAY = 0;
							tempPoint = 0;
							getCurrentTime(&YEAR, &MONTH, &DAY);
							memset(str28, 0, sizeof(str28));
							cleardevice(); pict();
							while (TRUE)
							{
								setcolor(BLACK);
								xianzonglan();
								outtextxy(-25, 365, "����");
								line(-400, -50, 400, -50);
								line(-390, -400, -390, 300);
								line(-390, -400, -400, -390);
								line(-390, -400, -380, -390);
								line(400, -50, 390, -60);
								line(400, -50, 390, -40);
								settextstyle(12, 6, "����", 0, 0, 500, 0, 0, 0);
								i = 1;
								ii = 25;
								for (; i <= 31; i++)
								{
									sprintf_s(str28, "%d", i);
									line(-390 + ii, -50 ,- 390 + ii, -60);
									outtextxy(-390 + ii, -45, str28);
									ii+=25;
								}
								i = 1;
								ii = 0;
								iii = 1600;
								for (; i <= 17; i++)
								{
									if (i == 9)
									{
										sprintf_s(str28, "%d", iii);
										line(-390, -370 + ii, -380, -370 + ii);
										ii += 40;
										iii = iii - 200;
									}
									else
									{
										sprintf_s(str28, "%d", iii);
										line(-390, -370 + ii, -380, -370 + ii);
										outtextxy(-375, -370 + ii, str28);
										ii += 40;
										iii = iii - 200;
									}
									
								}
								i = 1;
								ii = 25;
								iiii = 0;
								for (; i <= DAY; i++)
								{
									profile = 0;
									calculate1 = recordHead;
									while (calculate1)
									{
										if ((calculate1->year == YEAR && calculate1->month == MONTH && calculate1->day == i)&&(calculate1->situation==0||calculate1->situation==1)&& getClientPtrFromName(calculate1->clientName)&& getCommodityPtrFromName(calculate1->commodityName))
										{
											if (getClientPtrFromName(calculate1->clientName)->isCostumer == 0)
											{
												if (calculate1->historyLv == 0)
												{
													tempDiscount = 1;
												}
												else if (calculate1->historyLv == 1)
												{
													tempDiscount = 0.95;
												}
												else if (calculate1->historyLv == 2)
												{
													tempDiscount = 0.9;
												}
												else if (calculate1->historyLv == 3)
												{
													tempDiscount = 0.85;
												}
												else if (calculate1->historyLv == 4)
												{
													tempDiscount = 0.8;
												}
												else
												{
													tempDiscount = 0.75;
												}
											}
											else
											{
												if (calculate1->historyLv == 0)
												{
													tempDiscount = 1;
												}
												else if (calculate1->historyLv == 1)
												{
													tempDiscount = 0.9;
												}
												else if (calculate1->historyLv == 2)
												{
													tempDiscount = 0.85;
												}
												else if (calculate1->historyLv == 3)
												{
													tempDiscount = 0.8;
												}
												else if (calculate1->historyLv == 4)
												{
													tempDiscount = 0.75;
												}
												else
												{
													tempDiscount = 0.7;
												}
											}
											profile += ((calculate1->soldPrice) * tempDiscount - calculate1->purchasePrice)*(calculate1->unitCount);
										}
										sprintf_s(PROFILE, "%.2lfԪ", profile);
										calculate1 = calculate1->nextRecord;
									}
									setlinestyle(PS_SOLID, 2);
									if (i == 1)
									{
										tempPoint = profile;
										line(-390+ii,-(tempPoint/5)-50, -390 + ii, -(tempPoint / 5) - 50);
										ii = ii + 25;
									}
									else
									{
										line(-390 + ii-25, -(tempPoint / 5) - 50, -390 + ii, -(profile / 5) - 50);
										tempPoint = profile;
										ii = ii + 25;
									}
									setlinestyle(PS_SOLID, 1);
									if (i >= 1 && i <= 5)
									{
										if (i == 1)
										{
											iiii = 0;
										}
										outtextxy(-370, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 6 && i <= 10)
									{
										if (i == 6)
										{
											iiii = 0;
										}
										outtextxy(-270, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 11 && i <= 15)
									{
										if (i == 11)
										{
											iiii = 0;
										}
										outtextxy(-170, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 16 && i <= 20)
									{
										if (i == 16)
										{
											iiii = 0;
										}
										outtextxy(190, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 21 && i <= 25)
									{
										if (i == 21)
										{
											iiii = 0;
										}
										outtextxy(290, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else
									{
										if (i == 26)
										{
											iiii = 0;
										}
										outtextxy(390, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
								}
								outtextxy(-390, 310, "1:");
								outtextxy(-390, 330, "2:");
								outtextxy(-390, 350, "3:");
								outtextxy(-390, 370, "4:");
								outtextxy(-390, 390, "5:");
								outtextxy(-290, 310, "6:");
								outtextxy(-290, 330, "7:");
								outtextxy(-290, 350, "8:");
								outtextxy(-290, 370, "9:");
								outtextxy(-290, 390, "10:");
								outtextxy(-190, 310, "11:");
								outtextxy(-190, 330, "12:");
								outtextxy(-190, 350, "13:");
								outtextxy(-190, 370, "14:");
								outtextxy(-190, 390, "15:");
								outtextxy(170, 310, "16:");
								outtextxy(170, 330, "17:");
								outtextxy(170, 350, "18:");
								outtextxy(170, 370, "19:");
								outtextxy(170, 390, "20:");
								outtextxy(270, 310, "21:");
								outtextxy(270, 330, "22:");
								outtextxy(270, 350, "23:");
								outtextxy(270, 370, "24:");
								outtextxy(270, 390, "25:");
								outtextxy(370, 310, "26:");
								outtextxy(370, 330, "27:");
								outtextxy(370, 350, "28:");
								outtextxy(370, 370, "29:");
								outtextxy(370, 390, "30:");
								outtextxy(370, 410, "31:");
								settextstyle(25, 12, "����", 0, 0, 500, 0, 0, 0);
								m = GetMouseMsg();
								if (m.x >= 465 && m.x <= 535 && m.y >= 855 && m.y <= 895)
								{
									setlinecolor(BLACK);
									rectangle(-35, 355, 35, 395);
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										cleardevice(); pict();
										break;
									}
								}
								else
								{
									setlinecolor(WHITE);
									rectangle(-35, 355, 35, 395);
								}
							}
						}
					}
					else if (m.x >= 680 && m.x <=900 && m.y >= 855 && m.y <= 895)
					{
						setlinecolor(BLACK);
						rectangle(180, 355, 400, 395);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							while (TRUE)
							{
								setcolor(BLACK);
								xianzonglan();
								outtextxy(-25, 365, "����");
								outtextxy(-25, 310, "Ԥ��");
								line(-400, -50, 400, -50);
								line(-390, -400, -390, 300);
								line(-390, -400, -400, -390);
								line(-390, -400, -380, -390);
								line(400, -50, 390, -60);
								line(400, -50, 390, -40);
								settextstyle(12, 6, "����", 0, 0, 500, 0, 0, 0);
								i = 1;
								ii = 25;
								for (; i <= 31; i++)
								{
									sprintf_s(str28, "%d", i);
									line(-390 + ii, -50, -390 + ii, -60);
									outtextxy(-390 + ii, -45, str28);
									ii += 25;
								}
								i = 1;
								ii = 0;
								iii = 1600;
								for (; i <= 17; i++)
								{
									if (i == 9)
									{
										sprintf_s(str28, "%d", iii);
										line(-390, -370 + ii, -380, -370 + ii);
										ii += 40;
										iii = iii - 200;
									}
									else
									{
										sprintf_s(str28, "%d", iii);
										line(-390, -370 + ii, -380, -370 + ii);
										outtextxy(-375, -370 + ii, str28);
										ii += 40;
										iii = iii - 200;
									}

								}
								i = 1;
								ii = 25;
								iiii = 0;
								for (; i <= DAY; i++)
								{
									profile = 0;
									calculate1 = recordHead;
									while (calculate1)
									{
										if ((calculate1->year == YEAR && calculate1->month == MONTH && calculate1->day == i) && (calculate1->situation == 0 || calculate1->situation == 1) && getClientPtrFromName(calculate1->clientName) && getCommodityPtrFromName(calculate1->commodityName))
										{
											if (getClientPtrFromName(calculate1->clientName)->isCostumer == 0)
											{
												if (calculate1->historyLv == 0)
												{
													tempDiscount = 1;
												}
												else if (calculate1->historyLv == 1)
												{
													tempDiscount = 0.95;
												}
												else if (calculate1->historyLv == 2)
												{
													tempDiscount = 0.9;
												}
												else if (calculate1->historyLv == 3)
												{
													tempDiscount = 0.85;
												}
												else if (calculate1->historyLv == 4)
												{
													tempDiscount = 0.8;
												}
												else
												{
													tempDiscount = 0.75;
												}
											}
											else
											{
												if (calculate1->historyLv == 0)
												{
													tempDiscount = 1;
												}
												else if (calculate1->historyLv == 1)
												{
													tempDiscount = 0.9;
												}
												else if (calculate1->historyLv == 2)
												{
													tempDiscount = 0.85;
												}
												else if (calculate1->historyLv == 3)
												{
													tempDiscount = 0.8;
												}
												else if (calculate1->historyLv == 4)
												{
													tempDiscount = 0.75;
												}
												else
												{
													tempDiscount = 0.7;
												}
											}
											profile += ((calculate1->soldPrice) * tempDiscount - calculate1->purchasePrice) * (calculate1->unitCount);
										}
										sprintf_s(PROFILE, "%.2lfԪ", profile);
										MMONEY[i - 1] = profile;
										calculate1 = calculate1->nextRecord;
									}
									setlinestyle(PS_SOLID, 5);
									if (i == 1)
									{
										line(-390 + ii, -(profile / 5) - 50, -390 + ii, -(profile / 5) - 50);
										ii = ii + 25;
									}
									else
									{
										line(-390 + ii, -(profile / 5) - 50, -390 + ii, -(profile / 5) - 50);
										ii = ii + 25;
									}
									setlinestyle(PS_SOLID, 1);
									if (i >= 1 && i <= 5)
									{
										if (i == 1)
										{
											iiii = 0;
										}
										outtextxy(-370, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 6 && i <= 10)
									{
										if (i == 6)
										{
											iiii = 0;
										}
										outtextxy(-270, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 11 && i <= 15)
									{
										if (i == 11)
										{
											iiii = 0;
										}
										outtextxy(-170, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 16 && i <= 20)
									{
										if (i == 16)
										{
											iiii = 0;
										}
										outtextxy(190, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 21 && i <= 25)
									{
										if (i == 21)
										{
											iiii = 0;
										}
										outtextxy(290, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else
									{
										if (i == 26)
										{
											iiii = 0;
										}
										outtextxy(390, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
								}
								outtextxy(-390, 310, "1:");
								outtextxy(-390, 330, "2:");
								outtextxy(-390, 350, "3:");
								outtextxy(-390, 370, "4:");
								outtextxy(-390, 390, "5:");
								outtextxy(-290, 310, "6:");
								outtextxy(-290, 330, "7:");
								outtextxy(-290, 350, "8:");
								outtextxy(-290, 370, "9:");
								outtextxy(-290, 390, "10:");
								outtextxy(-190, 310, "11:");
								outtextxy(-190, 330, "12:");
								outtextxy(-190, 350, "13:");
								outtextxy(-190, 370, "14:");
								outtextxy(-190, 390, "15:");
								outtextxy(170, 310, "16:");
								outtextxy(170, 330, "17:");
								outtextxy(170, 350, "18:");
								outtextxy(170, 370, "19:");
								outtextxy(170, 390, "20:");
								outtextxy(270, 310, "21:");
								outtextxy(270, 330, "22:");
								outtextxy(270, 350, "23:");
								outtextxy(270, 370, "24:");
								outtextxy(270, 390, "25:");
								outtextxy(370, 310, "26:");
								outtextxy(370, 330, "27:");
								outtextxy(370, 350, "28:");
								outtextxy(370, 370, "29:");
								outtextxy(370, 390, "30:");
								outtextxy(370, 410, "31:");
								/*
								if (DAY < 2)
								{
									MessageBox(hWnd, "���Ǳ��µ�һ�죬��ʱ�޷�Ԥ��", " ", MB_OK);
								}
								else
								{
									i = 0;
									for (; i < DAY; i++)
									{
										FILE* ss;
										fopen_s(&ss, ".\\Data\\LinearReggression.txt", "w");
										if (ss)
										{
											for (; i < DAY; i++)
											{
												fprintf_s(ss, "%lf %lf\n", (i+1)*1.0, MMONEY[i]);
											}
											fclose(ss);
										}
									}
									double k=0, b=0;
									xianxing(&k, &b, DAY);
									printf("%lf %lf", k, b);
								}
								*/
								settextstyle(25, 12, "����", 0, 0, 500, 0, 0, 0);
								m = GetMouseMsg();
								if (m.x >= 465 && m.x <= 535 && m.y >= 855 && m.y <= 895)
								{
									setlinecolor(BLACK);
									rectangle(-35, 355, 35, 395);
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										cleardevice(); pict();
										break;
									}
								}
								else if (m.x >= 465 && m.x <= 535 && m.y >= 805 && m.y <= 845)
								{
									setlinecolor(BLACK);
									rectangle(-35, 305, 35, 345);
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										memset(str29, 0, sizeof(str29));
										if (DAY < 2)
										{
											MessageBox(hWnd, "���Ǳ��µ�һ�죬��ʱ�޷�Ԥ��", " ", MB_OK);
										}
										else
										{
											i = 0;
											for (; i < DAY; i++)
											{
												FILE* ss;
												fopen_s(&ss, ".\\Data\\LinearReggression.txt", "w");
												if (ss)
												{
													for (; i < DAY; i++)
													{
														fprintf_s(ss, "%lf %lf\n", (i + 1) * 1.0, MMONEY[i]);
													}
													fclose(ss);
												}
											}
											k = 0, b = 0;
											xianxing(&k, &b, DAY);
											sprintf_s(str29, "�ع�ֱ�߷���:y=  %lf * x %+lf", k,b);
											MessageBox(hWnd, str29, " ", MB_OK);
											memset(str29, 0, sizeof(str29));
											cleardevice(); pict();
											sprintf_s(str29, "Ԥ�������յ�Ӫҵ��Ϊ:%lfԪ", k*(DAY+1)+b);
											MessageBox(hWnd, str29, " ", MB_OK);
											setcolor(GREEN);
											line(-390, (-b / 5) - 50, (31) * 25 - 390, ((-(k * (31) + b)) / 5) - 50);
											setlinecolor(BLACK);
										}
									}
								}
								else
								{
									setlinecolor(WHITE);
									rectangle(-35, 305, 35, 345);
									rectangle(-35, 355, 35, 395);
								}
							}
						}
					}
					else if (m.x >= 465 && m.x <= 535 && m.y >= 855 && m.y <= 895)
					{
						setlinecolor(BLACK);
						rectangle(-35, 355, 35, 395);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					else
					{
						setlinecolor(WHITE);
						rectangle(-400, 355, -180, 395);
						rectangle(180, 355, 400, 395);
						rectangle(-35, 355, 35, 395);
					}
				}
			}
		}
		//����ƶ���������ҳ
		else if (m.x >= 540 && m.x <= 660 && m.y >= 490 && m.y <= 530)
		{
			setlinecolor(BLACK);
			rectangle(40, -10, 160, 30);
			//�����������ҳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(adminCurrentName, 0, sizeof(adminCurrentName));
				memset(adminLoginName, 0, sizeof(adminLoginName));
				memset(adminLoginNameTmp, 0, sizeof(adminLoginNameTmp));
				memset(adminLoginPwd, 0, sizeof(adminLoginPwd));
				memset(adminLoginPwdTmp, 0, sizeof(adminLoginPwdTmp));
				auth2 = 0;
			}
		}
		//����ƶ����鿴����
		else if (m.x >= 340 && m.x <= 460 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(-160, 90, -40, 130);
			//������鿴����
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(TEXTtmp, 0, sizeof(TEXTtmp));
				memset(TEXT, 0, sizeof(TEXT));
				FILE* feedback;
				fopen_s(&feedback, ".\\Data\\RecordChainData\\feedback.txt", "r");
				if (feedback)
				{
					while (fscanf_s(feedback, "%s\n", TEXTtmp, 220) != EOF)
					{
						strcat_s(TEXT, 1 + strnlen_s(TEXT, sizeof(TEXT)) + strnlen_s(TEXTtmp, sizeof(TEXTtmp)), TEXTtmp);
						strcpy_s(TEXTtmp,"\n");
						strcat_s(TEXT, 1 + strnlen_s(TEXT, sizeof(TEXT)) + strnlen_s(TEXTtmp, sizeof(TEXTtmp)), TEXTtmp);
					}
					fclose(feedback);
					feedback = NULL;
				}
				if (strnlen_s(TEXT, sizeof(TEXT)) == 0)
				{
					MessageBox(hWnd, "���޹�����¼", " ", MB_OK);
				}
				else
				{
					MessageBox(hWnd, TEXT, "����ҳ��", MB_OK);
					if (MessageBox(hWnd, "�Ƿ���չ���", "", MB_OKCANCEL) == IDOK)
					{
						fopen_s(&feedback, ".\\Data\\RecordChainData\\feedback.txt", "w");
						if (feedback)
						{
							fclose(feedback);
							feedback = NULL;
							MessageBox(hWnd, "ɾ���ɹ�", " ", MB_OK);
						}
					}
				}
			}
		}
		//����ƶ����˳�����
		else if (m.x >= 540 && m.x <= 660 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(40, 90, 160, 130);
			//������˳�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				auth2 = 1;
			}
		}
		//����ƶ�������֮��
		else
		{
			setlinecolor(WHITE);
			rectangle(-160, -210, -40, -170);
			rectangle(40, -210, 160, -170);
			rectangle(-160, -110, -40, -70);
			rectangle(40, -110, 160, -70);
			rectangle(-160, -10, -40, 30);
			rectangle(40, -10, 160, 30);
			rectangle(40, 90, 160, 130);
			rectangle(-160, 90, -40, 130);
		}
		if (auth2 == 0 || auth2 == 1)
		{
			cleardevice(); pict();
			break;
		}
	}
}
//--------------------