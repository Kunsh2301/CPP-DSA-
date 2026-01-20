# Problem: Farthest Element Smaller Than Current

---

## Problem Statement

Given an array of integers, for every element in the array, find the **index of the farthest element to the right** which is **smaller than the current element**. If no such element exists, return -1.

**Note:** 0-based indexing is used.

---

## Intuition

For each element at position `i`, we need to find an element at position `j` (where `j > i`) such that `arr[j] < arr[i]`, and `j` should be as far from `i` as possible (maximum `j`).

The key insight is that if we know the minimum element from position `j` onwards for all `j`, we can use binary search to find the farthest position where the minimum is smaller than the current element.

---

## Brute Force Approach

### Explanation

For each element at position `i`, iterate backwards from the end of the array until we find an element smaller than `arr[i]`. Return the first such index found (which is the farthest one since we're going right to left).

### Algorithm
1. For each element at index `i` in the array
2. Iterate from the end of the array (index `n-1`) backwards to `i+1`
3. When we find an element `arr[j]` such that `arr[i] > arr[j]`, store index `j` and break
4. If no such element is found, store -1

### Complexity
- **Time:** O(n²) - For each element, we potentially scan the entire array to its right
- **Space:** O(n) - For storing the result array

---

## Optimization Reasoning

The brute force approach scans from right to left for each element. We can optimize this by:
1. Pre-computing the minimum value from each position to the end
2. Using binary search to find the farthest position where the minimum is still smaller than the current element

This leverages the Binary Search tree concept to achieve logarithmic search time.

---

## Key Observation

If we maintain an array where `minright[i]` represents the **minimum element from index `i` to the end**, then:
- For element at position `i`, we need to find the largest index `j > i` where `minright[j] < arr[i]`
- Since `minright` is monotonic (decreasing or staying same as we move right), we can use binary search

---

## Optimized Approach

1. **Pre-process:** Create an array `minright[]` where `minright[i]` stores the minimum element from index `i` to the end
2. **Binary Search:** For each element at index `i`, use binary search on the range `[i+1, n-1]` to find the farthest index where `minright[med] < arr[i]`

---

## Algorithm
1. Create `minright[]` array by iterating from right to left and storing the minimum value from current position onwards
2. For each element at index `i`:
   - Initialize binary search with `low = i+1` and `high = n-1`
   - While `low <= high`:
     - Calculate `mid = low + (high - low) / 2`
     - If `arr[i] > minright[mid]`, update result to `mid` and move `low = mid + 1` (search right)
     - Else move `high = mid - 1` (search left)
3. Store the result index for each element

---

## 🧪 Dry Run

### Example Input:
```
Array: [1, 5, 0, 3, 4, 5]
```

**Step 1: Build minright array**
```
minright[5] = 5
minright[4] = min(4, minright[5]) = 4
minright[3] = min(3, minright[4]) = 3
minright[2] = min(0, minright[3]) = 0
minright[1] = min(5, minright[2]) = 0
minright[0] = min(1, minright[1]) = 0

minright = [0, 0, 0, 3, 4, 5]
```

**Step 2: Binary search for each element**
- `arr[0] = 1`: Search in range [1, 5] for index where minright < 1
  - med=3: minright[3]=3, 1>3? No → high=2
  - med=1: minright[1]=0, 1>0? Yes → res=1, low=2
  - low > high → Result: 1
  
- `arr[1] = 5`: Search in range [2, 5] for index where minright < 5
  - med=3: minright[3]=3, 5>3? Yes → res=3, low=4
  - med=4: minright[4]=4, 5>4? Yes → res=4, low=5
  - med=5: minright[5]=5, 5>5? No → high=4
  - low > high → Result: 4

- `arr[2] = 0`: Search in range [3, 5] for index where minright < 0
  - Result: -1 (no element smaller than 0)

- `arr[3] = 3`: Search in range [4, 5] for index where minright < 3
  - med=4: minright[4]=4, 3>4? No → high=3
  - low > high → Result: -1

- `arr[4] = 4`: Search in range [5, 5] for index where minright < 4
  - med=5: minright[5]=5, 4>5? No → high=4
  - low > high → Result: -1

- `arr[5] = 5`: No elements to the right → Result: -1

**Output:** `[1, 4, -1, -1, -1, -1]`

---

## ⏱️ Complexity Analysis
- **Time Complexity:** O(n log n)
  - Pre-processing minright: O(n)
  - Binary search for each of n elements: O(n × log n)
  
- **Space Complexity:** O(n)
  - `minright[]` array: O(n)
  - Result array: O(n)
