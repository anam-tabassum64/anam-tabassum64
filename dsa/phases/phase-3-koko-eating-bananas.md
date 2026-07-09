# Koko Eating Bananas

## 1. Problem Statement

Koko has `n` piles of bananas. She eats at a constant speed `k` bananas per hour.

Given a time limit `h`, find the minimum integer speed `k` so that she can finish all bananas within `h` hours.

---

## 2. Constraints

- `1 <= piles.length <= 10^4`
- `piles[i] >= 1`
- `piles.length <= h <= 10^9`
- `1 <= piles[i] <= 10^9`

---

## 3. Intuition

If Koko eats faster, she needs fewer hours.

If Koko eats slower, she needs more hours.

This creates a monotonic relationship between eating speed and feasibility, which is exactly what binary search on answer needs.

---

## 4. Pattern Recognition

- Pattern: Binary Search on Answer

This fits because we are not searching for a value inside the array.

We are searching for the smallest speed that satisfies a yes/no condition:

`Can Koko finish within h hours at speed k?`

---

## 5. Brute Force

### Algorithm

Try every possible speed from `1` to `max(piles)`.

For each speed, simulate the total hours needed.

### Dry explanation

If the total hours are within `h`, record that speed as valid.

### Complexity

- Time: `O(maxPile * n)`
- Space: `O(1)`

---

## 6. Better Solution

Use binary search over the speed range.

### Why it is better

The feasibility condition is monotonic:

- if speed `k` works, then all larger speeds also work
- if speed `k` fails, then all smaller speeds also fail

### Complexity

- Time: `O(n log maxPile)`
- Space: `O(1)`

---

## 7. Optimal Solution

Use binary search on the answer and a helper function to check feasibility.

### Observation

The minimum valid speed lies between `1` and `max(piles)`.

### Algorithm

1. Set `left = 1`, `right = max(piles)`
2. While `left <= right`:
   - compute `mid`
   - calculate how many hours are needed at speed `mid`
   - if hours `<= h`, store `mid` as a candidate answer and try smaller speed
   - otherwise try larger speed
3. Return the smallest valid speed

### Why it works

The feasible speeds form a monotonic boolean range, so binary search can isolate the minimum valid one.

---

## 8. Dry Run

Example: `piles = [3, 6, 7, 11]`, `h = 8`

- `left = 1`, `right = 11`
- `mid = 6`
- Hours needed = `1 + 1 + 2 + 2 = 6`, valid
- Try smaller -> `right = 5`
- `mid = 3`
- Hours needed = `1 + 2 + 3 + 4 = 10`, not valid
- Try larger -> `left = 4`
- `mid = 4`
- Hours needed = `1 + 2 + 2 + 3 = 8`, valid
- Try smaller -> `right = 3`
- Stop, answer = `4`

---

## 9. C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool canFinish(const vector<int>& piles, int speed, int hoursLimit) {
        long long hoursNeeded = 0;

        for (int pile : piles) {
            hoursNeeded += (pile + speed - 1) / speed;
            if (hoursNeeded > hoursLimit) {
                return false;
            }
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, mid, h)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
```

---

## 10. Time Complexity

- Best Case: `O(n)` for a small number of binary search steps with early feasibility pruning
- Average Case: `O(n log maxPile)`
- Worst Case: `O(n log maxPile)`

---

## 11. Space Complexity

- Auxiliary space: `O(1)`

---

## 12. Common Mistakes

- Searching over the wrong speed range
- Using floor division instead of ceiling division
- Forgetting to use `long long` for the total hours
- Returning the first valid speed without checking if a smaller valid speed exists

---

## 13. Edge Cases

- One pile
- `h` equals number of piles
- Very large pile values
- Speed equal to the largest pile
- Already feasible at low speed

---

## 14. Interview Follow-ups

- What if the piles arrive as a stream?
- Can the feasibility check be optimized further?
- Why is the answer space monotonic?
- What other problems use the same pattern?

---

## 15. Similar Problems

- `1011. Capacity To Ship Packages Within D Days` - Medium - Binary search on answer
- `1482. Minimum Number of Days to Make m Bouquets` - Medium - Binary search on answer
- `410. Split Array Largest Sum` - Hard - Binary search on answer
- `2064. Minimized Maximum of Products Distributed to Any Store` - Medium - Binary search on answer
- `1760. Minimum Limit of Balls in a Bag` - Medium - Binary search on answer
- `2226. Maximum Candies Allocated to K Children` - Medium - Binary search on answer

---

## 16. Key Takeaways

- Pattern: Binary search on answer
- Important trick: feasibility is monotonic with speed
- Complexity: `O(n log maxPile)` time, `O(1)` space
- Interview tip: always define the check function first
