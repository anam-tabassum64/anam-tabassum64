# Contains Duplicate

## 1. Problem Statement

Given an integer array, determine whether any value appears at least twice.

---

## 2. Constraints

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- The array may contain duplicates, negative numbers, and zeros.

---

## 3. Intuition

We need to know whether we have seen a number before.

If we scan left to right and store every seen number, then the first time we see the same number again, we can stop immediately.

The key observation is that this is a membership problem, not a sorting problem.

---

## 4. Pattern Recognition

- Pattern: Hashing

This fits hashing because we need fast lookup for "have we seen this value before?".

An unordered set gives average `O(1)` insert and search, which is ideal for one-pass duplicate detection.

---

## 5. Brute Force

### Algorithm

Check every pair of elements.

### Dry explanation

For each index `i`, compare `nums[i]` with all later elements.
If any match is found, return true.

### Complexity

- Time: `O(n^2)`
- Space: `O(1)`

---

## 6. Better Solution

Sort the array first.

After sorting, duplicates become adjacent, so we only need to compare neighboring elements.

### Why it is better

It reduces the problem from pairwise comparison to one linear scan after sorting.

### Complexity

- Time: `O(n log n)`
- Space: `O(1)` or `O(log n)` depending on sort implementation

---

## 7. Optimal Solution

Use an unordered set while traversing the array once.

### Observation

If a number already exists in the set, we have found a duplicate.

### Algorithm

1. Create an empty set.
2. Traverse the array.
3. For each number:
   - if it already exists in the set, return true
   - otherwise insert it
4. If traversal finishes, return false

### Why it works

The set stores all previously seen values.
The first repeated value will be detected immediately.

---

## 8. Dry Run

Example: `nums = [1, 2, 3, 1]`

- Start with `seen = { }`
- Read `1` -> insert -> `seen = {1}`
- Read `2` -> insert -> `seen = {1, 2}`
- Read `3` -> insert -> `seen = {1, 2, 3}`
- Read `1` -> already present -> return true

---

## 9. C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int value : nums) {
            auto inserted = seen.insert(value);
            if (!inserted.second) {
                return true;
            }
        }

        return false;
    }
};
```

---

## 10. Time Complexity

- Best Case: `O(1)` if a duplicate is found early
- Average Case: `O(n)`
- Worst Case: `O(n^2)` in a pathological hash collision scenario

---

## 11. Space Complexity

- Auxiliary space: `O(n)` for the hash set

---

## 12. Common Mistakes

- Using a nested loop when one pass is enough
- Forgetting to stop immediately when a duplicate is found
- Using a normal vector search instead of hashing
- Ignoring hash collision discussion in interviews

---

## 13. Edge Cases

- Empty input
- Single element
- All elements unique
- All elements equal
- Large negative or positive values

---

## 14. Interview Follow-ups

- What if the array is streamed and cannot be stored fully?
- What if you must use `O(1)` extra space?
- What if you need to detect duplicates within distance `k`?

---

## 15. Similar Problems

- `219. Contains Duplicate II` - Easy - Hashing plus sliding window
- `220. Contains Duplicate III` - Medium - Ordered set and window
- `242. Valid Anagram` - Easy - Frequency counting
- `349. Intersection of Two Arrays` - Easy - Set based lookup
- `128. Longest Consecutive Sequence` - Medium - Hashing
- `347. Top K Frequent Elements` - Medium - Hash map plus heap

---

## 16. Key Takeaways

- Pattern: Hashing
- Important trick: store seen values in a set
- Complexity: `O(n)` average time, `O(n)` space
- Interview tip: mention sorting as a simpler alternative if extra space is restricted
