#include <bits/stdc++.h>
using namespace std;

int linearSearch(int a[], int n, int key) {

    for (int i = 0; i < n; i++) {
        if (key == a[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    int a[] = {10, 100, 2, 34, 32, 1000};

    int n = sizeof(a) / sizeof(a[0]);

    cout << linearSearch(a, n,34);

    return 0;
}
