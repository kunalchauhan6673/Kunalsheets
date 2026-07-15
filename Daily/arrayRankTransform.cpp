// https://leetcode.com/submissions/detail/2068391610/
// link: https://leetcode.com/problems/rank-transform-of-an-array/description
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        map<int, int> rank;
        int r=1;
        for(auto num: temp){
            if(rank.find(num)==rank.end()) // if num is not present in map
            {
                rank[num]=r;
                r++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};