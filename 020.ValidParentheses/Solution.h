/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(char &begin : s) {
            switch(begin) {
                case '(':
                case '[':
                case '{':   mystack.push(begin);
                            break;
                case ')':   if( !mystack.empty() && mystack.top() == '(' ) mystack.pop(); 
                            else return false;
                            break;
                case ']':   if( !mystack.empty() && mystack.top() == '[' ) mystack.pop(); 
                            else return false;
                            break;
                case '}':   if( !mystack.empty() && mystack.top() == '{' ) mystack.pop(); 
                            else return false;
                            break;
                default: ; // pass
            }
        }
        return mystack.empty();
    }
};