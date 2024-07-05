#include <stdio.h>
#include "hash_link.h"
#include <stdlib.h>


//ɢ�б������ַ����ʾ����غ�������

void intiHT(Hash_link HL, int n)
{
	for (int i = 0; i < n; i++)
	{
		HL[i].key_Link = NULL;
	}
	//��ʼ�������н��ָ��NULL��
}

int InsertHL(Hash_link HL, int p, Keytype key)
{
	int adress = key % p;
	if (HL[adress].key_Link == NULL)
	{
		KeyNode *new = (KeyNode*)malloc(sizeof(KeyNode));
		//�����½��
		new->keynext = NULL;
		new->key = key;
		HL[adress].key_Link = new;
		return INSERT_OK;
	}
	else
	{	
		Key_link pp = HL[adress].key_Link;
		//ָ��ͷ���
		while (pp->keynext)
		{
			if (pp->key == key)
			{
				//��β������·�ϣ������Ƚϣ��ж��Ƿ�key����
				//��Ϊ���룬����½�������
				printf("key:\t[ %d ]:\t %d �Ѵ��ڣ�����ʧ��", adress, key);
				return INSERT_FAIL;
			}
			pp = pp->keynext;
		}
		if (pp->key == key)
		{
			//������β�巨�����ָ����ָ��β�ͽ��
			//�����˳�ѭ��������Ҫ���ⲿ�ж�β�ͽ��
			printf("key:\t[ %d ]:\t %d �Ѵ��ڣ�����ʧ��",adress,key);
			return INSERT_FAIL;
		}
		else
		{
			KeyNode* newp = (KeyNode*)malloc(sizeof(KeyNode));
			newp->key = key;
			newp->keynext = pp->keynext;
			pp->keynext = newp;
			//�����½ڵ㣬β�巨
			return INSERT_OK;

		}
	}
}

int SearchHL(Hash_link HL, int p, Keytype key)
{
	int adress = key % p;
	if (HL[adress].key_Link == NULL)
	{
		return NO_FIND_KEY;
	}
	else
	{
		Key_link pp = HL[adress].key_Link->keynext;
		while (pp)
		{	//�����������ң���������;
			if (pp->key == key)
			{
				return adress;
			}
			pp = pp->keynext;
		}
		return NO_FIND_KEY;
	}
}

void DeleteHL(Hash_link HL, int p, Keytype key)
{	
	int adress = SearchHL(HL, p, key);
	//ͨ�����ң��ж��Ƿ���ڣ���ִ���Ƿ�ɾ��
	if ( adress!= NO_FIND_KEY)
	{
		Key_link pp = HL[adress].key_Link;
		while (pp->keynext)
		{
			if (pp->keynext->key == key) 
			{	//�����̵�keyΪ�ؼ�ֵkey
				//��ǰ���ָ���̵ĺ��
				//������ɾ�����
				//free�ͷ��ڴ�
				Key_link qq = pp->keynext;
				pp->keynext = pp->keynext->keynext;
				free(qq);
			}
			//����ɾ��
			pp = pp->keynext;
		}
		
	}
	else
	{
		printf("Ѱ�Ҳ������޷�ɾ��");
	}

}

void CreatHL(Hash_link HL, int p, Keytype key[])
{	
	int get_insert = 0;
	for (int i = 0; key[i] != END_INPUT_NUM; i++)
	{
		get_insert = InsertHL(HL, p, key[i]);
		//ѭ�����룬������ϣ��
	}
}

void DisplayHL(Hash_link HL, int l)
{	
	//չʾ����ַ��
	
	printf("\n");
	for (int i = 0; i < l; i++)
	{
		if (HL[i].key_Link == NULL)
		{
			printf("[%d]:^\t",i);
			printf("\n");
			continue;
		}
		else
		{
			//����һ��ָ��
			Key_link p = HL[i].key_Link;
			printf("[%d] : \t", i);
			while (p)
			{
				printf("%d -> ", p->key);
				p = p->keynext;
			}
			printf("\n");
		}
	}
}

