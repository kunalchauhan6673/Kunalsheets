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

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;

    generatePermutations(0, nums, ans);

    for (auto &perm : ans) {
        for (int x : perm) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

