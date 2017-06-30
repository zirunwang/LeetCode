/**
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
/*
 * no extra space be used!
 */
class Solution {
public:
    string convert(string s, int numRows) {
        string ret = "";
        size_t sz = s.size();
        if(sz <= 1 || numRows <= 1) return s;
        
        int nl = (sz + numRows - 1) / numRows; //number of loops
        int no = (numRows - 2) * 2 + 2; //number of one loop
        
        int n = 0;
        while(n < numRows) {
            //line: 0 ~ (numRows - 1)
            int count = 0;
            while(count < nl) {
                int index = count * no + n;
                if(index < sz) ret.append(1, s[index]);
                // 1 ~ (numRows - 2)
                if(n > 0 && n < numRows - 1) {
                    index = count * no + n + 2 * (numRows - n - 1);
                    if(index < sz) ret.append(1, s[index]);
                }
                ++count;
            }
            ++n;
        }
        return ret;
    }
};
    }
};