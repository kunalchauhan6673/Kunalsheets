// link: https://leetcode.com/problems/merge-intervals/description/
#include<bits/stdc++.h>
using namespace std;
// this is brute:
// Time: O(n²) (worst case) -> has two passes
// Space: O(n)
// intuition: here we are figuring out which ones will share the same start and end
vector<vector<int>> merge(vector<vector<int>>& interns) {
     vector<vector<int>> ans; // ans will be stored here
     sort(interns.begin(),interns.end()); // step1). sort the vector
     int n= interns.size();
     // step2). iterate a loop from 0 to n
     for(int i=0;i<n;i++){
        // initialise start and end of interns
        int start = interns[i][0];
        int end = interns[i][1];

        // step 3). if ans is not empty and our current end is smaller than last intern's end then skip
        if(!ans.empty() && end<=ans.back()[1]) continue;

        // step 4). iterate loop from i+1 to n
        for(int j=i+1;j<n;j++){
            // if new intern's start is smaller than current intern's end
            if(interns[j][0]<=end){
                // update new end
                end=max(end,interns[j][1]);
            }
        }
        ans.push_back({start,end});
     }
    return ans;
}
// intuition: focus on intervals that do not overlap, rather than brute where we focused otherwise
// Time complexity: O(n log n)
// Space complexity: O(n) (for the output array, excluding the returned result it's O(1) auxiliary space)
vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            // we check if either ans is empty or if they dont belong in the same intervals
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(ans.empty() || start>ans.back()[1]){
                ans.push_back(intervals[i]);
            } else{
            // if they do belong to the same intervals -> then we find max end
            ans.back()[1]=max(ans.back()[1],end);
            }
        }
        return ans;
}
