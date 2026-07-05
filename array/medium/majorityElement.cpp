// better approach: using hashmap
/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
#include<bits/stdc++.h>
using namespace std;
// uses Tc: o(n) and Sc: o(n)
int majorityElementHash(vector <int> &nums){
 unordered_map<int,int> Hmap;
 for(int i=0;i<nums.size();i++){
    Hmap[nums[i]]++;
 }
 for(auto& pair :Hmap){
    if(pair.second > nums.size()/2){
        return pair.first;
    }
 }
 return -1;
}

// best: TC: O(n) and sc: O(1)
int MooreAlgo(vector<int> &nums){
 int candidate=nums[0];
 int c=1;
 for(int i=1;i<nums.size();i++){
    if(c==0){
        candidate=nums[i];
        c=1;
    }
    else if(candidate==nums[i]){
        c++;
    }else{
     c--;
    }
 }
 return candidate;
}
int main(){
 vector<int> a={1,2,1,2,1,2,1};
 cout<<MooreAlgo(a);
}
