# Product of Array Except Self

## 1. Problem Statement

Given an integer array `nums`, return an array `answer` such that `answer[i]` is the product of all elements of `nums` except `nums[i]`.

Do this without using division if possible.

---

## 2. Constraints

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The answer fits in 32-bit integer in the original problem setting
- Arrays may contain zeros

---

## 3. Intuition

For each position, we need the product of everything on its left and everything on its right.

If we already know:

- prefix product up to index `i - 1`
- suffix product from index `i + 1` to the end

then the answer is just their multiplication.

This naturally suggests a prefix and suffix style solution.

---

## 4. Pattern Recognition

- Pattern: Prefix Sum / Prefix Product

It fits this pattern because each answer depends on values before and after the current index.

Instead of recomputing products from scratch for every index, we reuse partial results.

---

## 5. Brute Force

### Algorithm

For every index, multiply all other elements.

### Dry explanation

For each `i`, loop through the whole array and skip `i`.

### Complexity

- Time: `O(n^2)`
- Space: `O(1)`

---

## 6. Better Solution

Use two helper arrays:

- `prefix[i]` = product of all elements before `i`
- `suffix[i]` = product of all elements after `i`

Then `answer[i] = prefix[i] * suffix[i]`.

### Why it is better

Each product is computed once and reused.

### Complexity

- Time: `O(n)`
- Space: `O(n)`

---

## 7. Optimal Solution

Use the answer array itself to store prefix products, then multiply suffix products in a second pass.

### Observation

We do not need separate prefix and suffix arrays.

### Algorithm

1. Build the answer array with prefix products from left to right.
2. Traverse from right to left while maintaining a suffix product.
3. Multiply each answer cell by the current suffix product.

### Why it works

At index `i`, the answer must equal:

`product of all elements left of i * product of all elements right of i`

The first pass stores the left product.
The second pass multiplies the right product.

---

## 8. Dry Run

Example: `nums = [1, 2, 3, 4]`

### First pass

- `answer = [1, 1, 1, 1]`
- prefix = 1
- i = 0 -> answer[0] = 1, prefix = 1
- i = 1 -> answer[1] = 1, prefix = 2
- i = 2 -> answer[2] = 2, prefix = 6
- i = 3 -> answer[3] = 6, prefix = 24

Now `answer = [1, 1, 2, 6]`

### Second pass

- suffix = 1
- i = 3 -> answer[3] = 6 * 1 = 6, suffix = 4
- i = 2 -> answer[2] = 2 * 4 = 8, suffix = 12
- i = 1 -> answer[1] = 1 * 12 = 12, suffix = 24
- i = 0 -> answer[0] = 1 * 24 = 24

Final answer: `[24, 12, 8, 6]`

---

## 9. C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> result(n, 1);

        long long prefixProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] = static_cast<int>(prefixProduct);
            prefixProduct *= nums[i];
        }

        long long suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = static_cast<int>(1LL * result[i] * suffixProduct);
            suffixProduct *= nums[i];
        }

        return result;
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

- Auxiliary space: `O(1)` excluding the output array
- If you count the output array, total storage is `O(n)`

---

## 12. Common Mistakes

- Using division and failing on zero values
- Forgetting that zeros need special handling
- Building both prefix and suffix arrays when one output array is enough
- Using `int` for intermediate multiplication and overflowing too early

---

## 13. Edge Cases

- Array with one zero
- Array with two or more zeros
- All values are positive
- Negative values
- Minimum length input
- Large products near integer limits

---

## 14. Interview Follow-ups

- What if division is allowed?
- What if the input is streaming?
- Can this be done in constant extra space?
- How do zeros change the logic?

---

## 15. Similar Problems

- `1480. Running Sum of 1d Array` - Easy - Prefix accumulation
- `724. Find Pivot Index` - Easy - Prefix sums
- `303. Range Sum Query - Immutable` - Easy - Prefix sums
- `1991. Find the Middle Index in Array` - Easy - Prefix and suffix sums
- `2574. Left and Right Sum Differences` - Easy - Prefix and suffix comparison
- `152. Maximum Product Subarray` - Medium - Product tracking with negative numbers

---

## 16. Key Takeaways

- Pattern: Prefix and suffix reuse
- Important trick: store left products in the answer array, then multiply by right products
- Complexity: `O(n)` time, `O(1)` extra space
- Interview tip: mention zero handling and why division is avoided
