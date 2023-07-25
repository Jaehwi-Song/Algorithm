#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {
	List list;
	ListInit(&list);
	NameCard * pcard;
	
	// Save 3 namecard data into list
	pcard = MakeNameCard("Jason", "010-1234-5123");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("Jefferey", "010-5432-6253");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("Max", "010-1563-2135");
	LInsert(&list, pcard);
	
	// search specific person's data and print
	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "Jefferey")==0)
			ShowNameCardInfo(pcard);
		
		while(LNext(&list, &pcard))
		{
			if (NameCompare(pcard, "Jefferey")==0)
			{
				ShowNameCardInfo(pcard);
				break;
			}
		}
	}
	
	// change specific person's phone number
	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "Max")==0)
			ChangePhoneNum(pcard, "010-2495-9834");
		
		while (LNext(&list, &pcard))
		{
			if (NameCompare(pcard, "Max")==0)
			{
				ChangePhoneNum(pcard, "010-2495-9834");
				break;
			}
		}
	}
	
	// delete specific person's info
	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "Jefferey")==0)
		{
			pcard = LRemove(&list);
			free(pcard);
		}
		
		while (LNext(&list, &pcard))
		{
			if (NameCompare(pcard, "Jefferey")==0)
			{
				pcard = LRemove(&list);
				free(pcard);
				break;
			}
		}
	}
	printf("\n");
	// print all data in list
	printf("There are %d namecards in database\n\n", LCount(&list));
	
	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);
		
		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}

	return 0;
}