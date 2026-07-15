 // this is the brute approach, run it and it will give time limit exceeded as tc: o(n^3)
 // link: https://leetcode.com/problems/3sum/description/
 #include<bits/stdc++.h>
 using namespace std;
 vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        // Generate all possible triplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {

                    // Check if the triplet sums to zero
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};

                        // Sort to handle different permutations
                        sort(temp.begin(), temp.end());

                        // Set automatically removes duplicate triplets
                        st.insert(temp);
                    }
                }
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
