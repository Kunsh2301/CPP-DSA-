Problem Name - peak_index

Problem Statement :
Given an array of integers, find the peak index.
A peak index is defined as the position i such that:
* The elements before index i are strictly increasing
* The elements after index i are strictly decreasing
The array is guaranteed to have exactly one peak element.
If the array size is less than 3, return -1.

Intuition :
Initial Thought (Brute Force)
A simple approach is to iterate through the array and find an index i where:
arr[i] > arr[i - 1]
arr[i] > arr[i + 1]

Time Complexity: O(n)
Works fine for small inputs
Inefficient when input size grows

Why Brute Force Is Not Optimal ?
* The array follows a mountain-like structure (increasing then decreasing)
* We don’t need to check every element
* We can eliminate half of the search space at every step
This observation leads to an optimized Binary Search approach.

Key Observation : 
* If arr[mid] < arr[mid + 1], we are in the increasing part, so the peak lies on the right
* Otherwise, we are in the decreasing part, so the peak lies on the left (including mid)

Approach :
1. Take input for array size and elements
2. If size < 3, return -1
3. Apply Binary Search:
* Maintain low and high pointers
* Compare arr[mid] with arr[mid + 1]
* Adjust search space accordingly
4. When low == high, that index is the peak

Algorithm (Step-by-Step)
1. Read integer n (size of array)
2. Read n elements into a vector
3. If n < 3, return -1
4. Initialize:
low = 0 , high = n - 1
5. While low < high:
* Compute   
mid = low + (high - low) / 2
* If arr[mid] < arr[mid + 1]
→ move right → low = mid + 1
* Else
→ move left → high = mid
6. Return low (or high) as the peak index

Dry Run (Very Important)
Example Input:
Array size: 7
Array elements: 1 3 7 9 6 4 2

Sorted Array:
[1, 3, 5, 7, 9]

Execution:
Step	low	high	mid	arr[mid]	arr[mid+1]	Action
1	    0	 6	    3	  9	           6	    Move left
2	    0	 3	    1	  3	           7	    Move right
3	    2	 3	    2	  7	           9	    Move right
4	    3	 3	    —	  —	           —	    Stop

Output: 3

Note: Complexity is calculated excluding input/output and the main() function.
TIME COMPLEXITY- O(log(n))
Space complexity- O(1)