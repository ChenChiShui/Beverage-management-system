#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include "..\Headfiles\ChainOpt.h"
#include"..\Headfiles\ClientChain.h"
#include"..\Headfiles\RecordChain.h"
#include"..\Headfiles\CommodityChain.h"
#include"..\Headfiles\CartChain.h"

//--------------------
//�ⲿ���������� �����ͷ�ڵ�ָ��
extern struct RecordNode* recordHead;//��¼����ͷ
extern struct ClientNode* clientHead;//�ͻ�����ͷ
extern struct CommodityNode* commodityHead;//��Ʒ����ͷ
extern struct CartNode* cartHead;//���ﳵ����
extern struct userRecordNode* userRecordHead;
extern struct userRecordNode* userRecordTail;
extern struct userRecordNode* userRecordHeadT;
extern struct userRecordNode* userRecordTailT;
extern struct userRecordNode* userRecordHeadC;
extern struct userRecordNode* userRecordTailC;
//--------------------
// 
//--------------------
//����Ϊ���ݺ���
char ch;
void backupAll()
{
    //RecordData.txt���ݼ�¼�ļ�
    FILE* recordFile;
    fopen_s(&recordFile,".\\Data\\RecordChainData\\RecordData.txt", "r");
    FILE* recordFile_backup;
    fopen_s(&recordFile_backup,".\\Data\\RecordChainData\\RecordData_backup.txt", "w");
    if (recordFile && recordFile_backup)
    {
       ch = fgetc(recordFile);
        while (ch != EOF)
        {
            fputc(ch, recordFile_backup);
            ch = fgetc(recordFile);
        }
        fclose(recordFile);     fclose(recordFile_backup);
    }
    recordFile = recordFile_backup = NULL;
    //feedback.txt���ݼ�¼�ļ�
    FILE* feedFile;
    fopen_s(&feedFile, ".\\Data\\RecordChainData\\feedback.txt", "r");
    FILE* feedbkFile_backup;
    fopen_s(&feedbkFile_backup, ".\\Data\\RecordChainData\\feedback_backup.txt", "w");
    if (feedFile && feedbkFile_backup)
    {
        ch = fgetc(feedFile);
        while (ch != EOF)
        {
            fputc(ch, feedbkFile_backup);
            ch = fgetc(feedFile);
        }
        fclose(feedFile);     fclose(feedbkFile_backup);
    }
    recordFile = recordFile_backup = NULL;
    //ClientData.txt���ݿͻ��ļ�
    FILE* clientFile;
    fopen_s(&clientFile,".\\Data\\ClientChainData\\ClientData.txt", "r");
    FILE* clientFile_backup;
    fopen_s(&clientFile_backup,".\\Data\\ClientChainData\\ClientData_backup.txt", "w");
    if (clientFile && clientFile_backup)
    {
        ch = fgetc(clientFile);
        while (ch != EOF)
        {
            fputc(ch, clientFile_backup);
            ch = fgetc(clientFile);
        }
        fclose(clientFile);     fclose(clientFile_backup);
    }
    clientFile = clientFile_backup = NULL;
    //CommodityData.txt.txt������Ʒ�ļ�
    FILE* commodityFile;
    fopen_s(&commodityFile,".\\Data\\CommodityChainData\\CommodityData.txt", "r");
    FILE* commodityFile_backup;
    fopen_s(&commodityFile_backup,".\\Data\\CommodityChainData\\CommodityData_backup.txt", "w");
    if (commodityFile && commodityFile_backup)
    {
        ch = fgetc(commodityFile);
        while (ch != EOF)
        {
            fputc(ch, commodityFile_backup);
            ch = fgetc(commodityFile);
        }
        fclose(commodityFile);     fclose(commodityFile_backup);
    }
    commodityFile = commodityFile_backup = NULL;
    //AdminData.txt���ݹ���Ա��¼���˺�����
    FILE* adminDataFile;
    fopen_s(&adminDataFile,".\\Data\\loginData\\adminData.txt", "r");
    FILE* adminDataFile_backup;
    fopen_s(&adminDataFile_backup,".\\Data\\loginData\\adminData_backup.txt", "w");
    if (adminDataFile && adminDataFile_backup)
    {
        ch = fgetc(adminDataFile);
        while (ch != EOF)
        {
            fputc(ch, adminDataFile_backup);
            ch = fgetc(adminDataFile);
        }
        fclose(adminDataFile);     fclose(adminDataFile_backup);
    }
    adminDataFile = adminDataFile_backup = NULL;
    //UserData.txt�����û���¼���˺�����
    FILE* userDataFile;
    fopen_s(&userDataFile,".\\Data\\loginData\\userData.txt", "r");
    FILE* userDataFile_backup;
    fopen_s(&userDataFile_backup,".\\Data\\loginData\\userData_backup.txt", "w");
    if (userDataFile && userDataFile_backup)
    {
        ch = fgetc(userDataFile);
        while (ch != EOF)
        {
            fputc(ch, userDataFile_backup);
            ch = fgetc(userDataFile);
        }
        fclose(userDataFile);     fclose(userDataFile_backup);
    }
    userDataFile = userDataFile_backup = NULL;

}
//--------------------

