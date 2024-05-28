class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> localMaxes(nums.size());
        int previous = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            localMaxes[i] = std::max(previous + nums[i], nums[i]);
            previous = localMaxes[i];
        }
        return *max_element(localMaxes.begin(), localMaxes.end());
    }
};