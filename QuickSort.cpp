#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int start,int end){
    int pivot=a[start];
    int count;
    for(int i=start+1;i<=end;i++){
    	if(a[i]<=pivot){
    		count++;
		}
	}
	int pivotIndex=count+start;
	a[start]=a[pivotIndex];
	a[pivotIndex]=pivot;
	int i=start;
	int j=end;
	while(i<=pivotIndex && j>=pivotIndex){
		if(a[i]<=pivot){
			i++;
		}
		else if(a[j]>pivot){
			j--;
		}
		else if(i<pivotIndex && j>pivotIndex){
			swap(&a[i],&a[j]);
			i++;
			j--;
		}
	}
	return pivotIndex;
}
void quicksort(int a[],int start,int end){
	if(start>=end)
	   return;
	   
	int pi=partition(a,start,end);
    quicksort(a,start,pi-1);
	quicksort(a,pi+1,end);   
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
