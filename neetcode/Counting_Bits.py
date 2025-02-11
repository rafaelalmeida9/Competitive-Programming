class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0]*(n+1)
        
        for i in range(n+1):
            count = 0
            for j in range(11):
                if ((i>>j)&1):
                    count += 1
            ans[i] = count

        return ans
