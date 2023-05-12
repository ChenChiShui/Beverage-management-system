//���ؿ���̨
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//����ͷ�ļ�������
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
#include<math.h>
//--------------------

//--------------------
//����ͷ�ļ������ã���Ҫ��ͷ�ļ�����㶨��ȫ�ֱ��� �����ض��壩
#include".\Headfiles\GraphPage.h"
#include".\Headfiles\loginFunction.h"
#include".\Headfiles\ClientChain.h"
#include".\Headfiles\CommodityChain.h"
#include".\Headfiles\RecordChain.h"
#include".\Headfiles\ChainOpt.h"
#include".\Headfiles\CartChain.h"
//-------------------
 
//-------------------
//��¼���ñ�������
int auth = -1;//�ж��û���� ��ʼ��Ϊ-1
int auth1 = -1;//�ж��û��˳�ʱ��ѡ�� ��ע�������˳�����
int auth2 = -1;//�ж�����Ա�˳�ʱ��ѡ�� ��ע�������˳�����
char userCurrentName[50];//���ַ����洢��ǰ��¼�û����û���
char adminCurrentName[50];//���ַ����洢��ǰ��¼����Ա���û���
char tempStr1[50];//�û���¼�ɹ�����ʾ�ַ���
char tempStr2[50];//����Ա��¼�ɹ�����ʾ�ַ���
HWND hWnd;//easyx����
IMAGE background;
//--------------------

//--------------------
//�߸������ָ��
struct RecordNode* recordHead = NULL, * recordTail = NULL;//��¼����
struct ClientNode* clientHead = NULL, * clientTail = NULL;//�ͻ�����
struct CommodityNode* commodityHead = NULL, * commodityTail = NULL;//��Ʒ����
struct CartNode* cartHead = NULL, * cartTail = NULL;//���ﳵ����
struct userRecordNode* userRecordHead, * userRecordTail;
struct userRecordNode* userRecordHeadT, * userRecordTailT;
struct userRecordNode* userRecordHeadC, * userRecordTailC;
//--------------------

//--------------------
//����Ϊ������
int main(void)
{
	backupAll();//����ʼʱ���ȱ���ȫ���ļ�
	buildClientChain(&clientHead, &clientTail);//�����ͻ�����
	buildCommodityChain(&commodityHead,&commodityTail); //������Ʒ����
	buildRecordChain(&recordHead, &recordTail);// ������¼����
	initgraph(1000, 1000);//---�������� 1000*1000
	loadimage(&background, "picture.png", 1000, 1000);
	//setbkcolor(RGB(243, 230, 0));//---������ɫ
	setbkmode(TRANSPARENT);
	//cleardevice();//---���ֱ�����ɫ
	hWnd = GetHWnd();//---��ȡ����API
	SetWindowText(hWnd, "��ˮ��������ϵͳ�û���");// ʹ�� Windows API �޸Ĵ�������
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);//�����ö�
	MoveWindow(hWnd, 780, 220, 1000, 1040, TRUE);//����λ��---2k��Ļ���м�------------------------------------------------Ӧ������Ļ�ߴ����������޸�
	settextstyle(25, 12, "����", 0, 0, 500, 0, 0, 0);  //�������峤�� ��������
	setorigin(500, 500);//����ԭ��λ��
	Loop://����ע���˻��Ժ����½����¼����
	loginPage();//���е�¼��ע�����
	if (auth == 0)//�û��ڵ�½ע������˳�
	{
		MessageBox(hWnd, "��л����ʹ�� �ټ�", "Jlu_Bar_System_v1.0", MB_OKCANCEL);//��ʾ
		releaseAll();//�ͷ��ڴ�
		closegraph();//�رմ���
		return 0;
	}
	else if (auth == 1)//�û��ɹ���¼ �����û�����
	{
		sprintf_s(tempStr1, "�û�:%s", userCurrentName);//Ϊ��ʾ�ַ�����ֵ
		MessageBox(hWnd, "��¼�ɹ�", tempStr1, MB_OKCANCEL);//��ʾ
		userPage();//�����û�ҳ��
		if (auth1 == 1)
		{
			MessageBox(hWnd, "��л����ʹ�� �ټ�", "Jlu_Bar_System_v1.0", MB_OKCANCEL);//��ʾ
			releaseAll();//�ͷ��ڴ�
			closegraph();//�رմ���
			return 0;
		}
		else
		{
			auth = -1;//�ж��û���� ��ʼ��Ϊ-1
			auth1 = -1;//��ʼ���û��˳������ѡ��
			goto Loop;//��ת����¼
		}
	}
	else//����Ա�ɹ���¼ �������Ա����
	{
		sprintf_s(tempStr2, "����Ա:%s", adminCurrentName);//Ϊ��ʾ�ַ�����ֵ
		MessageBox(hWnd, "��¼�ɹ�", tempStr2, MB_OKCANCEL);//��ʾ
		adminPage();//�����û�ҳ��
		if (auth2 == 1)
		{
			MessageBox(hWnd, "��л����ʹ�� �ټ�", "Jlu_Bar_System_v1.0", MB_OKCANCEL);//��ʾ
			releaseAll();//�ͷ��ڴ�
			closegraph();//�رմ���
			return 0;
		}
		else
		{
			auth = -1;//�ж��û���� ��ʼ��Ϊ-1
			auth2 = -1;//��ʼ���û��˳������ѡ��
			goto Loop;//��ת����¼
		}
	}
}
//--------------------