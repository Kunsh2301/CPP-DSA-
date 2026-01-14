//WAP to return indices of two numbers in an array that sum to a target value (i!=j)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> brute(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target) return {i,j};
        }
    }
    return {};
}
vector<int> optimized(vector<int>& nums, int target) {
    unordered_map<int,int>index;
    for(int i=0;i<nums.size();i++){
        if(index.find(target-nums[i])!=index.end()) return {index[target-nums[i]],i};
        index[nums[i]]=i;
    }
    return {};
}
int main(){
    int n,target;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>target;
    string choice;
    cout<<"enter choice (brute/optimized): ";
    cin>>choice;
    if(choice=="brute"){
        vector<int> result = brute(arr,target);
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        return 0;
    }
    vector<int> result = optimized(arr,target);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}