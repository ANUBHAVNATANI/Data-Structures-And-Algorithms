#include <stdio.h>
//swap function
void swap(int *a,int b,int c){
	int temp=a[c];
	a[c]=a[b];
	a[b]=temp;
}
//quick sort function
void quicksort(int *a,int first,int last){
	if(first>=last){
		return;
	}
	else{
		int pivot=first;
		int i=first;
		int j=last;
		while(i<j){
			while(a[i]<=a[pivot] && i<last){
				i++;
			}
			while(a[j]>a[pivot]){
				j--;
			}
			if(i<j){
				swap(a,i,j);
			}
		}
		swap(a,pivot,j);
		quicksort(a,first,j-1);
		quicksort(a,j+1,last);
	}
}
//main function
void main(){
	int a[100],n;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	printf("Enter the numbers\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("Array after sorting");
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
