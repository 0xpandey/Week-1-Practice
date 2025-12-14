#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
namespace fs = std::filesystem;
using namespace std;
int main() {
    fs::path currentPath = fs::current_path();
    string command;
    cout<<"Simple Command-Line File Explorer\n";
    cout<<"Type 'help' for commands\n";
    while (true) {
        cout<<"\n[" << currentPath << "]> ";
        cin>>command;
        if (command == "help") {
            cout<<"Commands:\n";
            cout<<"  ls        - list files\n";
            cout<<"  cd <dir>  - change directory\n";
            cout<<"  cat <file>- read a text file\n";
            cout<<"  exit      - quit program\n";
        }
        else if (command == "ls") {
            for (const auto& entry : fs::directory_iterator(currentPath)) {
                cout<<entry.path().filename()<<endl;
            }
        }
        else if (command == "cd") {
            string dir;
            cin>>dir;
            fs::path newPath = currentPath / dir;

            if (fs::exists(newPath) && fs::is_directory(newPath)) {
                currentPath = fs::canonical(newPath);
            } else {
                cout<<"Directory not found!"<<endl;
            }
        }
        else if (command == "cat") {
            string file;
            cin>>file;
            fs::path filePath = currentPath / file;

            ifstream inFile(filePath);
            if (!inFile) {
                cout<<"Cannot open file!"<<endl;
            } else {
                string line;
                while (getline(inFile, line)) {
                    cout<<line<<endl;
                }
            }
        }
        else if (command == "exit") {
            cout<<"Exiting explorer.\n";
            break;
        }
        else {
            cout<<"Unknown command. Type 'help'.\n";
        }
    }
    return 0;
}
