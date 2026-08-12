

class Solution {
private:
    int memo[101][101]; // memo[i][m] stores max stones starting at index i with modifier m
    int suffixSum[101];
    int n;

    int getMaxStones(int i, int m) {
        // Base case: Current player can take all remaining piles
        if (i + 2 * m >= n) {
            return suffixSum[i];
        }

        if (memo[i][m] != -1) {
            return memo[i][m];
        }

        int maxStones = 0;

        // Try taking X piles where 1 <= X <= 2 * m
        for (int x = 1; x <= 2 * m; ++x) {
            // Opponent gets the best possible score from index (i + x) with new M = max(m, x)
            int opponentScore = getMaxStones(i + x, std::max(m, x));
            
            // Current player gets total remaining stones minus what the opponent gets
            int currentScore = suffixSum[i] - opponentScore;
            
            maxStones = std::max(maxStones, currentScore);
        }

        return memo[i][m] = maxStones;
    }

public:
    int stoneGameII(std::vector<int>& piles) {
        n = piles.size();

        // Initialize memoization table with -1
        std::fill(&memo[0][0], &memo[0][0] + sizeof(memo) / sizeof(int), -1);

        // Precompute suffix sums: suffixSum[i] = sum(piles[i...n-1])
        suffixSum[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return getMaxStones(0, 1);
    }
};