//--------------------
//����Ϊ�ڴ��ͷź���
void releaseAll()
{
    // RecordChain�ͷ�
    struct RecordNode* p = recordHead;
    struct RecordNode* pp = NULL;
    while (p)
    {
        pp = p;
        p = p->nextRecord;
        free(pp);
    }
    // ClientChain�ͷ�
    struct ClientNode* q = clientHead;
    struct ClientNode* qq = NULL;
    while (q)
    {
        qq = q;
        q = q->nextClient;
        free(qq);
    }
    //CommodityChain�ͷ�
    struct CommodityNode* r = commodityHead;
    struct CommodityNode* rr = NULL;
    while (r)
    {
        rr = r;
        r = r->nextCommodity;
        free(rr);
    }
    //CartChain�ͷ�
    struct CartNode* t = cartHead;
    struct CartNode* tt = NULL;
    while (t)
    {
        tt = t;
        t = t->nextCart;
        free(tt);
    }
    //�û������¼�����ͷ�
    struct userRecordNode* s = userRecordHead;
    struct userRecordNode* ss = NULL;
    while (s)
    {
        ss = s;
        s = s->nextRecord;
        free(ss);
    }
    //�˻���¼����
    struct userRecordNode* n = userRecordHeadT;
    struct userRecordNode* nn = NULL;
    while (n)
    {
        nn = n;
        n = n->nextRecord;
        free(nn);
    }
    struct userRecordNode* m = userRecordHeadC;
    struct userRecordNode* mm = NULL;
    while (m)
    {
        mm = m;
        m = m->nextRecord;
        free(mm);
    }
}
//-------------------

//--------------------
//����Ϊ�û�Ѱ�Һ���
struct ClientNode* getClientPtrFromName(char yourName[])
{
    struct ClientNode* searchPtr = clientHead;
    struct ClientNode* res = NULL;
    while (searchPtr != NULL)
    {
        if (strcmp(searchPtr->clientName, yourName) == 0)
        {
            res = searchPtr;
            return res;
        }
        searchPtr = searchPtr->nextClient;
    }
    return res;
}
//--------------------

//-------------------
//��Ϊ��ȡ��Ʒָ��ĺ���
struct CommodityNode* getCommodityPtrFromName(char yourName[])
{
    struct CommodityNode* searchPtr = commodityHead;
    struct CommodityNode* res = NULL;
    while (searchPtr != NULL)
    {
        if (strcmp(searchPtr->commodityName, yourName) == 0)
        {
            res = searchPtr;
            return res;
        }
        searchPtr = searchPtr->nextCommodity;
    }
    return res;
}
//--------------------