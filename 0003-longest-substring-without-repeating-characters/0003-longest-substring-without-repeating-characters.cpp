class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int left = 0;
        vector<int> temp(256,0);
        
        for( int right = 0 ; right < n ; right++  ){
            while( temp[s[right]] == 1){
                temp[s[left]]--;
                left++;
            }
            temp[s[right]]++;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};