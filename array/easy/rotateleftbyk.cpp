#include<bits/stdc++.h>
using namespace std;
void reverseArray(int a[], int l, int h){
 while(l<h){
    swap(a[l],a[h]);
    l++; h--;
 }
}
void rotateleftbyk(int a[], int n, int k){
 k%=n;
 reverseArray(a,0,k-1);
 reverseArray(a,k,n-1);
 reverseArray(a,0,n-1);
}
int main(){
 int a[]={1,2,3,4,5};
 int size = sizeof(a)/sizeof(a[0]);
 rotateleftbyk(a,size,2);
 for(int i=0;i<size;i++){
    cout<<a[i]<<" ";
 }
}

