class Solution {
public:
    char arr[30009];
    string replaceSpace(string s) {
        int idx = 0;
        for (auto c:s) {
            if (c == ' ') {
                arr[idx++] = '%';
                arr[idx++] = '2';
                arr[idx++] = '0';
            } else {
                arr[idx++] = c;
            }
        }
        string ans(arr);
        return ans;
    }
};