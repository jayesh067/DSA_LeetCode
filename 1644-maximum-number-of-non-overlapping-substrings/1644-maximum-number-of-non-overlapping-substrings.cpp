
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> first, last;
        
        // Step 1: Find first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (first.find(s[i]) == first.end()) first[s[i]] = i;
            last[s[i]] = i;
        }
        
        // Step 2: Form closed intervals
        vector<pair<int, int>> intervals;
        for (auto& [c, f] : first) {
            int l = f;
            int r = last[c];
            
            // Expand interval
            bool changed = true;
            while (changed) {
                changed = false;
                for (int i = l; i <= r; ++i) {
                    char ch = s[i];
                    if (first[ch] < l) {
                        l = first[ch];
                        changed = true;
                    }
                    if (last[ch] > r) {
                        r = last[ch];
                        changed = true;
                    }
                }
            }
            
            // Check if this interval is valid (contains all occurrences of all chars in it)
            // Actually, by construction, it is valid.
            intervals.push_back({l, r});
        }
        
        // Remove duplicates
        sort(intervals.begin(), intervals.end());
        intervals.erase(unique(intervals.begin(), intervals.end()), intervals.end());
        
        // Step 3: Sort by end index
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });
        
        // Step 4: Greedily select non-overlapping intervals
        vector<string> result;
        int lastEnd = -1;
        
        for (auto& [l, r] : intervals) {
            if (l > lastEnd) {
                result.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }
        
        return result;
    }
};