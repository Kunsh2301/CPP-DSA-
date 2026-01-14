#include<iostream>
#include<vector>
using namespace std;
vector<int> brute(vector<int>& arr) {
    vector<int> result;
    for(int i=0;i<arr.size();i++) if(arr[i]!=0) result.push_back(arr[i]);
    for(int i=0;i<arr.size();i++) if(arr[i]==0) result.push_back(arr[i]);
    return result;
}
void optimized(vector<int>& arr) {
    int i=0,j=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            arr[j]=arr[i];
            j++;
        }
    }
    for(int k=j;k<arr.size();k++) arr[k]=0;
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
        vector<int> result = brute(arr);
        for(int i=0;i<n;i++){
            cout<<result[i]<<" ";
        }
        return 0;
    }
    optimized(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}