#include <bits/stdc++.h>
using namespace std;

void rotateLeftByone(int a[], int n) {
    int newlast = a[0];
    for (int i = 0; i < n-1; i++) {
       a[i]=a[i+1];
    }
    a[n-1]=newlast;
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};

    int n = sizeof(a) / sizeof(a[0]);

     rotateLeftByone(a, n);
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
     }

    return 0;
}

