/**
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
 class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        //先以i为锚点，搜索可能的组合
        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            //判断当前区间是否可能
            int maxi = nums[i] + nums[right - 1] + nums[right];
            if(target > maxi) {
                if(abs(target - closest) > abs(target - maxi))
                    closest = maxi;
                continue;
            }
            //当前区间搜索
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return sum;
                if(abs(sum - target) < abs(closest - target))
                    closest = sum;
                if(sum < target) ++left;
                else --right;
            }
        }
        return closest;
    }
};