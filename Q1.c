//Q1.c-Assignment 3 Q1 - Collishaw_Andy 
//import libraries 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function that takes an array and two indexes and swaps them 
void swap (int *a, int g, int h)

{
	//set temporary int to hold 1 value 
	int  t = a[g];		
	//set the index that was given to temmp as the otehr value 
	a[g] = a[h];
	//set temp to the opposite index 
	a[h] = t;
	
}

int partition (int*a,  int left, int right)

{
	//initialize neccisary variables
	int	ll, rr, pivotval;
	ll = left+1;
	rr = right;
	//pivotval is the smaller index (left)
	pivotval = a[left];
	//while the left index doesnt cross the right index 
    while (ll < rr)	{
		//if the left index value is less then the pivot value that is good so keep going 
		if(a[ll] <= pivotval)	{ ll++; continue;}
		// if the right value is greater then then pivot value that is good kepp going 
        if(a[rr] > pivotval)	{ rr--; continue;}
		// call swap to swap the left value and the right value 
		swap(a, ll, rr);
       	}
	//after the left value crosses the right value 
	if (a[ll] < pivotval)	{
		//if the left value is less then pivot value swap the left value with original left which is the start index of the array 
		swap(a, ll, left);
		//otherwise swap the value below left to the orginal value 
	} else	{
		swap(a, --ll, left);
		}
		//return the left value 
	return ll;
}

//quicksort function to sort the dates 
int * DateSort (int *a,  int left, int right, int size)
{
	//while left is less then right 
	if (left < right)    {
		//the pivot index is the returned left value
		int  pivotndx = partition (a, left, right);
		//go through reccursively untill all in order 
		DateSort (a, left, pivotndx-1,size);
		DateSort (a, pivotndx+1, right,size);
		}
		//return the array 
	return a;
}



int main(){
//size of the array 
int size = 11;

//date array 
int dates[12][3] = {
{20, 1, 2014}, {25, 3, 2010}, {3, 12, 1676}, {18, 11, 1982}, {19, 4,
2015},{ 9, 7, 2015}, {12, 8, 2010}, {30, 8, 2010}, {21, 1, 2014}, {20, 7, 2014},
{18, 11, 2020}};

//print the unsorted array 
printf("Input:\n\n");
printf("Date arr[] = {");
for(int i = 0; i<size; i++){
		printf("{%d, %d, %d},", dates[i][0], dates[i][1], dates[i][2]);
	}
	printf("}\n");

//temp array 
int dates2[size]; 
//temp int to hold value at index 
int b = 0; 
//this turns the 2d array into a 1d array by making and int of yearmonthday
for(int g = 2; g>-1;g--){
	for (int i =0; i<size; i++){
        b = dates[i][g];
        if(g!=2){
			dates2[i] = dates2[i]*100+b; 
		}else{
        	dates2[i]= b; 
		}
    }
}

//anotha one 
int *dates3;

//sort the single int array and put it in the new one 
dates3=DateSort(dates2,-1, size, size); 

//undo the signle intefiying process 
for(int g = 0; g<3; g++){
	for(int i = 0; i<size;i++){
		if(dates3[i]>9999){
			dates[i][g]= dates3[i]%100;
			dates3[i]= round(dates3[i]/100);
		}else{
			dates[i][g] = dates3[i];
		}
	}
}

//print the outpuit 
printf("\nOutput:\n\n");
printf("Date arr[] = {");
for(int i = 0; i<size; i++){
	printf("{%d, %d, %d},", dates[i][0], dates[i][1], dates[i][2]);
}
printf("}\n");
	
return 0;
}

