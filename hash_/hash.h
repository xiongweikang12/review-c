//ап╠М
#define MAXSIZE 100
#define NULLKEY -1
#define DELKEY -2
typedef int KeyType;
typedef char *Infotype;
typedef struct
{
	KeyType key;
	Infotype data;
	int count;
}HashTable[MAXSIZE];

int SeachHT(HashTable, int, KeyType );

int DeleteHT(HashTable , int, KeyType );

void InsertHT(HashTable , int , KeyType );

void creatHT(HashTable , int , KeyType[], int);

void DisplayHT(HashTable , int );

void show_ASL(HashTable, int);
