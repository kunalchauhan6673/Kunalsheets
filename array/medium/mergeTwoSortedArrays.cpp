//https://leetcode.com/problems/merge-sorted-array/description/
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
#include<bits/sdtc++.h>
using namespace std;
// note:
// tc: o(n+m) and sc: o(n+m)
void merge1(vector<int>& num1, int m, vector<int>& nums2, int n) {
       vector<int> temp=num1;
       int i=0,j=0,k=0;
       while(i<m && j<n){
         if(temp[i]<nums2[j]){
            num1[k++]=temp[i++];
         } else{
            num1[k++]=nums2[j++];
         }
       }
       while(i<m)
       num1[k++]=temp[i++];
       while(j<n)
       num1[k++]=nums2[j++];
}
void merge2(vector<int>& num1, int m, vector<int>& nums2, int n) {
// our thinking is opposite here, we start by storing the largest element first at the end
// tc: o(n+m) and sc: o(1)
       int i=m-1,j=n-1,k=num1.size()-1;
       while(i>=0 && j>=0){
         if(num1[i]>nums2[j]){
            num1[k--]=num1[i--];
         } else{
            num1[k--]=nums2[j--];
         }
       }
       while(i>=0)
       num1[k--]=num1[i--];
       while(j>=0)
       num1[k--]=nums2[j--];
    }
int main(){
 vector<int> a={1,2,3,0,0,0};
 vector<int> b={2,5,6};
 merge1(a,3,b,3);

}
