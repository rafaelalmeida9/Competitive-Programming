class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        for i in range(0,33):
            if ((n>>i)&1):
                count += 1
        
        return count
