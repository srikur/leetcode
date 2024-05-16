class Solution {
    public boolean isPalindrome(String s) {
        s = s.replaceAll("[\\W]|_", "").toLowerCase();
        if (s.length() == 0) return true;

        int n = s.length();
        for (int i = 0; i < n / 2 + 1; i++) {
            if (s.charAt(i) != s.charAt(n - i - 1)) return false;
        }
        return true;
    }
}