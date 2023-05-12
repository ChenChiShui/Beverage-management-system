#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"..\Headfiles\InputCheck.h"
#include"..\Headfiles\RecordChain.h"
#include"..\Headfiles\ClientChain.h"
#include"..\Headfiles\CommodityChain.h"
#include"..\Headfiles\GetTime.h"
#include"..\Headfiles\ChainOpt.h"

extern struct CommodityNode* commodityHead, * commodityTail;
extern struct userRecordNode* userRecordHead;
extern struct userRecordNode* userRecordTail;
//--------------------
//����Ϊ������¼����ĺ���
void buildRecordChain(struct RecordNode** head, struct RecordNode** tail)
{
    // ��ֻ��ģʽ���ļ�
    FILE* recordFILE;
    fopen_s(&recordFILE,".\\Data\\RecordChainData\\RecordData.txt", "r");
    *head = *tail = NULL; // �ȳ�ʼ����ֹ����������Ұֵ
    struct RecordNode* pre = NULL, * now = NULL;
    if (recordFILE)
    {
        int opt;
        fscanf_s(recordFILE, "%d", &opt); // opt==-1Ϊֹͣ��ӽڵ㣬==1Ϊ����½ڵ�
        while (opt == 1)
        {
            now = (struct RecordNode*)malloc(sizeof(struct RecordNode));
            now->preRecord = NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            now->nextRecord =NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            // ���´�������¼��ÿ����¼��ϸ����Ϣ�� ���ɴ���鷽���۵�
            {
                int temp;   // temp ������bool���ͱ���isSoldOut��ֵ
                fscanf_s(recordFILE, "%d", &temp);
                if (temp == 1)
                    now->isSoldOut = true;
                else
                    now->isSoldOut = false;
                fscanf_s(recordFILE, "%s", &now->commodityName, 50);
                fscanf_s(recordFILE, "%s", &now->clientName,50);
                fscanf_s(recordFILE, "%lf", &now->purchasePrice);
                fscanf_s(recordFILE, "%lf", &now->soldPrice);
                fscanf_s(recordFILE, "%d", &now->unitCount);
                fscanf_s(recordFILE, "%d", &now->historyLv);
                fscanf_s(recordFILE, "%d %d %d", &now->year, &now->month, &now->day);
                fscanf_s(recordFILE, "%d", &now->situation);
                // fscanf("")
            }

            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextRecord = now;
                now->preRecord = pre;
            }
            pre = now;
            fscanf_s(recordFILE, "%d", &opt);
        }
        *tail = now;
        fclose(recordFILE);
    }
    recordFILE = NULL;
}
//--------------------

