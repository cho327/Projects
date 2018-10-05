// Calvin Ho
// cho327
// sorting.c is the file that will combine many different sorts.
// The file will sort numbers from a random seed at the users prompting.

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <getopt.h>
# include <string.h>

# include "sorting.h"
# include "minsort.h"
# include "insertionsort.h"
# include "bubblesort.h"
# include "quicksort.h"
# include "mergesort.h"

int64_t compares = 0;
int64_t movecount = 0;

void printsorted(uint32_t *a, uint32_t printsize, uint32_t arraysize)
{
	printf("%d elements \n", arraysize);
	printf("%ld moves \n", movecount);
	printf("%ld compares \n", compares);
	for(uint32_t i = 0; i < printsize; i++)
	{
		printf("%u	",a[i]);
	}
	printf("\n");
}

// creates a copy of the array that i can use instead of my original random array
uint32_t *copyarray(uint32_t *a, uint32_t size)
{
	uint32_t *copy = calloc(size, sizeof(uint32_t));
	for(uint32_t i = 0; i < size; i++)
	{
		copy[i] = a[i];
	}
	return copy;
}

int main(int argc, char *argv[])
{
	// activation variables
	uint32_t minsort_on = 0;
	uint32_t bubblesort_on = 0;
	uint32_t insertionsort_on = 0;
	uint32_t quicksort_on = 0;
	uint32_t mergesort_on = 0;
	int c;

	// user input / default variables
	uint32_t printelement = 100;
	uint32_t randomseed = 8222022;
	uint32_t arraysize = 100;
	
	// randomnumber generator to put into array
	uint32_t randomnumber;
	
	// usage of getopt to get user input and run program accordingly
	while ((c = getopt(argc, argv, "AmbiqMp:r:n:")) != -1)
	{
		switch (c)
		{
			case 'p':
			{
				printelement = atoi(optarg);
				break;
			}
			
			case 'r':
			{
				randomseed = atoi(optarg);
				break;
			}

			case 'n':
			{
				arraysize = atoi(optarg);
				break;
			}

			case 'A':
			{
				minsort_on = 1;	
				bubblesort_on = 1;
				insertionsort_on = 1;
				quicksort_on = 1;
				mergesort_on = 1;
				break;
			}

			case 'm':
			{
				minsort_on = 1;
				break;
			}
			
			case 'b':
			{
				bubblesort_on = 1;
				break;
			}
			
			case 'i':
			{
				insertionsort_on = 1;
				break;
			}

			case 'q':
			{
				quicksort_on = 1;
				break;
			}
			
			case 'M':
			{
				mergesort_on = 1;
				break;
			}
		}
	}

	// if print request is larger than arraysize, then bring print size down to size of array
	if(printelement > arraysize)
	{
		printelement = arraysize;
	}
	// inputs the random seed into our psuedo random number generator and calloc's array to arraysize
	srand(randomseed);
	uint32_t *rand_array = calloc(arraysize, sizeof(uint32_t));
	
	// puts random numbers in array
	for(uint32_t i = 0; i < arraysize; i++)
	{
		randomnumber = rand() % 16777216;
		rand_array[i] = randomnumber;
	}

	// performs minsort if on
	if(minsort_on == 1)
	{
		uint32_t *array_copy = copyarray(rand_array,arraysize);
		movecount = 0;
		compares = 0;
		minSort(array_copy, arraysize);
		printf("\nMin Sort \n");
		printsorted(array_copy, printelement, arraysize);
		free(array_copy);
	}

	// performs bubblesort if on
	if(bubblesort_on == 1)
	{
		uint32_t *array_copy = copyarray(rand_array,arraysize);
		movecount = 0;
		compares = 0;
		bubbleSort(array_copy, arraysize);
		printf("Bubble Sort \n");
		printsorted(array_copy, printelement, arraysize);
		free(array_copy);
	}

	// performs insertionsort if on
	if(insertionsort_on == 1)
	{
		uint32_t *array_copy = copyarray(rand_array,arraysize);
		movecount = 0;
		compares = 0;
		insertionSort(array_copy, arraysize);
		printf("Insertion Sort \n");
		printsorted(array_copy, printelement, arraysize);
		free(array_copy);
	}

	// performs quicksort if on
	if(quicksort_on == 1)
	{
		uint32_t *array_copy = copyarray(rand_array,arraysize);
		movecount = 0;
		compares = 0;
		quickSort(array_copy, arraysize);
		printf("Quick Sort \n");
		printsorted(array_copy, printelement, arraysize);
		free(array_copy);
	}

	// performs mergesort if on
	if(mergesort_on == 1)
	{
		uint32_t *array_copy = copyarray(rand_array,arraysize);
		movecount = 0;
		compares = 0;
		mergeSort(array_copy, arraysize);
		printf("Merge Sort \n");
		printsorted(array_copy, printelement, arraysize);
		free(array_copy);
	}

	free(rand_array);
	return 0;
}
