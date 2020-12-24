//Priority queue


#include<iostream>
using namespace std;

class item
{
public:
    int item_no,priority;
    item()
    {
        item_no = 0;
        priority=0;
    }
    bool operator <=(const item &a)
    {
        if(priority<=a.priority)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator ==(const item &a)
    {
        if(priority==a.priority)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator <(const item &a)
    {
        if(priority==a.priority)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend class Queue;
};

class Queue
{

public:
    int front,rear;
    item *queue=new item[5];
    int s = 5;

    Queue()
    {
        front=rear=-1;
    }
    bool isFull(){
        return (rear == s-1 && front==0);
    }

    bool isEmpty(){
        if (front >rear || (front==-1 && rear == -1)){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(item i)
    {
        if(isFull())
        {
            cout<<"queue is full!"<<endl;
        }
        else if(isEmpty())
        {
            front=0;
            rear=0;
            queue[rear]=i;
            cout<<"element added!"<<endl;
            display();
        }
        else
        {
            rear=rear+1;
            int j=rear-1;
            int flag = 0;
            while(queue[j]<=i && j>=0)
            {
                if(queue[j]==i){
                    flag = 1;
                    cout<<"elements with same priority not allowed!"<<endl;
                    rear=rear-1;
                    break;
                }
                if(queue[j].priority>0){
                    queue[j+1]=queue[j];
                    j=j-1;
                }
                if(queue[j].priority==0){
                    flag = 1;
                    queue[j+1] = i;
                    break;
                }
            }

            if(flag==0){
                queue[j+1]=i;
                cout<<"element added!"<<endl;
            }
            display();
        }
    }

    void dequeue()
    {

        if(isEmpty()){
            cout<<"cannot delete, queue is empty!"<<endl;
        }
        else if(front==0 && rear==0){
            front=-1;
            rear=-1;
        }
        else{
            queue[front].item_no = 0;
            queue[front].priority = 0;
            front = front+1;
            cout<<"deleted!"<<endl;

        }
        display();
    }

    void display()
    {

            for(int i=front;i<=rear;i++)
            {
                cout<<"("<<queue[i].item_no<<","<<queue[i].priority<<")"<<endl;
            }
        }
};

int main()
{

    item p;
    Queue q;
    int ch=0;
    while(ch!=4)
    {
        cout<<"1.Add\n2.delete\n3.Display\n4.Exit"<<endl;
        cout<<"Enter your choice-"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            if(q.isFull())
            {
                cout<<"queue is full!"<<endl;
            }
            else{
                item a;
                cout<<"Enter item no.: "<<endl;
                cin>>a.item_no;
                cout<<"Enter priority > 0: "<<endl;
                cin>>a.priority;
                if(a.priority<=0){
                    cout<<"enter a priority greater than 0!"<<endl;
                    continue;
                }
                q.enqueue(a);
           }
        }
            break;
        case 2:
        {
            q.dequeue();
        }
            break;
        case 3:
        {
            if(q.isEmpty()){
                cout<<"queue is empty"<<endl;
            }
            else{
                q.display();
            }
        }
            break;
        case 4:
        {
            cout<<"thank you!"<<endl;
        }
            break;

        default:
        {
            cout<<"invalid input!"<<endl;
        }
        }
    }

    return 0;
}