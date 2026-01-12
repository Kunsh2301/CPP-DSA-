// WAP TO CHECK WHEATHER A NUMBER IS PRESENT IN AN ARRAY OR NOT USING BINARY SEARCH
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool binarysearch(vector<int>&,int);
int main(){
    int n,target;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<endl<<"Enter the target of the array : ";
    cin>>target;
    vector<int>nums(n);
    cout<<endl<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++) cin>>nums[i];
    sort(nums.begin(),nums.end());
    cout<<endl<<(binarysearch(nums,target)?"TRUE":"FALSE");
    return 0;
}
bool binarysearch(vector<int>&arr,int target){
    int n=arr.size(),low=0,high=n-1;
    while(low<=high){
        int med=low+(high-low)/2;
        if(arr[med]==target) return true;
        else if(arr[med]>target) high=med-1;
        else low=med+1;
    }
    return false;
}
