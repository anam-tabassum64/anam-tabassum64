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
