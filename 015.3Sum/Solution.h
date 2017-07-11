/**
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int temp = nums[left] + nums[right];
                if(temp > target) --right;
                else if(temp < target) ++left;
                else {
                    vector<int> vec(3);
                    vec[0] = nums[i];
                    vec[1] = nums[left];
                    vec[2] = nums[right];
                    ret.push_back(vec);
                    
                    while(left < right && vec[1] == nums[left]) ++left;
                    while(left < right && vec[2] == nums[right]) --right;
                }
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        }
        
        return ret;
    }
};