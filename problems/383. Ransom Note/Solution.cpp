class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::map<char, int> magazineMap;
        for (const char& ch : magazine) {
            magazineMap[ch] += 1;
        }
        for (const char& ch : ransomNote) {
            if (magazineMap.count(ch) == 0 || magazineMap[ch] == 0) return false;
            magazineMap[ch] -= 1;
        }
        return true;
    }
};