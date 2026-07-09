class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // g[i] will store the connected component ID for node i
        vector<int> g(n, 0);
        int componentId = 0;
        
        // Linear scan to find breaks/barriers between consecutive nodes
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                componentId++; // Start a new connected component
            }
            g[i] = componentId;
        }
        
        // Process each query in O(1) time
        vector<bool> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            // If they belong to the same component, a path exists
            ans.push_back(g[u] == g[v]);
        }
        
        return ans;
    }
};