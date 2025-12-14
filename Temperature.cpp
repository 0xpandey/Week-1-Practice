#include <iostream>
using namespace std;
int main() {
    int choice;
    float temp, result;
    cout<<"Temperature Converter\n";
    cout<<"1. °C to °F\n";
    cout<<"2. °F to °C\n";
    cout<<"Enter your choice (1 or 2): ";
    cin>>choice;

    if (choice == 1) {
        cout<<"Enter temperature in °C: ";
        cin>>temp;
        result = (temp * 9 / 5) + 32;
        cout<<"Temperature in °F: "<<result<<endl;
    }else if (choice == 2) {
        cout<<"Enter temperature in °F: ";
        cin>>temp;
        result = (temp - 32) * 5 / 9;
        cout<<"Temperature in °C: "<<result<<endl;
    }else {
        cout<<"Invalid choice!"<<endl;
    }
    return 0;
}
