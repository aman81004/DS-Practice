class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
    int totalOnes = 0;
        int maxZeroSum = 0;
        int prevZeroLen = 0;
        int n = s.length();
        
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int segmentLen = j - i;
            
            if (s[i] == '1') {
                totalOnes += segmentLen;
            } else {
                // Combine current '0' block length with the previous '0' block length
                if (prevZeroLen > 0) {
                    maxZeroSum = std::max(maxZeroSum, prevZeroLen + segmentLen);
                }
                prevZeroLen = segmentLen;
            }
            
            i = j;
        }
        
        return totalOnes + maxZeroSum;
    }
};