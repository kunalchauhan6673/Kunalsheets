 // this is the best approach
// link: https://leetcode.com/problems/3sum/description/
#include<bits/stdc++.h>
 using namespace std;
 vector<vector<int>> threeSum(vector<int>& a) {
  int n=a.size();
  sort(a.begin(),a.end());
  vector<vector<int>> ans;

  for(int fixed=0;fixed<n-2;fixed++){

  //handling duplicates:
  if(fixed>0 && a[fixed]==a[fixed-1]) continue;

  int left = fixed+1;
  int right = n-1;
  while(left<right){
    int sum = a[fixed]+a[left]+a[right];
    if(sum==0){
        ans.push_back({a[fixed],a[left],a[right]});
        right--;
        left++;

        // handling duplicates: instead of using a set
        while(left<right && a[left]==a[left-1])
            left++;
        while(left<right && a[right]==a[right+1])
            right--;

    }
    else if(sum<0){
        left++;
    } else{
      right--;
    }
  }
  }
  return ans;
}
int main(){
 vector<int> a = {-1,0,1,2,-1,-4};
 vector<vector<int>>ans = threeSum(a);
 for(auto nums: ans){
    for(auto n: nums){
        cout<<n<<" ";
    }
    cout<<endl;
 }
}


// note:
// Time: O(n²) (sorting is dominated by the two-pointer search)
// Space: O(1) extra (excluding the output vector)
