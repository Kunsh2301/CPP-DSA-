# Problem: Check if an array is a palindrome

---

## Problem Statement

Given an integer `n` and an array of `n` integers, determine whether the array reads the same forwards and backwards. Print `Palindrome` if it does, otherwise print `Not a palindrome`.

Input format:
- First line: integer `n` (size of array)
- Second line: `n` integers (array elements)

---

## Intuition

An array is a palindrome if for every index `i` (0-based) the element at `i` equals the element at `n-1-i`. We only need to check pairs of elements from the two ends moving toward the center.

---

## Optimization Reasoning

use two pointers from both ends and compare in-place, stopping at the middle.

---

## Key Observation

Only pairs of elements symmetric around the center matter; once all such pairs match, the whole array is a palindrome.

---

## Optimized Approach

Use two pointers `i = 0` and `j = n-1`. While `i < j`, compare `arr[i]` and `arr[j]`. If any pair differs, the array is not a palindrome. Otherwise advance `i++` and `j--` until they meet.

---

## Algorithm
1. Read integer `n` and array `arr` of length `n`.
2. Initialize `i = 0`, `j = n - 1`.
3. While `i < j`: if `arr[i] != arr[j]` print `Not a palindrome` and stop; else `i++`, `j--`.
4. If loop finishes, print `Palindrome`.

---

## 🧪 Dry Run
### Example Input:

```
5
1 2 3 2 1
```

Execution steps:
- `i=0, j=4`: compare `1` and `1` → match
- `i=1, j=3`: compare `2` and `2` → match
- `i=2, j=2`: stop (center reached) → all pairs matched

Output:

```
Palindrome
```

---

## ⏱️ Complexity Analysis
- Time Complexity: O(n)
- Space Complexity: O(1) extra space

---

## Compile & Run (example)

# input (example):
5
1 2 3 2 1
```
The program will print `Palindrome` for the above input.
