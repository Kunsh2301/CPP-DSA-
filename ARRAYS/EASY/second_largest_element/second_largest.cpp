//WAP TO FIND SECOND LARGEST ELEMENT OF THE ARRAY RETURN -1 IF NOT PRESENT
#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int brute(vector<int> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=arr[n-1]) return arr[i];
    }
    return -1;
}
int optmize(vector<int> &arr) {
    int firstlargest=INT_MIN;
    int secondlargest=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>firstlargest){
            secondlargest=firstlargest;
            firstlargest=arr[i];
        }
        else if(arr[i]<firstlargest && arr[i]>secondlargest) secondlargest=arr[i];
    }
    return secondlargest==INT_MIN?-1:secondlargest;
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
        cout<<brute(arr)<<" ";
        return 0;
    }
    cout<<optmize(arr)<<" ";
}