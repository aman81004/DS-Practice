class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            int rightChar = s[right] - 'a';
            freq[rightChar]++;

            // Shrink window from the left if current character occurs more than twice
            while (freq[rightChar] > 2) {
                int leftChar = s[left] - 'a';
                freq[leftChar]--;
                left++;
            }

            // Update the maximum length found
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};