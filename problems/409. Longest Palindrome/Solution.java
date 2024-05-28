class Solution {
    public int longestPalindrome(String s) {
        int[] occurrences = new int[58];
        for (int i = 0; i < s.length(); i++) {
            occurrences[s.charAt(i) - 'A'] += 1;
        }
        int longest = 0;
        boolean hasOdd = false;
        for (int i = 0; i < 58; i++) {
            int value = occurrences[i];
            if (value % 2 == 0) longest += value;
            else {
                longest += value - 1;
                hasOdd = true;
            }
        }
        return longest + (hasOdd ? 1 : 0);
    }
}