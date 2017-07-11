/**
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        int n = nums.size();
        if(n < 4) return ret;
        sort(nums.begin(), nums.end());
        //refer to the 3Sum's Solution
        //use i,j take the place of i
        for(int i = 0; i < n - 3; i++) {
            //判断当前锚点是否可能
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;   //min > target
            if(nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;//max < target
            for(int j = i + 1; j < n - 2; j++) {
                //判断当前锚点是否可能
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if(nums[i] + nums[j] + nums[j + 2] + nums[j + 3] > target) break;   //min > target
                if(nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;//max < target
                //
                int left = j + 1;
                int right = n - 1;
                while(left < right) {
                    int curr = nums[i] + nums[j] + nums[left] + nums[right];
                    if(curr < target) ++left;
                    else if(curr > target) --right;
                    else {
                        vector<int> vec = {nums[i], nums[j], nums[left], nums[right]};
                        ret.push_back(vec);
                        
                        while(left < right && vec[2] == nums[left]) ++left;
                        while(left < right && vec[3] == nums[right]) --right;
                    }
                }
            }
        }
        return ret;
    }
};