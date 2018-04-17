#include<stdio.h>
int b[100];
//merge function
void merge(int a[100],int low,int mid,int high){
	int l1,l2,i;
	for(l1=low,l2=mid+1,i=low;l1<=mid && l2<=high;i++){
		if(a[l1]<=a[l2]){
			b[i]=a[l1++];
			}
		else{
			b[i]=a[l2++];
			}
		}
	while(l1<=mid){
		b[i++]=a[l1++];
		}
	while(l2<=high){
		b[i++]=a[l2++];
		}
	for(i=low;i<=high;i++){
		a[i]=b[i];
		}
}
//merge sort function
void mergesort(int a[100],int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      mergesort(a,low, mid);
      mergesort(a,mid+1, high);
      merge(a,low, mid, high);
   } else { 
      return;
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
	mergesort(a,0,n-1);
	printf("Array after sorting");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
