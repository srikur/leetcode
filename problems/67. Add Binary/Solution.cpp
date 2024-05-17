class Solution {
public:
    string addBinary(string a, string b) {
        int lengthDiff = std::abs((int)a.length() - (int)b.length());
        if (a.length() < b.length()) a = string(lengthDiff, '0') + a;
        if (b.length() < a.length()) b = string(lengthDiff, '0') + b;
        int carry = 0;
        string ret = "";
        for (int i = a.length() - 1; i >= 0; i--) {
            int total = (a[i] - '0') + (b[i] - '0') + carry;
            if (total == 3) {
                ret = "1" + ret;
                carry = 1;
            } else if (total == 2) {
                ret = "0" + ret;
                carry = 1;
            } else {
                ret = to_string(total) + ret;
                carry = 0;
            }
        }
        return (carry == 1) ? "1" + ret : ret;
    }
};