#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"..\Headfiles\InputCheck.h"
#include"..\Headfiles\CommodityChain.h"
#include"..\Headfiles\GetTime.h"

//--------------------
//����Ϊ��Ʒ����������
void buildCommodityChain(struct CommodityNode** head, struct CommodityNode** tail)
{
    FILE* commodityFILE;
    fopen_s(&commodityFILE,".\\Data\\CommodityChainData\\CommodityData.txt", "r");
    if (commodityFILE)
    {
        *head = *tail = NULL; // �ȳ�ʼ����ֹ����������Ұֵ
        int opt;
        fscanf_s(commodityFILE, "%d", &opt); // opt==-1Ϊֹͣ��ӽڵ㣬==1Ϊ����½ڵ�
        struct CommodityNode* pre = NULL, * now = NULL;
        while (opt == 1)
        {
            now = (struct CommodityNode*)malloc(sizeof(struct CommodityNode));
            now->nextCommodity = NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��
            now->preCommodity = NULL; // ������ռ�ֱ�Ӱ�ָ���ʼ��

            // ���´�������¼��ÿ����¼��ϸ����Ϣ�� ���ɴ���鷽���۵�
            {
                fscanf_s(commodityFILE, "%s", &now->commodityName, 50);
                fscanf_s(commodityFILE, "%lf", &now->purchasePrice);
                fscanf_s(commodityFILE, "%lf", &now->soldPrice);
                fscanf_s(commodityFILE, "%d", &now->unitCount);
                // fscanf("")
            }

            if (*head == NULL)
            {
                *head = now;

            }
            else {
                pre->nextCommodity = now;
                now->preCommodity = pre;
            }
            pre = now;
            fscanf_s(commodityFILE, "%d", &opt);
        }
        *tail = now;

        fclose(commodityFILE);
    }
    commodityFILE = NULL;
}
//--------------------

//--------------------
//����Ϊɾ����Ʒ�ĺ���
void  delCommodity(struct CommodityNode** head, struct CommodityNode** tail, struct CommodityNode* p)
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
            struct CommodityNode* temp = *head;
            *head = (*head)->nextCommodity;
            (*head)->preCommodity = NULL;
            free(temp);
            return;
        }
        if (*head != p && *tail == p)
        {
            // Ҫɾ���Ľڵ���β��������ͷ
            struct CommodityNode* temp = *tail;
            *tail = (*tail)->preCommodity;
            (*tail)->nextCommodity = NULL;
            free(temp);
            return;
        }
    }
    // ���ɾ���Ľڵ㲻��ͷ����β���������
    // ע�⣬p��ָ��ڵ��ָ�룬��head��tail��һ��
    p->nextCommodity->preCommodity = p->preCommodity;
    p->preCommodity->nextCommodity = p->nextCommodity;
    free(p);
}
//--------------------

//--------------------
//����Ϊ�����Ʒ�ĺ���
void addCommodity(struct CommodityNode** head, struct CommodityNode** tail, char commodityName[50], double soldPrice, double purchasePrice, int unitCount)
{
    struct CommodityNode* now = (struct CommodityNode*)malloc(sizeof(struct CommodityNode));
    now->preCommodity =  NULL;    // �����½ڵ��һ���¾���ָ���ʼ�����ǳ���Ҫ��
    now->nextCommodity = NULL;
    if (*head == NULL && *tail == NULL)
    {
        *head = *tail = now;
        // ���������Ϣ�Ĵ����
        strcpy_s(now->commodityName, commodityName);
        now->purchasePrice = purchasePrice;
        now->soldPrice = soldPrice;
        now->unitCount = unitCount;
        return;
    }
    else {
        // ���ǵ�һ���ڵ㣬��ֻ��������ڵ�(tail)�ĺ���
        (*tail)->nextCommodity = now;
        now->preCommodity = *tail;
        *tail = now;
        // ���������Ϣ
        strcpy_s(now->commodityName, commodityName);
        now->purchasePrice = purchasePrice;
        now->soldPrice = soldPrice;
        now->unitCount = unitCount;
        return;
    }
}
//--------------------

//--------------------
//����Ϊ�ع���Ʒ�ļ��ĺ���
void rebuildCommodityFile(struct CommodityNode* head)
{
    FILE* commodityFile;
    fopen_s(&commodityFile,".\\Data\\CommodityChainData\\CommodityData.txt", "w");
    if (commodityFile)
    {
        while (head != NULL)
        {
            // ����ڵ�������Ϣ�Ĵ���飬�ڲ���ʱ����ʱֻ���unit count
            {
                fprintf(commodityFile, "1\n");
                fprintf_s(commodityFile, "%s\n", head->commodityName);
                fprintf_s(commodityFile, "%.2f\n", head->purchasePrice);
                fprintf_s(commodityFile, "%.2f\n", head->soldPrice);
                fprintf_s(commodityFile, "%d\n", head->unitCount);
                fprintf_s(commodityFile, "\n");
                head = head->nextCommodity;
            }
        }
        fputs("-1", commodityFile);
        fclose(commodityFile);
    }
    commodityFile = NULL;
}
//--------------------
