class BrowserHistory {
public:
    stack<string> forw;
    stack<string> backward;

    BrowserHistory(string homepage) {
    
    backward.push(homepage);    
    }
    
    void visit(string url) {
    while(!forw.empty()){
     forw.pop();
    }

    backward.push(url);
    }
    
    string back(int steps) {
        while(steps)
     if(backward.size()==1){
        steps=0;
        
    }
    else{
    forw.push(backward.top());
   
    backward.pop();
    steps--;
     
    }
    return backward.top();
    }
    
    string forward(int steps) {
    while(steps){
    if(forw.size()==0){
        steps=0;

    }
    else{
        backward.push(forw.top());
        forw.pop();
        steps--;
    }
    
    }return backward.top();}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */