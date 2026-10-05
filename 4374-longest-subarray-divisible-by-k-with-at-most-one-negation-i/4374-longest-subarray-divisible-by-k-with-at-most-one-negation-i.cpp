class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            long long sum =0;
            unordered_set<int> values;
            for(int j=i;j<n;j++){
                sum += nums[j];

                int x = ((2LL * nums[j])%k + k)%k;
                values.insert(x);
                int rem = ((sum%k)+k)%k;
                if(rem == 0) ans = max(ans,j-i+1);
                else if(values.count(rem)) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};