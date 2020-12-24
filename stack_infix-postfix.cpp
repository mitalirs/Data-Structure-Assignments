//Implement C++ program for expression conversion as infix to postfix and its evaluation
//using stack based on given conditions:
//1. Operands and operator, both must be single character.
//2. Input Postfix expression must be in a desired format.
//3. Only '+', '-', '*' and '/ ' operators are expected.

#include<iostream>
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
    int topmost_f(){
        return st[top];
    }
};


stack postfix;
stack operands;

int precedence_value(char ch){

    if(ch=='*' || ch == '/'){
        return 2;
    }
    if(ch=='+' || ch == '-'){
        return 1;
    }
    return 0;
}

char higherPrecedence(char ch1, char ch2){
    int c1  = precedence_value(ch1);
    int c2  = precedence_value(ch2);
    return (c1>c2)? ch1:ch2;
}

bool isClosing(char c){return c==')';}
bool isOpening(char c){return c=='(';}
bool isOperator(char c){return c=='*'||c=='/'||c=='+'||c=='-';}
bool isOperand(char c){return isalnum(c);}

string infTopost(string input){
    int i=0;
    int n = input.size();
    string output = "";
    while(i<n){
        if(isOpening(input[i])){
            postfix.push(input[i]);
        }

        if(isClosing(input[i])){
            while(!postfix.isEmpty() && !isOpening(postfix.topmost())){
                output = output + postfix.topmost();
                postfix.pop();
            }
            postfix.pop();  //for the opening (
        }

        if(isOperator(input[i])){
                while(!postfix.isEmpty() && higherPrecedence(input[i], postfix.topmost())==postfix.topmost() && !isOpening(postfix.topmost())){
                    output = output + postfix.topmost();
                    postfix.pop();
                }
            postfix.push(input[i]);
        }

        if(isOperand(input[i])){
            output = output + input[i];
        }

        i++;

    }

    while(!postfix.isEmpty()){
        output = output + postfix.topmost();
        postfix.pop();
    }

    return output;
}

stack eval;


void evaluatePostfix(){
    string exp;
    cout<<"enter postfix string with numbers in place of variables: "<<endl;
    cin>>exp;
    int k =exp.length();
    for(int i=0;i<k;i++){
        if(isdigit(exp[i])){
            int x = (int)exp[i] - 48; //char to int
            eval.push(x);
        }
        else if(isOperator(exp[i])){
            int o1 = eval.topmost();
            eval.pop();
            int o2 = eval.topmost();
            eval.pop();
            float f;
            if(exp[i]=='*'){
                f = (o1*o2);
                cout<<"st_top: "<<f<<endl;
                eval.push(f);
            }
            if(exp[i]=='+'){
                f = (o1+o2);
                cout<<"st_top: "<<f<<endl;
                eval.push(f);
            }
            if(exp[i]=='-'){
                f = (o2-o1);
                cout<<"st_top: "<<f<<endl;
                eval.push(f);
            }
            if(exp[i]=='/'){
                f = (o2/o1);
                cout<<"st_top: "<<f<<endl;
                eval.push(f);
            }
            if(i==k-1){
                cout<<"final value: ";
                cout<<f;
            }
        }
    }

}

int main()
{
        cout<<"enter string: "<<endl;
        string input;
        cin>>input;
        string exp = infTopost(input);
        cout<<exp<<endl;
        evaluatePostfix();

    return 0;
}
