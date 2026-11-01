class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int count =0;
        for(int val : nums){
            count += val - mini;
        }
        return count;
    }
};