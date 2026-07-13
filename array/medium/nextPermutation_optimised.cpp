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
void nextPermutation(vector<int>& a) {
        int n=a.size();
        int index=-1;
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
              index=i;
              break;
            }
        }
        if(index==-1){
            reverse(a.begin(),a.end());
            return;
        }
        for(int i=n-1;i>=index;i--){
        if(a[index]<a[i]){
            swap(a[index],a[i]);
            break;
        }
        }
        reverse(a.begin()+index+1,a.end());
    }
int main() {
    vector<int> nums = {2, 1, 3};
    nextPermutation(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
// Time Complexity: O(n) and sc: O(1), since we are not using any extra space.