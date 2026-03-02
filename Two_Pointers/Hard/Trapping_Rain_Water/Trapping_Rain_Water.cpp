/*Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int brute(vector<int>& height) {
    int n=height.size(),ans=0;
    for(int i=0;i<n;i++){
        int leftmax=0,rightmax=0;
        for(int j=i;j>=0;j--) leftmax=max(leftmax,height[j]);
        for(int j=i;j<n;j++) rightmax=max(rightmax,height[j]);
        int mini=min(leftmax,rightmax);
        ans+=mini-height[i];
    }
    return ans;
}
int better(vector<int>& height) {
    int n=height.size(),ans=0;
    vector<int>leftmax(n,0),rightmax(n,0);
    leftmax[0]=height[0];
    rightmax[n-1]=height[n-1];
    for(int i=1;i<n;i++) leftmax[i]=max(height[i],leftmax[i-1]);
    for(int i=n-2;i>=0;i--) rightmax[i]=max(height[i],rightmax[i+1]);
    for(int i=0;i<n;i++){
        int mini=min(leftmax[i],rightmax[i]);
        ans+=mini-height[i];
    }
    return ans;
}
int optimized(vector<int> &arr){
    int n=arr.size();
    int i=0,j=n-1;
    int maxleft=0,maxright=0;
    long long ans=0;
    while(i<j){
        maxleft=max(maxleft,arr[i]);
        maxright=max(maxright,arr[j]);
        if(maxright<maxleft){
            ans+=maxright-arr[j];
            j--;
        }
        else{
            ans+=maxleft-arr[i];
            i++;
        }
    }
    return ans;
}
int main(){
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<better(height)<<endl;
    return 0;
}