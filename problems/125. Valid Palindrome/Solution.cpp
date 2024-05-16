class Solution {
public:
    bool isPalindrome(string s) {
        std::regex word("[\\W]|_");
        s = std::regex_replace(s, word, "");
        if (s.length() == 0) return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int n = s.length();
        for (int i = 0; i < n / 2 + 1; i++) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
};