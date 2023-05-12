#include"..\Headfiles\CartChain.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

extern double discount;//�����ⲿ����discount
//--------------------

//--------------------
//����Ϊ�����Ʒ�����ﳵ�ĺ���
void addCart(struct CartNode** head, struct CartNode** tail,double originPrice,int unitNumber,char unitName[50],int lv)
{
    struct CartNode* now = (struct CartNode*)malloc(sizeof(struct CartNode));
    now->preCart  = NULL;    // �����½ڵ��һ���¾���ָ���ʼ�����ǳ���Ҫ��
    now->nextCart = NULL;
    now->soldPrice_Original = originPrice*unitNumber;
    if (*head == NULL && *tail == NULL)
    {
        // ���������һ���ڵ�,�ýڵ㼴��ͷ����β
        *head = *tail = now;
        // ���������Ϣ�Ĵ����
        now->unitCount = unitNumber;
        now->soldPrice_Discount = originPrice * unitNumber*discount;
        now->historylv = lv;
        strcpy_s(now->unitName,unitName);
        return;
    }
    else {
        // ���ǵ�һ���ڵ㣬��ֻ��������ڵ�(tail)�ĺ���
        (*tail)->nextCart = now;
        now->preCart = *tail;
        *tail = now;
        // ���������Ϣ
        now->unitCount = unitNumber;
        now->soldPrice_Discount = originPrice *unitNumber* discount;
        now->historylv = lv;
        strcpy_s(now->unitName, unitName);
        return;
    }
}
//--------------------

//--------------------
//����Ϊɾ�����ﳵ��Ʒ�ĺ���
void  delCart(struct CartNode** head, struct CartNode** tail, struct CartNode* p)
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
            struct CartNode* temp = *head;
            *head = (*head)->nextCart;
            (*head)->preCart = NULL;
            free(temp);
            return;
        }
        if (*head != p && *tail == p)
        {
            // Ҫɾ���Ľڵ���β��������ͷ
            struct CartNode* temp = *tail;
            *tail = (*tail)->preCart;
            (*tail)->nextCart = NULL;
            free(temp);
            return;
        }
    }
    // ���ɾ���Ľڵ㲻��ͷ����β���������
    // ע�⣬p��ָ��ڵ��ָ�룬��head��tail��һ��
    p->nextCart->preCart = p->preCart;
    p->preCart->nextCart = p->nextCart;
    free(p);
}
//--------------------