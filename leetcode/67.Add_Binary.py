class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a_int = 0
        b_int = 0

        a = a[::-1]
        b = b[::-1]

        for i in range(len(a)):
            if a[i] == '1':
                a_int += 2**i
        
        for i in range(len(b)):
            if b[i] == '1':
                b_int += 2**i
        
        c = a_int + b_int

        if c == 0:
            return "0"

        ans = ""
        for i in range(10001):
            if c == 0:
                break

            if c%2 == 1:
                ans += '1'
            else:
                ans += '0'
            c //= 2
        
        return ans[::-1]
