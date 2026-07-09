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
