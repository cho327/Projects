// Calvin Ho
// cho327
// Insertionsort.c sorts by inerting elements where they are supposed to be
// then it shrinks the sort search by one to continue placing it in the correct postion.

#include "sorting.h"

void insertionSort(uint32_t a[], uint32_t length)
{
	for(uint32_t i = 1; i < length; i++)
	{
		uint32_t tmp = a[i];
		int32_t j = i - 1;
		while( j >= 0 && a[j] > tmp)
		{
			compares++;
			movecount++;
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = tmp;
		movecount++;
	}
}
