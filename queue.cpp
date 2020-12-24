//Queues are frequently used in computer programming, and a typical example is the
//creation of a job queue by an operating system. If the operating system does not use
//priorities, then the jobs are processed in the order they enter the system. Write C++
//program for simulating job queue. Write functions to add job and delete job from queue. (not circular)

#include<iostream>
using namespace std;

class queue{
private:
    int arr[5];
    int s = 5;

public:
    int front = -1;
    int rear = -1;
    queue(){
        for(int i=0;i<5;i++){
            arr[i] = 0;
        }
    }
    bool isFull(){
          return rear==s-1;
    }
    bool isEmpty(){
        if (front == -1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int e){
        if(rear == s-1){
            cout<<"queue is full!"<<endl;
        }
        else if(isEmpty()){
            front = 0;
            rear = 0;
            arr[rear]= e;
            display();
        }
        else{
            rear = rear+1;
            arr[rear]= e;
            display();
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"cannot delete, queue is empty!"<<endl;
            display();
        }
        else if(front==rear){
            arr[front] = 0;
            front=-1;
            rear=-1;
            display();
        }
        else{
            arr[front] = 0;
            //front = (front+1)%s;
            front = front+1;
            cout<<"is deleted!"<<endl;
            display();
        }
    }


    void Front(){
        if(!isEmpty()){
            cout<<"ID"<<arr[front];
        }
        else{
            cout<<"queue is empty"<<endl;
        }
    }

    void display(){
        int i = s-1;
        while(i>=0){
            cout<<arr[i]<<" ";
            i--;
        }
        cout<<endl;
    }

};

int main()
{
    queue q;
    while(1){

        int ch;
        cout<<"press 1. to insert\npress 2. to delete\npress 3. to display\npress 4. to quit\n"<<endl;
        cin>>ch;
        if(ch==1){
            if(!q.isFull()){
                int id;
                cout<<"enter integer job ID: "<<endl;
                cin>>id;
                q.enqueue(id);
            }
            else{
                cout<<"queue is full!"<<endl;
            }
        }
        if(ch==2){
            q.dequeue();
        }
        if(ch==3){
            q.display();
        }
        if(ch==4){
            cout<<"thank you!"<<endl;
            break;
        }
    }

    return 0;
}
