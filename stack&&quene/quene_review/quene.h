#include "stack.h"

#define Maxlength 15
#define ERROR 0
#define OVERFLOW -1
#define OK 1

/*�����������*/
typedef struct quene {
	int *data;
	int front; //ͷָ��
	int rear; //βָ��
}SqQuene;

/*��������������ȡ����ѭ��*/

int initQuene(SqQuene* Q);
int Quenelength(SqQuene Q); 
int DeQuene(SqQuene* Q, int* e);
int EeQuene(SqQuene* Q, int content);
int GetHead(SqQuene Q);

