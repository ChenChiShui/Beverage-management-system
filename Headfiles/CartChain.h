//--------------------
//����Ϊ���ﳵ�����ܺ����ͽṹ�������
//--------------------

//--------------------
#ifndef _CARTCHAIN_H_
#define _CARTCHAIN_H_
struct CartNode {
    char unitName[50];
    double soldPrice_Original;
    double soldPrice_Discount;
    int unitCount;
    int historylv;
    struct CartNode* preCart, * nextCart;
};
void addCart(struct CartNode** head, struct CartNode** tail, double originPrice, int unitNumber, char unitName[50], int lv);//���ӹ��ﳵ�ڵ�
void  delCart(struct CartNode** head, struct CartNode** tail, struct CartNode* p);//ɾ���ù��ﳵ�ڵ�
#endif 
