class Solution {
    public String addBinary(String a, String b) {
        int lengthDiff = Math.abs(a.length() - b.length());
        if (a.length() < b.length()) {
            a = "0".repeat(lengthDiff) + a;
        }
        if (b.length() < a.length()) {
            b = "0".repeat(lengthDiff) + b;
        }
        int carry = 0;
        String sum = "";
        for (int i = a.length() - 1; i >= 0; i--) {
            int total = (a.charAt(i) - '0') + (b.charAt(i) - '0') + carry;
            if (total == 3) {
                sum = "1" + sum;
                carry = 1;
            } else if (total == 2) {
                sum = "0" + sum;
                carry = 1;
            } else {
                sum = Integer.toString(total) + sum;
                carry = 0;
            }
        }
        return (carry == 1) ? "1" + sum : sum;
    }
}