//--------------------
//����Ϊ��Ʒ�����ܺ����ͽṹ�������
//--------------------

#ifndef _COMMODITYCHAIN_H_
#define _COMMODITYCHAIN_H_
//--------------------
//����Ϊ�ṹ������
struct CommodityNode {
    char commodityName[50];
    double soldPrice;
    double purchasePrice;
    int unitCount;//��ǰ����
    struct CommodityNode* nextCommodity, * preCommodity;
};
//--------------------

//--------------------
//����Ϊ���ܺ���
void buildCommodityChain(struct CommodityNode** head, struct CommodityNode** tail);//������Ʒ����
void delCommodity(struct CommodityNode** head, struct CommodityNode** tail, struct CommodityNode* p);//ɾ����Ʒ
void addCommodity(struct CommodityNode** head, struct CommodityNode** tail, char commodityName[50], double soldPrice, double purchasePrice, int unitCount);//�����Ʒ
void rebuildCommodityFile(struct CommodityNode* head);//�ع���Ʒ�ļ�
//--------------------
#endif //CLIONPROJECT_COMMODITYCHAIN_H
