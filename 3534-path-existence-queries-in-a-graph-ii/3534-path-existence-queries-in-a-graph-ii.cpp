class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // 1. Pair value with original index and sort
        vector<pair<int, int>> sortedPairs(n);
        for (int i = 0; i < n; ++i) {
            sortedPairs[i] = {nums[i], i};
        }
        sort(sortedPairs.begin(), sortedPairs.end());

        vector<int> sortedNums(n);
        vector<int> toSortedIdx(n);
        for (int i = 0; i < n; ++i) {
            sortedNums[i] = sortedPairs[i].first;
            toSortedIdx[sortedPairs[i].second] = i;
        }

        // Determine the maximum power of 2 needed for binary lifting
        int maxLevel = 0;
        while ((1 << maxLevel) <= n) {
            maxLevel++;
        }
        maxLevel++; 

        // jump[i][j] stores the farthest index reachable from i after 2^j steps
        vector<vector<int>> jump(n, vector<int>(maxLevel));
        
        // 2. Compute the base case: 1 step (2^0) using a two-pointer sliding window
        int r = 0;
        for (int i = 0; i < n; ++i) {
            while (r + 1 < n && sortedNums[r + 1] - sortedNums[i] <= maxDiff) {
                r++;
            }
            jump[i][0] = r;
        }

        // 3. Fill the binary lifting table
        for (int j = 1; j < maxLevel; ++j) {
            for (int i = 0; i < n; ++i) {
                jump[i][j] = jump[jump[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        // 4. Process queries
        for (const auto& q : queries) {
            int u = toSortedIdx[q[0]];
            int v = toSortedIdx[q[1]];
            
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (u > v) swap(u, v); // Keep u <= v for unidirectional traversal

            // If even the maximum single step from u cannot reach or pass beyond u's component boundary
            // to reach v, then they are disconnected.
            if (jump[u][maxLevel - 1] < v) {
                ans.push_back(-1);
                continue;
            }

            int steps = 0;
            int curr = u;

            // Greedily lift up to the target without overshooting
            for (int j = maxLevel - 1; j >= 0; --j) {
                if (jump[curr][j] < v) {
                    curr = jump[curr][j];
                    steps += (1 << j);
                }
            }

            // One last step is guaranteed to land on or cross v
            ans.push_back(steps + 1);
        }

        return ans;
    }
};