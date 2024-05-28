class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < magazine.length(); i++) {
            char ch = magazine.charAt(i);
            if (map.containsKey(ch) == true) {
                int oldVal = map.get(ch);
                map.replace(ch, oldVal + 1);
            } else {
                map.put(ch, 1);
            }
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            char ch = ransomNote.charAt(i);
            if (map.containsKey(ch) == false || map.get(ch) == 0) return false;
            int oldVal = map.get(ch);
            map.replace(ch, oldVal - 1);
        }
        return true;
    }
}