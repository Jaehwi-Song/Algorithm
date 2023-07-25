#ifndef __NAME_CARD_H__
#define __NAME_CARD_H__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

// dynamic allocation & initialize & return address
NameCard * MakeNameCard(char * name, char * phone);

// print NameCard info (ONLY 1 NAME, PHONE_NUM)
void ShowNameCardInfo(NameCard * pcard);

// if name is same return 0, else other value
int NameCompare(NameCard * pcard, char * name);

// change phone number
void ChangePhoneNum(NameCard * pcard, char * phone);

#endif