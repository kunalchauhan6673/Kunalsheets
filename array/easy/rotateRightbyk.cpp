#include<bits/stdc++.h>
using namespace std;
void rotateRightbyk(int a[], int n, int k){
 k=k%n; // normalize
 for(int i=0;i<n/2;i++){
    swap(a[i],a[n-1-i]);
 }
 for(int i=0;i<k/2;i++){
    swap(a[i],a[k-1-i]);
 }
  for(int i=k;i<k+(n-k)/2;i++){
    swap(a[i],a[k+n-1-i]);
 }
}
int main(){
 int a[]={1,2,3,4,5};
 int size = sizeof(a)/sizeof(a[0]);
 rotateRightbyk(a,size,2);
 for(int i=0;i<size;i++){
    cout<<a[i]<<" ";
 }
}

