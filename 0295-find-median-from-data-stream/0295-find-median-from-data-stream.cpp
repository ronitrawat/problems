class MedianFinder {
public:
    priority_queue<int>leftMax;
    priority_queue<int,vector<int>,greater<int>>rightMin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    if(leftMax.empty() || num<=leftMax.top()){
        leftMax.push(num);
    }
    else{
        rightMin.push(num);
    }
    if(leftMax.size()>rightMin.size()+1){
        int a =leftMax.top();
        leftMax.pop();
        rightMin.push(a);
    }
    else if(rightMin.size()>leftMax.size()+1){
         int a =rightMin.top();
        rightMin.pop();
        leftMax.push(a);
    }
    }
    
    double findMedian() {
        if(leftMax.size()==rightMin.size()){
            return (leftMax.top()+rightMin.top())/2.0;

        }
        else if (leftMax.size()>rightMin.size()){
            return leftMax.top();
        }
        else{
            return rightMin.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */