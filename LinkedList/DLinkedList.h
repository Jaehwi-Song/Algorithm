#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__
#include "Point.h"      // depend on data type we use for a Node->data.
#define TRUE 1
#define FALSE 0

typedef Point * LData;   // save Point data type into a Node; 
// typedef int * LData;  // save integer data type into a Node;

typedef struct _node
{
	LData data;
	struct _node * next;
}Node;

typedef struct _linkedList
{
	Node * head;       // pointing dummy node
	Node * cur;        // use for search & delete
	Node * before;     // use for delete
	int numOfData;     // num of data in LinkedList
	int (*comp)(LData d1, LData d2); // standard of sorting
}LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

#endif