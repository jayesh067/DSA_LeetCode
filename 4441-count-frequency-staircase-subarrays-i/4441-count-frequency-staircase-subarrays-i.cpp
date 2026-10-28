class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> freq;
            vector<int> order;

            for(int j=i;j<n;j++){
                int x = nums[j];
                if(freq[x] == 0)
                    order.push_back(x);
                freq[x]++;

                bool valid = true;
                for(int k=0;k<order.size();k++){
                    if(freq[order[k]] != k+1){
                        valid = false;
                        break;
                    }
                }
                if(valid) ans++;
            }
        }
        return ans;
    }
};