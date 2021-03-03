#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int start,int end){
	int i=start,j,pivot=a[end];
	for(int j=start;j<end;j++){
		if(a[j]<pivot){
			swap(&a[i],&a[j]);
			i++;
		}
	}swap(&a[i],&a[end]);
	return i;
}
void quicksort(int a[],int start,int end){
	int pivot;
	if(start>=end)
	    return;
	pivot=partition(a,start,end);
	quicksort(a,start,pivot-1);
	quicksort(a,pivot+1,end);
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
