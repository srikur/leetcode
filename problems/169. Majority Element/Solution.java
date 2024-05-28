class Solution {
    public int majorityElement(int[] nums) {
        if (nums.length == 1) return nums[0];
        int ans = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (count == 0) ans = nums[i];
            if (nums[i] == ans) count += 1;
            else count -= 1;
        }
        return ans;
    }
}