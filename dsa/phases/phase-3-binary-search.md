# Binary Search

## 1. Problem Statement

Given a sorted array and a target value, return the index of the target if it exists. Otherwise return `-1`.

---

## 2. Constraints

- `1 <= nums.length <= 10^5`
- `nums` is sorted in non-decreasing order
- `-10^9 <= nums[i], target <= 10^9`

---

## 3. Intuition

If the array is sorted, we do not need to scan every element.

We can inspect the middle element and discard half of the search space each time.

That is the core advantage of binary search: eliminate half the candidates per step.

---

## 4. Pattern Recognition

- Pattern: Binary Search

This pattern fits because the array order gives us a monotonic structure.

Each comparison tells us whether the target must be on the left half or the right half.

---

## 5. Brute Force

### Algorithm

Check every element from left to right.

### Dry explanation

Return the first index where `nums[i] == target`, otherwise return `-1`.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 6. Better Solution

Use recursion or iteration to implement binary search on the sorted array.

### Why it is better

It removes half of the search range at each step instead of one element at a time.

### Complexity

- Time: `O(log n)`
- Space: `O(log n)` for recursion, `O(1)` for iteration

---

## 7. Optimal Solution

Use an iterative binary search loop.

### Observation

If `nums[mid] == target`, we are done.

If `nums[mid] < target`, the target can only be in the right half.

If `nums[mid] > target`, the target can only be in the left half.

### Algorithm

1. Set `left = 0`, `right = n - 1`
2. While `left <= right`:
   - compute `mid`
   - compare `nums[mid]` with `target`
   - shrink the search range accordingly
3. Return `-1` if the target is not found

### Why it works

The array is sorted, so the half that cannot contain the target is eliminated on every step.

---

## 8. Dry Run

Example: `nums = [1, 3, 5, 7, 9]`, `target = 7`

- `left = 0`, `right = 4`
- `mid = 2`, `nums[mid] = 5`
- `5 < 7`, so search right half -> `left = 3`
- `left = 3`, `right = 4`
- `mid = 3`, `nums[mid] = 7`
- Found target at index `3`

---

## 9. C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
```

---

## 10. Time Complexity

- Best Case: `O(1)` if the target is at the middle initially
- Average Case: `O(log n)`
- Worst Case: `O(log n)`

---

## 11. Space Complexity

- Auxiliary space: `O(1)` for the iterative version

---

## 12. Common Mistakes

- Using `mid = (left + right) / 2` without considering overflow in general code
- Forgetting the loop condition should be `left <= right`
- Updating the wrong bound
- Returning `-1` too early
- Applying binary search to an unsorted array

---

## 13. Edge Cases

- Empty array
- Single element
- Target smaller than all elements
- Target larger than all elements
- Target appears multiple times
- Already sorted ascending input
- Reverse sorted input is invalid for standard binary search

---

## 14. Interview Follow-ups

- Can you return the first or last occurrence?
- Can you do binary search on answers?
- Can you search in a rotated sorted array?
- Can you implement the recursive version?

---

## 15. Similar Problems

- `35. Search Insert Position` - Easy - Binary search variant
- `34. Find First and Last Position of Element in Sorted Array` - Medium - Boundary binary search
- `153. Find Minimum in Rotated Sorted Array` - Medium - Rotated array binary search
- `162. Find Peak Element` - Medium - Binary search on local conditions
- `278. First Bad Version` - Easy - Binary search on answer
- `74. Search a 2D Matrix` - Medium - Binary search
- `852. Peak Index in a Mountain Array` - Easy - Binary search on monotonic shape

---

## 16. Key Takeaways

- Pattern: Binary Search
- Important trick: cut the search space in half every step
- Complexity: `O(log n)` time, `O(1)` space
- Interview tip: always state the monotonic property that makes binary search valid
