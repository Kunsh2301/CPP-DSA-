# Problem: Find Second Largest Element in Array

---

## Problem Statement

Given an array of integers, find the second largest element. If the second largest element does not exist (e.g., all elements are the same, or array has less than 2 distinct elements), return -1.

---

## Intuition

The key insight is that we need to find the element that is smaller than the maximum but larger than all other elements. We can either sort the array and search backwards for a different element, or traverse the array once while keeping track of the largest and second-largest elements.

---

## Brute Force Approach

### Explanation

Sort the entire array in ascending order. Then iterate from the second-to-last element backwards to find the first element that is different from the largest element. This ensures we get the second largest distinct element.

### Algorithm

1. Sort the array in ascending order
2. Start from index `n-2` (second-to-last element)
3. Iterate backwards and return the first element that is not equal to the largest element (at index `n-1`)
4. If no such element exists, return -1

### Complexity

- Time: O(n log n) - dominated by sorting
- Space: O(1) - no extra space (in-place sort)

---

## Optimization Reasoning

The brute force approach sorts the entire array, which is inefficient. We can solve this problem in a single pass by maintaining two variables: the largest and second-largest elements. This eliminates the need for sorting and reduces the time complexity significantly.

---

## Key Observation

During a single traversal of the array:

- When we find an element larger than the current largest, the current largest becomes the second-largest, and this element becomes the new largest
- When we find an element that is between the second-largest and largest, it becomes the new second-largest
- We need to ensure we're comparing distinct elements

---

## Optimized Approach

Maintain two variables `firstlargest` and `secondlargest` initialized to `INT_MIN`. Traverse the array once:

- If current element is greater than `firstlargest`, update `secondlargest` to `firstlargest` and `firstlargest` to current element
- Else if current element is less than `firstlargest` and greater than `secondlargest`, update `secondlargest` to current element
- Return `secondlargest` if it's not `INT_MIN`, otherwise return -1

---

## Algorithm

1. Initialize `firstlargest = INT_MIN` and `secondlargest = INT_MIN`
2. Iterate through each element in the array
3. If element > `firstlargest`: set `secondlargest = firstlargest`, then `firstlargest = element`
4. Else if `firstlargest > element > secondlargest`: set `secondlargest = element`
5. After loop, return `secondlargest` if it's not `INT_MIN`, else return -1

---

## 🧪 Dry Run

### Example Input:

```
Array: [5, 3, 8, 1, 9]
n = 5
```

### Step-by-Step Execution:

**Initial State:**
- `firstlargest = INT_MIN` (representing negative infinity)
- `secondlargest = INT_MIN` (representing negative infinity)

---

**Step 1: i = 0, arr[0] = 5**
- Condition: `5 > INT_MIN` ✓
- Action: Update `secondlargest = INT_MIN`, then `firstlargest = 5`
- State: `firstlargest = 5, secondlargest = INT_MIN`

---

**Step 2: i = 1, arr[1] = 3**
- Condition: `3 < 5` AND `3 > INT_MIN` ✓
- Action: Update `secondlargest = 3`
- State: `firstlargest = 5, secondlargest = 3`

---

**Step 3: i = 2, arr[2] = 8**
- Condition: `8 > 5` ✓
- Action: Update `secondlargest = 5`, then `firstlargest = 8`
- State: `firstlargest = 8, secondlargest = 5`

---

**Step 4: i = 3, arr[3] = 1**
- Condition: `1 < 8` AND `1 < 5` ✗
- Action: No update (1 is not between secondlargest and firstlargest)
- State: `firstlargest = 8, secondlargest = 5`

---

**Step 5: i = 4, arr[4] = 9**
- Condition: `9 > 8` ✓
- Action: Update `secondlargest = 8`, then `firstlargest = 9`
- State: `firstlargest = 9, secondlargest = 8`

---

### Final Result:

Since `secondlargest = 8` (not INT_MIN), return **8**

**Second Largest Element = 8** ✅

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n) - single pass through the array
- Space Complexity: O(1) - only using two integer variables
