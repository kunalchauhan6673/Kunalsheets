// letcode link: https://leetcode.com/problems/sequential-digits/description/
// dirty solution, but it works, Tc: O(36), Sc: O(36) means O(1) because 36 is constant,
// we can also generate the list of sequential digits using a loop, but this is easier and faster to implement.
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
    vector<int> list = {12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
    vector<int> ans;
    for (auto num: list){
        if(num>=low && num<=high){
            ans.push_back(num);
        }
    }
    return ans;
    }
};