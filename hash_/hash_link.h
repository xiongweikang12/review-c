#include <stdio.h>

//key��Ӧ��һ������
//��ͻͬ��Ĵ����������У�
//������̽��̽���ظ����ҵĹ���

#define NO_FIND_KEY -1 //û���ҵ�key

#define END_INPUT_NUM -1 //���봴����ϣ��Ľ�����־

#define INSERT_FAIL 0 //����ʧ�ܣ�����key

#define INSERT_OK 1 //����ɹ�

//ɢ�б������ַ����ʾ����غ����������ṹ�嶨��

typedef int Keytype;

typedef int value;

typedef struct keynode {
	Keytype key;
	struct keynode* keynext;
}KeyNode ,*Key_link;
//����ָ�룬��������Ķ���

typedef struct hash_keylink {
	value data;
	Key_link key_Link;
}Hash_link[20];
//һ��������ָ��Ĺ�ϣ��

void intiHT(Hash_link, int);

int InsertHL(Hash_link, int, Keytype);

int SearchHL(Hash_link, int, Keytype);

void DeleteHL(Hash_link, int, Keytype);

void CreatHL(Hash_link, int, Keytype[]);

void DisplayHL(Hash_link, int);

