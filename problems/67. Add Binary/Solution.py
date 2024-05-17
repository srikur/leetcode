class Solution:
    def addBinary(self, a: str, b: str) -> str:
        lengthDiff = abs(len(a) - len(b))
        if len(b) < len(a):
            b = lengthDiff * "0" + b
        if len(a) < len(b):
            a = lengthDiff * "0" + a
        ret = ""
        carry = 0
        for i in range(len(b) - 1, -1, -1):
            total = int(a[i]) + int(b[i]) + carry
            if total == 3: # Carry 1
                ret = "1" + ret
                carry = 1
            elif total == 2:
                ret = "0" + ret
                carry = 1
            else:
                ret = str(total) + ret
                carry = 0
        return ret if carry == 0 else "1" + ret