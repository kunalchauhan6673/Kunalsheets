/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include<bits/stdc++.h>
using namespace std;
// brute: use two loops, find max sum; TC: o(n);
// optimal: Tc: o(n)
int maxProfit(int a[], int n){
 int mins=INT_MAX;
 int maxs=0,sum=0;
 for(int i=0;i<n;i++){
    mins=min(mins,a[i]);
    sum=a[i]-mins;
    maxs=max(maxs,sum);
 }
 return maxs;
}
int main(){
 int a[]={7,1,5,3,6,4};
 int n=sizeof(a)/sizeof(a[0]);
 cout<<maxProfit(a,n);
 return 0;
}

