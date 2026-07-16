//https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
    l
class Solution {
public:
    long gcd(int a, int b){
        while(b!=0){
            int temp = a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int maxEl=nums[0];
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
          maxEl = max(maxEl,nums[i]);
          temp.push_back(gcd(maxEl,nums[i]));
        }
        sort(temp.begin(),temp.end());
        int i=0;
        int j=temp.size()-1;
        long long sum=0;
        while(i<j){
            sum+=gcd(temp[i],temp[j]);
            i++; j--;
        }
        return sum;
    }
};