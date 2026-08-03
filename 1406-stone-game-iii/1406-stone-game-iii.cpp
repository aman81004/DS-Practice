class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
       
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = INT_MIN;
            int currentTakeSum = 0;

           
            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                currentTakeSum += stoneValue[i + k - 1];
                dp[i] = max(dp[i], currentTakeSum - dp[i + k]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};