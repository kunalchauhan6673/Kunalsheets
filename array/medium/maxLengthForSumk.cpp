#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums, int k)
{      // TC: o(n^2) and sc: o(1)
        int n = nums.size();
        int maxLength = 0;
        for(int i=0;i<n;i++){
            int sum=0,length=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k)
                     maxLength = max(maxLength, j - i + 1);
            }
        }
        return maxLength;
}

int main()
{
    vector<int> a = { -5,10,1,1,1,1,1,5 };
    int k = 10;
    int len = longestSubarray(a, k);

    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
