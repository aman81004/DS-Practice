class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        long long num = 0;
        long long sum = 0;

        for (char c : s) {
            if (c != '0') {
                int digit = c - '0';
                num = num * 10 + digit;
                sum += digit;
            }
        }

        return num * sum;
    }
};