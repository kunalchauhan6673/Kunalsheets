#include <bits/stdc++.h>
using namespace std;

void rotateLeftByk(int a[], int n, int k) {
    k %= n;
    int temp[n];

    for (int i = 0; i < n; i++) {
        temp[i] = a[(i + k) % n];
    }

    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}


int main() {
    int a[] = {1,2,3,4,5};

    int n = sizeof(a) / sizeof(a[0]);

     rotateLeftByk(a, n,4);
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
     }

    return 0;
}

