/**
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string str, ret;
        for(size_t i = 0; i < s.size() - 1; ++i) {
            str = palindromeStr(s, i, i);
            if(str.size() > ret.size()) ret = str;
            
            str = palindromeStr(s, i, i + 1);
            if(str.size() > ret.size()) ret = str;
        }
        return ret;
    }
    string palindromeStr(string s, int left, int right) {
        size_t sz = s.size();
        while(left >= 0 && right < sz && s[left] == s[right]) {
            --left;
            ++right;
        }
        return s.substr(left + 1, right - left - 1);
    }
};