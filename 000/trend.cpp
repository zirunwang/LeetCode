/*
 * 给定升序排列的整形数组 a[n] 和整数 5，需要在数组中找出任意个下标，使之对应数字之和为 S
 * 输出所有可能下标组合
 * 1,4,8,10,12,15,22,25,31 S=30
 * 2,5 a[2]+a[5]=30
 * 0,1,3,4 a[0]+a[1]+a[3]+a[4]=30
 */
#include <iostream>
#include <vector>
#include <algorithm>    //find
using namespace std;

vector<vector<int>> vecs;
vector<vector<int>> indexs; //递归的方法无法在过程中确定下标
void recSearch(vector<int> data, unsigned int length, int sum, vector<int> v);

int searchNumbers(vector<int> data, unsigned int length, int sum)
{
    if (data.empty() || sum < 0) return 0;
    vector<int> v;
    recSearch(data, length, sum, v);
    for (auto begin = vecs.begin(); begin != vecs.end(); begin++) {
        vector<int> index;
        vector<int> temp(*begin);
        for (auto beg = temp.begin(); beg != temp.end(); beg++) {
            index.push_back( find(data.begin(), data.end(), *beg) - data.begin() );
            // cout << *beg << " ";
        }
        indexs.push_back(index);
        // cout << endl;
    }
    return 0;
}
// recursion
// could found data[] sum of index v[] = sum 
void recSearch(vector<int> data, unsigned int length, int sum, vector<int> v)
{
    vector<int> ret;
    if (sum < 0) return;
    if (sum == 0) {
        vecs.push_back(v);
        return;
    }
    for (auto begin = data.begin(); begin != data.end(); begin++) {
        vector<int> tdata(begin+1, data.end());
        v.push_back(*begin);
        recSearch(tdata, length - 1, sum - *begin, v);
        v.pop_back();
    }

}

int main()
{
    vector<int> data = {1,4,8,10,12,15,22,25,31};
    searchNumbers(data, 9, 30);
    // vector<int> v;
    // recSearch(data, 9, 30, v);
    // 所有数的组合
    for (auto begin = vecs.begin(); begin != vecs.end(); begin++) {
        vector<int> temp(*begin);
        for (auto beg = temp.begin(); beg != temp.end(); beg++) {
            cout << *beg << " ";
        }
        cout << endl;
    }
    // 对应所有数组合的下标
    for (auto begin = indexs.begin(); begin != indexs.end(); begin++) {
        vector<int> temp(*begin);
        for (auto beg = temp.begin(); beg != temp.end(); beg++) {
            cout << *beg << " ";
        }
        cout << endl;
    }
    return 0;   //main()返回数值 0~255 （若 -1 = 255）
}