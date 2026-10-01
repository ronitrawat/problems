class Node {
public:
    int key, val, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        val = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;

        size++;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }
};

class LFUCache {
    int capacity;
    int curSize;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        keyNode.erase(node->key);

        freqList[node->freq]->removeNode(node);

        if (node->freq == minFreq &&
            freqList[node->freq]->size == 0) {
            minFreq++;
        }

        node->freq++;

        List* nextHigherFreqList;

        if (freqList.find(node->freq) != freqList.end()) {
            nextHigherFreqList = freqList[node->freq];
        } else {
            nextHigherFreqList = new List();
            freqList[node->freq] = nextHigherFreqList;
        }

        nextHigherFreqList->addFront(node);
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];
        int ans = node->val;

        updateFreq(node);

        return ans;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        if (curSize == capacity) {
            List* list = freqList[minFreq];

            Node* nodeToDelete = list->tail->prev;

            keyNode.erase(nodeToDelete->key);
            list->removeNode(nodeToDelete);

            curSize--;
        }

        curSize++;

        minFreq = 1;

        List* listFreq1;

        if (freqList.find(1) != freqList.end()) {
            listFreq1 = freqList[1];
        } else {
            listFreq1 = new List();
            freqList[1] = listFreq1;
        }

        Node* newNode = new Node(key, value);

        listFreq1->addFront(newNode);
        keyNode[key] = newNode;
    }
};