class Solution:
    def countCommas(self, n: int) -> int:

        ans = 0
        start = 1000

        while  n >= start :
            ans += (n - start + 1)
            start *= 1000
            
        return ans
