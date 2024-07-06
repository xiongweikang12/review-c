
#define MaxSize 20
typedef int KeyType;


typedef struct {
	KeyType key;
	int otherinfo;
}redtype;

typedef struct {
	redtype r[MaxSize + 1];
	int length;
}Sqlist;

void Output_key(Sqlist);
void Input_key(Sqlist*);
void Insert_Sort(Sqlist*);
void BanInsert_Sort(Sqlist*);
void Bubbling_Sort(Sqlist*);
void Choice_Sort(Sqlist*);
int partion(Sqlist*, int, int);
void quick_Sort(Sqlist*, int, int);
int get_top(int);
int get_button_left(int );
int get_button_right(int );
int heap_big(Sqlist*);
int heap_small(Sqlist*);
int heap_sort_check(Sqlist*,int(*build_head)(Sqlist *)); //建立打大根堆，或小大根堆
void heap_sort(Sqlist*, Sqlist*);//堆排序


