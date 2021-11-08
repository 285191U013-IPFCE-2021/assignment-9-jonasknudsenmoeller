#include "search.h"
#include <stdbool.h>

//function "search" finds element "x" in array "a" with length "n" using recursion  

bool search(int a[], int n, int x)
{
    if (n == 0) //base case 1
        return false;
    if (n > 0 && a[n -1] == x) //base case 2
        return true;
    if (n > 0 && a[n -1] != x) //recursive step
        return search(a, n-1, x);
}