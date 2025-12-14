#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector<vector<string>> marathon;   // 2D vector
    vector<string> row;
    string name;
    char choice;
    cout<<"Marathon Registration System\n";
    cout<<"Each row contains 5 participants.\n\n";
    do{
        row.clear();   // clear previous row data
        cout<<"Enter names for a row (5 participants):\n";
        for (int i = 0; i < 5; i++){
            cout<<"Participant "<<i + 1<<": ";
            cin>>name;
            row.push_back(name);
        }
        marathon.push_back(row);  // store row
        cout<<"\nDo you want to enter another row? (y/n): ";
        cin>>choice;
        cout<<endl;
    } while (choice == 'y' || choice == 'Y');
    cout<<"\n--- Marathon Participants Arrangement ---\n";
    for (int i = 0; i < marathon.size(); i++){
        cout<<"Row "<<i + 1<<": ";
        for (int j = 0; j < marathon[i].size(); j++){
            cout<<marathon[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
