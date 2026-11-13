class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(nums.rbegin(), nums.rend());

        deque<int> dq;
        long long ans = 0, cost = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            while (!dq.empty() && a[dq.back()] < a[r]) {
                int j = dq.back();
                dq.pop_back();

                int p = dq.empty() ? l - 1 : dq.back();
                cost -= 1LL * (a[j] - a[r]) * (j - p);
            }

            dq.push_back(r);

            while (cost > k) {
                cost -= a[dq.front()] - a[l];
                if (dq.front() == l) {
                    dq.pop_front();
                }
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};