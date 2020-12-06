/* Below is a simple iterative binary search algorithm, implement it with
 * all the exception handling - if needed use gdb and valgrind*/

#include <iostream>
#include "ElementNotFoundException.h"
#include "ArrayNotSortedException.h"
#include <algorithm>
#include "InvalidIndexException.h"
#include "IndexOutOfBoundsException.h"

using namespace std;

/*iterative binary search: it returns the location of x in given array
 * arr[l..r] else it should throw appropriate exceptions
 * */
int binarySearch(int arr[], int l, int r, int x)
{
	//1. throw for sum overflows and goes to negative int - this produces unexpected results
    if(l>r){
        throw InvalidIndexException();
    }
    //3. throw if accessing invalid indices
    int n=0;
    while(arr[n])
        n++;
    if(l <0||r>=n){
        throw IndexOutOfBoundsException();
    }
	//2. throw if array is not sorted
	if(!is_sorted(arr+l,arr+r+1)){
	    throw ArrayNotSortedException();
	}

	//5. this should return proper value once all exceptions are added
	while (l <=r)
	{
		int m=l+((r-l)/2);
		//Check if x is present at mid
		if (arr[m] == x)
			return m;
		//If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	//4. throw if element is not found
    throw ElementNotFoundException();
	return -1;
}
