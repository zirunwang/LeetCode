#include <iostream>
#include <vector>
#include <string>
#include "solution.h"
using namespace std;

int main() {
    const char* sc[]={"abab","aba","abc"};
    vector<string> strs(sc, sc + 3);
    Solution s;
    string sol = s.longestCommonPrefix(strs);
    cout << sol << endl;

    return 0;
}