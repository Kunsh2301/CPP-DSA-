/*WAP to take input an array of integers from user (n,arr[]). For every element in the array, your task is to find the index 
of the farthest element in the array to the right which is smaller than the current element. If no such number exists then print -1.
Note: 0 based indexing is followed , n=size of array*/ 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> optimize(int n, vector<int> &arr) {
    vector<int>minright(n);
    int mini=INT_MAX;
    for(int i=n-1;i>=0;i--){
        mini=min(mini,arr[i]);
        minright[i]=mini;
    }
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        int low=i+1,high=n-1,res=-1;
        while(low<=high){
            int med=low+(high-low)/2;
            if(arr[i]>minright[med]){
                res=med;
                low=med+1;
            }
            else high=med-1;
        }
        ans[i]=res;
    }
    return ans;
}
vector<int> brute(int n, vector<int> &arr) {
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]){
                ans[i]=j;
                break;
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string choice;
    cout<<"enter choice (brute/optimized): ";
    cin>>choice;
    if(choice=="brute"){
        vector<int>ans=brute(n,arr);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        vector<int>ans=optimize(n,arr);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}