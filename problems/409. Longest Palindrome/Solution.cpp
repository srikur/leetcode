class Solution {
public:
    int longestPalindrome(string s) {
        int occ[58];
        for (const char& ch : s) occ[ch - 'A'] += 1;
        int longest = 0;
        bool hasOdd = false;
        for (int i = 0; i < 58; i++) {
            int val = occ[i];
            if (val % 2) {
                longest += val - 1;
                hasOdd = true;
            } else longest += val;
        }
        return longest + (hasOdd ? 1 : 0);
    }
};