#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
		printf("disk 1 moved from %c to %c\n", from, to);
	
	else
	{	
		HanoiTowerMove(num-1, from, to, by); // n-1 disks move from A to B
		printf("disk %d moved from %c to %c\n", num, from, to); // the largest disk move from A to C
		HanoiTowerMove(num-1, by, from, to); // n-1 disks move from B to C	
	}
}

int main(void)
{
	int num = 4;
	printf("In case of %d disks\n", num);
	HanoiTowerMove(num, 'A', 'B', 'C');
	return 0;
}