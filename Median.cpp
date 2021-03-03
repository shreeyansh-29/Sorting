#include<iostream>
#include<algorithm>
using namespace std;
int median(int a[],int n){
	sort(a,a+n);
	if(n%2!=0)
	    return a[n/2];
	return (a[n/2]+a[(n-1)/2])/2.0;    
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m=median(a,n);
	cout<<"Median of array: "<<m<<endl;
}
