# Phase 1 - Patterns

## Patterns used in this phase

- Traversal
- Two pointers
- Prefix and suffix product
- Hashing
- Greedy boundary tracking

## Pattern map

| Pattern | When to use | Current problem |
| --- | --- | --- |
| Hashing | Need fast lookup or duplicate detection | Contains Duplicate |
| Prefix/suffix | Answer depends on left and right accumulated values | Product of Array Except Self |
| Two pointers | Boundaries or sorted movement decide the answer | Trapping Rain Water |
| Greedy scan | Track best value seen so far | Best Time to Buy and Sell Stock |
| Sliding window | Work with contiguous subarrays or ranges | Minimum Window Substring |
| Sorting + scan | Order makes comparisons easier | 3Sum / Merge Intervals |

## Interview signals

If a problem asks you to combine left and right information, think prefix/suffix.

If a problem asks whether something was seen before, think hashing.

If the answer depends on a boundary from both ends, think two pointers.

If the problem asks for best profit, max running value, or minimum running value, think greedy scan.

If the problem asks about contiguous subarrays with constraints, think sliding window or prefix sum.
