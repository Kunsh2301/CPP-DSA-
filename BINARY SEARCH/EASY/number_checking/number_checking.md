# Number Checking

## Problem Statement

Given an array of integers and a target value, determine whether the target element is present in the array or not.

Since Binary Search is used, the array must be sorted before searching. The program should return `TRUE` if the element exists, otherwise `FALSE`.

## Intuition

### Initial Thought (Brute Force)

The most straightforward way is to traverse the array linearly and compare each element with the target.

- **Time Complexity**: O(n)
- **Notes**: Works fine for small inputs, but inefficient for large datasets.

### Why Brute Force Is Not Optimal?

When the input size grows, checking every element becomes slow and unnecessary.

### Key Observation

If the array is sorted, we can eliminate half of the search space at every step. This observation naturally leads to Binary Search, which is significantly faster.

## Approach

1. Take input for array size, target, and elements.
2. Sort the array (mandatory for binary search).
3. Apply Binary Search:
   - Maintain two pointers: `low` and `high`.
   - Calculate the middle element.
   - Compare middle with target.
   - Reduce the search space accordingly.
4. Return result based on whether the target is found.

## Algorithm (Step-by-Step)

1. Read integer `n` (size of array) and `target`.
2. Read `n` elements into a vector.
3. Sort the array in ascending order.
4. Initialize: `low = 0`, `high = n - 1`.
5. While `low <= high`:
   - Compute `mid = low + (high - low) / 2`.
   - If `arr[mid] == target`, return `true`.
   - If `arr[mid] > target`, move left → `high = mid - 1`.
   - Else move right → `low = mid + 1`.
6. If loop ends, return `false`.

## Dry Run

### Example Input

```
Array size: 5
Target: 7
Array elements: 1 3 5 7 9
```

### Sorted Array

```
[1, 3, 5, 7, 9]
```

### Execution

| Step | low | high | mid | arr[mid] | Action       |
| ---- | --- | ---- | --- | -------- | ------------ |
| 1    | 0   | 4    | 2   | 5        | Move right   |
| 2    | 3   | 4    | 3   | 7        | Target found |

### Output

```
TRUE
```

## Complexity Analysis

**Note**: Complexity is calculated excluding input/output and the main() function.

- **Time Complexity**: O(log n)
- **Space Complexity**: O(1)
