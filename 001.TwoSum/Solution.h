#include<vector>
#include<map>
using namespace std;    //map是STL容器中的一种，属于关联性容器.此处必须声明

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> result;
        int i, tofind;
        int nums_size = nums.size();
        
        m[nums[0]] = 0;
        for (i=1; i<nums_size; i++) {
            tofind = target-nums[i];
            if (m.find(tofind) == m.end()) {
                 //std::cout<<"There is no result!"<<std::endl;
                 m[nums[i]] = i;
            }
            else {
                result.push_back(m[tofind]);
                result.push_back(i);
            }
        }
        return result;
    }
};