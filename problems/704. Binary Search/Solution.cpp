class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return (nums[0] == target) ? 0 : -1;
        int value = recurse(nums, 0, nums.size() - 1, target);
        return value;
    }

    int recurse(vector<int>& nums, size_t start, size_t end, int& target) {
        if (start == end) return (nums[start] == target) ? start : -1;
        size_t pivot = (end - start) / 2;
        int leftRet = recurse(nums, start, start + pivot, target);
        int rightRet = recurse(nums, start + pivot + 1, end, target);
        if (leftRet != -1) return leftRet;
        if (rightRet != -1) return rightRet;
        return -1;
    }
};