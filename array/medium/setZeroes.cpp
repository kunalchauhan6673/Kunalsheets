/*Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix..*/
// https://leetcode.com/problems/set-matrix-zeroes/description/
#include<bits/stdc++.h>
using namespace std;
void setZeroes_brute(vector<vector<int>> &matrix){
int n=matrix.size(); // gives the number of rows;
int m=matrix[0].size();  // gives the number of columns
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(matrix[i][j]==0){
            for(int cols=0;cols<m;cols++){
                if(matrix[i][cols]!=0)
                    matrix[i][cols]=-1;
            }
            for(int rows=0;rows<n;rows++){
                if(matrix[rows][j]!=0)
                    matrix[rows][j]=-1;
            }
        }
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(matrix[i][j]==-1)
            matrix[i][j]=0;
    }
}
// note: TC: o(n*m*(n+m)) and sc is o(1) <- why this isnt good -> -1 can be in the testcase eg: [[-1],[2],[3]], in such case, it will give wrong ans
}

void setZeroes_better(vector<vector<int>> &matrix){
 int n=matrix.size();
 int m=matrix[0].size();
 vector<int> rowMarker(n,0);
 vector<int> colMarker(m,0);
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(matrix[i][j]==0){
                rowMarker[i]=1;
                colMarker[j]=1;
    }
}
}
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(colMarker[j]==1||rowMarker[i]==1){
                matrix[i][j]=0;
    }
}

// note: TC: o(n*m) and sc: o(n+m); the problem of -1 doesnt occur here
}
int main(){
 vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
 setZeroes_better(matrix);
 for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[0].size();j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
 }
 return 0;
}

