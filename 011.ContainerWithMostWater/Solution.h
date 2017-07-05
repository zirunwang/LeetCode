/**
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int left = 0, right = height.size() - 1;
        
        while(left < right) {
            int h = min(height[left], height[right]);
            water = max(water, h * (right - left));
            //reduce width but h must increase
            //aim to increase the min edge ( = h)
            // while(height[left] <= h && left < right) left++;
            // while(height[right] <= h && left < right) right--;
            height[left] < height[right] ? left++ : right--;
        }
        return water;
    }
};