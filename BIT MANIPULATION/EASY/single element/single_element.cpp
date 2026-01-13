// WAP to find single element in sorted array which contains duplicate elements except the one to be find.
#include<iostream>
#include<vector>
using namespace std;
int singleelement(vector<int>& arr){
    int n=arr.size(),res=0;
    for(int i=0;i<n;i++) res^=arr[i];
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<singleelement(arr);
}