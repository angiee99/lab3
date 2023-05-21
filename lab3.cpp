#include <iostream>
// #include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>

#include "structs.cpp" 
/* 1) class Token 
    int precedence 
    char value
    + getPrecedence() 


*/
using namespace std; 
//just for test
void testStructs(); 
//Parser
// - mb queue, stack 
// + toPostfix, # ifNumber
void toPostfix(string); 
bool _ifNumber(const string); 


int main(int argc, char *argv[]){
    
    try{
        // if(argc != 2){
        //     cerr << "The command argument should include 2 arguments: \n-the name of the program \n-the directory name" << endl; 
        //     return 1;       
        // }
        for(int i = 0; i < argc; i ++){
            cout << argv[i] << endl; 
        }

        toPostfix(argv[1]); 
    }
    catch(exception &e){
        cerr << "Default exception occured:\n" << e.what() << endl; 
    }

}


void toPostfix(string input){
    stringstream inp(input); 
    string value; 
    cout << input.length() << endl; 
    // int size = input.length();
    Queue qu(input.length()); 
    Stack st(input.length());

    while(inp >> value) {
        if (_ifNumber(value)){
            cout<< value<< endl; 
            qu.enqueue(value); 
        }
        else{
            
            cout << "notNum" << value << endl; 
            //check precedence 
            /*
            if prec value > prec before
                qu.enqueu(st.pop()); 
                st.push(value);
            else
                st.push(value);
            */
            st.push(value); 
        }
    }
    cout<<"\nQueue: "; 
    qu.print();
    cout<<"\nStack: "; 
    st.print();  

}

bool _ifNumber(const string s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
void testStructs(){
    try{
       
        Queue q(5); 
        q.enqueue("1"); 
        q.enqueue("2"); 
        q.print();
        cout << endl; 
        cout << q.dequeue()<< endl;
        q.print();

        Stack s(5); 
        s.push("1"); 
        s.push("2"); 
        s.push("3"); 
        s.print(); 
        cout << s.pop() << endl; 
        s.print();
    }
    catch(exception &e){
        cerr << "Default exception occured:\n" << e.what() << endl; 
    }

}