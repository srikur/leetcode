class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 1) return (nums[0] == target) ? 0 : -1;
        int value = recurse(nums, 0, nums.length - 1, target);
        return value;
    }

    private int recurse(int[] nums, int start, int end, int target) {
        if (start == end) return (nums[start] == target) ? start : -1;
        int pivot = (end - start) / 2;
        int leftVal = recurse(nums, start, start + pivot, target);
        int rightVal = recurse(nums, start + pivot + 1, end, target);
        return (leftVal + rightVal != -2) ? ((leftVal == -1) ? rightVal : leftVal) : -1;
    }
}