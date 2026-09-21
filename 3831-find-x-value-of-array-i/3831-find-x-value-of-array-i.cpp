class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int val = num % k;

            // Option 1: Extend previous subarrays ending at index i - 1
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * val) % k] += dp[r];
                }
            }

            // Option 2: Start a new subarray at current index
            next_dp[val] += 1;

            // Add the occurrences ending at the current index to total counts
            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            // Move to next iteration
            dp = move(next_dp);
        }

        return ans;
    }
};