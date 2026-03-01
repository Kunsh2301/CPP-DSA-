# Problem: Reverse a Singly Linked List

---

## Problem Statement

Given the head of a singly linked list, reverse the list and return the new head pointer. For example, if the original list is

```
1 -> 2 -> 3 -> 4 -> 5
```

the reversed list should be

```
5 -> 4 -> 3 -> 2 -> 1
```

---

## Intuition

Reversing a linked list means changing the `next` pointers of each node so that they point to the previous node instead of the next. By iterating through the list and adjusting pointers one by one while keeping track of the preceding node, the direction of the list can be flipped in-place.

---

## Optimization Reasoning

The in-place reversal does not require any extra data structures; only a few pointers are used for traversal and reconnection. This results in constant auxiliary space and only requires a single pass through the list, giving linear time complexity which is optimal for this operation.

---

## Key Observation

- At each step, the current node's `next` pointer must be redirected to the previous node.
- Before changing the connection, the next node must be preserved so the traversal can continue.
- After the loop, the previous pointer holds the new head of the reversed list.

---

## Optimized Approach

Maintain three pointers:

1. `prev` – initially `NULL`, will eventually point to the new head.
2. `curr` – starts at the original head and moves forward.
3. `next` – temporarily stores `curr->next` before breaking the link.

Loop until `curr` becomes `NULL`, repeatedly reversing the `next` link and advancing all pointers one node.

---

## Algorithm

1. Initialize `prev = NULL` and `curr = head`.
2. While `curr` is not `NULL`:
   - Set `next = curr->next` to save the remainder of the list.
   - Redirect `curr->next` to `prev`.
   - Move `prev` to `curr` and `curr` to `next`.
3. After the loop, `prev` is the head of the reversed list; return `prev`.

---

## 🧪 Dry Run

### Example Input:

List: `1 -> 2 -> 3 -> 4 -> 5`

Steps:

1. `prev = NULL`, `curr = 1`. Save `next = 2`. Set `1->next = NULL`. Advance `prev = 1`, `curr = 2`.
2. Save `next = 3`. Set `2->next = 1`. Advance `prev = 2`, `curr = 3`.
3. Save `next = 4`. Set `3->next = 2`. Advance `prev = 3`, `curr = 4`.
4. Save `next = 5`. Set `4->next = 3`. Advance `prev = 4`, `curr = 5`.
5. Save `next = NULL`. Set `5->next = 4`. Advance `prev = 5`, `curr = NULL`.

Return `prev`, which points to `5 -> 4 -> 3 -> 2 -> 1`.

---

## ⏱️ Complexity Analysis

- Time Complexity: O(N) – one traversal through the list of N nodes.
- Space Complexity: O(1) – only a constant number of pointer variables used.
