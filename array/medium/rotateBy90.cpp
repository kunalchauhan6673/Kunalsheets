// Problem Statement: Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.
// The rotation must be done in place, meaning the input 2D matrix must be modified directly..
// ques: https://leetcode.com/problems/rotate-image/description

// how to:
// step 1) .Transpose the matrix: swap elements across the diagonal. This converts rows into columns.
// Step 2) Reverse each row: this turns the new columns into the final rotated row

#include<bits/stdc++.h>
using namespace std;
void rotateBy90(vector<vector<int>> &matrix){
 int n=matrix.size(); // rows

 // step1). tranpose the matrix
 for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){ // i+1 -> The reason is to avoid swapping the same pair twice and to avoid swapping an element with itself.
        swap(matrix[i][j],matrix[j][i]);
    }
 }
 // step 2). reverse each row
 for(int i=0;i<n;i++){
    reverse(matrix[i].begin(),matrix[i].end());
 }
}
int main(){
 vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotateBy90(matrix);
 for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix.size();j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
 }
    return 0;
}

