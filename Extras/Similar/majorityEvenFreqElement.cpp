#include<bits/stdc++.h>
using namespace std;
int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> hmap;
        for(int num: nums){
          if(num%2==0)
          hmap[num]++;
        }
        int ans=-1;
        int maxfreq=0;
        for(auto& it: hmap){
            if(it.second>maxfreq){
                maxfreq=it.second;
                ans=it.first;
            }
            else if (it.second == maxfreq && it.first < ans) {
                ans = it.first;
            }
        }
        return ans;
}
int main(){
 vector<int> a = {1,2,3,4,4,4,4,5,6,6,6,6};
 cout<<mostFrequentEven(a);
}
// this is optimal solution, tc:o(n) and sc is o(n)
// link: https://leetcode.com/submissions/detail/2067637540/
