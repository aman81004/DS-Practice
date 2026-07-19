class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> visited(26, false);

        // Store the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        string st = "";   // Using string as a stack

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Skip if already included
            if (visited[ch - 'a'])
                continue;

            // Remove larger characters if they appear later
            while (!st.empty() &&
                   st.back() > ch &&
                   last[st.back() - 'a'] > i) {

                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return st;
    }
};