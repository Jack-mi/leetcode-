struct DLinkedNode {
    int k, v;
    DLinkedNode* prev, *next;
    DLinkedNode():k(0), v(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _k, int _v):k(_k), v(_v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head, *tail;
    int size;
    int capacity;

public:
    LRUCache(int capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;
        DLinkedNode* tar = cache[key];
        moveToHead(tar);
        return tar->v;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            DLinkedNode* tar = cache[key];
            tar->v = value;
            moveToHead(tar);
        } else {
            DLinkedNode* b = new DLinkedNode(key, value);
            cache[key] = b;
            if (size < capacity) {
                size++;
            } else {
                DLinkedNode* node = removeTail();
                cache.erase(node->k);
                delete node;
            }
            addToHead(b);
        }
    }

    DLinkedNode* removeTail() {
        DLinkedNode* tp = tail->prev;
        deleteNode(tp);
        return tp;
    }

    void deleteNode(DLinkedNode* tar) {
        DLinkedNode* p = tar->prev;
        DLinkedNode* n = tar->next;
        p->next = n;
        n->prev = p;
    }

    void addToHead(DLinkedNode* tar) {
        DLinkedNode* hn = head->next;
        tar->prev = head;
        tar->next = hn;
        head->next = tar;
        hn->prev = tar;
    }

    void moveToHead(DLinkedNode* tar) {
        deleteNode(tar);
        addToHead(tar);
    }
};
