//--------------------
//����Ϊ�ͻ������ܺ����ͽṹ�������
//--------------------

#ifndef _CLIENTCHAIN_H_
#define _CLIENTCHAIN_H_
//--------------------
//����Ϊ�ͻ�����Ľṹ������
struct ClientNode {
    int situation;//0δ�� 1 ����
    int isCostumer;    // 0 �˿ͣ�1 ������
    double balance;     // ����ǹ˿��������´������Ϊ0
    char clientName[50];
    int lv;
    int year, month, day;
    struct ClientNode* nextClient, * preClient;
};
//--------------------

//--------------------
//����Ϊ���ܺ���
void buildClientChain(struct ClientNode** head, struct ClientNode** tail);//�����ͻ�����
void delClient(struct ClientNode** head, struct ClientNode** tail, struct ClientNode* p);//ɾ���ͻ�
void addClient(struct ClientNode** head, struct ClientNode** tail, char clientNAME[], char tempLv[],int isCostumer);//��ӿͻ�
void rebuildClientFile(struct ClientNode* head);//�ع��ͻ��ļ�
//--------------------
#endif