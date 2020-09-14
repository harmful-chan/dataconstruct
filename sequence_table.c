#include <stdio.h>
#include <string.h>

#define SIZE 10

//sequence list for dynamic
typedef struct 
{
	int* data;
	int length;
} SeqList;

//init sequence
int InitList(SeqList *list)
{
	list->data = (int *)malloc(SIZE*sizeof(int));
	memset(list->data, '\0', SIZE*sizeof(int));
	return list->length = 0;
}

//insert element in index.
int Insert(SeqList *list, int index, int number)
{
	if( index >= SIZE ) return -1;
	list->data[index] = number;
	return list->length = (list->length - 1 < index) ?  index + 1 : list->length; ;
}

//show all of list element.
void ToString(SeqList *list)
{
	for(int i = 0; i < list->length; i++)
	{
		printf("%d ", list->data[i]);
	}
	printf("\r\n");
}

int main(void)
{
	SeqList list;
	InitList(&list);
	Insert(&list, 0, 1);
	Insert(&list, 1, 2);
	Insert(&list, 5, 3);
	Insert(&list, 10, 4);

	ToString(&list);
	return 0;
}
