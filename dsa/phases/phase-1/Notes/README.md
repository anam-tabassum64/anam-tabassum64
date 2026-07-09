# Phase 1 - Notes

## Focus areas

- Traversal
- Prefix and suffix techniques
- Hashing for duplicates and frequency
- Two pointers for boundary-based array problems

## Current notes

- [Array Traversal](../../phase-1-arrays.md)
- [Contains Duplicate](../../phase-1-contains-duplicate.md)
- [Product of Array Except Self](../../phase-1-product-except-self.md)
- [Trapping Rain Water](../../phase-1-trapping-rain-water.md)

## Study sequence

1. Learn traversal and simple aggregation
2. Practice hashing for duplicate and frequency problems
3. Learn prefix and suffix arrays/products
4. Practice two pointers on sorted arrays and boundary problems
5. Add sliding window after contiguous subarray problems feel familiar
6. Finish with hard boundary, stack, and binary-search array problems

## Implementation habits

- Use `vector<int>` for array problems
- Prefer `long long` when sums or products can grow
- Keep helper functions private inside the `Solution` class when they support one problem
- Avoid unnecessary global state
- Name variables by role: `left`, `right`, `prefixProduct`, `suffixProduct`, `maxLeft`
