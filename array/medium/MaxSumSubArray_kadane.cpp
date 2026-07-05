#include<bits/stdc++.h>
using namespace std;
int Kadane(vector<int>& nums){ //tc: o(n) and sc: o(1)
 int maxSum=INT_MIN;
 int sum=0;
 for(int num: nums){
    sum+=num;
    maxSum=max(sum,maxSum);
    if(sum<0)
        sum=0;
 }
 return maxSum;
}
int main(){
 vector<int> a={2, 3, 5, -2, 7, -4};
 cout<<Kadane(a);
 return 0;
}
