# Search in Rotated Sorted Array

## 1. Problem Statement

Given a sorted array that has been rotated at some pivot and a target value, return the index of the target if it exists, otherwise return `-1`.

---

## 2. Constraints

- `1 <= nums.length <= 10^5`
- `nums` contains unique values
- The array was originally sorted in ascending order and then rotated
- `-10^9 <= nums[i], target <= 10^9`

---

## 3. Intuition

A rotated sorted array still has structure.

At least one half of the array is always sorted.

If we can identify the sorted half, we can decide whether the target lies in that half or the other half, then continue searching only where it can still exist.

---

## 4. Pattern Recognition

- Pattern: Modified Binary Search

This fits binary search because we still eliminate half of the array each step.

The difference is that the array is not globally sorted, so we first identify which half is sorted.

---

## 5. Brute Force

### Algorithm

Scan the array linearly and compare each element with the target.

### Dry explanation

This works because any array can be searched by direct traversal.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 6. Better Solution

Find the pivot first, then do binary search in the correct half.

### Why it is better

You still use binary search, but in two stages.

### Complexity

- Time: `O(log n)`
- Space: `O(1)`

---

## 7. Optimal Solution

Use one modified binary search loop.

### Observation

For any `mid`, either:

- the left half `nums[left..mid]` is sorted, or
- the right half `nums[mid..right]` is sorted

### Algorithm

1. Initialize `left` and `right`
2. Compute `mid`
3. If `nums[mid] == target`, return `mid`
4. Check which half is sorted
5. Determine whether the target lies inside the sorted half
6. Shrink the search range accordingly

### Why it works

Even though the full array is rotated, one side remains sorted, so the sorted half gives a valid comparison rule.

---

## 8. Dry Run

Example: `nums = [4, 5, 6, 7, 0, 1, 2]`, `target = 0`

- `left = 0`, `right = 6`
- `mid = 3`, `nums[mid] = 7`
- Left half `[4, 5, 6, 7]` is sorted
- Target `0` is not in `[4, 7]`
- Search right half -> `left = 4`
- `mid = 5`, `nums[mid] = 1`
- Right half `[0, 1, 2]` is sorted
- Target `0` is in `[0, 1]`
- Search left side of that half -> `right = 4`
- `mid = 4`, `nums[mid] = 0`
- Found target at index `4`

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

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
```

---

## 10. Time Complexity

- Best Case: `O(1)` if the target is at mid immediately
- Average Case: `O(log n)`
- Worst Case: `O(log n)`

---

## 11. Space Complexity

- Auxiliary space: `O(1)`

---

## 12. Common Mistakes

- Not identifying the sorted half correctly
- Mixing up the range checks for the target
- Forgetting unique values are assumed
- Applying normal binary search directly

---

## 13. Edge Cases

- Single element array
- Target is the pivot element
- Target is not present
- Array rotated by 1 position
- Array not rotated at all
- Array of size 2

---

## 14. Interview Follow-ups

- What changes if duplicates are allowed?
- Can you find the minimum element first?
- Can you search the rotated array in `O(log n)`?
- Can you adapt the same logic to rotated matrices?

---

## 15. Similar Problems

- `81. Search in Rotated Sorted Array II` - Medium - Modified binary search with duplicates
- `153. Find Minimum in Rotated Sorted Array` - Medium - Rotated binary search
- `154. Find Minimum in Rotated Sorted Array II` - Hard - Rotated binary search with duplicates
- `34. Find First and Last Position of Element in Sorted Array` - Medium - Boundary search
- `162. Find Peak Element` - Medium - Binary search on shape
- `540. Single Element in a Sorted Array` - Medium - Binary search on parity
- `74. Search a 2D Matrix` - Medium - Binary search style elimination

---

## 16. Key Takeaways

- Pattern: Modified binary search
- Important trick: one half is always sorted
- Complexity: `O(log n)` time, `O(1)` space
- Interview tip: explain why each branch preserves correctness
