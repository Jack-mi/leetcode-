class CQueue {
public:
    stack<int> p, q;
    CQueue() {}

    void appendTail(int value) {
        p.push(value);
    }

    int deleteHead() {
        if (p.empty())
            return -1;
        while (!p.empty()) {
            int x = p.top();
            p.pop();
            q.push(x);
        }
        int ans = q.top();
        q.pop();
        while (!q.empty()) {
            int x = q.top();
            q.pop();
            p.push(x);
        }
        return ans;
    }
};