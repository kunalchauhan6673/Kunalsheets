#include<bits/stdc++.h>
using namespace std;
int missingNumber(int a[], int n){
 int ans=n+1;
  for(int i=0;i<n;i++){
    ans^=(i+1);
    ans^=a[i];
 }
 return ans;
}
int main(){
 int a[]={1,2,3,4,5,6,7,8,10};
 int n=sizeof(a)/sizeof(a[0]);
 cout<<missingNumber(a,n)<<" ";
 return 0;
}

