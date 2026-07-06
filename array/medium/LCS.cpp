/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.*/
// https://leetcode.com/problems/longest-consecutive-sequence/description/
#include<bits/stdc++.h>
using namespace std;
bool linearSearch(int x, vector<int> nums){
 for(int a: nums){
    if(x==a)
        return true;
 }
 return false;
}
int LCS_Brute(vector<int> a){
 int ans=0;
 for(int i=0;i<a.size();i++){
    int curr=a[i];
    int countt=1;
    while(linearSearch(curr+1,a)){
        curr++;
        countt++;
    }
    ans=max(ans,countt);
 }
 return ans;
}
int main(){
 vector<int> a={100,4,200,1,3,2};
 cout<<LCS_Brute(a);
}

