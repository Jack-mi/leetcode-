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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> board;
    int vis[101][101];
    int M, N;
    int ans;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    using node = pair<int, int>;
    queue<node> q;

    void bfs(int x, int y, int step) {
        vis[0][0] = 1;
        q.push(node(0, 0));
        while (!q.empty()) {
            node cur = q.front();
            q.pop();
            ans ++;
            for (int i = 0; i < 4; ++i) {
                int nx = cur.first+dir[i][0];
                int ny = cur.second+dir[i][1];
                // out-of-border
                if (nx<0 || nx>=M || ny<0 || ny>=N)
                    continue;
                // vis
                if (vis[nx][ny])
                    continue;
                // forbidden
                if (board[nx][ny] == 0)
                    continue;
                vis[nx][ny] = 1;
                q.push(node(nx, ny));
            }
        }
    }
    int movingCount(int m, int n, int k) {
        M = m;
        N = n;
        board.resize(m);
        for (int i = 0; i < m; ++i) {
            board[i].resize(n);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                int a, b;
                if (i < 10) {
                    a = i;
                } else {
                    int p = i/10;
                    int q = i-10*p;
                    a = p+q;
                }
                if (j < 10) {
                    b = j;
                } else {
                    int p = j/10;
                    int q = j-10*p;
                    b = p+q;
                }
                sum = a+b;
                if (sum <= k)
                    board[i][j] = 1;
//                cout<<board[i][j];
            }
//            cout<<endl;
        }
        bfs(0, 0, 1);
        return ans;
    }
};

int main() {
    vector<int> num = {2,2,2,0,1};
    vector<vector<char>> matrix = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    Solution* s = new Solution();
    string c = "ABCB";
    cout<<s->movingCount(3, 2, 17);
    return 0;
}















