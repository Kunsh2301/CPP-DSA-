# Trapping Rain Water

---

## Problem Statement

Given `n` non-negative integers representing an elevation map where the width of each bar is 1, compute how much water can be trapped after raining.

---

## Intuition

Imagine pouring water over the elevation bars. Water accumulates between the bars where there are dips. The amount trapped at any index depends on the maximum height of bars to its left and right. If either side is low, it limits the water that can be held.

---

## Brute Force Approach

### Explanation

For each bar, find the highest bar to its left and the highest bar to its right. The water that can be trapped on top of the current bar is the minimum of these two maxima minus the height of the current bar.

### Algorithm

1. Initialize `ans = 0` and `n = height.size()`.
2. For each index `i` from `0` to `n-1`:
   - Compute `leftmax` by scanning from `i` down to `0`.
   - Compute `rightmax` by scanning from `i` up to `n-1`.
   - Add `min(leftmax, rightmax) - height[i]` to `ans`.
3. Return `ans`.

### Complexity

- Time: O(n²) due to nested scans for left and right maximums.
- Space: O(1) (constant extra space).

---

## Optimization Reasoning

The brute-force scanning repeats work. We can precompute the maximums seen from the left and right for each position, or even avoid extra arrays by using two pointers. Precomputation reduces the repeated scanning and gives linear time solutions. With two pointers we achieve constant space.

---

## Key Observation

The water trapped at position `i` is determined by the shorter of the tallest bar on the left and the tallest bar on the right. If we already know these values for every index, we can compute the trapped water in one pass. Further, we can maintain these maxima on the fly using two pointers moving inward from both ends.

---

## Optimized Approach

Use two pointers `i` and `j` at the start and end of the elevation array. Maintain `maxleft` and `maxright` as the highest bars seen so far from each side. Move the pointer pointing to the lower current maximum inward, calculate trapped water using the known maximum, and update corresponding maxima.

---

## Algorithm

1. Set `i = 0`, `j = n-1`, `maxleft = 0`, `maxright = 0`, and `ans = 0`.
2. While `i < j`:
   - Update `maxleft = max(maxleft, height[i])` and `maxright = max(maxright, height[j])`.
   - If `maxright < maxleft`:
     - Add `maxright - height[j]` to `ans`.
     - Decrement `j`.
   - Else:
     - Add `maxleft - height[i]` to `ans`.
     - Increment `i`.
3. Return `ans`.

---

## 🧪 Dry Run

### Example Input:

```
height = [0,1,0,2,1,0,1,3,2,1,2,1]
```

Processing steps:

1. Start `i=0`, `j=11`, `maxleft=0`, `maxright=0`.
2. Update maxima, move pointers inward while computing trapped water. Eventually `ans` accumulates water units at each index. For this example, the result is `6`.

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n) since each element is visited at most once by the two pointers.
- Space Complexity: O(1) using only a few variables.

---

## Better Approach (Precomputed Arrays)

Although the two-pointer method is optimal in space, the precomputed-array approach is easier to understand and still linear time.

### Explanation

Create two arrays `leftmax` and `rightmax` of size `n`. Fill `leftmax[i]` with the maximum height seen from the start to index `i`. Fill `rightmax[i]` with the maximum height seen from the end to index `i`. Then compute trapped water for each index using these arrays.

### Algorithm

1. Initialize `leftmax[0] = height[0]` and `rightmax[n-1] = height[n-1]`.
2. Fill the rest of `leftmax` by iterating forward.
3. Fill the rest of `rightmax` by iterating backward.
4. Sum `min(leftmax[i], rightmax[i]) - height[i]` for all `i`.

### Complexity

- Time: O(n)
- Space: O(n) additional arrays.

This approach is a trade‑off between clarity and space efficiency.