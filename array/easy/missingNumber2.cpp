#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(int a[], int n){
 int ans=0;
 for(int i=1;i<=n+1;i++){
    ans^=i;
 }
  for(int i=0;i<n;i++){
    ans^=a[i];
 }
 return ans;
}
int main(){
 int a[]={1,2,3,4,5,6,7,8,10};
 int n=sizeof(a)/sizeof(a[0]);
 cout<<maxConsecutiveOnes(a,n)<<" ";
 return 0;
}

