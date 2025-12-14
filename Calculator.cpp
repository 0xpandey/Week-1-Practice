#include<iostream>
using namespace std;
int main(){
    double Num1, Num2;
    char Operator;
    char Option;
    do{
        cout<<"Enter first number: ";
        cin>>Num1;
        cout<<"Enter an operator: ";
        cin>>Operator;
        cout<<"Enter second number: ";
        cin>>Num2;
        switch (Operator){
            case '+':
            cout<<"Result = "<<Num1 + Num2;
            break;
            case '-':
            cout<<"Result = "<<Num1 - Num2;
            break;
            case '*':
            cout<<"Result = "<<Num1 * Num2;
            break;
            case '/':
            if(Num2!=0)
            cout<<"Result = "<<Num1 / Num2;
            else
            cout<<"Zero/Infinity";
            break;
            default:
            cout<<"Invalid operator";
        }
        cout<<"\nDo you want to perfrom another calculation? (y/n): ";
        cin>>Option;
    } while(Option == 'y' || Option == 'Y');
    cout<<"\nCalculation Ends.";
    return 0;
}