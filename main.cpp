#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

//1    5    9
//10   11   13
//12   13   15

int main() {
    class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            priority_queue<int, vector<int>, greater<int>> q;
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    q.push(matrix[i][j]);
                }
            }
            int n = matrix.size()*matrix[0].size();
            int ans;
            while (k--) {
                ans = q.top();
                q.pop();
            }
            return ans;
        }
    };
    Solution* s = new Solution();
    vector<vector<int>> matrix = {{1,5,9},
                                  {10,11,12},
                                  {12,13,15}};
    cout<<s->kthSmallest(matrix, 8);
    return 0;
}
