
class Solution {
    multiset<long long> low, high;
    long long sumLow = 0, sumHigh = 0;

    // Keep low with one extra element when window size is odd.
    void balance() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            long long val = *it;

            low.erase(it);
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }

        while (low.size() < high.size()) {
            auto it = high.begin();
            long long val = *it;

            high.erase(it);
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    }

    void add(long long val) {
        if (low.empty() || val <= *prev(low.end())) {
            low.insert(val);
            sumLow += val;
        } else {
            high.insert(val);
            sumHigh += val;
        }

        balance();
    }

    void remove(long long val) {
        auto it = low.find(val);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= val;
        } else {
            it = high.find(val);
            high.erase(it);
            sumHigh -= val;
        }

        balance();
    }

    long long getCost() {
        long long median = *prev(low.end());

        return median * (long long)low.size() - sumLow
             + sumHigh - median * (long long)high.size();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Step 1: Calculate the cost of every window of size x.
        vector<long long> cost(n - x + 1);

        low.clear();
        high.clear();
        sumLow = sumHigh = 0;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        // Step 2: DP with rolling arrays.
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip current element.
                curr[i] = curr[i - 1];

                // Select a window ending at i-1.
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
