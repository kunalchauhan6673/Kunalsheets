#include <bits/stdc++.h>
using namespace std;

int largest(int a[], int n) {
    int largest = a[0];
    int slargest = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (largest <a[i]) {
            slargest = largest;
            largest = a[i];
        }else if(slargest<a[i] && a[i]!=largest){
            slargest=a[i];
       }
    }
    if(slargest==INT_MIN){
        slargest=-1;
    }
    return slargest;
}

int main() {
    int a[] = {10, 100, 2, 340, 32, 1000};

    int n = sizeof(a) / sizeof(a[0]);

    cout << largest(a, n);

    return 0;
}

