// Calvin Ho
// cho327
// mergesort.c

#include "sorting.h"

void mergeSort(uint32_t a[], uint32_t length)
{
	if(length > 1)
	{
		uint32_t middle = length/2;
		uint32_t *leftlist = calloc(middle, sizeof(uint32_t));
		uint32_t *rightlist = calloc(length - middle, sizeof(uint32_t));
		uint32_t i;
		uint32_t l = 0;
		uint32_t r = 0;
		
		for(i = 0; i < middle; i++)
		{
			movecount++;
			leftlist[i] = a[i];
		}
		for(uint32_t j = 0; j < length - middle; j++)
		{
			movecount++;
			rightlist[j] = a[i++];
		}

		mergeSort(leftlist, middle);
		mergeSort(rightlist, length - middle);

		for(i = 0; i < length; i++)
		{
			if(l < middle && r < length - middle)
			{
				movecount++;
				compares++;
				if(leftlist[l] < rightlist[r])
				{
					a[i] = leftlist[l];
					l++;
				}
				else
				{
					a[i] = rightlist[r];
					r++;
				}
			}
			else if(l < middle)
			{
				movecount++;
				a[i] = leftlist[l];
				l++;
			}
			else
			{
				movecount++;
				a[i] = rightlist[r];
				r++;
			}
		}
		free(leftlist);
		free(rightlist);
		return;
	}
}
