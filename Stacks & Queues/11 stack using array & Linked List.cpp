//1> stack using array

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

void MyStack :: push(int x)
{
    arr[++top]=x;
}

int MyStack :: pop()
{
    if(top==-1) return -1;
    return arr[top--];
}


//2> Stack using Linked List 

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

void MyStack ::push(int x) {
    StackNode *temp = new StackNode(x);
    if(top==NULL)  top=temp;
    else{
        temp->next = top;
        top = temp;
    }
}

int MyStack ::pop() {
    if(top==NULL) return -1;
    StackNode *temp = top;
    int data = top->data;
    top = top->next;
    delete(temp);
    return data;
}

