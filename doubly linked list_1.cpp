//Write C++ program for storing binary number using doubly linked lists. Write functions-
//a) To compute 1‘s and 2‘s complement
//b) Add two binary numbers

#include <iostream>
#include <math.h>
using namespace std;

class node{
    int data;
    node* next;
    node* prev;
    friend class dll;
    friend class binary;
};

class dll{
private:
node* head = NULL;
public:
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
    void Print(){
            node* temp = head;
            while(temp !=NULL){

                cout<<temp->data;
                temp = temp->next;
            }
            cout<<endl;
        };
        void Print_reverse(){
            node* temp = head;
            if(temp == NULL){
                return;
            }
            while(temp->next != NULL){
                temp = temp->next;
            }
            cout<<"reverse ";
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->prev;
            }
            cout<<endl;
        };
        friend class binary;
};

class binary{
public:
    dll generateBinary(int dec){
        int n1 = dec;
        dll binaryDLL;
        while(n1>-1){
            binaryDLL.begin(n1%2);
            n1 = n1/2;
            if(n1==1){
                binaryDLL.begin(n1);
                break;
            }
        };
        return binaryDLL;

    };
    dll addBinary(int dec1, int dec2){
        dll add_b;
        binary bin;
        int add_d = dec1 + dec2;
        add_b = bin.generateBinary(add_d);
        return add_b;

    };
    dll onesComplement(int dec1){
        binary bin;
        dll dll_bin = bin.generateBinary(dec1);
        //dll_bin.Print();
        dll dll_bin_1scomplement = dll_bin;
        node* temp;
        temp = dll_bin_1scomplement.head;
        while(temp!=NULL){
            if(temp->data == 0){
                temp->data = 1;
            }
            else{
                temp->data = 0;
            }
            temp = temp->next;
       }
        return dll_bin_1scomplement;
    };
    dll twosComplement(int dec){
        //finding onesCompl of no., then converting it to decimal adding 1 to it and then generating binary thus getting 2s complement
        binary bin1;
        dll onesCompl = bin1.onesComplement(dec);  //onesCompl
        node* temp = onesCompl.head;
        int c = 0, n = 0;
        while(temp->next!=NULL){
            temp = temp->next;
        }                          //traversing till end
        while(temp->prev!=NULL){          //traversing to start while calculating decimal value(of 1sCompl) by multiplting by 2^0, 2^1, 2^2, 2^3...
            n = n + ((temp->data) * pow(2, c));
            c++;
            temp = temp->prev;
        }
        n = n + 1;         //adding 1 to decimal thus finding decimal form(of 2sCompl)
        binary bin2;
        return bin2.generateBinary(n); //generating binary from dec form of 2s complement
    };

};
int main()
{

    while(1){
        int choice;
        cout<<"press 1. to generate binary from decimal"<<endl<<"press 2. to add numbers"<<endl<<"press 3. to find 1s Complement"<<endl<<"press 4. to find 2s Complement"<<endl<<"press 5. to quit"<<endl;
        cin>>choice;
        if(choice==1){
           int dec;
           cout<<"enter no.: "<<endl;
           cin>>dec;
           binary bin;
           cout<<"binary form: ";
           bin.generateBinary(dec).Print();
           cout<<endl;
        }
        if(choice==2){
            //add
            int dec1, dec2;
            binary bin1, bin2, bin3;
            cout<<"enter 1st no: ";
            cin>>dec1;
            cout<<"binary form: "<<" ";
            bin1.generateBinary(dec1).Print();
            cout<<"enter 2nd no: ";
            cin>>dec2;
            cout<<"binary form: "<<" ";
            bin2.generateBinary(dec2).Print();
            cout<<"addition in dec: "<<dec1+dec2<<endl;
            cout<<"addition in binary: ";
            bin3.addBinary(dec1, dec2).Print();
            cout<<endl;
        }
        if(choice==3){
            //ones complement
            int dec;
            cout<<"enter decimal no.: "<<endl;
            cin>>dec;
            binary bin;
            cout<<"binary form: ";
            bin.generateBinary(dec).Print();
            cout<<"onesComplement: ";
            bin.onesComplement(dec).Print();
            cout<<endl;
        }
        if(choice==4){
            //twos complement
            int dec;
            cout<<"enter decimal no.: "<<endl;
            cin>>dec;
            binary bin;
            cout<<"binary form: ";
            bin.generateBinary(dec).Print();
            cout<<"twosComplement: ";
            bin.twosComplement(dec).Print();
            cout<<endl;
        }
        if(choice==5){
            cout<<"thank you!"<<endl;
            break;
        }
    }
    return 0;
}