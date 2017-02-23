#include "structs.h"
#include "qsort.h"


void quickSort1( VideoWeight a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
	
}



int partition1( VideoWeight a[], int l, int r) {
   int pivot, i, j;
   VideoWeight t;
   Video* video;
   pivot = a[l].weight;
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i].weight <= pivot && i <= r );
   	do --j; while( a[j].weight > pivot );
   	if( i >= j ) break;
   	
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l]= a[j]; a[j] = t;
   
   return j;
}




