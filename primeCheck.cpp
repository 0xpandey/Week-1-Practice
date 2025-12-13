#include <iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n < 2) {
        cout << "Not prime";
        return 0;
    }
    if(n % (int)sqrt(n)==0){
        cout<<"Not prime";
    }
    else{
        cout<<"Prime";
    }
    return 0;
}
