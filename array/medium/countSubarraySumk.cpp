/*Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.
A subarray is a contiguous non-empty sequence of elements within an array.*/
// ques: https://leetcode.com/problems/subarray-sum-equals-k/description/
#include<bits/stdc++.h>
using namespace std;
// brute force: tc: o(n*n) and sc is o(1); works fine on leetcode but isnt optimal
int subarraySum_Brute(vector<int>& a, int k) {
    int n = a.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += a[j];

            if(sum == k)
                cnt++;
        }
    }
    return cnt;
}
// optimal approach uses prefix sum + hash map
/*
1). Create an unordered_map<int, int> mp.
2). Initialize:
-> mp[0] = 1; This represents the empty prefix before the array starts.
3). Traverse the array:
a. Update the running sum:
b. sum += nums[i];
c. Find:-> rem = sum - k;
d. If rem exists in the map:-> cnt += mp[rem];
(Every occurrence of rem forms a valid subarray.)
e. Store the current prefix sum:-> mp[sum]++; */
// note: tc and sc both o(n)
int subarraySum_optimal(vector<int> &a, int k){
 int n=a.size();
 unordered_map<int,int> prefixSumMap;
 int sum=0;
 int cnt=0;
 prefixSumMap[0]=1;
 for(int i=0;i<n;i++){
    sum+=a[i];
    int rem=sum-k;
    if(prefixSumMap.find(rem)!=prefixSumMap.end())
        cnt+=prefixSumMap[rem];
    prefixSumMap[sum]++;
 }
 return cnt;
}
int main(){
 vector<int> nums ={1,1,1};
 int ans = subarraySum_optimal(nums,2);
 cout<<ans<<" ";
    return 0;
}

