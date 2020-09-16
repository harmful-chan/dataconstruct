#include <stdio.h>
#include <string.h>
#include <math.h>

#define BASE_SIZE 5

#define MAX_BYTE_SIZE(i) ( (int)pow(2, i) * BASE_SIZE * sizeof(int) )
#define MAX_TYPE_SIZE(i) ( MAX_BYTE_SIZE(i) >> 2 )

//sequence list for dynamic
static int expansion;
typedef struct 
{
	int* data;
	int length;
	int expansion;
} SeqList;



//init sequence
void InitList(SeqList *list)
{
	list->expansion = 0;
	list->data = (int*)malloc(MAX_BYTE_SIZE(list->expansion));
	memset(list->data, '\0', MAX_BYTE_SIZE(expansion));
}

//destroy list
void DestroyList(SeqList* list)
{
	free(list->data);
	list->length = 0;
	list->expansion = 0;
}

//clear list
void Empty(SeqList* list)
{
	memset(list->data, '\0', MAX_BYTE_SIZE(list->expansion));
}

//get list length
int Length(SeqList* list)
{
	return list->length;
}

//locate element index
int Locate(SeqList* list, int elm)
{
	for(int i = 0; i < list->length; i++){
		if( list->data[i] == elm )
			return i;
	}
	return -1;
}

//get element by index.
int Get(SeqList* list, int index)
{
	if( index >= list->length )
		return -1;

	return list->data[index];
}

//insert element in index.
int Insert(SeqList *list, int index, int elm)
{
	int expan_count = 0;
	for( int i = list->expansion; \
		MAX_TYPE_SIZE(i) <= index;\
		 expan_count++, i++ );
	 if( expan_count > 0 ) 
	{
		//The index more than maximum size
		//, list will expanded length of 2^'expansion'.
		int* old = (list->data != NULL) ? list->data : NULL;
		list->expansion +=  expan_count;
		list->data = (int*)malloc(MAX_BYTE_SIZE(list->expansion));
		memset(list->data, '\0', MAX_BYTE_SIZE(list->expansion));
		memcpy(list->data, old, MAX_BYTE_SIZE(list->expansion - expan_count));  
		free(old);
	}


	//insert element into middle.
	list->data[index] = elm;
	if( index >= list->length ) 
		list->length = index+1;
	return index;
}

//delete element
int Delete(SeqList* list, int index)
{
	if( index >= list->length || index < 0  ) return -1;
	memcpy(list->data, list->data + index+ 1, list->length - index - 1);
	list->length--;
}

//show all of list element.
void ToString(SeqList *list)
{
	printf("length: %-3d, cur_max_byte_size: %-3d, elm: ", list->length, MAX_TYPE_SIZE(list->expansion));
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
	ToString(&list);
	Insert(&list, 5, 3);
	ToString(&list);
	Insert(&list, 20, 4);
	ToString(&list);
	return 0;
}
