// Calvin Ho
// cho327

# ifndef _SORTING_H
# define _SORTING_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>

# define _INSTRUMENTED
# ifdef _INSTRUMENTED
# define SWAP(x,y) { uint32_t t = x; x = y; y = t ; ; movecount += 3; }
# else
# define SWAP(x,y) { uint32_t t = x; x = y; y = t ; ;}
# endif

extern int64_t compares;
extern int64_t movecount;

# endif

