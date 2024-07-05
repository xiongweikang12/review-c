#include <stdio.h>
#include "hash.h"

int SeachHT(HashTable ha, int p, KeyType key)
{	//�ڹ�ϣ���в���
	//��ѭ��ĳ��ӳ���
	//ͨ���ؼ��ִ��룬���ص�ַ
	//��洢Ҳ����ѭ�����Ĺ����
	int i = 0;
	int adress = key % p;
	while (ha[adress].key!=NULLKEY && ha[adress].key!=key)
	{
		i++; //��ʾ��ͻ��key�Ѵ��ڣ���NULLKEY
		adress = (adress + 1) % p;//����̽�⵽��һ�����еĵ�ַ
	}
	if (ha[adress].key == key)
	{
		return adress; //���ҳɹ�
	}
	else
	{
		return -1;//����ʧ��
	}
}

int DeleteHT(HashTable ha, int p, KeyType key)
{	//ɾ����ͨ��Search key���� adress
	//�޲��ң�����-1
	//����ɾ��key,ͨ����ַ�����޸�keyΪDELKEY
	int adress = SeachHT(ha, p, key);
	if (adress != -1)
	{
		ha[adress].key = DELKEY;//���
		return 1;
	}
	else
	{
		return 0;//ɾ��ʧ��
	}
}

void InsertHT(HashTable ha, int p, KeyType key)
{
	int adress = key % p;
	int i = 0;
	//������keyΪNULLKEY �� DELKEY��
	if (ha[adress].key == NULLKEY || ha[adress].key == DELKEY)
	{
		ha[adress].key = key;
		ha[adress].count = 1;
	}
	else //ha[adress]�Ѵ���key���������������̽��
	{
		i = 1;
		do
		{
			adress = (adress + 1) % p;
			i++;

		} while (ha[adress].key!=NULLKEY &&ha[adress].key!=DELKEY);
		//Ҫ�����������������˳�
		ha[adress].key = key;
		ha[adress].count = i;
	}
}

void creatHT(HashTable ha, int p, KeyType key[],int n)
{ //����ʱ����ؼ�ֵ����
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}//��ʼ��
	for (i = 0; i < n; i++)
	{
		InsertHT(ha, p, key[i]);
	}
}

void DisplayHT(HashTable ha, int n)
{
	printf("��ϣ���ַ :\t");
	for (int i = 0; i < n; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	printf("��ϣ��ؼ��� :\t");
	for (int i = 0; i < n; i++)
	{
		if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
		{
			printf("   ");
		}
		else
		{
			printf("%3d", ha[i].key);
		}
	}
	printf("\n");
	printf(" �������� :\t ");
	for (int i = 0; i < n; i++)
	{
		if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
		{
			printf("   ");
		}
		else
		{
			printf("%3d", ha[i].count);
		}
	}
	printf("\n");
	show_ASL(ha, n);
}

void show_ASL(HashTable ha, int n)
{
	int  i;
	double sum_road = 0;
	double i_key = 0;
	for (i = 0; i < n; i++)
	{
		if (ha[i].key != NULLKEY && ha[i].key != DELKEY)
		{
			i_key++;
			sum_road += ha[i].count;
		}
		else
		{
			continue;
		}
	}
	printf("\nɢ�б�˴β��ҵ�ASLΪ : % .2f", (sum_road / i_key));

}