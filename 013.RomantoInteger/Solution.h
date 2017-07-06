/**
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = {  {'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000} };
        
        auto begin=s.cbegin();
        auto end=s.cend();
        int x=0, pre=0, curr=0;
        while (begin != end) {
            curr=T[*begin];
            if(pre < curr) x += curr - 2*pre;
            else x += curr;
            pre = curr;
            ++begin;
        }
        return x;
    }
};