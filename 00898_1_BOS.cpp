/**
 * @file 00898_1_BOS.cpp
 * @brief 超时
 * @author Zerorlis
 * @version 0.1
 * @date 2019-03-31
 */

#include <array>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        // 初始化了一个全是-1的二维数组,大小A.size()*A.size()
        vector<vector<int>> two_Array(A.size(), vector<int>(A.size(), -1));
        unordered_set<int> result;
        result.reserve(A.size() * A.size() / 2);
        getSeq(two_Array, A, 0, A.size() - 1, result);
        return result.size();
    }
    int getSeq(vector<vector<int>>& two_Array, vector<int>& A, int i, int j,
               unordered_set<int>& result) {
        if (two_Array[i][j] != -1) {
            return two_Array[i][j];
        }
        if (i == j) {
            two_Array[i][j] = A[i];
        }
        if (i > j) {
            // [i][j] = [i-1][j] | [i+1][j];
            two_Array[i][j] = getSeq(two_Array, A, i, j - 1, result) |
                              getSeq(two_Array, A, i + 1, j, result);
        }
        // 到这一步，代表产生了一个新的结果，把结果给丢到set中
        result.insert(two_Array[i][j]);
        return two_Array[i][j];
    }
};
