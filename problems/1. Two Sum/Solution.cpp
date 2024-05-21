class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement) > 0 && map[complement] != i) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {0, 0};
    }
};