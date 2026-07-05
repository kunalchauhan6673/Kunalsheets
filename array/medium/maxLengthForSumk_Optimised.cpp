/*Prefix sum- hasMap Approach: We calculate the prefix sum while traversing the array.
At each index, if the current prefix sum equals k, we've found a valid subarray starting from index 0.
Otherwise, we compute sum - k and check if that prefix sum has occurred before.
If it has, we ignore all elements up to that previous index, because the remaining elements up to the current index will sum to k.
This approach is optimised if the array has negative, zero and positive elements. however it is not the best if the array has
only positive elements, in that case we use two pointers!*/

#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums, int k)
{      // TC: o(n) and sc: o(n)
       // optimised for pos,neg,zero array
       map<long long, int> prefixSumMap;
       long long sum=0;
       int maxLen=0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k)
            maxLen=max(maxLen,i+1);
       long long rem=sum-k;
       // if block is executed only when rem is found!
       if(prefixSumMap.find(rem) != prefixSumMap.end()){ //"Does the prefix sum rem exist in the map?"
            int len = i - prefixSumMap[rem];
            maxLen = max(maxLen, len);
        }
       // It's checking whether the current prefix sum has already been stored.
      if (prefixSumMap.find(sum) == prefixSumMap.end()) { // "Has this current prefix sum been stored before?"
          prefixSumMap[sum] = i;
    }
       }
    return maxLen;
}
int main()
{
    vector<int> a = {10,1,1,1,1,1,5 };
    int k = 10;
    int len = longestSubarray(a, k);

    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

/*
Note:
-> With map:
Time = O(n log n) (because map is implemented as a balanced BST)
-> With unordered_map:
Average Time = O(n)
Worst Case = O(n^2) (rare due to hash collisions) */

