class MyStack {
public:
    MyStack() {
        
    }
    queue<int> a;
    queue<int> b;

    void push(int x) {
    b.push(x);
    while(!a.empty()){
        int c=a.front();
        a.pop();
        b.push(c);
    } 
    while(!b.empty()){
        int c=b.front();
        b.pop();
        a.push(c);
    }
    }
    
    int pop() {
      int c=a.front();
      a.pop();
      return c;
    }
    
    int top() {
      return  a.front();
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */