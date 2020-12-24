//Write a C++ program to implement following operations on DLL of integer
//1) Insert at endt 2) Insert before any element 3) Display all 4) Display odd
//numbers from list 5) Delete specific element.

#include<iostream>
using namespace std;

class node{
    int data;
    node* next;
    node* prev;
    friend class dll;
};

class dll{
private:
node* head = NULL;
public:
    bool isEmpty(){
        return(head == NULL);
    }
    node* createNode(int val){
        node* new_node = new node();
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = NULL;
        return new_node;
    }
    void begin(int val){
        node* temp = createNode(val);
        if(head == NULL){
            head = temp;
            return;
        }
        head->prev = temp;
        temp->next = head;
        head = temp;

    };
    void append(int val){
        node* temp1 = createNode(val);
        node* temp2 = head;
        while(temp2->next!=NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        temp1->next = NULL;
        temp1->prev = temp2;
    };
    int count(){
        node* temp1 = head;
        int c = 0;
        while(temp1!=NULL){
            c++;
            temp1 = temp1->next;
        }
        return(c);
    }
    void insert(int val, int n){
        int c = count();
        node* temp1 = createNode(val);
        node* temp2 = head;
        if(n == 1){
            if(head==NULL){                //insert at pos 1 when list is empty
                begin(val);
                return;
            }
            else{                        //insert at pos 1 when list is not empty
                temp1->next = head;
                head->prev = temp1;
                head = temp1;
            }
        }
        else if(n<=c){                         //inserting in between
            for(int i=0; i<n-2; i++){
                temp2 = temp2->next;
            }
            temp1->next = temp2->next;
            node* temp3 = temp2->next;
            temp3->prev = temp1;
            temp2->next = temp1;
            temp1->prev = temp2;
        }
        else if(n>c || n==0){                             //invalid pos
            cout<<"invalid position!"<<endl;
        }
        Print();

    };
    void remove(int val){
        node* temp1 = head;
        int flag =0;
        while(temp1!=NULL){                      //traversing to find element
            if(temp1->data == val){
                flag =1;
                break;
            }
            temp1 = temp1->next;
        }
        if(flag==1){
            if(temp1->prev == NULL){                    //delete 1st element
                node*temp = temp1->next;
                temp->prev=NULL;
                head = temp;
                return;

            }
            if(temp1->next == NULL){                   //delete last element
                node* prev= temp1->prev;
                prev->next = NULL;
            }
            else{                                      //delete element in between
                node* prev = temp1->prev;
                node* next = temp1->next;
                prev->next = next;
                next->prev = prev;
            }
            temp1->next = NULL;
            temp1->prev = NULL;
            temp1->data = 0;
        }
        else{
            cout<<"element to be deleted is not present in the list"<<endl;
        }
    }
    void Print(){
            node* temp = head;
            while(temp !=NULL){
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<endl;
        };
    void Print_odd(){
            node* temp = head;
            while(temp !=NULL){
                if(temp->data % 2!=0){
                    cout<<temp->data<<"\t";
                }
                temp = temp->next;
            }
            cout<<endl;
        };
};

int main()
{

    dll d1;
    while(1){
        cout<<"press 1. to insert at start\npress 2. to insert at end\npress 3. to insert in between\npress 4. to display all elements\npress 5. to display odd elements\npress 6. to delete a specific element\npress 7. to quit"<<endl;
        int ch;
        cout<<"enter choice: "<<endl;
        cin>>ch;
        if(ch==1){
            int n;
            cout<<"enter element to insert it at start: "<<endl;
            cin>>n;
            d1.begin(n);
            cout<<endl;
        }
        if(ch==2){
            int n;
            cout<<"enter element to insert it at end: "<<endl;
            cin>>n;
            d1.append(n);
            cout<<endl;
        }
        if(ch==3){
            int n, pos;
            cout<<"enter element to insert it at a specific position: "<<endl;
            cin>>n;
            cout<<"enter position: "<<endl;
            cin>>pos;
            d1.insert(n, pos);
            cout<<endl;
        }
        if(ch==4){
            d1.Print();
            cout<<endl;
        }
        if(ch==5){
            d1.Print_odd();
            cout<<endl;
        }
        if(ch==6){
            if(d1.isEmpty()){
                continue;
                cout<<"list is empty!"<<endl;
                continue;
            }
            int n;
            cout<<"enter element to delete: "<<endl;
            cin>>n;
            d1.remove(n);
            d1.Print();
            cout<<endl;
        }
        if(ch==7){
            cout<<"thank you!"<<endl;
        }
    }
    return 0;
}
