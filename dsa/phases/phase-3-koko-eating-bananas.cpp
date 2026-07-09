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
