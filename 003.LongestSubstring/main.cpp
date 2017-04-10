#include <iostream>
#include <string>
#include "solution.h"

int main() {
    Solution s;
    std::string str3     = "";
    std::string str     = "c";
    std::string str1    = "pwwkew";
    std::string str2    = "bbbbbbbb";
    //s.lengthOfLongestSubstring(str);
    std::cout << str + "'s length is:'" << std::endl;
    std::cout << s.lengthOfLongestSubstring(str) << std::endl;
    std::cout << s.lengthOfLongestSubstring(str1) << std::endl;
    std::cout << s.lengthOfLongestSubstring(str2) << std::endl;
    std::cout << s.lengthOfLongestSubstring(str3) << std::endl;

    return 0;
}