//--------------------
//����Ϊɾ����¼����ĺ���
void  delRecord(struct RecordNode** head, struct RecordNode** tail, struct RecordNode* p)
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

            //�˲��ֿ�����Ҫ����
            struct CommodityNode* searchPtr = commodityHead;
            while (searchPtr != NULL)
            {
                if (strcmp(searchPtr->commodityName, (*head)->commodityName) == 0)
                {
                    if ((*head)->isSoldOut == true)
                        searchPtr->unitCount += (*head)->unitCount;
                    else if ((*head)->isSoldOut == false)
                        searchPtr->unitCount -= (*head)->unitCount;
                }
                searchPtr = searchPtr->nextCommodity;
            }
            rebuildCommodityFile(commodityHead);
            *head = *tail = NULL; // free���ڴ汻��������ָ����ָ��õ�ַ�������ÿշ�bug
            return;
        }
        if (*head == p && *tail != p)
        {
            // Ҫɾ���Ľڵ���ͷ��������β
            struct RecordNode* temp = *head;
            *head = (*head)->nextRecord;
            (*head)->preRecord = NULL;

            //�˲��ֿ�����Ҫ����
            struct CommodityNode* searchPtr = commodityHead;
            while (searchPtr != NULL)
            {
                if (strcmp(searchPtr->commodityName, temp->commodityName) == 0)
                {
                    if (temp->isSoldOut == true)
                        searchPtr->unitCount += temp->unitCount;
                    else if (temp->isSoldOut == false)
                        searchPtr->unitCount -= temp->unitCount;
                }
                searchPtr = searchPtr->nextCommodity;
            }
            rebuildCommodityFile(commodityHead);
            free(temp);
            return;
        }
        if (*head != p && *tail == p)
        {
            // Ҫɾ���Ľڵ���β��������ͷ
            struct RecordNode* temp = *tail;
            *tail = (*tail)->preRecord;
            (*tail)->nextRecord = NULL;

            //�˲��ֿ�����Ҫ����
            struct CommodityNode* searchPtr = commodityHead;
            while (searchPtr != NULL)
            {
                if (strcmp(searchPtr->commodityName, temp->commodityName) == 0)
                {
                    if (temp->isSoldOut == true)
                        searchPtr->unitCount += temp->unitCount;
                    else if (temp->isSoldOut == false)
                        searchPtr->unitCount -= temp->unitCount;
                }
                searchPtr = searchPtr->nextCommodity;
            }
            rebuildCommodityFile(commodityHead);
            free(temp);
            return;
        }
    }
    // ���ɾ���Ľڵ㲻��ͷ����β���������
    // ע�⣬p��ָ��ڵ��ָ�룬��head��tail��һ��
    p->nextRecord->preRecord = p->preRecord;
    p->preRecord->nextRecord = p->nextRecord;
    //��record�еı仯��Ӧ��commodity��

    struct CommodityNode* searchPtr = commodityHead;
    while (searchPtr != NULL)
    {
        if (strcmp(searchPtr->commodityName, p->commodityName) == 0)
        {
            if (p->isSoldOut == true)
                searchPtr->unitCount += p->unitCount;
            else if (p->isSoldOut == false)
                searchPtr->unitCount -= p->unitCount;
        }
        searchPtr = searchPtr->nextCommodity;
    }
    rebuildCommodityFile(commodityHead);
    free(p);
}
//--------------------

//--------------------
//����Ϊ���������¼�ĺ���
void addRecord(struct RecordNode** head, struct RecordNode** tail,char tempIsSoldOut,char commodityName[50],char clientName[50], double soldPrice,double purchasePrice,char tempUnitCount[50],int lv_)
{
    struct RecordNode* now = (struct RecordNode*)malloc(sizeof(struct RecordNode));
    now->preRecord = now->nextRecord = NULL;    // �����½ڵ��һ���¾���ָ���ʼ�����ǳ���Ҫ��
    if (*head == NULL && *tail == NULL)
    {
        *head = *tail = now;
        // ���������Ϣ�Ĵ����
        // �˴�Ӧ�бȽϸ��ӵķǷ�������
        {
            now->isSoldOut = (tempIsSoldOut == '1') ? true : false;
            now->situation = 0;
            now->historyLv = lv_;
            strcpy_s(now->commodityName, commodityName);
            strcpy_s(now->clientName, clientName);

            // ��Ҫһ��strToDouble������������
            now->soldPrice = soldPrice;
            now->purchasePrice = purchasePrice;
            // ������Ҫ
            now->unitCount = strToInt(tempUnitCount);
            getCurrentTime(&now->year, &now->month, &now->day);
        }
        return;
    }
    else {
        // ���ǵ�һ���ڵ㣬��ֻ��������ڵ�(tail)�ĺ���
        (*tail)->nextRecord = now;
        now->preRecord = *tail;
        *tail = now;

        // ���������Ϣ
        // �˴�Ӧ�бȽϸ��ӵķǷ�������
        
            now->isSoldOut = (tempIsSoldOut == '1') ? true : false;
            now->situation = 0;
            now->historyLv = lv_;
            strcpy_s(now->commodityName, commodityName);
            strcpy_s(now->clientName, clientName);

            // ��Ҫһ��strToDouble������������
            now->soldPrice = soldPrice;
            now->purchasePrice = purchasePrice;
            // ������Ҫ
            now->unitCount = strToInt(tempUnitCount);
            getCurrentTime(&now->year, &now->month, &now->day);
        return;
    }
}
//--------------------

