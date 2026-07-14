class Solution {
    int MOD = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxEl = -1;
        for (int x : nums) 
            maxEl = max(maxEl, x);

        // prev = layer i+1, curr = layer i   (2D instead of 3D)
        vector<vector<int>> prev(maxEl+1, vector<int>(maxEl+1, 0));

        // Base case
        for (int first = maxEl; first >= 0; first--) {
            for (int second = maxEl; second >= 0; second--) {
                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdsMatch    = (first == second);
                prev[first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> curr(maxEl+1, vector<int>(maxEl+1, 0));
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    // Skip this index entirely
                    int skip  = prev[first][second];

                    // Include this index in seq1
                    int take1 = prev[__gcd(first, nums[i])][second];

                    // Include this index in seq2
                    int take2 = prev[first][__gcd(second, nums[i])];

                    curr[first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
            prev = move(curr);
        }

        return prev[0][0];
    }
};