// problem link: https://leetcode.com/problems/maximize-number-of-active-sections-after-tradeoff/
// given a string s consisting of '0's and '1's, where '1' represents an active section and '0' represents an inactive section. 
// You can perform a tradeoff operation to maximize the number of active sections. 
// The goal is to find the maximum number of active sections after performing the tradeoff operation.
// example: s = "11001000", output = 5
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
     int n=s.size();
     int maxMise=0;
     int ones=0,prev=-1;
     bool seenOne=false;
     for(int i=0;i<n;)
     {
       int j=i;
        while(j<n && s[i]==s[j]){
            j++;
        }
        int len = j-i;
        if(s[i] == '1'){
            seenOne=true;
            ones+=len;
        }
        else{
            if(seenOne && prev!=-1){
                maxMise=max(maxMise,prev+len);
            }
            prev=len;
            seenOne=false;
        }
        i=j;
     }
     return ones+maxMise;
     }
};