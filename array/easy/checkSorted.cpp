#include <bits/stdc++.h>
using namespace std;

bool checkSorted(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
                return false;
        }
    }
    return true;
}

int main() {
    int a[] = {10, 100, 2, 34, 32, 1000};

    int n = sizeof(a) / sizeof(a[0]);

    cout << checkSorted(a, n);

    return 0;
}

