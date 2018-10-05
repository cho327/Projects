// Calvin Ho
// cho327
// Bubblesort is a sort method that sorts by swapping if the number before if it is greater than the number after it.

#include "sorting.h"
#include "bubblesort.h"

void bubbleSort(uint32_t a[], uint32_t length)
{
	while(1)
	{
		uint32_t swapped = 0;
		for(uint32_t i = 1; i <= length - 1; i++)
		{
			compares++;
			if(a[i-1] > a[i])
			{
				SWAP(a[i-1], a[i]);
				swapped = 1;
			}
		}
		length = length - 1;

		if(!swapped)
		{
			return;
		}
	}
}
