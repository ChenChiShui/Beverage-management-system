//-------------------
//����Ϊ��׼��������ĺ�������
//--------------------

#ifndef _INPUTCHECK_H_
#define _INPUTCHECK_H_
//--------------------
//����Ϊ���ܺ���
bool isCharacter(char ch);//�Ƿ�Ϊ�ַ�
bool isDigit(char ch);//�Ƿ�Ϊ����
bool isFullCharacter(char str[]);//�Ƿ����ַ�
bool isFullDigit(char str[]);//�Ƿ�������
// ��׼������ζ�Ÿ��ַ���ֻ����ĸ������
bool isStdInput(char str[]);//�Ƿ�Ϊ��׼�������
// ��д��дΪСд�����಻��
void strToLower(char str[]);//��д��дΪСд���಻��
// ���ַ���ת��Ϊ����
// ʹ�ñ�����ǰ�������ж��ַ����Ϸ��ԣ�
int strToInt(char str[]);//�ַ�ת����
bool isStandardFloat(char str[]);//�Ƿ�Ϊ��׼�ĸ���������
double strToDouble(char str[]);//�ַ�ת������
double intStrToDouble(char str[]);//�����ַ�ת������
bool isStandardText(char str[]);
//--------------------
#endif