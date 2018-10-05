// Calvin Ho
// cho327
// minsort.c is the most basic type of sort

# include "sorting.h"
# include "minsort.h"

// minIndex : find the index of the least element.

uint32_t minIndex ( uint32_t a[], uint32_t first , uint32_t last )
{ 
	uint32_t smallest = first ; // Assume the first is the least
	for ( uint32_t i = first ; i < last ; i++)
	{
		compares++;
		smallest = a[i] < a[ smallest ] ? i : smallest ;
	}
	return smallest;
}

// minSort : sort by repeatedly finding the least element .

void minSort ( uint32_t a[], uint32_t length )
{
	for ( uint32_t i = 0; i < length - 1; i++)
	{
		uint32_t smallest = minIndex (a, i, length );
		if ( smallest != i) // It ’s silly to swap with yourself !
		{
			SWAP (a[ smallest ], a[i]);
		}
	}
	return;
}
