//A double-ended queue (deque) is a linear list in which additions and deletions may be 
//made at either end. Obtain a data representation mapping a deque into a one-dimensional array. Write C++ program to simulate deque with functions to add and 
//delete elements from either end of the deque.

#include<iostream>
#include<math.h>
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
        return (rear == s-1 && front==0);
    }
    bool isEmpty(){
        if (front == -1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue_r(int e){
        if(rear == s-1){
            cout<<"cannot add elements from the rear end!"<<endl;
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
    void enqueue_f(int e){
        if(front==0){
            cout<<"rear: "<<rear<<endl;
            int j = rear;
            while(j>=front){
                arr[j+1] = arr[j];
                j--;
            }
            arr[front] = e;
            rear++;
            display();
        }
        else if(isEmpty()){
            front = 0;
            rear = 0;
            arr[front]= e;
            display();
        }
        else{
            front = front - 1;
            arr[front]= e;
            display();
        }
    }

    void dequeue_f(){
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
            front = front+1;
            cout<<"is deleted!"<<endl;
            display();
        }
    }
    void dequeue_r(){
        if(isEmpty()){
            cout<<"cannot delete, queue is empty!"<<endl;
        }
        else if(front==rear){
            arr[front] = 0;
            front=-1;
            rear=-1;
            display();
        }
        else{
            arr[rear] = 0;
            rear = rear-1;
            cout<<"is deleted!"<<endl;
            display();
        }
    }

    void Front(){
        if(!isEmpty()){
            cout<<"ID"<<arr[front];
            display();
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
        cout<<"press 1. to insert from front\npress 2. to insert from back\npress 3. to delete from front\npress 4. to delete from back\npress 5. to display\npress 6. to quit\n"<<endl;
        cin>>ch;
        if(ch==1){
            if(!q.isFull()){
                int id;
                cout<<"enter integer job ID: "<<endl;
                cin>>id;
                q.enqueue_f(id);
            }
            else{
                cout<<"queue is full!"<<endl;
            }
        }
        if(ch==2){
            if(!q.isFull()){
                int id;
                cout<<"enter integer job ID: "<<endl;
                cin>>id;
                q.enqueue_r(id);
            }
            else{
                cout<<"queue is full!"<<endl;
            }
        }
        if(ch==3){
            q.dequeue_f();
        }
        if(ch==4){
            q.dequeue_r();
        }
        if(ch==5){
            q.display();
        }
        if(ch==6){
            cout<<"thank you!"<<endl;
            break;
        }
    }

    return 0;
}
