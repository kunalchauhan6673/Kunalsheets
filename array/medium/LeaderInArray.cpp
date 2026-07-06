/*Input:
arr = [4, 7, 1, 0]
Output:
 7 1 0
Explanation:
The rightmost element (0) is always a leader.
7 and 1 are greater than the elements to their right, making them leaders as well.*/
// note: brute is just using two loops, this below is the optimal
#include<bits/stdc++.h>
using namespace std;
vector<int> LeaderInArray(vector<int> a){
 vector<int> ans;
 int Leader=a[a.size()-1];
 ans.push_back(Leader);
 for(int i=a.size()-2;i>=0;i--){
    if(Leader<a[i]){
        ans.push_back(a[i]);
        Leader=a[i];
    }
 }
 reverse(ans.begin(), ans.end());
 return ans;
}
int main(){
vector<int> a={4, 7, 1, 0};
vector<int> ans = LeaderInArrayBrute(a);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
}
/*
/*
Optimal:
TC = O(n)
SC = O(n) (output array to store leaders)
*/*/

