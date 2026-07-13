/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.*/
// note: this isnt lcs that we studied in dp, both are different!!
// https://leetcode.com/problems/longest-consecutive-sequence/description/
#include<bits/stdc++.h>
using namespace std;
bool linearSearch(int x, vector<int> nums){
 for(int a: nums){
    if(x==a)
        return true;
 }
 return false;
}
int LCS_Brute(vector<int> a){
 int ans=0;
 for(int i=0;i<a.size();i++){
    int curr=a[i];
    int countt=1;
    while(linearSearch(curr+1,a)){
        curr++;
        countt++;
    }
    ans=max(ans,countt);
 }
 return ans;
}
// Idea for O(n) solution using set:
// • Store all numbers in an unordered_set for fast searching.
// • Start counting only from the first number of a consecutive sequence.
// • A number is the first in a sequence if its previous number (a - 1) is NOT present in the set.
// • Keep checking for the next number (a + 1) until the sequence ends.
// • Store the maximum sequence length.

// Key Condition:
// if (st.find(it - 1) == st.end())
// → It means there is no previous consecutive number.
// → So, 'it' is the starting point of a new sequence.
// → This avoids counting the same sequence multiple times
int LCS_optimal(vector<int> a){
 if(!a.size()) return 0;
 unordered_set<int> Set;
 for(int i=0;i<a.size();i++){
    Set.insert(a[i]);
 }
 int maxLength=1;
 for(auto it: Set){
    if(Set.find(it-1)==Set.end()){ // works only when it-1 is not present in the set
       int curr=it;
       int cnt=1;
       while(Set.find(curr+1)!=Set.end()){ // works only when it+1 is present in the set
        cnt++;
        curr++;
       }
       maxLength=max(maxLength,cnt);
    }
 }
 return maxLength;
}
int main(){
 vector<int> a={100,4,200,1,3,2};
 cout<<LCS_optimal(a);
}

/*
Brute Force:
TC = O(n³)
SC = O(1)

Optimal (using unordered_set):
TC = O(n) average, O(n²) worst case (due to hash collisions)
SC = O(n)
*/