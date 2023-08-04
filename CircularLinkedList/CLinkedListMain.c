#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	List list;
	int data, i, nodeNum;
	ListInit(&list);
	
	// Insert 5 data into List
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	// print data in List 3 times
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		
		for (i=0; i<LCount(&list)*3-1; i++)
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");
	
	// delete data that is multiple of 2
	nodeNum = LCount(&list);
	
	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);
		
		for (i=0; i<nodeNum-1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}
	
	// print data in List
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		
		for (i=0; i<LCount(&list)-1; i++)
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

}