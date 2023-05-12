//--------------------
//����Ϊ��¼�����ܺ����ͽṹ�������
//--------------------

#ifndef _RECORDCHAIN_H_
#define _RECORDCHAIN_H_
#include <stdbool.h>

//--------------------
//��¼�ṹ��
struct RecordNode {
    bool isSoldOut;  // ���ֽ�����������¼

    // commodityName����Ʒ����
    char commodityName[50];
    char clientName[50];
    int situation;
    int unitCount;
    int year, month, day;
    int historyLv;

    double purchasePrice, soldPrice; //���ۣ��ۼ�

    struct RecordNode* nextRecord, * preRecord;
    // struct RecordNode * toClientNode;
};
struct userRecordNode 
{
  struct RecordNode* ptr;
  struct userRecordNode* nextRecord, * preRecord;
};
//--------------------

//����Ϊ������¼����ĺ���
void buildRecordChain(struct RecordNode** head, struct RecordNode** tail);
//����Ϊɾ����¼����ĺ���
void delRecord(struct RecordNode** head, struct RecordNode** tail, struct RecordNode* p);
//����Ϊ���������¼�ĺ���
void addRecord(struct RecordNode** head, struct RecordNode** tail, char tempIsSoldOut, char commodityName[50], char clientName[50], double soldPrice, double purchasePrice, char tempUnitCount[50], int lv_);
//����Ϊ�ع���¼�ļ��ĺ���
void rebuildRecordFile(struct RecordNode* head);
//����Ϊ�����û������¼�ĺ���
void buildUserRecordChain(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail, char userName[50]);
//����Ϊ�����˻���¼��¼�ĺ���
void buildUserRecordChainT(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail);
//������Ʒ�йؼ�¼
void buildUserRecordChainC(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail, char commodityName[50]);
#endif


