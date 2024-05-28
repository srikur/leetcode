class Solution {
    public int maxSubArray(int[] nums) {
        int[] localMaxes = new int[nums.length];
        int previousTerm = 0;
        for (int i = 0; i < nums.length; i++) {
            localMaxes[i] = Math.max(previousTerm + nums[i], nums[i]);
            previousTerm = localMaxes[i];
        }
        int globalMax = localMaxes[0];
        for (int i = 0; i < localMaxes.length; i++) {
            if (localMaxes[i] > globalMax) globalMax = localMaxes[i];
        }
        return globalMax;
    }
}