#include<iostream>
using namespace std;
int search(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(key==arr[i]){
            return i+1;
        }
    }
    return -1;
}
int main(){
    int n,i,key;
    cout<<"Enter the number of term:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the terms:\n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nEnter the number to be find: ";
    cin>>key;
    cout<<search(arr,n,key);
    return 0;
}

