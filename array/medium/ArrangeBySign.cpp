// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
/*
Conditions:
1.Every consecutive pair of integers have opposite signs.
2.For all integers with the same sign, the order in which they were present in nums is preserved.
3.The rearranged array begins with a positive integer.*/
#include<bits/stdc++.h>
using namespace std;
vector<int> RearrangeBySign_brute(vector<int> a){
 vector<int> ans;
 vector<int> pos; vector<int> neg;
 for(int i=0;i<a.size();i++){
    if(a[i]>0){
        pos.push_back(a[i]);
    } else{
       neg.push_back(a[i]);
     }
 }
 int p=0,n=0;
 for(int i=0;i<a.size();i++){
    if(i%2==0){
        ans.push_back(pos[p++]);
    } else{
        ans.push_back(neg[n++]);
    }
 }
 return ans;
}
vector<int> RearrangeBySign_Optimal(vector<int> a){
 vector<int> ans(a.size());
 int pos=0; int neg=1;
 for(int i=0;i<a.size();i++){
    if(a[i]>0){
        ans[pos]=a[i];
        pos+=2;
    }
    else{
        ans[neg]=a[i];
        neg+=2;
    }
 }
 return ans;
}
int main(){
vector<int> a={3,1,-2,-5,2,-4};
// vector<int> ans = RearrangeBySign_brute(a);
vector<int> ans = RearrangeBySign_Optimal(a);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
}
/*
=> Brute Force: TC = O(n), SC = O(n) (uses two extra arrays (pos, neg) along with the output array).
=> Optimal: TC = O(n), SC = O(n) (uses only the output array; no auxiliary arrays).*/

