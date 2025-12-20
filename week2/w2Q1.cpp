// Rall Resource Wrapper
//  Create a class that manages:
//  - File
//  - Memory buffer
//  - Or timer   
//       Destructor must clean automatically.

#include <iostream>
#include <fstream> 
#include <chrono>

using namespace std;
using namespace chrono;

class ResourceRall {
    ofstream file;
    int* buffer;
    time_point<high_resolution_clock> start;
    
    public:
    //constructor : acquiring resources
        ResourceRall(const string& filename, int size){
            // timer starts her
            start = high_resolution_clock::now();
            cout << "Timer started\n";


            // file opens her
            file.open(filename);
            if(file.is_open())
                cout<< "File is opened successfully\n";
            else
                cout<< "failed to open file\n";
            
            // allocating memory
            buffer = new int[size];
            cout<< "Memory allocated\n";

        }
        
        // write the text int the file
        void writeTofile(const string& text){
            if (file.is_open()){
                file << text << endl;
            }
        }

        // set a timmer buffer
        void setbuffer(int index, int value){
            buffer[index] = value;
        }

        // destructor --- releasing resources automatically
        ~ResourceRall() {
            // stop timmer

            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end-start);

            cout<< "timer taken: " << duration.count() << "ms\n";

            //close file
            if(file.is_open()){
                file.close();
                cout<< "File is closed automatically\n";
            }

            // free memory
            delete[] buffer;
            cout<< "Memory released automatically\n";
        }
};

int main(){
    ResourceRall r("raii_demo.txt",5);
    r.writeTofile("RAII exammple program");
    r.setbuffer(0,100);

    cout<<"program running...\n";
    return 0 ;

}

// Constructor acquires resources (file, memory, timer)
// Destructor releases resources automatically
// Ensures no memory leaks


