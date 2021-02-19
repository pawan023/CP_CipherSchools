//1> Queue using array

class MyQueue {
private:
    int arr[10001];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

rear=front=0;

void MyQueue :: push(int x)
{
        arr[rear++] = x;
}

int MyQueue :: pop()
{
        if(rear==front) return -1;
        return arr[front++];
}

//2> Queue using Linked List

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};

void MyQueue:: push(int x)
{
    QueueNode* newnode=new QueueNode(x);
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL)
    {
        front=newnode
        rear=newnode;                                             
        return;
    }   
    rear->next=newnode;
    rear=newnode;
    
}

int MyQueue :: pop()
{       if(front==NULL) return -1;
        if(front==rear) 
        {
            int num=front->data;
             delete(front);
              front=NULL;
              rear=NULL;
             return num;
        }
        QueueNode* temp=front;
        int num=front->data;
        front=front->next;      
        delete(temp);
        return num;
        
}

