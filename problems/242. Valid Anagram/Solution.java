class Solution {
    public boolean isAnagram(String s, String t) {
        int[] sLetters = new int[26];
        int[] tLetters = new int[26];
        for (int i = 0; i < s.length(); i++) sLetters[s.charAt(i) - 'a'] += 1;
        for (int i = 0; i < t.length(); i++) tLetters[t.charAt(i) - 'a'] += 1;
        for (int i = 0; i < 26; i++) if (sLetters[i] != tLetters[i]) return false;
        return true;
    }
}