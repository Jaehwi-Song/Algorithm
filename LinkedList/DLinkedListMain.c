#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	// New List produce & initialize
	List list;
	int data;
	ListInit(&list);
	
	// Insert data to linked list
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);
	
	// print all data in list
	printf("Total data in Linked List : %d\n", LCount(&list));
	
	if (LFirst(&list, &data))
	{
		
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");
	
	// delete data 22 in Linked List
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);
		
		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}
	
	// print remaining data in Linked List
	// print all data in list
	printf("Remaining data : %d\n", LCount(&list));
	
	if (LFirst(&list, &data))
	{
		
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");
	
	return 0;
}