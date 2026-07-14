// link: https://leetcode.com/submissions/detail/2067620988/
/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 3⌋ times. return all such elements You may assume that the majority element always exists in the array.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
// moore's algo
// intuition for all such ques: there can be only one candidate when n/2 ; 2 candidates when n/3; 3 when n/4 and so on
// use basic math to understand what i said above
    int cand1,cand2,cnt1,cnt2;
    cand1=cand2=cnt1=cnt2=0;
    for(auto num: nums){
        if(num==cand1){
            cnt1++;
        }
        else if(num==cand2){
            cnt2++;
        }
        else if(cnt1==0){
            cand1=num;
            cnt1=1;
        } else if(cnt2==0){
            cand2=num;
            cnt2++;
        }else{
            cnt1--; cnt2--;
        }
    }
    // we verify our candidates
    cnt1=cnt2=0;
    for(auto num: nums){
        if(num==cand1) cnt1++;
        else if(num==cand2) cnt2++;
    }
    vector<int> ans;
    int n=nums.size();
    if(cnt1>n/3) ans.push_back(cand1);
    if(cnt2>n/3) ans.push_back(cand2);

    return ans;
}
int main(){
 vector<int> a={1,2,1,2,1,2,1};
 vector<int> ans = majorityElement(a);
 for(auto num: ans){
    cout<<num<<" ";
 }
}

