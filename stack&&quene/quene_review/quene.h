#include "stack.h"

#define Maxlength 15
#define ERROR 0
#define OVERFLOW -1
#define OK 1

/*定义队列类型*/
typedef struct quene {
	int *data;
	int front; //头指针
	int rear; //尾指针
}SqQuene;

/*真溢出，假溢出：取余变成循环*/

int initQuene(SqQuene* Q);
int Quenelength(SqQuene Q); 
int DeQuene(SqQuene* Q, int* e);
int EeQuene(SqQuene* Q, int content);
int GetHead(SqQuene Q);

