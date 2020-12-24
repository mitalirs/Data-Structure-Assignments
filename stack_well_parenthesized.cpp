//In any language program mostly syntax error occurs due to unbalancing delimiter such as
//(),{},[]. Write C++ program using stack to check whether given expression is well
//parenthesized or not.

#include <iostream>
#include<string>
using namespace std;

class stack {
public:
    char st[100];
    int top = -1;

    void push(char x){
        top++;
        st[top] = x;
    };
    void pop(){
            top--;

    };
    bool isEmpty(){
        return top==-1;
    };
    char topmost(){
        return st[top];
    }
};

int main()
{
    stack s1;
    string s;
    int p = 0;
    cout<<"enter expression: "<<endl;
    cin>>s;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            char ch = s[i];
            s1.push(ch);
            p++;
        }
        if(s[i]=='}'){
            if(s1.topmost() == '{'){
                s1.pop();
            }
            else if(s1.topmost()){
                cout<<"a closing brace for "<< s1.topmost()<<" needed"<<" at position (0-base indexed) "<<p<<endl;
                break;
            }
            else if(!s1.topmost()){
                cout<<"extra closed brackets!"<<endl;
                break;
            }
            p++;
        }

        if(s[i]==']'){
            if(s1.topmost() == '['){
                s1.pop();
            }
            else if(s1.topmost()){
                cout<<"a closing bracket for "<< s1.topmost()<<" needed"<<" at position (0-base indexed) "<<p<<endl;
                break;
            }
            else if(!s1.topmost()){
                cout<<"extra closed brackets!"<<endl;
                break;
            }
            p++;
        }

        if(s[i]==')'){
            if(s1.topmost() == '('){
                s1.pop();
            }
            else if(s1.topmost()){
                cout<<"a closing bracket for "<< s1.topmost()<<" needed"<<" at position (0-base indexed) "<<p<<endl;
                break;
            }
            else if(!s1.topmost()){
                cout<<"extra closed brackets!"<<endl;
                break;
            }
            p++;
        }
        if(i==n-1){
            if(s1.isEmpty()){
                cout<<"well parenthesized!"<<endl;
                break;
            }
            else{
                 cout<<"extra opening brackets!"<<endl;
                 break;
            }
      }

}

    return 0;
}