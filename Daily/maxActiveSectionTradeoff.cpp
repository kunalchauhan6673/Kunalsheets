// problem link: https://leetcode.com/problems/maximize-number-of-active-sections-after-tradeoff/
// given a string s consisting of '0's and '1's, where '1' represents an active section and '0' represents an inactive section. 
// You can perform a tradeoff operation to maximize the number of active sections. 
// The goal is to find the maximum number of active sections after performing the tradeoff operation.
// example: s = "11001000", output = 5
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Stores the maximum number of inactive sections
        // that can be converted to active after one trade.
        int maxMise = 0;

        // Total number of active ('1') sections already present.
        int ones = 0;

        // Length of the previous zero block.
        int prev = -1;

        // Indicates whether we have encountered a block of '1's.
        bool seenOne = false;

        // Traverse the string block by block.
        for (int i = 0; i < n;) {

            int j = i;

            // Find the length of the current block
            // (continuous sequence of same characters).
            while (j < n && s[i] == s[j]) {
                j++;
            }

            int len = j - i;

            // Current block consists of active sections.
            if (s[i] == '1') {
                seenOne = true;
                ones += len;
            }
            // Current block consists of inactive sections.
            else {

                // Pattern found:
                // previous zero block -> one block -> current zero block
                // These two zero blocks can be merged after one trade.
                if (seenOne && prev != -1) {
                    maxMise = max(maxMise, prev + len);
                }

                // Store current zero block for future merging.
                prev = len;

                // Reset because we are currently on a zero block.
                seenOne = false;
            }

            // Move to the next block.
            i = j;
        }

        // Existing active sections + maximum inactive sections
        // that can be activated after the optimal trade.
        return ones + maxMise;
    }
};