# Two Sum

## Problem Statement
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

## Intuition
The problem requires finding two distinct elements in the array that sum to the target value. A naive approach would check all pairs, but we can optimize using a hash map to store elements we've seen and their indices.

## Brute Force Approach
### Explanation
Iterate through each element and check every other element to see if their sum equals the target.

### Algorithm
1. Loop through each element `i` from 0 to n-1.
2. For each `i`, loop through `j` from i+1 to n-1.
3. If `nums[i] + nums[j] == target`, return `[i, j]`.
4. If no pair is found, return an empty array.

### Complexity
- Time: O(n²)
- Space: O(1)

## Optimization Reasoning
The brute force approach is inefficient for large arrays due to its quadratic time complexity. We can reduce this by using a hash map to store the complement of each element as we iterate.

## Key Observation
For each element `nums[i]`, check if `target - nums[i]` exists in the map. If it does, we've found the pair.

## Optimized Approach
Use a hash map to store elements and their indices. For each element, compute the complement and check if it's in the map.

## Algorithm
1. Initialize an unordered_map to store value to index.
2. Iterate through the array:
   - Compute complement = target - nums[i].
   - If complement is in the map, return [map[complement], i].
   - Else, store nums[i] and i in the map.
3. If no pair is found, return an empty array.

## 🧪 Dry Run
### Example Input:
```
Array: [2, 7, 11, 15]
Target: 9
```

- i=0, nums[0]=2, complement=7, not in map, store {2:0}
- i=1, nums[1]=7, complement=2, found in map, return [0,1]

## ⏱️ Complexity Analysis
- Time Complexity: O(n)
- Space Complexity: O(n)