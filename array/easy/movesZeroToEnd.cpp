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

void movesN(int a[], int n) {
 // using two pointers
 int j=0; // keeps the index of zeroes
 for(int i=0;i<n;i++){
    if(a[i]!=0){
        if(i!=j){
            swap(a[i],a[j]);
        }
        j++;
    }
 }
}

int main() {
    int a[] = {1,0,2,0,3,0};

    int n = sizeof(a) / sizeof(a[0]);

     // moves(a, n);
     movesN(a,n);
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
     }

    return 0;
}
// O(n2) and O(n)

