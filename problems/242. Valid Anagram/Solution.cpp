class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int sLetters[26], tLetters[26];
        for (char& ch : s) sLetters[ch - 'a'] += 1;
        for (char& ch : t) tLetters[ch - 'a'] += 1;
        for (int i = 0; i < 26; i++) if (sLetters[i] != tLetters[i]) return false;
        return true;
    }
};