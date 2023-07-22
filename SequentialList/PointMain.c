#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void)
{
	List list;
	ListInit(&list);
	
	Point * ppos;
	Point compPos;
	
	// item insert
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);
	
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	
	// print total item number
	
	printf("현재 저장된 데이터 수 : %d\n", LCount(&list));
	
	// show items in list
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");
	
	// delete items that have xpos value equal to 2
	compPos.xpos = 2;
	compPos.ypos = 0;
	
	if (LFirst(&list, &ppos))
	{
		if (PointComp(&compPos, ppos) == 2)
			ppos = LRemove(&list);
			free(ppos);
		while (LNext(&list, &ppos))
		{
			if (PointComp(&compPos, ppos) == 2)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}
	
	printf("현재 저장된 데이터 수 : %d\n", LCount(&list));
	// print left items
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");
	
	return 0;
}