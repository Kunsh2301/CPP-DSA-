/*Given an unsorted array arr[] of integers, 
find the number of subarrays whose sum exactly equal to a given number k.*/
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
int optimized(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> prefix;
    prefix.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        prefix.push_back(prefix[i - 1] + nums[i]);
    }
    int count = 0;
    unordered_map<int, int> store;
    for (int i = 0; i < n; i++)
    {
        if (prefix[i] == k)
            count++;
        if (store.find(prefix[i] - k) != store.end())
            count += store[prefix[i] - k];
        store[prefix[i]]++;
    }
    return count;
}
int brute_force(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> prefix;
    prefix.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        prefix.push_back(prefix[i - 1] + nums[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == 0)
            {
                if (prefix[j] == k)
                    count++;
            }
            else
            {
                if (prefix[j] - prefix[i - 1] == k)
                    count++;
            }
        }
    }
    return count;
}
int main()
{
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter the target sum: ";
    int k;
    cin>>k;
    int ans = optimized(nums, k);
    cout<<ans;
    return 0;
}