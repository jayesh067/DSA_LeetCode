class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store key-value pairs
        for (auto &p : knowledge) {
            mp[p[0]] = p[1];
        }

        string ans;
        int i = 0;

        while (i < s.length()) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
                i++;
            }
            else {
                // Find the closing ')'
                int j = i + 1;

                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Check if key exists
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += "?";
                }

                // Move after ')'
                i = j + 1;
            }
        }

        return ans;
    }
};