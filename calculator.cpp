#include<iostream>
using namespace std;
int main(){
    int num1;
    int num2;
    char op;
    cout<<"Enter first number:";
    cin>>num1;
    cout<<"Choose Operator (+,-,*,/):";
    cin>>op;
    cout<<"Enter second number:";   
    cin>>num2;

    if (op=='+'){
        cout<<"Sum:"<<num1+num2;
    }
    else if (op=='-'){
        cout<<"Substraction:"<<num1-num2;
    }
    else if (op=='*'){
        cout<<"Multiplication:"<<num1*num2;
    }
    else if (op=='/'){
        if(num2!=0){
            cout<<"Division:"<<num1/num2;
        }
        else{
            cout<<"Error, Division by zero is not allowed.";
        }
    }
    else{
        cout<<"Invalid Operator";
    }   
    return 0;
}
