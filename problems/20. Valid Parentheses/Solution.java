class Solution {
    public boolean isValid(String s) {
        if (s.length() <= 1) return false;
        Stack<Character> stack = new Stack<Character>();
        HashMap<Character, Character> inverses = new HashMap<>();
        inverses.put(']', '[');
        inverses.put(')', '(');
        inverses.put('}', '{');
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                if (stack.empty() || inverses.get(ch) != stack.pop()) return false;
            }
        }
        return stack.empty();
    }
}