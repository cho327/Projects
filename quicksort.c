// Calvin Ho
// cho327
// quicksort.c is a sort that works by declaring a pivot and sorting the elements onto two different sides of the array
// it then sorts each side using a recursive method.

# include "sorting.h"

void quickSort(uint32_t a[], uint32_t length)
{
	if(length > 0)
	{
		uint32_t pivot = a[0];
		uint32_t *left = calloc(length-1, sizeof(uint32_t));
		uint32_t *mid = calloc(length, sizeof(uint32_t));
		uint32_t *right = calloc(length-1, sizeof(uint32_t));
		uint32_t len_left = 0;
		uint32_t len_mid = 0;
		uint32_t len_right = 0;
		uint32_t j;

		for(uint32_t i = 0; i < length; i++)
		{
			uint32_t x = a[i];
			compares++;
			if(x == pivot)
			{
				mid[len_mid++] = x;
			}
			
			else if(x < pivot)
			{
				compares++;
				left[len_left++] = x;
			}
			
			else
			{
				compares++;
				right[len_right++] = x;
			}
			movecount++;
		}
		
		//recursively sort our arrays until they comeback as sorted arrays
		quickSort(left, len_left);
		quickSort(right, len_right);
		
		for(j = 0; j < len_left; j++)
		{
			a[j] = left[j];
			movecount++;
		}
		for(uint32_t k = 0; k < len_mid; k++)
		{
			a[j++] = mid[k];
			movecount++;
		}
		for(uint32_t i = 0; i < len_right; i++)
		{
			a[j++] = right[i];
			movecount++;
		}
		
		free(left);
		free(mid);
		free(right);

		//end function
		return;
	}
	else 
	{
		return;
	}
}
