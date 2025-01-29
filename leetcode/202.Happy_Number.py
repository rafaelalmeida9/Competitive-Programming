class Solution:
    def isHappy(self, n: int) -> bool:
        def getSquares(n):
            sum = 0
            while n != 0:
                sum += (n % 10) ** 2
                n = n // 10
            return sum

        check = {}

        while True:
            if n in check:
                return False
            else:
                check[n] = True
                n = getSquares(n)
                if n == 1:
                    return True
