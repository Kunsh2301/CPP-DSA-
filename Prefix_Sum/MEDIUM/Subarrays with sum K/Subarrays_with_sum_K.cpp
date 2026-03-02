/*Given an unsorted array arr[] of integers, 
find the number of subarrays whose sum exactly equal to a given number k.*/
#include <vector>
#include <unordered_map>
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
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int ans = optimized(nums, k);
    return 0;
}