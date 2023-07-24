#include <stdio.h>
#include <stdlib.h>

typedef struct __node 
{
	int data;
	struct __node * next;
}Node;

int main (void)
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;
	
	Node * newNode = NULL;
	int readData;
	
	// Making new node
	while(1)
	{
		printf("Enter a natural number : ");
		scanf("%d", &readData);
		if (readData < 1)
			break;
		
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		if (head == NULL)
			tail = newNode;
		else
		{
			newNode->next = head;
		}
		head = newNode;
	}
	printf("\n");
	
	// print all data in Linked List
	if (head == NULL)
		printf("No data exist in Linked List\n");
	else
	{
		cur = head;
		printf("-------Data in Linked List-------\n");
		printf("%d ", cur->data);
		
		while(cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}	
	}
	printf("\n\n");
	
	// delete all data in Linked List
	if (head == NULL)
	{
		printf("No data exist in Linked List\n");
		return 0;
	}
	else
	{
		Node * delNode = head;
		Node * delNextNode = head->next;
		
		printf("deleting %d in Linked List\n", delNode->data);
		free(delNode);
		
		while (delNextNode != NULL)
		{	
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			
			printf("deleting %d in Linked List\n", delNode->data);
			free(delNode);
		}
	}
	
	return 0;
}