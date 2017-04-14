/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
    	if (strs.size()==0) return prefix;

    	for (int i=0; i<strs[0].size(); ++i) {
    	    int j;
    		for (j=1; j<strs.size() && strs[j].size()>i; ++j) {
    			if (strs[0][i] != strs[j][i])
    				return prefix;
    		}
    		if (j == strs.size()) prefix += strs[0][i];
		
    	}
    	return prefix;
    }
};