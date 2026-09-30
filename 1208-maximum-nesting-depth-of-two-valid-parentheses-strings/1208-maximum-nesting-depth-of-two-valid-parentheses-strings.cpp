class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        ans.reserve(seq.size());
        
        int depth = 0;
        for (char ch : seq) {
            if (ch == '(') {
                depth++;
                ans.push_back(depth % 2); // Assign even depth to A (0), odd to B (1)
            } else { // ch == ')'
                ans.push_back(depth % 2); // Match corresponding '('
                depth--;
            }
        }
        
        return ans;
    }
};