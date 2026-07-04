#include<bits/stdc++.h>
using namespace std;
void unionSortedArrays(int a[],int an, int b[],int bn,int c[]){
  int i,j,k; k=i=j=0;
  while(i<an && j<bn){
    if(a[i]>b[j]){
        c[k++]=b[j++];
    } else{
       c[k++]=a[i++];
    }
  }
  while(i<an){
    c[k++]=a[i++];
  }
  while(j<bn){
    c[k++]=b[j++];
  }
}
int main(){
 int a[]={1,3,5,7,9};
 int b[]={2,4,6,8,10};
 int an=sizeof(a)/sizeof(a[0]);
 int bn=sizeof(b)/sizeof(b[0]);
 int c[an+bn];
 unionSortedArrays(a,an,b,bn,c);
 for(int i=0;i<sizeof(c)/sizeof(c[0]);i++){
    cout<<c[i]<<" ";
 }
 return 0;
}

