class Solution:
    def countCommas(self, n: int) -> int:
        
        start = 1000 
        commas = 0

        while n >= start :
            commas += n - start + 1 
            start *= 1000
        
        return commas
        