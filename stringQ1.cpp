#include <iostream>
#include <string>
using namespace std;

void cpp_strings() {
    
    string unformatted_full_name {"StephenHawking"};
    
   
    
    string first_name { unformatted_full_name,0,7};
    string last_name=unformatted_full_name.substr(7,14);

    string formatted_full_name = first_name + last_name ;
    formatted_full_name.insert(first_name.length()," ");
  
    
    cout << formatted_full_name;
}