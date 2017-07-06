/**
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
 */
/*
I II III IV V VI VII VIII IX X : 1 ~ 10
//
I 1
V 5
X 10
L 50
C 100
D 500
M 1000
eg: 3999 MMMDCCCCLXXXXIX -> MMMCMXCIX
 */
class Solution {
    string intToStr(int num) {
        string sr = "";
        vector<string> M = {"M", "MM", "MMM"};  //1000
        vector<string> C = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};  //100
        vector<string> X = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};  //10
        vector<string> I = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};  //1
        int index = 0;
        if((index = num / 1000) != 0) {
            sr.append(M[index - 1]);
            num %= 1000;
        }
        if((index = num / 100) != 0) {
            sr.append(C[index - 1]);
            num %= 100;
        }
        if((index = num / 10) != 0) {
            sr.append(X[index - 1]);
            num %= 10;
        }
        if(num) sr.append(I[num - 1]);
        
        return sr;
    }
public:
    string intToRoman(int num) {
        return intToStr(num);
    }
};