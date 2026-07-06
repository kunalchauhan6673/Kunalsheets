//A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally,
// if all the permutations of the array are sorted in one container according to their lexicographical order,
// then the next permutation of that array is the permutation that follows it in the sorted container.
// If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// https://leetcode.com/problems/next-permutation/description/


// ques:
/* For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums. */
#include <bits/stdc++.h>
using namespace std;
void generatePermutations(int index, vector<int>& nums, vector<vector<int>>& ans) {
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        generatePermutations(index + 1, nums, ans);
        swap(nums[index], nums[i]); // Backtrack
    }
}
void nextPermutation_brute(vector<int> &nums){
    vector<vector<int>> ans;
    generatePermutations(0, nums, ans);

   sort(ans.begin(), ans.end());
   ans.erase(unique(ans.begin(), ans.end()), ans.end()); // erase duplicates!

    for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == nums) {
        if (i == ans.size() - 1)
            nums = ans[0];
        else
            nums = ans[i + 1];
        return;
    }
}
}
int main() {
    vector<int> nums = {2, 1, 3};
    nextPermutation_brute(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
// Time Complexity: O(N!*N), since we are generating all possible permutations, it takes N! time.
// Space Complexity: O(N!), storing all permutations.
