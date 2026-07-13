/*Problem Statement: Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly*/
// ques: https://leetcode.com/problems/pascals-triangle/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> pascalTriangle(int n){
 vector<vector<int>> ans;
 for(int i=0;i<n;i++){
    vector<int> row(i+1,1);
    for(int j=1;j<i;j++){
        row[j]= ans[i-1][j-1]+ans[i-1][j];
    }
    ans.push_back(row);
 }
 return ans;
}
int main(){
 vector<vector<int>> ans = pascalTriangle(6);
 for(auto num: ans){
    for(auto n: num){
        cout<<n<<" ";
    }
    cout<<endl;
 }
 return 0;
}


