 // this is the better approach, run it
 // and it will also give time limit exceeded
// | Complexity | Value                                                                         |
// | ---------- | ----------------------------------------------------------------------------- |
// | **Time**   | **O(n² log n)**                                                               |
// | **Space**  | **O(n + k)**, where `k` is the number of unique triplets (worst case `O(n²)`) |
// link: https://leetcode.com/problems/3sum/description/
 #include<bits/stdc++.h>
 using namespace std;
 vector<vector<int>> threeSum(vector<int>& a) {
        set<vector<int>> st;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            set<int> hashset;
            for (int j = i + 1; j < n; j++) {
               int third = -(a[i]+a[j]);
               if(hashset.find(third)!=hashset.end())
               {
                   vector<int> temp = {a[i],a[j],third};
                   sort(temp.begin(),temp.end());
                   st.insert(temp);
               }
               hashset.insert(a[j]);
            }
        }
        // Convert set to vector
        return vector<vector<int>>(st.begin(), st.end());
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


