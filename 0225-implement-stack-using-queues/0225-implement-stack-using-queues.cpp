class MyStack {
public:
    queue<int>q1;
    // queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
        // while(q1.size()>0){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // q1.push(x);
        // while(q2.size()>0){
        //     q1.push(q2.front());
        //     q2.pop();
        // }
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
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