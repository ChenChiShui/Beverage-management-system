//--------------------
//����ʼǰ���еĲ���
//--------------------

#ifndef _CHAINOPT_H_
#define _CHAINOPT_H_
void backupAll();// ����ʼǰ����ִ��backupAll�������ļ�����
void releaseAll();// ����ʼǰ����ִ��backupAll�������ļ�����
struct ClientNode* getClientPtrFromName(char yourName[]);//���ݿͻ�����ȡ�ͻ�����ָ��
struct CommodityNode* getCommodityPtrFromName(char yourName[]);//������Ʒ����ȡ��Ʒ����ָ��
#endif