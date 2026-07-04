#include <bits/stdc++.h>
using namespace std;

void moves(int a[], int n) {
    for (int i = 0; i < n; i++) {
       for(int j=i+1;j<n;j++){
          if(a[i]==0){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
          }
       }
    }
}

void moveZeroesToEnd(int a[], int n){
  int j=0;
  int i=j+1;
  while(i<n){
   if(a[j]!=0) // get j to the position of 0
   {  
    j++;
    i++;
   }
   else{ // once j is at 0, get i to the position of non-zero
    if(a[i]!=0) 
  {
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    i++; j++;
   }
   else{
    i++;
   }
   }
  }
}

int main() {
    int a[] = {1,0,2,0,3,0};

    int n = sizeof(a) / sizeof(a[0]);

     // moves(a, n);
     moveZeroesToEnd(a,n);
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
     }

    return 0;
}
// O(n2) and O(n)

