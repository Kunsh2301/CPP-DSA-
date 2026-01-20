/*WAP TO RETURN PEAK INDEX(THE POINT WHERE ITS LEFT PART IS IN INCREASING ORDER AND RIGHT PART IS DECREASING ORDER)
 IN AN ARRAY */
#include<iostream>
#include<vector>
using namespace std;
int peakindex(vector<int>&);
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<endl<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<endl<<peakindex(nums);
    return 0;
}
int peakindex(vector<int>&arr){
    int n=arr.size(),low=0,high=n-1;
    if(n<3) return -1;
    while(low<high){
        int mid=low+(high-low)/2;
        if (arr[mid]<arr[mid+1]) low=mid+1;
        else high=mid;
    }
    return low;
}
/* CONSTRAINTS :
3 <= arr.length 
0 <= arr[i]
arr is guaranteed to be a SINGLE PEAK INDEX array.
*/