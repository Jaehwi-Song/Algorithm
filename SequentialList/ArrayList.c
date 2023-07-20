#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)  // 초기화
{
	plist->numOfData = 0;
	plist->CurPosition = -1;
}

void LInsert(List *plist, LData data)
{
	if (plist->numOfData >= 100)
	{
		puts("저장 공간이 부족해 저장에 실패했습니다.\n");
		return;
	}
	plist->arr[numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
	if (plist->numOfData == 0)
		return FALSE;
	
	plist->CurPosition = 0;
	*pdata = plist->arr[plist->CurPosition];
	return TRUE;
}

int LNext(List *plist, LData *pdata)
{
	if (plist->CurPosition >= (plist->numOfData)-1)
		return FALSE;
	
	(plist->CurPosition)++;
	*pdata = plist->arr[plist->CurPosition];
	return TRUE;
}

LData LRemove(List *plist)
{
	int idx = plist->CurPosition;
	int num = plist->numOfData;
	int target = plist->arr[idx];
	int i;
	
	for(i=0; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1];
	
	(plist->CurPosition)--;
	(plist->numOfData)--;
	return target;
}

int LCount(List *plist)
{
	return plist->numOfData;
}