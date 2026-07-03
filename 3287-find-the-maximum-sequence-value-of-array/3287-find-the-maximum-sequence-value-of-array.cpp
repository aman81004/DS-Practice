#define pii pair<int, int>
#define F first
#define S second

vector<vector<pii>> prefix(401, vector<pii>(128, {1e9, 0}));
vector<vector<pii>> suffix(401, vector<pii>(128, {1e9, 0}));

class Solution {
    
    void Compute (const vector<int>& arr) {
        int n = arr.size();
        
        prefix[0][arr[0]] = {1, 1};
        for (int j = 1; j < n; j ++) {
            prefix[j] = prefix[j-1];
            prefix[j][arr[j]].F = 1;
            prefix[j][arr[j]].S = max(prefix[j][arr[j]].S, 1);
            
            for (int val = 1; val < 128; val ++) {
                if (prefix[j-1][val].F == 1e9) continue;
                
                int new_val = val | arr[j];
                prefix[j][new_val].F = min(prefix[j][new_val].F, 1 + prefix[j-1][val].F);
                prefix[j][new_val].S = max(prefix[j][new_val].S, 1 + prefix[j-1][val].S);
            }
        }
        
        suffix[n-1][arr[n-1]] = {1, 1};
        for (int j = n-2; j >= 0; j --) {
            suffix[j] = suffix[j+1];
            suffix[j][arr[j]].F = 1;
            suffix[j][arr[j]].S = max(suffix[j][arr[j]].S, 1);
            
            for (int val = 1; val < 128; val ++) {
                if (suffix[j+1][val].F == 1e9) continue;
                
                int new_val = val | arr[j];
                suffix[j][new_val].F = min(suffix[j][new_val].F, 1 + suffix[j+1][val].F);
                suffix[j][new_val].S = max(suffix[j][new_val].S, 1 + suffix[j+1][val].S);
            }
        }
    }
    
    bool IsPossible (int lft_or, int rgt_or, int k, int n) {
        for (int l = 0; l < n-1; l ++) {
            pii lft = prefix[l][lft_or];
            pii rgt = suffix[l+1][rgt_or];
            
            if ((lft.F <= k && k <= lft.S) && (rgt.F <= k && k <= rgt.S)) return true;
        }
        return false;
    }
    
public:
    int maxValue(vector<int>& nums, int k) {
        prefix.clear(), suffix.clear();
        prefix.resize(401, vector<pii>(128, {1e9, 0}));
        suffix.resize(401, vector<pii>(128, {1e9, 0}));
        
        Compute (nums);
        int n = nums.size();
        
        int ans = 0;
        for (int l = 1; l < 128; l ++) {
            for (int r = 1; r < 128; r ++)
                if (IsPossible (l, r, k, n)) {
                    // cout << l << " " << r << endl;
                    ans = max (ans, l^r);
                }
        }
        return ans;
    }
};