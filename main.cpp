#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cmath>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)



int main() {
    vector<vector<int>> matrix = {
            {1, 1}
//            {1,   4,  7, 11, 15},
//            {2,   5,  8, 12, 19},
//            {3,   6,  9, 16, 22},
//            {10, 13, 14, 17, 24},
//            {18, 21, 23, 26, 30}
    };
    Solution* s = new Solution();
    cout<<s->findNumberIn2DArray(matrix, 5)<<endl;
    return 0;
}















