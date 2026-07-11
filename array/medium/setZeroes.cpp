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
}
// note: TC: o(n*m) and sc: o(n+m); the problem of -1 doesnt occur here
}
void setZeroes_optimal(vector<vector<int>> &matrix){
 int n=matrix.size();
 int m=matrix[0].size();

 bool firstRow=false;
 bool firstCol=false;

 for(int i=0;i<n;i++){
    if(matrix[i][0]==0)
    {
      firstRow=true; break;
    }
 }
  for(int i=0;i<m;i++){
    if(matrix[0][i]==0)
    {
      firstCol=true; break;
    }
 }
 for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
        if(matrix[i][j]==0){
            matrix[i][0]=0; // marking the row
            matrix[0][j]=0; // marking the col
        }
    }
 }
  for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
        if(matrix[i][0]==0 || matrix[0][j]==0){
           matrix[i][j]=0; // setting the cell as zero
        }
    }
 }
 if(firstCol){
    for(int i=0;i<m;i++)
        matrix[0][i]=0;
 }
  if(firstRow){
    for(int i=0;i<n;i++)
        matrix[i][0]=0;
 }
}

int main(){
 vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
 setZeroes_optimal(matrix);
 for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[0].size();j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
 }
 return 0;
}

// note for optimal: Tc: o(n*m) and sc: o(1)
// how its done:
// intuition: Unlike the better approach where we use two extra arrays (row[] and col[]),
/* here we reuse the matrix's first column as the row marker array and the first row as the column marker array.
Before doing this, we check whether the original first row or first column contains any zero and store that information in two boolean variables.
Then we traverse the matrix from (1,1) onwards. Whenever we find a zero, we mark its entire row and column by setting matrix[i][0] = 0 and matrix[0][j] = 0.
In the second pass, again from (1,1), if either the row marker or column marker is zero, we set that cell to zero.
Finally, based on the two boolean variables, we zero out the first row and/or the first column if they originally contained a zero. */

/* 1. Check if the first row or first column initially contains any 0.
   Store this information in:
   firstRowZero and firstColZero.

2. Traverse the matrix from (1,1) to (m-1,n-1).
   If matrix[i][j] == 0, mark its row and column by setting:
   matrix[i][0] = 0 and matrix[0][j] = 0.

3. Traverse the matrix again from (1,1) to (m-1,n-1).
   If matrix[i][0] == 0 OR matrix[0][j] == 0,
   set matrix[i][j] = 0.

4. If firstRowZero is true, set the entire first row to 0.

5. If firstColZero is true, set the entire first column to 0. /*
