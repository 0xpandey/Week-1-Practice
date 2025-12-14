#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1 ; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover = temp;
    }

    return head;
}

int Nodelength(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        
        temp = temp->next;
        count++;
    }

    return count;
}

int Nodesearch(Node *head,int key){
    Node* temp = head;
    int index = 0,x;
    bool flag = false;

    while (temp!= NULL){
        if(temp->data == key){
            flag = true;
            x=index;
            break;
        }
        temp = temp->next;
        index++;
    }
    if(flag){
        return x;
    }
    else{
        return -1;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
} 

Node* removehead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
    
}

Node* removetail(Node* head){

    if(head == NULL || head->next == NULL) return NULL;
    
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }   
    delete temp->next;
    temp->next = nullptr;
     
    return head;  
}

Node* removeatK(Node* head,int k){
    if(head == NULL) return head;

    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int count = 0; 
    Node* temp = head; 
    Node* previous = NULL;

    while (temp!= NULL){
        count++;
        if(count == k){
            previous->next = previous->next->next;
            free(temp);
            break;
        }
        previous = temp;
        temp = temp->next;
    }
    return head;


}

Node* removeelement(Node* head,int ele){
    if(head == NULL) return head;

    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    
    Node* temp = head; 
    Node* previous = NULL;

    while (temp!= NULL){
        
        if(temp->data == ele){
            previous->next = previous->next->next;
            free(temp);
            break;
        }
        previous = temp;
        temp = temp->next;
    }
    return head;
}


    
int main(){
    vector<int> arr = {12,9,17,5};
    Node* head = convertArr2LL(arr);
    Node* temp = head;

    // while(temp){
    //     cout<< temp->data<<" ";
    //     temp = temp->next;
    // }
    // cout<<endl;

    // cout<<Nodelength(head);
    // cout<<endl;
    // cout<<Nodesearch(head,14);

    // head = removehead(head);
    // print(head);
    // head = removetail(head);
    // print(head);
    // head = removeatK(head,2);
    // print(head);
    head = removeelement(head,17);
    print(head);
    


}

