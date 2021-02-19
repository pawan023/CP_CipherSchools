// Implement (stack|queue) using (queue|stack)

//1> Queue using two Stacks

class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; 

void StackQueue :: push(int x) {
    s1.push(x);
}

int StackQueue :: pop() {
    if(s2.empty()){
        if(s1.empty()) return -1;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    int front=s2.top();
    s2.pop();
    return front;
}

//2> Stack using two queues 

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};

void QueueStack :: push(int x)
{
    q1.push(x);
}

int QueueStack :: pop()
{
    if(q1.empty()) return -1;
        int pop_till=q1.size()-1;
        while(pop_till--){
            q2.push(q1.front());
            q1.pop();
        }
        int front=q1.front();
        q1.pop();
        swap(q1,q2);
        return front;
}
