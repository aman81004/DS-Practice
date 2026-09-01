#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startR = -1, startC = -1;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        int litterCount = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                } else if (classroom[i][j] == 'L') {
                    litterIdx[i][j] = litterCount++;
                }
            }
        }

        // If there is no litter to collect, 0 moves are needed
        if (litterCount == 0) {
            return 0;
        }

        int targetMask = (1 << litterCount) - 1;

        // max_energy[r][c][mask] stores the maximum remaining energy seen so far
        // Dimensions: 20 x 20 x 1024
        static int max_energy[20][20][1024];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int mask = 0; mask < (1 << litterCount); ++mask) {
                    max_energy[i][j][mask] = -1;
                }
            }
        }

        // State can be encoded as a 32-bit integer:
        // (r << 22) | (c << 16) | (e << 10) | mask
        auto encode = [](int r, int c, int e, int mask) -> int {
            return (r << 22) | (c << 16) | (e << 10) | mask;
        };

        queue<int> q;
        max_energy[startR][startC][0] = energy;
        q.push(encode(startR, startC, energy, 0));

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; ++s) {
                int curr = q.front();
                q.pop();

                int r = (curr >> 22) & 31;
                int c = (curr >> 16) & 63;
                int curEnergy = (curr >> 10) & 63;
                int mask = curr & 1023;

                // Cannot take any further move if energy is depleted
                if (curEnergy == 0) {
                    continue;
                }

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    int nextEnergy = (classroom[nr][nc] == 'R') ? energy : (curEnergy - 1);
                    int nextMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        nextMask |= (1 << litterIdx[nr][nc]);
                    }

                    // Reached all litter items
                    if (nextMask == targetMask) {
                        return moves + 1;
                    }

                    // Dominance check: only push if strictly higher energy is achieved
                    if (nextEnergy > max_energy[nr][nc][nextMask]) {
                        max_energy[nr][nc][nextMask] = nextEnergy;
                        q.push(encode(nr, nc, nextEnergy, nextMask));
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};