#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node));  // allocating dummy node to head
	plist->head->next = NULL;
	plist->numOfData = 0;                        // total # of data in Linked List
	plist->comp = NULL;							 // initialize sorting standard	
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = plist->head->next;      // Linking newnode to head
	plist->head->next = newNode;
	
	(plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	Node * pred = plist->head;             // pointing dummy node
	newNode->data = data;
	
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	
	newNode->next = pred->next;
	pred->next = newNode;
	
	(plist->numOfData)++;
}

void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else 
		SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next == NULL)
		return FALSE;
	
	plist->before = plist->head;
	plist->cur = plist->head->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(rpos);
	(plist->numOfData)--;
	
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}