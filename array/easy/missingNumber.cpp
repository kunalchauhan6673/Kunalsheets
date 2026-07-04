#include<bits/stdc++.h>
using namespace std;

int missingNum(int *a, int n) {
    long long sum = 0;

    for(int i = 0; i < n; i++) {
        sum += a[i];
    }

    long long actualSum = 1LL * (n + 1) * (n + 2) / 2;

    return (int)(actualSum - sum);
}
int main(){
 int a[]={1,2,3,4,6};
 cout<<missingNum(a,5);
 return 0;
}
