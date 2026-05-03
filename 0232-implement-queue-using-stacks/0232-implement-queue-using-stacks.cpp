class MyQueue {
public:


    stack<int> a;
    stack<int> b;

    MyQueue() {
       
    }
    
    void push(int x) {
    a.push(x);    
    }
    
    int pop() {
    while(!a.empty()){
        int x=a.top();
        a.pop();
        b.push(x);
    }
    int y=b.top();
    b.pop();    
    while(!b.empty()){
        int x=b.top();
        b.pop();
        a.push(x);
    }
     return y;
    }

    
    int peek() {
         while(!a.empty()){
        int x=a.top();
        a.pop();
        b.push(x);
    }
    int y=b.top();
      
    while(!b.empty()){
        int x=b.top();
        b.pop();
        a.push(x);
    }
     return y;
    }
    
    bool empty() {
        return a.empty();
        }
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */