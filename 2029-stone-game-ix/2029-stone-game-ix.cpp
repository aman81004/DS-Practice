class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0, 0, 0};
        for (int stone : stones) {
            count[stone % 3]++;
        }

        int c0 = count[0];
        int c1 = count[1];
        int c2 = count[2];

        // Even count of 0s: Alice wins if both 1s and 2s exist
        if (c0 % 2 == 0) {
            return c1 >= 1 && c2 >= 1;
        }

        // Odd count of 0s: Alice wins if the difference between 1s and 2s exceeds 2
        return abs(c1 - c2) > 2;
    }
};