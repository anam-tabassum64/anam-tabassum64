# Phase 1 - Revision

## Quick revision list

- Traversal: one pass, `O(n)` time, `O(1)` space
- Contains Duplicate: hash set lookup
- Product Except Self: prefix and suffix reuse
- Trapping Rain Water: two pointers with boundary tracking

## Current solved recap

| Problem | Pattern | Time | Space |
| --- | --- | --- | --- |
| Contains Duplicate | Hashing | `O(n)` average | `O(n)` |
| Product of Array Except Self | Prefix/suffix | `O(n)` | `O(1)` extra |
| Trapping Rain Water | Two pointers | `O(n)` | `O(1)` |

## Review questions

- When is hashing better than sorting?
- When can prefix and suffix arrays replace brute force?
- Why does the smaller boundary control trapped water?

## Mini interview checklist

- Can you explain brute force first?
- Can you identify the exact pattern?
- Can you state the invariant?
- Can your solution handle empty or single-element input?
- Can you explain why the optimal solution improves time or space?

## Common mistakes

- Forgetting zero handling in product problems
- Using nested loops when a hash set is enough
- Moving the wrong pointer in two-pointer problems
- Missing duplicate handling after sorting
- Using `int` where `long long` is safer
