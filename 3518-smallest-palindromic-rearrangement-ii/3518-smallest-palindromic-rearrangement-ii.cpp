#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static const long long LIMIT = 1000001; // k <= 10^6 constraint

    // Helper function to calculate distinct permutations of current remaining characters:
    // formula: (total!) / (count[0]! * count[1]! * ... * count[25]!)
    long long countWays(const vector<int>& cnt, int total) {
        long long res = 1;
        int remaining = total;

        for (int i = 0; i < 26; ++i) {
            int c = cnt[i];
            for (int j = 1; j <= c; ++j) {
                res = (res * (remaining - c + j)) / j;
                if (res > LIMIT) return LIMIT; // Cap at limit to prevent overflow
            }
            remaining -= c;
        }
        return min(res, LIMIT);
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> half(26, 0);
        int halfLen = 0;
        char mid = '\0';

        // Extract frequencies required for the left half
        for (int i = 0; i < 26; ++i) {
            half[i] = freq[i] / 2;
            halfLen += half[i];
            if (freq[i] % 2 == 1) {
                mid = 'a' + i;
            }
        }

        // Check if there are fewer than k distinct palindromes
        if (countWays(half, halfLen) < k) {
            return "";
        }

        string left = "";
        long long target = k;

        // Construct the left half position by position
        for (int pos = 0; pos < halfLen; ++pos) {
            for (int ch = 0; ch < 26; ++ch) {
                if (half[ch] == 0) continue;

                // Try placing 'a' + ch at the current position
                half[ch]--;
                long long ways = countWays(half, halfLen - pos - 1);

                if (ways >= target) {
                    // This character leads to the k-th permutation
                    left += (char)('a' + ch);
                    break;
                } else {
                    // Skip these permutations and adjust target count
                    target -= ways;
                    half[ch]++; // Backtrack
                }
            }
        }

        // Form the complete palindrome: left + mid + reverse(left)
        string ans = left;
        if (mid != '\0') {
            ans += mid;
        }
        string right = left;
        reverse(right.begin(), right.end());
        ans += right;

        return ans;
    }
};