// note: here we are returning the numbers which sum up to the target, 
// if we want to return the indexes of those numbers, we can do that too, 
// but the array should be sorted in that case.
// On leetcode the two sum ques requires us to return the indexes of the numbers, 
// so we can use hashmap approach to do that but not the two pointer solution!
#include<bits/stdc++.h>
using namespace std;
int ans[2]={-1};
int brute(int a[],int n, int t){
    // tc: o(n^2) and sc is o(1);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==t){
            ans[0]=a[i]; ans[1]=a[j];
            return 1;
            }
        }
    }
    return 0;
}

int hashmap(int a[], int n, int t){
    // tc: o(n) and sc is o(n);
 unordered_map<int, int> mp;
 for(int i=0;i<n;i++){
    int comp = t - a[i];
    if(mp.find(comp)!=mp.end()){
        ans[0]=comp;
        ans[1]=a[i];
        return 1;
    }
    mp[a[i]]=i;
 }
 return 0;
}

int optmized(int a[],int n, int t){
 // tc: o(nlogn) and sc is o(1);
 /*Note: Same logic can be used for two sum, return indexes, only if the array given is in sorted order!*/
 int i=0; int j=n-1;
 while(i<=j){
    if(a[i]+a[j]==t){
        ans[0]=a[i];
        ans[1]=a[j];
        return 1;
    }
    else if((a[i]+a[j])<t){
       i++;
    }
    else{
        j--;
    }
 }
 return 0;
}


int main(){
    int a[]={2,7,11,17};
    int size=sizeof(a)/sizeof(a[0]);
    int target=9;

    if(optmized(a,size,target)){
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    else{
        cout<<"No such numbers!"<<endl;
    }
    return 0;
}


