#include "sum.h"
#include <assert.h>

//function "sum" sums an array a that has length n by using recursion 

int sum(int a[], int n)
{

//assert (n >= 0); 

    if (n == 0)
        return 0; //base case
    else 
        return (a[n - 1] + sum(a, n - 1)); //a recursive step 
}