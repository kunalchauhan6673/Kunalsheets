#include <bits/stdc++.h>
using namespace std;

int largest(int a[], int n) {
    int largest = a[0];

    for (int i = 1; i < n; i++) {
        if (largest < a[i]) {
            largest = a[i];
        }
    }

    return largest;
}

int main() {
    int a[] = {10, 100, 2, 34, 32, 1000};

    int n = sizeof(a) / sizeof(a[0]);

    cout << largest(a, n);

    return 0;
}
