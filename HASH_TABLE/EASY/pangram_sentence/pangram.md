# Problem: Check if a String is a Pangram

---

## Problem Statement

A pangram is a sentence that contains all 26 letters of the English alphabet at least once. Write a program to check if a given string is a pangram.

---

## Intuition

A pangram must contain every letter from 'a' to 'z' (case-insensitive). We need to track which letters appear in the string and verify that all 26 letters are present.

---

## Brute Force Approach

### Explanation

For each letter from 'a' to 'z', search through the entire string to check if that letter exists (case-insensitive). If any letter is missing, return false. If all letters are found, return true.

### Algorithm

1. Iterate through each character from 'a' to 'z'
2. For each character, search through the entire string to find a match
3. If a match is found, move to the next letter; if not found, return false
4. If all 26 letters are found, return true

### Complexity

- Time: O(26 × n) = O(n), where n is the length of the string
- Space: O(1) - constant space

---

## Optimization Reasoning

The brute force approach searches for each letter individually through the string. We can optimize by doing a single pass through the string and tracking which letters we've seen, then checking if all 26 letters were encountered.

---

## Key Observation

A pangram must have exactly 26 unique alphabetic characters (when converted to lowercase). If we track the count of unique letters found, we can determine if it's a pangram in just one pass.

---

## Optimized Approach

Use a hash map (unordered_map) to store which letters we've seen. In a single pass through the string, mark each letter as seen. At the end, check if the hash map contains all 26 letters.

---

## Algorithm

1. Create an unordered_map to store seen letters
2. Iterate through each character in the string
3. If the character is alphabetic, convert to lowercase and mark it as seen in the map
4. After iteration, check if the map size equals 26
5. Return true if all 26 letters are present, false otherwise

---

## 🧪 Dry Run

### Example Input:

`"The quick brown fox jumps over the lazy dog"`

**Step-by-step execution:**

1. Initialize empty unordered_map `seen`
2. Iterate through each character:
   - 'T' → seen['t'] = true
   - 'h' → seen['h'] = true
   - 'e' → seen['e'] = true
   - ... continue for all characters
3. After processing all characters, `seen.size()` will be 26
4. Return `true` - it's a pangram

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n), where n is the length of the string (single pass through the string)
- Space Complexity: O(1) or O(26) = O(1), since the hash map stores at most 26 letters (constant space)
