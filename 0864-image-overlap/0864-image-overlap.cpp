class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> p1, p2;

        // Collect coordinates of all 1s
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) p1.push_back({r, c});
                if (img2[r][c] == 1) p2.push_back({r, c});
            }
        }

        // Count frequency of each translation vector (dr, dc)
        // Using a 2D array offset by 'n' to store frequencies quickly
        int count[60][60] = {0};
        int max_overlap = 0;

        for (const auto& a : p1) {
            for (const auto& b : p2) {
                int dr = b.first - a.first + n;
                int dc = b.second - a.second + n;
                count[dr][dc]++;
                max_overlap = std::max(max_overlap, count[dr][dc]);
            }
        }

        return max_overlap;
    }
};