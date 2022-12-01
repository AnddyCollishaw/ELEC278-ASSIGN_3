

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printarrowatposition (int posn)
// Prints a V - a down arrow - where the pivot value will be
{
	int	i;
	for (i=0; i<posn; i++)		printf ("     ");
	printf ("   V\n");
}//printarrowatposition()

int array_sorted (int a[], int min, int max, int ascending)
// Check if portion of array (parameter a) from index min to index max
// inclusive is sorted. Parameter ascending determines whether check is for
// ascending order, meaning lower value is in lower index, or descending
// order, meaning lower value is in higher index.
// If msg is not NULL, prints string pointed to by msg on stdout.
{
	int		correct = 0;			// either error or unsorted to begin

	// Check first for dumbness
	if (a != NULL)	{
		int		i;
		
		for (i=min; i<max; i++)	{
			// data in higher index position should be equal or higher value
			// when array is sorted in ascending order, and should be equal
			// or lower value when array is sorted in descending order.
			// (Note use of C's conditional evaluation.) Variable correct
			// will be true if order OK, and false if order wrong.
			if ((ascending  && (a[i] > a[i+1])) ||
				(!ascending && (a[i] < a[i+1])))	{
				// found two out of order - therefore it is unsorted
				return 0;
				}
			}//endfor
		// Get to this point only because we did not detect an out of order
	correct = 1;
	}
	return correct;

}//array_sorted()
\

void swap (int a[], int g, int h)
// Swap values at locations g and h in array a.
// If global verbose is set, reports that swap takes place.
// Global counter swaps is incremented by 1.  User needs to remember to
// reset swaps before starting code that swap count is required.
{
	int  t = a[g];		// temporary to hold one value being swapped
	a[g] = a[h];
	a[h] = t;
	
} //swap()  

int partition (int  a[],  int left, int right)
// Using locations a[left..right], partition fragment by picking a[left] as
// separator value, then working through bottom and top halves of the array,
// arranging - by swapping values if necessary - that all values smaller than
// the separator value are in the bottom part and all values larger are in
// the top part.
{
	int	ll, rr, pivotval;
	ll = left+1;
	rr = right;
	// choose pivot to be leftmost location
	pivotval = a[left];
    while (ll < rr)	{
		// if one on left less than pivot, leave it alone
		if(a[ll] <= pivotval)	{ ll++; continue;}
		// if one on right greater than pivot, leave it
        if(a[rr] > pivotval)	{ rr--; continue;}
		// both left and right on wrong side - swap them
		swap(a, ll, rr);
       	}//endwhile
	// we stop when rr and ll collide. Place pivot value such that everything
	// to left is less and everything to right is same or greater.
	if (a[ll] < pivotval)	{
		swap(a, ll, left);
	} else	{
		swap(a, --ll, left);
		}
	return ll;
}//partition()


int * DateSort (int a[],  int left, int right, int size)
{
	
	if (left < right)    {
		int  pivotndx = partition (a, left, right);
		DateSort (a, left, pivotndx-1,size);
		DateSort (a, pivotndx+1, right,size);
		}
	return a;
}//DateSort()


int main(){



//testing adding to newtest branch 
printf("n");


printf("g");
int *dates3;
int size; 

printf("Enter the Number of dates you want to enter:\n"); 
scanf("%d", &size); 
printf("%d", size); 

//  int dates[size][3]; 

// for(int g = 0; g<size; g++){
// 	for(int i = 0; i<3; i++){
// 		scanf("%d\n", &dates[g][i]);
// 	}
// }

// // int dates[12][3] = {
// // {20, 1, 2014}, {25, 3, 2010}, {3, 12, 1676}, {18, 11, 1982}, {19, 4,
// // 2015},{ 9, 7, 2015}, {12, 8, 2010}, {30, 8, 2010}, {21, 1, 2014}, {20, 7, 2014},
// // {18, 11, 2020}
// // };

// int dates2[size]; 
// int b = 0; 
// for(int g = 2; g>-1;g--){
// 	for (int i =0; i<size; i++){
//         b = dates[i][g];
//         if(g!=2){
// 			dates2[i] = dates2[i]*100+b; 
// 		}else{
//         	dates2[i]= b; 
// 		}
//     }
// }




// dates3=DateSort(dates2,-1, size, size); 

// for(int g = 0; g<3; g++){
// 	for(int i = 0; i<size;i++){
// 		if(dates3[i]>9999){
// 			dates[i][g]= dates3[i]%100;
// 			dates3[i]= round(dates3[i]/100);
// 		}else{
// 			dates[i][g] = dates3[i];
// 		}
// 	}
// }
// 	printf("\nDate arr[] = {");

// 	for(int i = 0; i<size; i++){
// 		printf("{%d, %d, %d},", dates[i][0], dates[i][1], dates[i][2]);
// 	}
// 	printf("}\n");
	
return 0;
}
