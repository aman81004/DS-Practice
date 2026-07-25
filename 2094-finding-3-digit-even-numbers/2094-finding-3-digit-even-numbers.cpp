class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        vector<int> ans;
        unordered_map<int, int> s;

        for (int ele : digits) {
            s[ele]++;
        }

        // Loop through all 3-digit EVEN numbers (100 to 998)
        for (int i = 100; i <= 998; i += 2) {
            int x = i;
            int a = x % 10;      // units digit (even)
            x /= 10;
            int b = x % 10;      // tens digit
            x /= 10;
            int c = x;           // hundreds digit

            // Try using 'a'
            if (s[a] > 0) {
                s[a]--;

                // Try using 'b'
                if (s[b] > 0) {
                    s[b]--;

                    // Try using 'c'
                    if (s[c] > 0) {
                        ans.push_back(i);
                    }

                    s[b]++; // Backtrack 'b'
                }

                s[a]++; // Backtrack 'a'
            }
        }

        return ans;
    }
};