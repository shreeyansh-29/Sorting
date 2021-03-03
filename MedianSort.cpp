#include<iostream>
#include<cstdlib>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void randomize(int a[],int start,int end){
	int n=end-start+1;
	int temp=rand()%n;
	swap(&a[start+temp],&a[end]);
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
int quicksort(int a[],int start,int end,int k){
	int pivot;
	if(start>end){
	randomize(a,start,end);    
	pivot=partition(a,start,end);
	if(pivot==k && end%2==1)
	    return a[k];
    else if(pivot==k || pivot==k-1 && end%2==0){
    	if(pivot==k)
    	    return(a[pivot]+a[pivot+1]/2);
		if(pivot==k-1)
		    return(a[pivot-1]+a[pivot]/2);
		}
	else if(pivot<k)
	    quicksort(a,start,pivot-1,k);
	else if(pivot>k)
     	quicksort(a,pivot+1,end,k);
    }
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}int k=n/2;
	int median=quicksort(a,0,n-1,k);
    cout<<"Median of array: "<<median<<endl;
}
