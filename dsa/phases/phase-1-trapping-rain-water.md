# Trapping Rain Water

## 1. Problem Statement

Given an array of bar heights, compute how much rain water can be trapped between the bars after rainfall.

---

## 2. Constraints

- `1 <= height.length <= 10^5`
- `0 <= height[i] <= 10^5`
- Heights are non-negative

---

## 3. Intuition

Water above an index is limited by the shorter of:

- the tallest bar on the left
- the tallest bar on the right

If we know both limits, we can compute trapped water at each position.

The key observation is that the water level at a position depends on the smaller boundary, not on the full array.

---

## 4. Pattern Recognition

- Pattern: Two Pointers
- Supporting idea: Prefix max / suffix max

Two pointers fit because we can decide which side is safe to process based on the smaller boundary.

---

## 5. Brute Force

### Algorithm

For each index, scan left to find the highest bar and scan right to find the highest bar.

### Dry explanation

For every position:

`water[i] = min(maxLeft, maxRight) - height[i]`

### Complexity

- Time: `O(n^2)`
- Space: `O(1)`

---

## 6. Better Solution

Precompute:

- `leftMax[i]`
- `rightMax[i]`

Then calculate the water at every index in one scan.

### Why it is better

Each boundary is computed once, so we avoid repeated scans.

### Complexity

- Time: `O(n)`
- Space: `O(n)`

---

## 7. Optimal Solution

Use two pointers from both ends.

### Observation

If `height[left] < height[right]`, then the left side is the limiting factor for the current step.

That means the trapped water at `left` only depends on `leftMax`.

Similarly, if `height[right] <= height[left]`, the right side is the limiting factor.

### Algorithm

1. Set `left = 0`, `right = n - 1`
2. Maintain `leftMax` and `rightMax`
3. Move the pointer on the smaller side
4. Add trapped water for that side

### Why it works

The smaller boundary is the bottleneck.
Once that side is fixed, the opposite side cannot improve the current water level.

---

## 8. Dry Run

Example: `height = [0,1,0,2,1,0,1,3,2,1,2,1]`

Start:

- `left = 0`
- `right = 11`
- `leftMax = 0`
- `rightMax = 0`
- `water = 0`

As the pointers move:

- update the smaller side boundary
- add `boundary - currentHeight`
- continue until pointers meet

Final trapped water: `6`

---

## 9. C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int leftMax = 0;
        int rightMax = 0;
        long long water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }

        return static_cast<int>(water);
    }
};
```

---

## 10. Time Complexity

- Best Case: `O(n)`
- Average Case: `O(n)`
- Worst Case: `O(n)`

---

## 11. Space Complexity

- Auxiliary space: `O(1)`

---

## 12. Common Mistakes

- Forgetting that water depends on both left and right boundaries
- Trying to add negative water
- Updating the wrong pointer
- Using `min(leftMax, rightMax)` incorrectly without understanding the two-pointer invariant

---

## 13. Edge Cases

- Empty input
- Single bar
- Two bars
- Strictly increasing bars
- Strictly decreasing bars
- All bars equal
- Very large arrays

---

## 14. Interview Follow-ups

- Can you solve it with prefix and suffix arrays first?
- Can you do it in `O(1)` extra space?
- How would the solution change for 2D rain water trapping?

---

## 15. Similar Problems

- `11. Container With Most Water` - Medium - Two pointers
- `84. Largest Rectangle in Histogram` - Hard - Monotonic stack
- `407. Trapping Rain Water II` - Hard - Heap / BFS
- `739. Daily Temperatures` - Medium - Monotonic stack
- `1762. Buildings With an Ocean View` - Medium - Stack / scan pattern
- `85. Maximal Rectangle` - Hard - Stack and matrix scan

---

## 16. Key Takeaways

- Pattern: Two pointers with boundary tracking
- Important trick: move the side with the smaller bar
- Complexity: `O(n)` time, `O(1)` extra space
- Interview tip: begin with the prefix/suffix max idea, then optimize to two pointers
