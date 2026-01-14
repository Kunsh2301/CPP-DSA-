# Problem: Move Zeroes to End

---

## Problem Statement

Given an integer `n` and an array of `n` integers, move all the zeroes to the end of the array while maintaining the relative order of the non-zero elements. The operation should be done in-place if possible, but a brute force version using extra space is also provided.

Input format:
- First line: integer `n` (size of array)
- Second line: `n` integers (array elements)

---

## Intuition

The problem requires rearranging the array so that all non-zero elements appear first, followed by all zeroes, without changing the order of non-zero elements. This resembles partitioning the array into two groups: non-zeroes and zeroes.

---

## Brute Force Approach
### Explanation
Create a new vector to store the result. First, iterate through the array and add all non-zero elements to the result vector. Then, iterate again and add all zero elements to the result vector. This preserves the order of non-zeroes and moves zeroes to the end, but uses extra space.

### Algorithm
1. Read integer `n` and the array `arr`.
2. Create a new vector `result`.
3. Iterate through `arr`: if element is non-zero, push to `result`.
4. Iterate through `arr` again: if element is zero, push to `result`.
5. Output the `result` vector.

### Complexity
- Time: O(n)
- Space: O(n)

---

## Optimization Reasoning
The brute force approach uses O(n) extra space, which is inefficient for large arrays. We can optimize to use O(1) extra space by modifying the array in-place using two pointers.

---

## Key Observation
We can use a pointer to track the position where the next non-zero element should be placed. After placing all non-zeroes, fill the remaining positions with zeroes.

---

## Optimized Approach
Use two pointers: one (`j`) to track the position for the next non-zero element. Iterate through the array; when a non-zero is found, swap or assign it to the position at `j` and increment `j`. After the loop, set all elements from `j` to the end as zero. This is done in-place.

---

## Algorithm
1. Read integer `n` and the array `arr`.
2. Initialize `j = 0`.
3. For each element in `arr`:
   - If `arr[i] != 0`, set `arr[j] = arr[i]` and increment `j`.
4. For `k` from `j` to `n-1`, set `arr[k] = 0`.
5. Output the modified `arr`.

---

## 🧪 Dry Run
### Example Input:
5
0 1 0 3 12

Execution steps (optimized):
- `j = 0`, `arr = [0, 1, 0, 3, 12]`
- i=0: 0 == 0, skip
- i=1: 1 != 0, arr[0] = 1, j=1
- i=2: 0 == 0, skip
- i=3: 3 != 0, arr[1] = 3, j=2
- i=4: 12 != 0, arr[2] = 12, j=3
- Fill from j=3 to end with 0: arr[3]=0, arr[4]=0
- Final arr: [1, 3, 12, 0, 0]

Output:
1 3 12 0 0

---

## ⏱️ Complexity Analysis
- Time Complexity: O(n)
- Space Complexity: O(1) extra space (optimized)