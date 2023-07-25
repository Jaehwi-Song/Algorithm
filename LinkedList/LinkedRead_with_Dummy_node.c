#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
	int data;
	struct __node * next;
}Node;

int main(void)
{
	Node * head = NULL;   // Pointing the first node in array
	Node * tail = NULL;   // Pointing the last node in array 
	Node * cur = NULL;    // Use for item read 
	
	Node * newNode = NULL;
	int readData;
	
	head = (Node *)malloc(sizeof(Node));  // making dummy node as the first node of list
	tail = head;	
	
	while(1)
	{
		printf("Enter a natural number : ");
		scanf("%d", &readData);
		
		if (readData < 1)
			break;
		
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");
	

	// print all data in linked list
	cur = head;
		
	printf("-------Data in Linked List-------\n");
	while (cur->next != NULL)
	{
		cur = cur->next;
		printf("%d ", cur->data);
	}
	
	printf("\n\n");
	
	// delete all items in Linked List
	Node * delNode = head;
	Node * delNextNode = head->next;
		
	while (delNextNode != NULL)
	{
		delNode = delNextNode;
		delNextNode = delNextNode->next;
			
		printf("deleting %d in Linked List\n", delNode->data);
		free(delNode);
	}
	
	free(head);
	
	return 0;
	
}