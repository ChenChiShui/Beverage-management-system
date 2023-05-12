#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"..\Headfiles\InputCheck.h"
#include"..\Headfiles\ClientChain.h"
#include"..\Headfiles\GetTime.h"

//-------------------
//����Ϊ�ͻ�����������
void buildClientChain(struct ClientNode** head, struct ClientNode** tail)
{
    FILE* clientFILE;
    fopen_s(&clientFILE,".\\Data\\ClientChainData\\ClientData.txt", "r");
    *head = *tail = NULL; // �ȳ�ʼ����ֹ����������Ұֵ
    int opt;//����
    if (clientFILE)
    {
        fscanf_s(clientFILE, "%d", &opt); // opt==-1Ϊֹͣ��ӽڵ㣬==1Ϊ����½ڵ�
        struct ClientNode* pre = NULL, * now = NULL;
        while (opt == 1)
        {
            now = (struct ClientNode*)malloc(sizeof(struct ClientNode));
            now->nextClient= NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            now->preClient = NULL;
            // ���´�������¼��ÿ����¼��ϸ����Ϣ�� ���ɴ���鷽���۵�
            {
                fscanf_s(clientFILE,"%s",&now->clientName, 50);
                fscanf_s(clientFILE,"%d",&now->lv);
                fscanf_s(clientFILE,"%lf",&now->balance);
                fscanf_s(clientFILE,"%d %d %d",&now->year,&now->month,&now->day);
                fscanf_s(clientFILE,"%d",&now->isCostumer);
                fscanf_s(clientFILE,"%d",&now->situation);
                // fscanf("")
            }
            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextClient = now;
                now->preClient = pre;
            }
            pre = now;
            fscanf_s(clientFILE, "%d", &opt);
        }
        *tail = now;
        fclose(clientFILE);
    }
    clientFILE = NULL;
}
//--------------------

//-------------------
//����Ϊɾ���ͻ��ĺ���
void  delClient(struct ClientNode** head, struct ClientNode** tail, struct ClientNode* p)
{
    // ** head, ** tail��ͷβָ��ĵ�ַ��ֱ�Ӷ�������ã�Ȼ������޸�
    // ע�⣬p��ָ��ڵ��ָ�룬��head��tail��һ��
    if (*head == p || *tail == p)
    {
        // ���Ҫɾ���Ľڵ�Ƚ����⣬��ͷ��β�ڵ�
        if (*head == p && *tail == p)
        {
            // Ҫɾ���Ľڵ����ͷ����β�� ��ʱ����ֻ����һ��Ԫ��
            free(*head);
            *head = *tail = NULL; // free���ڴ汻��������ָ����ָ��õ�ַ�������ÿշ�bug
            return;
        }
        if (*head == p && *tail != p)
        {
            // Ҫɾ���Ľڵ���ͷ��������β
            struct ClientNode* temp = *head;
            *head = (*head)->nextClient;
            (*head)->preClient = NULL;
            free(temp);
            return;
        }
        if (*head != p && *tail == p)
        {
            // Ҫɾ���Ľڵ���β��������ͷ
            struct ClientNode* temp = *tail;
            *tail = (*tail)->preClient;
            (*tail)->nextClient = NULL;
            free(temp);
            return;
        }
    }
    // ���ɾ���Ľڵ㲻��ͷ����β���������
    // ע�⣬p��ָ��ڵ��ָ�룬��head��tail��һ��
    p->nextClient->preClient = p->preClient;
    p->preClient->nextClient = p->nextClient;
    free(p);
}
//-------------------

//--------------------
//����Ϊ��ӿͻ��ĺ���
void addClient(struct ClientNode** head, struct ClientNode** tail,char clientNAME[], char tempLv[],int isCostumer)
{
    struct ClientNode* now = (struct ClientNode*)malloc(sizeof(struct ClientNode));
    now->preClient =NULL;    // �����½ڵ��һ���¾���ָ���ʼ�����ǳ���Ҫ��
    now->nextClient = NULL;
    now->balance = 0.00;    //�´������û����Ϊ0
    if (*head == NULL && *tail == NULL)
    {
        // ���������һ���ڵ�,�ýڵ㼴��ͷ����β
        *head = *tail = now;
        // ���������Ϣ�Ĵ����
        strcpy_s(now->clientName,clientNAME);
        now->lv = strToInt(tempLv);
        now->situation = 0;
        getCurrentTime(&now->year, &now->month, &now->day);
        now->isCostumer = isCostumer;
        return;
    }
    else {
        // ���ǵ�һ���ڵ㣬��ֻ��������ڵ�(tail)�ĺ���
        (*tail)->nextClient = now;
        now->preClient = *tail;
        *tail = now;
        // ���������Ϣ
        strcpy_s(now->clientName, clientNAME);
        now->lv = strToInt(tempLv);
        now->situation = 0;
        getCurrentTime(&now->year, &now->month, &now->day);
        now->isCostumer = isCostumer;
        return;
    }
}
//--------------------

//--------------------
//����Ϊ�ع��ͻ��ļ��ĺ���
void rebuildClientFile(struct ClientNode* head)
{
    FILE* clientFile;
    fopen_s(&clientFile,".\\Data\\ClientChainData\\ClientData.txt", "w");
    if (clientFile)
    {
        while (head != NULL)
        {
            // ����ڵ�������Ϣ�Ĵ���飬�ڲ���ʱ����ʱֻ���unit count
            {
                fprintf(clientFile, "1\n");
                fprintf_s(clientFile, "%s\n", head->clientName);
                fprintf_s(clientFile, "%d\n", head->lv);
                fprintf_s(clientFile, "%.2f\n", head->balance);
                fprintf_s(clientFile, "%d %d %d\n", head->year, head->month, head->day);
                fprintf_s(clientFile, "%d\n", head->isCostumer);
                fprintf_s(clientFile, "%d\n", head->situation);
                fprintf_s(clientFile, "\n");
                head = head->nextClient;
            }
        }
        fputs("-1", clientFile);
        fclose(clientFile);
    }
    clientFile = NULL;
}
//--------------------