// 1.用STL的sort对vector进行排序
class Solution {
public:
    using value_t = pair<int, int>;
    struct cmp {
        bool operator() (const value_t& t1, const value_t& t2) {
            return t1.second > t2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int n:nums) count[n]++;
        vector<int> res;
        /*
         * 关键此处：在unordered_map的基础上建立一个vector
         * 然后对此vector排序，再取前k个
         * */
        vector<value_t> v(count.begin(), count.end());
        sort(v.begin(), v.end(), cmp());
        for (int i = 0; i < k; ++i) {
            res.push_back(v[i].first);
        }
        return res;
    }
};

// 2.priority_queue
class Solution {
public:
    using value_t = pair<int, int>;
    struct cmp {
        bool operator() (const value_t& t1, const value_t& t2) {
            return t1.second < t2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int n:nums) count[n]++;
        vector<int> res;
        /*
         * 关键此处：在unordered_map的基础上建立一个priority_queue
         * */
        priority_queue<value_t, vector<value_t>, cmp> q;
        for (auto itr = count.begin(); itr != count.end(); itr++) {
            q.push(*itr);
        }
        for (int i = 0; i < k; ++i) {
            auto tmp = q.top();
            q.pop();
            res.push_back(tmp.first);
        }
        return res;
    }
};