//--------------------
//����Ϊ�ع���¼�ļ��ĺ���
void rebuildRecordFile(struct RecordNode* head) 
{
    // ��������ڵ㷢���仯ʱ��ִ�д˺�������дrecord.txt�ļ�
    // ע���Ǹ�д
    FILE* recordFile;
    fopen_s(&recordFile,".\\Data\\RecordChainData\\RecordData.txt", "w");
    if (recordFile)
    {
        while (head != NULL)
        {
            // ����ڵ�������Ϣ�Ĵ���飬�ڲ���ʱ����ʱֻ���unit count
            {
                fprintf(recordFile, "1\n");
                if (head->isSoldOut == true)
                {
                    fprintf(recordFile, "1\n");
                }
                else
                {
                    fprintf(recordFile, "0\n");
                }
                fprintf(recordFile, "%s\n", head->commodityName);
                fprintf(recordFile, "%s\n", head->clientName);
                fprintf(recordFile, "%.2f\n", head->purchasePrice);
                fprintf(recordFile, "%.2f\n", head->soldPrice);
                fprintf(recordFile, "%d\n", head->unitCount);
                fprintf(recordFile, "%d\n", head->historyLv);
                fprintf(recordFile, "%d %d %d\n", head->year, head->month, head->day);
                fprintf(recordFile, "%d\n", head->situation);
                fprintf(recordFile, "\n");
                head = head->nextRecord;
            }
        }
        fputs("-1", recordFile);
        fclose(recordFile);
    }
    recordFile = NULL;
}
//--------------------

//--------------------
//����Ϊ�����û������¼�ĺ���
void buildUserRecordChain(struct RecordNode* HEAD,struct userRecordNode** head, struct userRecordNode** tail,char userName[50])
{
    *head = *tail = NULL; // �ȳ�ʼ����ֹ����������Ұֵ
    struct RecordNode* temp=NULL;
    temp = HEAD;
    struct userRecordNode* pre = NULL, * now = NULL;
    while (temp)
    {
        if (strcmp(userName, temp->clientName)== 0 && getClientPtrFromName(temp->clientName) && getCommodityPtrFromName(temp->commodityName))
        {
            now = (struct userRecordNode*)malloc(sizeof(struct userRecordNode));
            now->nextRecord = NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            now->preRecord = NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            now->ptr = temp;
            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextRecord = now;
                now->preRecord = pre;
            }
            pre = now;
        }
        temp = temp->nextRecord;
    }
    *tail = now;
}
//--------------------

//--------------------
//����Ϊ�����˻���¼��¼�ĺ���
void buildUserRecordChainT(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail)
{
    *head = *tail = NULL; // �ȳ�ʼ����ֹ����������Ұֵ
    struct RecordNode* temp = NULL;
    temp = HEAD;
    struct userRecordNode* pre = NULL, * now = NULL;
    while (temp)
    {
        if (temp->situation==1&& getClientPtrFromName(temp->clientName)&& getCommodityPtrFromName(temp->commodityName))
        {
            now = (struct userRecordNode*)malloc(sizeof(struct userRecordNode));
            now->nextRecord = NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            now->preRecord = NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            now->ptr = temp;
            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextRecord = now;
                now->preRecord = pre;
            }
            pre = now;
        }
        temp = temp->nextRecord;
    }
    *tail = now;
}
//--------------------

//--------------------
//����Ϊ������Ʒ�йع����¼�ĺ���
void buildUserRecordChainC(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail, char commodityName[50])
{
    *head = *tail = NULL; // �ȳ�ʼ����ֹ����������Ұֵ
    struct RecordNode* temp = NULL;
    temp = HEAD;
    struct userRecordNode* pre = NULL, * now = NULL;
    while (temp)
    {
        if (strcmp(commodityName,temp->commodityName)==0 && getClientPtrFromName(temp->clientName) && getCommodityPtrFromName(temp->commodityName))
        {
            now = (struct userRecordNode*)malloc(sizeof(struct userRecordNode));
            now->nextRecord = NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            now->preRecord = NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            now->ptr = temp;
            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextRecord = now;
                now->preRecord = pre;
            }
            pre = now;
        }
        temp = temp->nextRecord;
    }
    *tail = now;
}
//--------------------
