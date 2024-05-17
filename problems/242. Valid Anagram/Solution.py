class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sLetters, tLetters = [0] * 26, [0] * 26
        a = ord('a')
        for char in s:
            sLetters[ord(char) - a] += 1
        for char in t:
            tLetters[ord(char) - a] += 1
        for i in range(0, 26):
            if sLetters[i] != tLetters[i]: return False
        return True