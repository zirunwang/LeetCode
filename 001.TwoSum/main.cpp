#include <iostream>
#include <vector>
#include "solution.h"

int main() {
    Solution s;
    vector<int> v{2,3,4};
    auto sol = s.twoSum(v, 6);
    for (int &c : sol)
        std::cout << c << std::endl;

    return 0;
}