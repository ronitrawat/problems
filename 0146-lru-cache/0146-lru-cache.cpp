class LRUCache {
public:
    class Node{
      public :
        Node* next;
        Node* prev;
        int val;
        int k;
        
        
           Node(int key,int value){
            k=key;
            val=value;
            next=prev=NULL;

        }
    };
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }

    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;

    }

    void insert(Node* node){
        head->next->prev=node;
        node->next=head->next;
        head->next=node;
        node->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* temp=m.find(key)->second;
            remove(temp);
            insert(temp);
            return temp->val;
                    }
         return -1;         
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* temp=m.find(key)->second;
            temp->val=value;
            
            remove(temp);
            insert(temp);
            
                    }
        else{
            Node* temp=new Node(key,value);
            insert(temp);
            m[key]=temp;
            if(m.size()>cap){
                Node* lru=tail->prev;
                remove(lru);
                m.erase(lru->k);
                delete(lru);

            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */