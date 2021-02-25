#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void SelectionSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int temp=a[i];
		int index=i;
		for(int j=i+1;j<n;j++){
			if(temp>a[j]){
				temp=a[j];
				index=j;
			}
		}swap(&a[index],&a[i]);
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	SelectionSort(a,n);
}
