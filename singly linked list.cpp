//Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
//B of students like butterscotch ice-cream. Write C++ program to store two sets using
//linked list. compute and display-
//a) Set of students who like both vanilla and butterscotch
//b) Set of students who like either vanilla or butterscotch or not both
//c) Number of students who like neither vanilla nor butterscotch

#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    friend class linkedList;
};


class linkedList{
private:
Node* head = NULL;
public:
    void begin(int val){
        Node* temp1 = new Node();
        temp1->data = val;
        temp1->next = head;
        head = temp1;

    };

    void insert(int val, int n){
        Node* temp1 = new Node();
        temp1->data = val;
        temp1->next = NULL;
        Node* temp2 = head;
        for(int i=0; i<n-2; i++){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;

    };

    void append(int val){
        Node* temp1 = new Node();
        temp1->data = val;
        temp1->next = NULL;
        Node* temp2 = head;
        if(head == NULL){
            head = temp1;
            temp1->next = NULL;
        }
        while(temp2->next!=NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    };

    void Print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    };

    linkedList intersection(linkedList a, linkedList b){
        Node* temp1 = a.head;
        linkedList intersection;
        int count=0;
        while(temp1!=NULL){
            Node* temp2 = b.head;
            while(temp2!=NULL){
                if(temp1->data == temp2->data){
                    count++;
                    if(count == 1){
                        intersection.begin(temp1->data);
                    }
                    else{
                        intersection.insert(temp1->data, count);
                    }
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        if(count == 0){
            cout<<"no. of common elements: "<<count<<endl;
        }
        return intersection;
    };

    linkedList Union(linkedList a, linkedList b){
            Node* temp = a.head;
            Node* temp2 = b.head;
            linkedList Union;
            int c = 0;
            //copying all ele of a
            while(temp!=NULL){
                c++;
                if(c==1){
                    Union.begin(temp->data);
                }
                else{
                    Union.insert(temp->data, c);
                }
                temp = temp->next;
            }

            //copying uncommon from b
            while(temp2!=NULL){           //temp2!=NULL and not temp2->next!=NULL else last element would be left out, same for temp1 below
                Node* temp1 = Union.head;
                int c = 0;
                while(temp1!=NULL){
                    if(temp1->data == temp2->data){
                          c++;
                          break;
                    }
                    temp1 = temp1->next;
                }
                if(c==0){
                    Union.append(temp2->data);
                }
                temp2 = temp2->next;
            }

            return Union;
        };

    linkedList neither_nor(linkedList all,linkedList a,linkedList b ){
        linkedList neither_nor;
        linkedList u ;
        u = u.Union(a, b);
        Node* temp1 = all.head;

        while(temp1!=NULL){
            Node* temp2 = u.head;
            int c = 0;
            while(temp2!=NULL){
                if(temp1->data == temp2->data){
                      c++;
                      break;
                }
                temp2 = temp2->next;
            }
            if(c==0){
                if(neither_nor.head == NULL){
                    neither_nor.begin(temp1->data);
                }
                else{
                    neither_nor.append(temp1->data);
                }
            }
            temp1 = temp1->next;
        }

        return neither_nor;

    }

    linkedList difference(linkedList a, linkedList b){
           linkedList difference, i;
           i = i.intersection(a,b);
           Node* temp1 = a.head;

           while(temp1!=NULL){
               Node* temp = i.head;
               int flag1 = 0;
               while(temp!=NULL){
                   if(temp1->data == temp->data){
                       flag1=-1;
                       break;
                   }
                   temp= temp->next;
               }
               if(flag1==0){
                   if(difference.head == NULL){
                       difference.begin(temp1->data);
                   }
                   else{
                       difference.append(temp1->data);
                   }
               }
               temp1 = temp1->next;
           }


           Node* temp2 = b.head;
           while(temp2!=NULL){
               Node* temp = i.head;
               int flag2 = 0;
               while(temp!=NULL){
                   if(temp2->data == temp->data){
                       flag2=-1;
                       break;
                   }
                   temp= temp->next;
               }
               if(flag2==0){
                   difference.append(temp2->data);
               }
               temp2 = temp2->next;
           }
           return difference;
       }

    bool in_superset(linkedList a, linkedList s){
        Node* temp1 = s.head;
        Node* temp2 = a.head;
        while(temp2!=NULL){   //comparing elements of set and superset
            int count = 0;
            while(temp1!=NULL){
                if(temp1->data == temp2->data){
                    count = 1;
                    break;
                }
                temp1 = temp1->next;
            }
            if(count == 0){
                return false;
            }
            temp2 = temp2->next;
        }

        int ca=0, cs = 0;  //comparing lengths of set and superset
        while(temp2!=NULL){
            ca++;
            temp2 = temp2->next;
        }
        while(temp1!=NULL){
            cs++;
            temp1 = temp1->next;
        }
        if(cs<ca){
            return false;
        }
        return true;
    }

   };


bool flag ;
int main()
{
    linkedList all;
    linkedList v;
    linkedList b;
    int vn, bn, an;

    cout<<"enter total no of students: "<<endl;
    cin>>an;
    for(int i=1; i<=an; i++){
        int rolla;
        cout<<"enter roll no. for student "<<i<<": "<<endl;
        cin>>rolla;
        if(i==1){
           all.begin(rolla);
        }
        else{
            all.insert(rolla, i);
        }
    }

    cout<<"enter no of students who like vanilla flavour: "<<endl;
    cin>>vn;
    for(int i=1; i<=vn; i++){
        int rollv;
        cout<<"enter roll no. for student "<<i<<": "<<endl;
        cin>>rollv;
        if(i==1){
           v.begin(rollv);
        }
        else{
            v.insert(rollv, i);
        }

    }

    linkedList d;
    bool flag1 = d.in_superset(v, all);

    cout<<"enter no of students who like butterscotch flavour: "<<endl;
    cin>>bn;
    for(int i=1; i<=bn; i++){
        int rollb;
        cout<<"enter roll no. for student "<<i<<": "<<endl;
        cin>>rollb;
        if(i==1){
           b.begin(rollb);
        }
        else{
            b.insert(rollb, i);
        }
    }

    bool flag2 = d.in_superset(b, all);

    if(flag1 && flag2){
        cout<<"all"<<endl;
        all.Print();
        cout<<"vanilla"<<endl;
        v.Print();
        cout<<"buterscotch"<<endl;
        b.Print();
        while(1){
            int choice;
            cout<<"press 1 to know students who like vanilla and butterscotch flavours"<<endl;
            cout<<"press 2 to know students who like vanilla or butterscotch flavours"<<endl;
            cout<<"press 3 to know students who like any 1 flavour"<<endl;
            cout<<"press 4 for students who like no flavour"<<endl;
            cout<<"press 5 to quit"<<endl;
            cin>>choice;
            linkedList I, U, D, N;
            if(choice == 1){
                cout<<"intersection"<<endl;
                I = I.intersection(v, b);
                I.Print();
            }
            if(choice == 2){
                cout<<"union"<<endl;
                U = U.Union(v, b);
                U.Print();
            }
            if(choice == 3){
                cout<<"difference"<<endl;
                D = D.difference(v, b);
                D.Print();
            }
            if(choice == 4){
                cout<<"neither_nor"<<endl;
                N = N.neither_nor(all, v, b);
                N.Print();
            }
            if(choice == 5){
                cout<<"thank you!";
                break;
            }
        }
    }
    else{
        cout<<"invalid input!"<<endl;
    }

    return 0;
}
