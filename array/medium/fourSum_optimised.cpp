 // this is the best approach
// link: https://leetcode.com/problems/4sum/description/
#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> fourSum(vector<int>& a) {
  sort(a.begin(),a.end());
  vector<vector<int>> ans;
  int n=a.size();
  for(int i=0;i<n-3;i++){
    if(i>0 && a[i]==a[i-1]) continue;
    for(int j=i+1;j<n-2;j++){
        if(j>i+1 && a[j]==a[j-1]) continue;
        int left=j+1;
        int right=n-1;
        int sum=0;
        while(left<right){
             sum=a[i]+a[j]+a[left]+a[right];
             if(sum==0){
                vector<int> temp ={a[i],a[j],a[left],a[right]};
                ans.push_back(temp);
                left++;
                right--;

                while(left<right && a[left]==a[left-1]) left++;
                while(left<right && a[right]==a[right+1]) right--;
             }else if(sum<0) left++;
             else right--;
        }
    }
  }
  return ans;
 }
int main(){
 vector<int> a = {1,2,3,4,0,-1,-2,-3,-4};
 vector<vector<int>>ans = fourSum(a);
 for(auto nums: ans){
    for(auto n: nums){
        cout<<n<<" ";
    }
    cout<<endl;
 }
 return 0;
}


// note:
// Time: O(n^3) (sorting is dominated by the two-pointer search)
// Space: O(1) extra (excluding the output vector)
