#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(int a[], int n){
 int uniqueEL=0;
 for(int i=1;i<n;i++){
    if(a[i]==a[uniqueEL])
        continue;
    else{
        uniqueEL++;
        a[uniqueEL]=a[i];
    }
 }
 return uniqueEL+1;
}
int main(){
 int a[]={1,1,1,2,2,3,3,3};
 int size = sizeof(a)/sizeof(a[0]);
 int n = removeDuplicates(a,size);
 for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
 }
}
