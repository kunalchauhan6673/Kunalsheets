#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(int a[], int n)
{
    int c,maxc;
    c=maxc=0;
    for(int i=0; i<n; i++)
    {
        if(a[i])
        {
            c++;
        }
        else
        {
            maxc=max(maxc,c);
            c=0;
        }
    }
    return maxc;
}
int main()
{
    int a[]= {1, 1, 0, 0, 1, 1, 1, 0,1};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<maxConsecutiveOnes(a,n)<<" ";
    return 0;
}
