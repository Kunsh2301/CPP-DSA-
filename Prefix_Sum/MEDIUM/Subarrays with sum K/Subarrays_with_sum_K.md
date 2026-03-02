# Problem: Count subarrays with sum equal to K

---

## Problem Statement

Given an unsorted array of integers `arr` and an integer `k`, determine the number of contiguous subarrays whose elements sum exactly to `k`.

Input format:
- First line: integer `n` (size of array)
- Second line: `n` integers (array elements)
- Third line: integer `k` (target sum)

---

## Intuition

A naive way is to consider all possible subarrays and compute their sum. However, this leads to O(n^2) time. A better idea is to leverage prefix sums: the sum of a subarray from index `i` to `j` can be expressed as `prefix[j] - prefix[i-1]` (with `prefix[-1]` considered 0).

---

## Brute Force Approach

1. Initialize `count = 0`.
2. Use two nested loops: outer index `i` from 0 to `n-1`, inner index `j` from `i` to `n-1`.
3. Compute the sum of `arr[i..j]` directly (or using a prefix array to speed summation to O(1)).
4. If the sum equals `k`, increment `count`.
5. After both loops complete, `count` holds the number of valid subarrays.

### Complexity of Brute Force
- Time: O(n^2) for iterating over all subarrays, plus O(n) if summing naively (resulting in O(n^3) total) or O(1) per subarray with prefix sums.
- Space: O(n) if using a prefix array, otherwise O(1).

---

## Optimization Reasoning

By keeping track of how many times each prefix sum has appeared so far, we can in a single pass count the number of earlier prefixes such that `current_prefix - earlier_prefix == k`. This converts the problem to O(n) time with a hash map for prefix frequency.

---

## Key Observation

If `prefix[i]` is the sum of elements up to index `i`, then any subarray ending at `i` with sum `k` corresponds to a previous prefix value of `prefix[i] - k` (including zero when the subarray starts at index 0).

---

## Optimized Approach

1. Iterate through the array while maintaining the running prefix sum.
2. Use an `unordered_map` to count how many times each prefix sum has been seen.
3. For each new prefix sum, if `(prefix - k)` exists in the map, add its count to the answer.
4. Also increment the count of the current prefix in the map.
5. Handle the case when a prefix itself equals `k` separately by initially adding to the count or by initializing the map with `{0:1}`.

---

## Algorithm
1. Read integer `n` and array `arr` of length `n`.
2. Read target `k`.
3. Initialize a map `freq` with `freq[0] = 1` to account for subarrays starting at index 0.
4. Initialize `prefix = 0` and `count = 0`.
5. For each element `x` in `arr`:
   - `prefix += x`.
   - If `(prefix - k)` exists in `freq`, `count += freq[prefix - k]`.
   - Increment `freq[prefix]`.
6. Print or return `count`.

---

## 🧪 Dry Run
### Example Input:

```
3
1 1 1
2
```

Execution steps:
- Start with `freq = {0:1}`, `prefix=0`, `count=0`.
- Read 1: `prefix=1`; `prefix-k = -1` not in map; add `freq[1]=1`.
- Read 1: `prefix=2`; `prefix-k = 0` exists with count 1 → `count = 1`; add `freq[2]=1`.
- Read 1: `prefix=3`; `prefix-k = 1` exists with count 1 → `count = 2`; add `freq[3]=1`.

Output:

```
2
```

Two subarrays meet the condition: `[1,1]` starting at index 0 and `[1,1]` starting at index 1.

---

## ⏱️ Complexity Analysis
- Time Complexity: O(n)
- Space Complexity: O(n) extra space for the hash map

---

## Compile & Run (example)

```bash
# input (example):
3
1 1 1
2
```

The program will output `2` for the above input.
