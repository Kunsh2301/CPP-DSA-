# Problem: Find the single element in an array where every other element appears twice

---

## Problem Statement

Given an integer `n` and an array of `n` integers where every element appears exactly twice except for one element which appears only once, find and print that single element.

Input format:
- First line: integer `n` (size of array)
- Next line(s): `n` integers (array elements)

---

## Intuition

Using the XOR operation: `a ^ a = 0` and `a ^ 0 = a`. XORing all numbers cancels out the pairs and leaves the unique element.

---

## Optimization Reasoning

Counting or sorting is unnecessary. XOR is associative and commutative, so XOR-ing all elements yields the unique element in a single pass using constant extra space.

---

## Key Observation

Pairs of equal numbers cancel out under XOR, so only the unpaired number remains after XORing the entire array.

---

## Optimized Approach

Iterate through the array once, maintaining a running XOR of all elements. The final XOR value is the single element.

---

## Algorithm
1. Read integer `n` and the array `arr`.
2. Initialize `res = 0`.
3. For each element `x` in `arr`, set `res = res ^ x`.
4. Print `res`.

---

## 🧪 Dry Run
### Example Input:

```
7
2 3 2 4 4 5 3
```

Execution steps:
- `res = 0`
- XOR with 2 → `res = 2`
- XOR with 3 → `res = 1`
- XOR with 2 → `res = 3`
- XOR with 4 → `res = 7`
- XOR with 4 → `res = 3`
- XOR with 5 → `res = 6`
- XOR with 3 → `res = 5`

Output:

```
5
```

---

## ⏱️ Complexity Analysis
- Time Complexity: O(n)
- Space Complexity: O(1) extra space

---

## Compile & Run (example)

# input (example):
7
2 3 2 4 4 5 3
```

The program will print `5` for the above input.
