class Solution {
public:
    void backtrack(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > start && nums[i] == nums[start]) continue;

            std::swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            std::swap(nums[start], nums[i]); // Backtrack
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end()); 
        backtrack(nums, 0, result);
        return result;
    }
};
