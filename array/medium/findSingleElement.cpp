// https://leetcode.com/problems/single-number/description/
/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.*/
#include<bits/stdc++.h>
using namespace std;
int singleNumber(int nums[], int n) {
        int count=0;
        for(int i=0;i<n;i++)
        {
           count^=nums[i];
        }
        return count;
}
int main(){
int a[]={1,3,4,3,4};
int n=sizeof(a)/sizeof(a[0]);
int num= singleNumber(a,n);
cout<<num<<" ";
}
