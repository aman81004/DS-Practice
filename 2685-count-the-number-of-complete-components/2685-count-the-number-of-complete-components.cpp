
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list for the graph
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        // Step 2: Traverse each unvisited node to find connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int vertexCount = 0;
                int edgeDegreeSum = 0;
                
                dfs(i, adj, visited, vertexCount, edgeDegreeSum);

                // In an undirected graph, each edge is counted twice (once from each endpoint)
                int uniqueEdges = edgeDegreeSum / 2;

                // Check if the component is complete
                if (uniqueEdges == (vertexCount * (vertexCount - 1)) / 2) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }

private:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, int& vertexCount, int& edgeDegreeSum) {
        visited[node] = true;
        vertexCount++;                 // Increment vertex count
        edgeDegreeSum += adj[node].size(); // Accumulate the degree of the node

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, vertexCount, edgeDegreeSum);
            }
        }
    }
};