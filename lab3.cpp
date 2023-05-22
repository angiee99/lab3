#include <iostream>
// #include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>

#include "structs.h"  // hpp later
#include "parser.h" 
/* 1) class Token 
    int precedence 
    char value
    + getPrecedence() 


*/
using namespace std; 
//just for test
void testStructs(); 


int main(int argc, char *argv[]){
    
    try{
        if(argc != 2){
            cerr << "The command argument should include 2 arguments: \n-the name of the program \n-the math expresion inside the quotes " << endl; 
            return 1;       
        }
        for(int i = 0; i < argc; i ++){
            cout << argv[i] << endl; 
        }
        // stringstream ss(argv[1]); 
        // char c;

        // while(ss.get(c)){
        //     cout << c << endl; 
        // } 

        Parser p(argv[1]); 
        p.toPostfix(); 
   

    }
    catch(exception &e){
        cerr << "Default exception occured:\n" << e.what() << endl; 
    }

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