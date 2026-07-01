#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r,c});
                }
            }
        }

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]==-1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }

        
        priority_queue<array<int,3>> pq; 
        pq.push({dist[0][0], 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n,false));

        while (!pq.empty()) {
            auto [safe, r, c] = pq.top(); pq.pop();
            if (r == n-1 && c == n-1) return safe;
            if (visited[r][c]) continue;
            visited[r][c] = true;

            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]) {
                    pq.push({min(safe, dist[nr][nc]), nr, nc});
                }
            }
        }
        return 0;
    }
};