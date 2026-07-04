#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(int a[], int n) {
    int count = 0;
    int maxCount = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            count++;
        if(maxCount < count) {
                maxCount = count;
            }
        } else {
            count = 0;
        }
    }  
    return maxCount;
}
int main()
{
    int a[]= {1, 1, 0, 0, 1, 1, 1, 0,1};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<findMaxConsecutiveOnes(a,n)<<" ";
    return 0;
}
