/*Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } }
Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form. */
// ques: https://leetcode.com/problems/spiral-matrix/description/

// how to:
// step 1) initialise top, left, bottom, right;
// Step 2) we iterate a loop as long as left<= right && top<=bottom, in it we:
// -> first print left -> right and top++; matrix[top][i]
// -> print top -> bottom and right--; matrix[i][right]
// -> check if top<=right and then print right -> left and bottom --; matrix[bottom][i]
// -> check if left<=right and then print bottom -> top and left++; matrix[i][left]

#include<bits/stdc++.h>
using namespace std;
vector<int> rotateSpirally(vector<vector<int>> &matrix){
 int top=0, left=0;
 int bottom = matrix.size()-1, right=matrix[0].size()-1;
 vector<int> ans;
 while(left<=right && top<=bottom){
    for(int i=left;i<=right;i++){
       ans.push_back(matrix[top][i]);
    }
    top++;
    for(int i=top;i<=bottom;i++){
        ans.push_back(matrix[i][right]);
    }
    right--;
    if(top<=bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
    }
    if(left<=right){
        for(int i=bottom;i>=top;i--){
         ans.push_back(matrix[i][left]);
        }
        left++;
    }
 }
 return ans;
}
int main(){
 vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
 vector<int> ans = rotateSpirally(matrix);
 for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
 }
    return 0;
}

