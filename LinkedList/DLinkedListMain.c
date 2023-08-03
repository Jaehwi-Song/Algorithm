#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main(void)
{
	// New List produce & initialize
	List list;
	int data;
	ListInit(&list);
	SetSortRule(&list, WhoIsPrecede);            // define Sort Rule
	
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