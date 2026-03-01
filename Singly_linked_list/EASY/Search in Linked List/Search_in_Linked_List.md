# Problem: Search in Linked List

---

## Problem Statement

Given a singly linked list and an integer `key`, determine whether the key exists in the list. The function should return `true` if the key is found and `false` otherwise. The list is represented by its head pointer.

---

## Intuition

A linked list is a linear collection of nodes where each node points to the next. To verify whether a particular value is present, we can traverse the list from the head and compare each node's data with the target key. If we find a match, the search succeeds; if we reach the end of the list without finding the key, the search fails.

---

## Optimization Reasoning

The simple traversal described above is already optimal for this problem. There is no better way to search an unsorted singly linked list without additional data structures or preprocessing. Each node must be inspected at most once. The solution uses constant extra space and performs in linear time relative to the number of nodes.

---

## Key Observation

- A linked list does not support random access, so we cannot jump to arbitrary positions. We must move step by step from the head.
- If the key exists, we discover it during the forward traversal; otherwise, the traversal ends at a `nullptr`.

---

## Optimized Approach

Use a single pointer to iterate through the list:
1. Start from the head node.
2. For each node, compare the node's data with the key.
3. If they match, return `true` immediately.
4. Move to the next node and repeat until the end of the list.
5. If the loop completes without finding the key, return `false`.

---

## Algorithm
1. Initialize a temporary pointer `current` to the head of the list.
2. While `current` is not `NULL`:
   - If `current->data == key`, return `true`.
   - Otherwise, set `current = current->next`.
3. Return `false` after exiting the loop.

---

## 🧪 Dry Run
### Example Input:
List: 10 → 20 → 30 → 40
Key: 30

Traversal steps:
1. Compare 10 with 30 → not equal, move to next node.
2. Compare 20 with 30 → not equal, move to next node.
3. Compare 30 with 30 → equal, return `true`.

---

## ⏱️ Complexity Analysis
- Time Complexity: O(N), where N is the number of nodes in the linked list. In the worst case the algorithm visits each node once.
- Space Complexity: O(1), only a pointer variable is used regardless of list size.
