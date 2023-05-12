#include <math.h>
#include <string.h>
#include<stdbool.h>
#include "..\Headfiles\InputCheck.h"

#define strnlen_s strnlen

//-------------------
//����Ϊ���ܺ���
//�Ƿ�Ϊ�ַ�
bool isCharacter(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
//�Ƿ�Ϊ��������
bool isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}
//�Ƿ�ȫ���ַ�
bool isFullCharacter(char str[])
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (!isCharacter(str[i]))
			return false;
	return true;
}
//�Ƿ�ȫ����������
bool isFullDigit(char str[])
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (!isDigit(str[i]))
			return false;
	return true;
}
//�Ƿ�Ϊ��׼����
bool isStdInput(char str[])
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (!(isCharacter(str[i]) || isDigit(str[i])))
			return false;
	return true;
}
//��д��дΪСд���಻��
void strToLower(char str[])
{
	// (int)'a' - 'A' = 32
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
}
//�ַ�תΪ����
int strToInt(char str[])
{
	int res = 0, L = strlen(str);
	for (int i = 0; i < L; i++)
	{
		res = res * 10 + str[i] - '0';
	}
	return res;
}
//�ַ�ת������
double intStrToDouble(char str[])
{
	int res = 0, L = strlen(str);
	for (int i = 0; i < L; i++)
	{
		res = res * 10 + str[i] - '0';
	}
	return res;
}
//�Ƿ��׼�ĸ�����
bool isStandardFloat(char str[])
{
	int i = strlen(str);
	int k = 0;

	//������ָ���������
	for (int m = 0; m < i; m++)
	{
		if (str[m] == '-')
			return false;
	}

	if (i > 9)
		return false;
	int j = 0;
	int z = 0;
	if (str[0] == '.' || str[i - 1] == '.')
		return false;
	for (; j < i; j++)
	{
		if (str[j] == '.')
		{
			z++;
			if (z == 1)
			{
				k = j;
			}
		}
	}
	if (z == 1)
	{
		if (k + 3 < i)
			return false;
		else
			return true;
	}
	else {
		return false;
	}
}
//�ַ�ת��Ϊ������
double strToDouble(char str[])
{
	int i = strlen(str);
	int j = 0;
	int z = 0;
	for (; j < i; j++)
	{
		if (str[j] == '.')
		{
			z = j;
			break;
		}
	}
	double sum = 0;
	j = z - 1;
	double tmp = 1;
	for (; j >= 0; j--)
	{
		sum += (str[j] - '0') * tmp;
		tmp *= 10;
	}
	j = z + 1;
	tmp = 0.1;
	for (; j < i; j++)
	{
		sum += 1.0 * (str[j] - '0') * tmp;
		tmp = tmp * 0.1;
	}
	return sum;
}
//�Ƿ�Ϊ��׼���ı�
bool isStandardText(char str[])
{
	int len = 0;
	int i = 0;
	len = strnlen_s(str, sizeof(str));
	for (; i < len;i++)
	{
		if (str[i] == ' ')
		{
			return false;
		}
	}
	return true;
}
//--------------------