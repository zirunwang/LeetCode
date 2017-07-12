/**
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty()) return ret;
        const vector<string> vecStr = {"", "", "abc", "def", "ghi", "jkl", "mno",
                                   "pqrs", "tuv", "wxyz"};
        ret.push_back("");
        for(int i = 0; i < digits.size(); ++i) {
            int num = digits[i] - '0';
            if(0 > num || num > 9) break;
            string currStr = vecStr[num];
            if(currStr.empty()) continue;
            
            vector<string> tmp;
            for(int t = 0; t < ret.size(); ++t) {
                 for(int j = 0; j < currStr.size(); ++j){
                    tmp.push_back(ret[t] + currStr[j]);
                }
            }
            swap(ret, tmp);
        }
        return ret;
    }
};